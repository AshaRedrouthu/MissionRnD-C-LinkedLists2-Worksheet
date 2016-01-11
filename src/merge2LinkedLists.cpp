/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL&&head2 != NULL)
		return head2;
	if (head2 == NULL&&head1 != NULL)
		return head1;
	if (head1==NULL||head2==NULL)
	    return NULL;
	struct node *ptr = NULL,*result=NULL;
	if (head1->num <= head2->num){
		result = head1;
		ptr = head1;
		head1 = head1->next;
	}
	else{
		result = head2;
		ptr = head2;
		head2 = head2->next;
	}
	while (head1 != NULL && head2 != NULL){
		if (head1->num <= head2->num){
			ptr->next = head1;
			ptr = ptr->next;
			head1 = head1->next;
		}
		else{
			ptr->next = head2;
			ptr = ptr->next;
			head2 = head2->next;
		}
	}
	if (head2 != NULL)
		ptr->next = head2;
	else
		ptr->next = head1;
	return result;

}
	

