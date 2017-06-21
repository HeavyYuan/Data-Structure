/*该链表带有头节点（不是第一个节点，是头节点）*/
#include <stdio.h>
#include <stdlib.h>
#include "sl1_node.h"

int sll_insert(Node *head,int value)
{
	Node *current = head->next;
	Node *previous = head;
	Node *new = NULL;

	while(current && current->value < value)
	{
		previous = current;
		current = current->next;	
	}

	new = (Node *)malloc(sizeof(struct NODE));
	if(new == NULL)
	{
		printf("malloc failed in sll_insert\n");
		exit(1);
	}

	new->value = value;
	previous->next = new;
	new->next = current;
	return 0;

}
Node *create_list() /*初始化头节点*/
{
	Node *list = NULL;
	list = (Node *)malloc(sizeof(struct NODE));	
	if(list == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	list->value = -1;
	list->next = NULL;
	return list;
}

int print_list(Node *list)
{
	printf("The element of the list is:\n");
	while(list->next)
	{
		printf("%d ",list->next->value);
		list->next = list->next->next;
	}
	printf("\n");
	return 0;
}

int main(int args,char *argv[])
{
	Node *list = NULL;
	list = create_list(); /*创建链表的头节点*/
	if(list == NULL)
	{
		printf("create list failed!\n");
		exit(1);
	}
	sll_insert(list,2); /*传入指针的指针*/
	sll_insert(list,1); /*传入指针的指针*/
	sll_insert(list,3); /*传入指针的指针*/
	sll_insert(list,0); /*传入指针的指针*/

	print_list(list);
	exit(0);	

}
