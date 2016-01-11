/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<=0)
	return NULL;
	int i = 0;
	struct node *ptr = head, *preptr = head;
	struct node *newnode;
	
	while (ptr != NULL)
	{
		i = 0;
		while (i < K&&ptr!=NULL)
		{
			preptr = ptr;
			ptr = ptr->next;
			i++;
		}
		if (i == K)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = K;
			preptr->next = newnode;
			newnode->next = ptr;
		}
	}
	return head;
}
