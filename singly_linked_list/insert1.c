/*问题：插入比第一个节点小的节点会core*/ 
/*create_list创建了一个链表，只是该链表只有一个节点。*/
#include <stdio.h>
#include <stdlib.h>
#include "sl1_node.h"

#define TRUE 1
#define FALSE 0

int sl1_insert(Node *list, int new_value)
{
	Node *previous = NULL;
	Node *new = NULL;

	/*确定插入位置*/
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
	previous->link = new; /*core点,previous=NULL*/

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
	sl1_insert(list,2);
	print_list(list);
	exit(0);	

}
