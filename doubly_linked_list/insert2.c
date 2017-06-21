#include "doubly_linked_list_node.h"

int dll_insert(Node *rootpt, int value)
{
	Node *this = NULL,*next = NULL;
	Node *newnode = NULL;

	for(this = rootpt; (next = this->fwd) != NULL; this=next)
	{
		if(next->value == value)
			return 0;
		if(next->value > value)
			break;
	}

	newnode = (Node *)malloc(sizeof(struct NODE));
	if(newnode == NULL)
	{
		printf("malloc failed!\n");
		exit(1);
	}

	newnode->value = value;


	if(next != NULL)
	{
		newnode->fwd = next;
		if(rootpt != this)
		{
			this->fwd = newnode;
			newnode->bwd = this;
		}else{
			rootpt->fwd = newnode;
			newnode->bwd = NULL;
		}
		next->bwd = newnode;
		
	}else{
		newnode->fwd = NULL;
		if(rootpt != this)
		{
			this->fwd = newnode;
			newnode->bwd = this;
		}else{

			rootpt->fwd = newnode;
			newnode->bwd = NULL;
		}
		rootpt->bwd = newnode;
	}
	return 0;
}

int print_link(Node *rootpt)
{
	Node *this = NULL;
	printf("doubly linked list: \n");
	for(this = rootpt;this;this=this->fwd)
	{
		printf("%d ",this->value);
	}
	printf("\n");
	return 0;
	
}

int create_dll(Node **rootpt)
{
	Node *head = NULL;
	head = (Node *)malloc(sizeof(struct NODE));
	if(head==NULL)
	{
		printf("malloc failed when create dll.\n");
		exit(1);
	}
	head->value = -1;
	head->fwd = NULL;
	head->bwd = head;
	*rootpt = head;
	return 0;
}

int main(int args,char *argv[])
{

	Node *rootpt = NULL;
	create_dll(&rootpt);
	dll_insert(rootpt,5);
	dll_insert(rootpt,1);
	dll_insert(rootpt,10);
	dll_insert(rootpt,5);
	print_link(rootpt);
	return 0;

	
}
