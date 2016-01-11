/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int m = 0;
	if (head == NULL)
		return -1;
	struct node *ptr = head, *preptr = head;
	if (head != NULL){
		while (ptr != NULL&&ptr->next != NULL)
		{
			m = preptr->num + preptr->next->num;
			ptr = ptr->next->next;
			preptr = preptr->next;
		}
		
		if (ptr == NULL)
			return ((m) / 2);
		return preptr->num;

	}

}
