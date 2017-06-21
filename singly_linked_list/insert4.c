 /*解决的问题：消除特殊情况的处理
  *去掉previous变量，每次确定插入点时，不在保留当前节点的前一个节点。
  *而是保留previous节点中的link变量的地址linkp
  *在当前实现中，我们不需要在已经存在的链表中来插入值。
  *当前实现可以在第一个节点为NULL的情况下，通过sll_insert函数创建一个单链表。
 * */
#include <stdio.h>
#include <stdlib.h>
#include "sl1_node.h"

#define TRUE 1
#define FALSE 0

int sll_insert(Node **linkp, int new_value) /*传入指针的指针*/
{

	Node *new = NULL;
	Node *current = NULL;

	/*确定插入点*/
	 current = *linkp;
	while(current && current->value < new_value)
	{
	   	linkp = &current->link; /*取Node中link的地址*/
		current = *linkp;
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
	new->link = current;
	*linkp = new; /*应对两种情况：1.linkp是第一个节点；2.linkp是list->link的地址*/
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
	/*list = create_list(); //不在需要创建链表
	/if(list == NULL)
	/{
	/	printf("create list failed!\n");
	/	exit(1);
	/}*/
	sll_insert(&list,2); /*传入指针的指针*/
	sll_insert(&list,1); /*传入指针的指针*/
	sll_insert(&list,3); /*传入指针的指针*/
	print_list(list);
	exit(0);	

}
