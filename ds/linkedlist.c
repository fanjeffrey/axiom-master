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
	ListNode * r = head;
	ListNode * node;
	int i;
	for(i=1; i<=n; i++)
	{
		printf("add a new node at %d with the data: %d ...\n", i, i);
		node = (ListNode *)malloc(sizeof(ListNode));
		node->data = i;
		r->next = node;
		r = node;
	}
	r->next = NULL;
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
	printf("Testing reverse with a linked list containing %d node(s) ...\n", n);
	List_Pointer head = init(n);
	print(head);
	List_Pointer reversed = reverse1(head);
	//List_Pointer reversed = reverse(head);
	print(reversed);
	printf("\n");
}

ListNode * locate(List_Pointer head, int d)
{
    ListNode *p, *q;
    p = head;
    q = head->next;
    while (q != NULL && q->data > d)
    {
        p = q;
        q = q->next;
    }
    
    return p;
}

void insertSortedList(List_Pointer head, int d)
{
    ListNode * p = locate(head, d);
    if (p == NULL)
        error("Can't find a node.");
        
    ListNode * n = (ListNode *)malloc(sizeof(ListNode));
    n->data = d;
    n->next = p->next;
    p->next = n;
}

void test_insert_into_sorted_list()
{
    printf("Testing insertSortedList ...\n");
    List_Pointer head = init(10);
    print(head);
    insertSortedList(head, 7);
    print(head);
    insertSortedList(head, 0);
    print(head);
    insertSortedList(head, 17);
    print(head);
    printf("\n");
    
    head = init(0);
    print(head);
    insertSortedList(head, 7);
    print(head);
}

List_Pointer split(List_Pointer a)
{
	List_Pointer b = (List_Pointer)malloc(sizeof(ListNode));
	ListNode * br = b;
	ListNode *p, *q;
	int i = 1;
	p = a->next;
	while(p != NULL)
	{
		if (i % 2 == 0)
		{
			// remove the node from a
			q->next = p->next;
			// append the node to b
			br->next = p;
			br = p;			
		}
		
		q = p;
		p = p->next;
		i++;
	}
	br->next = NULL;
	
	return b;
}

List_Pointer split1(List_Pointer a)
{
	List_Pointer b = (List_Pointer)malloc(sizeof(ListNode));
	ListNode * br = b;
	ListNode * ar = a;
	ListNode *q = a->next;
	while(q != NULL)
	{
		ar->next = q;
		ar = q;
		q = q->next;
		if (q)
		{
			br->next = q;
			br = q;
			q = q->next;
		}
	}
	ar->next = br->next = NULL;
	
	return b;
}

List_Pointer split2(List_Pointer a)
{
	List_Pointer b = (List_Pointer)malloc(sizeof(ListNode));
	ListNode * br = b;
	ListNode *p, *q;
	q = a->next;
	while(q != NULL)
	{
		p = q;
		q = q->next;
		if (q)
		{
			p->next = q->next;		
			br->next = q;
			br = q;
			q = q->next;
		}
	}
	br->next = NULL;
	
	return b;
}

void test_split()
{
	printf("Testing split ...\n");
	List_Pointer a = init(10);
	print(a);
	List_Pointer b = split2(a);
	print(b);
	print(a);
	printf("\n");
}

int main(void)
{
	test_split();
	//test_reverse(7);
	//test_reverse(2);	
	//test_reverse(1);	
	//test_reverse(0);
	//test_reverse(100);
	
	//test_insert_into_sorted_list(10);
	
	return 0;
}
