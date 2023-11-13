#ifndef __ROLE_LIST__
#define __ROLE_LIST__
#include<stdio.h>

typedef struct user_to_dev{
	int a;
	int b;
	int c;

}
struct list_head{
	struct list_head *prev;
	struct list_head *next;
};
typedef struct user_list{
	int fd;
	int num_type;
	int IEMI_list;
	//int math;
	struct list_head list;
}User_List;

typedef struct dev_list{
	int fd;
	int num_type;
	int IEMI_list;
	struct list_head list;
}Dev_List;

/*
(1)INIT_LIST_HEAD()
(2)list_add()
(3)list_add_tail
(4)list_del()
(5)list_entry()
(6)list_for_each()
*/
 
#define prefetch(x) __builtin_prefetch(x)
#define list_for_each(pos, head) \
	for ( pos = (head)->next; prefetch(pos->next), pos != (head); pos = pos->next)
 
/****************************************entry***********************************************/
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define list_entry(ptr, type, member) container_of(ptr, type, member)
#define container_of(ptr, type, member) (\
	{															\
		const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
		(type *)( (char *)__mptr - offsetof(type,member) );     \
	}															\
)
/****************************************add***********************************************/
void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}
void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}
/***************************************del************************************************/
void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}
void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	entry->next = (void *) 0;
	entry->prev = (void *) 0;
}
/***************************************************************************************/
 
void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}
/***************************************************************************************/
 
 
//struct list_head score_head;
//struct score stu1, stu2,stu3;
//struct list_head *pos;
//struct score *tmp;
 
int test_main(void)
{	
	INIT_LIST_HEAD(&score_head);
	stu1.englist=99;stu1.math=98;stu1.num=1001;
	stu2.englist=9;stu2.math=8;stu2.num=1002;
	stu3.englist=69;stu3.math=68;stu3.num=1003;
	
	list_add_tail(&(stu1.list),&score_head);
	list_add_tail(&(stu2.list),&score_head);
	list_add_tail(&(stu3.list),&score_head);
 
	list_for_each(pos,&score_head){
		tmp=list_entry(pos,struct score,list);//根据head_list的地址，找到结构体基地址
		printf("math=%d\n",tmp->math); 
	}
	return 0;
}

#endif
