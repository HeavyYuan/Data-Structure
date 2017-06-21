/*解决的问题：插入比第一个节点小的节点，不在core*
 *新问题：只能打印第一个节点。list = new没有生效.*
 *原因：函数的参数传入是值传入: sll_insert的传入参数list
 * */
#include <stdio.h>
#include <stdlib.h>
#include "sl1_node.h"

#define TRUE 1
#define FALSE 0

int sll_insert(Node *list, int new_value)
{
	Node *previous = NULL;
	Node *new = NULL;

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
		list = new;
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
	sll_insert(list,2);
	sll_insert(list,1);
	sll_insert(list,3);
	print_list(list);
	exit(0);	

}
