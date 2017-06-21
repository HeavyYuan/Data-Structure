 /*解决的问题：只能打印第一个节点。list = new没有生效.*
  *
 * */
#include <stdio.h>
#include <stdlib.h>
#include "sl1_node.h"

#define TRUE 1
#define FALSE 0

int sll_insert(Node **rootp, int new_value) /*传入指针的指针*/
{
	Node *previous = NULL;
	Node *new = NULL;
	Node *list = *rootp;

	while(list && list->value < new_value)
	{
		previous = list;
		list = list->link;
	}

	new = (Node *)malloc(sizeof(struct NODE));
	if(new == NULL)
	{
		printf("malloc failed!\n"); /*c的错误处理 -- morac*/
		return -1;
	}

	/*赋值*/
	new->value = new_value;
	
	/*插入*/
	new->link = list;
	if(previous == NULL)
		*rootp = new; /*如果previous==NULL,表明第一个节点是NULL（链表为空）,就把插入的节点设置成第一个节点*/
	else
		previous->link = new;

	return 0;

}

 Node *create_list()
{
	Node *list = NULL;
	list = (Node *)malloc(sizeof(struct NODE));	
	if(list == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	list->value = 3;
	list->link = NULL;
	return list;
}

int print_list(Node *list)
{
	printf("The element of the list is:\n");
	while(list)
	{
		printf("%d ",list->value);
		list = list->link;
	}
	printf("\n");
	return 0;
}

int main(int args,char *argv[])
{
	Node *list = NULL;
	list = create_list();
	if(list == NULL)
	{
		printf("create list failed!\n");
		exit(1);
	}
	sll_insert(&list,2); /*传入指针的指针*/
	sll_insert(&list,1); /*传入指针的指针*/
	sll_insert(&list,3); /*传入指针的指针*/
	print_list(list);
	exit(0);	

}
