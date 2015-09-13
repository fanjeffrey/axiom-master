#include<stdlib.h>
#include<stdio.h>

void error(char * message)
{
	fprintf(stderr, "Error: %s \n", message);
	exit(1);
}

// --------------------------------
// Linked List
// --------------------------------
typedef struct node{
	int data;
	struct node *next;
} ListNode;

typedef ListNode * List_Pointer;

List_Pointer init(int n)
{
	if (n < 0)
		error("The argument 'n' can't be less than zero.\n");
	
	printf("Initializing a linked list with %d node(s) ...\n", n);
	printf("add a head node ...\n");	
	List_Pointer head = (ListNode *)malloc(sizeof(ListNode));
	head->next = NULL;
	
	ListNode * node;
	int i;
	for(i=1; i<=n; i++)
	{
		printf("add a new node at %d with the data: %d ...\n", i, i);
		node = (ListNode *)malloc(sizeof(ListNode));
		node->data = i;
		node->next = head->next;
		head->next = node;
	}
	printf("Initializing a linked list with %d node(s) ... done.\n", n);
	
	return head;
}

List_Pointer reverse(List_Pointer head)
{
	if (head == NULL)
		error("The head is NULL.");
		
	printf("reversing linked list ...\n");	
	ListNode * current;
	ListNode * previous;
	previous = NULL;	
	while(head->next != NULL)
	{
		current = head->next;
		head->next = current->next;
		current->next = previous;
		previous = current;
	}
	head->next = previous;	
	printf("reversing linked list ... done.\n");
	
	return head;
}

List_Pointer reverse1(List_Pointer head)
{
	if (head == NULL)
		error("The head is NULL.");
		
	printf("reversing linked list ...\n");	
	ListNode * reversing, * toReverse;
	toReverse = head->next; // points to the start node, as the start node is the first node to reverse
	head->next = NULL; // used to point to the reversed nodes
	while(toReverse != NULL)
	{
		reversing = toReverse;
		toReverse = toReverse->next;
		reversing->next = head->next;
		head->next = reversing;
	}
	printf("reversing linked list ... done.\n");
	
	return head;
}

void print(List_Pointer head)
{
	if (head == NULL)
		error("The head pointer is NULL.\n");
		
	if (head->next == NULL) 
		printf("This is an empty linked list.\n");
	
	ListNode * p = head->next;	
	printf("The list is printed as below:\n");
	printf("-----------------------------------\n");
	printf("head->next");
	int count = 1;
	while(p != NULL)
	{
		printf(" : %d@%d", p->data, count++);
		p = p->next;
	}
	printf("\n-----------------------------------\n");	
} 

void test_reverse(n)
{
	printf("Testing InvertLinkedList with a linked list containing %d node(s) ...\n", n);
	List_Pointer head = init(n);
	print(head);
	List_Pointer reversed = reverse1(head);
	//List_Pointer reversed = reverse(head);
	print(reversed);
	printf("\n");
}

int main(void)
{
	test_reverse(7);
	test_reverse(2);	
	test_reverse(1);	
	test_reverse(0);
	//test_reverse(100);
	
	return 0;
}
