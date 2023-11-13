#include "role_list.h"
#include <stdlib.h>

struct list_head score_head;
void list_init()
{
	INIT_LIST_HEAD(&score_head);
}
int add_user(int fd,char *IMEI[16])
{
	User_List *p = malloc(User_List);
	if(p == NULL){
		perror("create malloc error");
		return -1;
	}
	p->fd = fd;
	p->IEMI_list = IMEI;
	p->num_type = 1;
	list_add_tail(&(p->list),&score_head);
}
int del_user(int fd)
{
	struct list_head *pos;
	User_List *tmp;
	list_for_each(pos,&score_head){
		tmp=list_entry(pos,struct score,list);//根据head_list的地址，找到结构体基地址
		if(tmp->fd == fd){
			list_del(tmp->list)
			printf("fd = %d User back\r\n"); 
		}
		printf("math=%d\n",tmp->math); 
	}
}
void msg_user_to_dev(int fd,)
{
	struct list_head *pos;
	User_List *tmp;
	int cont;
	list_for_each(pos,&score_head){
		tmp=list_entry(pos,struct score,list);//根据head_list的地址，找到结构体基地址
		if(tmp->fd == fd){
			cont = 1;
		}
		//printf("math=%d\n",tmp->math); 
	}
		
	list_for_each(pos,&score_head){
		tmp=list_entry(pos,struct score,list);//根据head_list的地址，找到结构体基地址
		if(tmp->fd == fd){
			cont = 1;
		}
		//printf("math=%d\n",tmp->math); 
	}
}
int add_dev(int fd,char *IMEI[16])
{
	Dev_List *p = malloc(Dev_List);
	if(p == NULL){
		perror("create malloc error");
		return -1;
	}
	p->fd = fd;
	p->IEMI_list = IMEI;
	p->num_type = 2;
	list_add_tail(&(p->list),&score_head);
}
int del_dev(int fd)
{
	struct list_head *pos;
	Dev_List *tmp;
	list_for_each(pos,&score_head){
		tmp=list_entry(pos,struct score,list);//根据head_list的地址，找到结构体基地址
		if(tmp->fd == fd){
			list_del(tmp->list)
			printf("fd = %d dev back\r\n"); 
		}
		printf("math=%d\n",tmp->math); 
	}
}