 /*
  * 去掉list变量
  *
 * */
#include <stdio.h>
#include <stdlib.h>
#include "sl1_node.h"

#define TRUE 1
#define FALSE 0

int sll_insert(Node **linkp, int new_value) /*传入指针的指针*/
{

	Node *new = NULL;

	/*确定插入点*/
	while((*linkp) && (*linkp)->value < new_value)
	{
		linkp = &(*linkp)->link; /*取Node中link的地址*/
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
	new->link = *linkp;
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
	list = create_list();
	if(list == NULL)
	{
		printf("create list failed!\n");
		exit(1);
	}
	sll_insert(&list,2); /*传入指针的指针*/
	sll_insert(&list,2); /*传入指针的指针*/
	print_list(list);
	exit(0);	

}
