#include<stdlib.h>
#include<stdio.h>

void error(char * message)
{
	fprintf(stderr, "Error: %s \n", message);
	exit(1);
}

// -------------------------------
// Sequential List
// -------------------------------
#define MaxSize 100
typedef int DataType;
typedef struct {
	DataType data[MaxSize];
	int length;
} SequentialList;

SequentialList * init(int n)
{
	SequentialList * list = malloc(sizeof(SequentialList));
	list->length = 0;
	
	int i;
	for(i=1; i<=n; i++)
	{
		list->data[i-1] = i;
		list->length ++;
	}
	printf("Initialized a sequential list with %d element(s).\n", n);
	
	return list;
}

void insert(SequentialList * list, DataType x, int i)
{
	if (list == NULL)
		error("The sequential list can't be NULL.\n");
		
	if ( i < 1 || i > list->length + 1)
		error("The insert position is out of the boundary.\n");
		
	int j;
	for (j = list->length - 1; j >= i-1; j--)
	{
		list->data[j+1] = list->data[j];		
	}	
	list->data[i-1] = x;
	list->length ++;
	
	printf("Inserted %d at %d.\n", x, i);	
}

void reverse(SequentialList * list)
{
	if (list == NULL)
		error("The sequential list can't be NULL.\n");
	
	printf("reversing sequential list ...\n");		
	int i, k, temp;
	k = list->length / 2;
	for(i=0; i<k; i++)
	{
		temp = list->data[i];
		list->data[i] = list->data[list->length-1 - i];
		list->data[list->length-1 - i] = temp;
	}
	printf("reversing sequential list ... done.\n");
}

void print(SequentialList * list)
{
	if (list == NULL) 
		error("The list is NULL.\n");
		
	if (list->length == 0) 
		printf("This is an empty sequential list.\n");
	
	printf("The list is printed as below:\n");
	printf("-----------------------------------\n");
	printf("Length: %d\n", list->length);
	printf("Element(s)");
	int i;
	for(i=0; i<list->length; i++)
	{
		printf(" : %d@%d", list->data[i], i);
	}
	printf("\n-----------------------------------\n");	
} 

void test_reverse(n)
{
	printf("Testing reverse with a sequential list containing %d element(s) ...\n", n);
	SequentialList * list = init(n);
	print(list);
	reverse(list);
	print(list);
	printf("\n");
}


int main(void)
{
	test_reverse(10);
	test_reverse(11);
	
	return 0;
}
