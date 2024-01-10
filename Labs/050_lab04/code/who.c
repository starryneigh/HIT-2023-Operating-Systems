#include <errno.h>
#include <linux/kernel.h>
#include <asm/segment.h>
#include <string.h>

char name_cp[24];
int len = 0;
int errno = 0;

int sys_whoami(char* name, unsigned int size){
	int i;
	if(len > size){
		errno = EINVAL;
		return -errno;
	}
	for(i=0; i<len; i++){
		put_fs_byte(name_cp[i], name+i);
		//printk("%c", name_cp[i]);
	}
	//printk("\t");
	return len;
}

int sys_iam(const char* name){
	int i;
	char temp[24];
	for(i=0; i<24; i++){
		temp[i] = get_fs_byte(name+i);
		if(temp[i] == '\0'){
			break;
		}
		//printk("%c", temp[i]);
	}
	//printk("\t");
	if(i>=24 && temp[i-1]!='\0'){
		errno = EINVAL;
		return -errno;
	}
	len = i;
	strcpy(name_cp, temp);
	//printk("%d\n", len);
	return len;
}
