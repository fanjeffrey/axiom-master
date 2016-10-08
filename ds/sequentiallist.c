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

SequentialList init(int n)
{
	SequentialList list; // = malloc(sizeof(SequentialList));
	list.length = 0;
	
	printf("Initializing a sequential list with %d element(s) ...\n", n);
	int i;
	for(i=1; i<=n; i++)
	{
		list.data[i-1] = i;
		list.length ++;
	}
	printf("Initialized a sequential list with %d element(s).\n", n);
	
	return list;
}

void insert(SequentialList * list, int i, DataType x)
{
	printf("trying to insert %d at %d ...\n", x, i);
	
	if (list == NULL)
		error("The sequential list can't be NULL.\n");
	
	if ( i < 1 || i > list->length + 1)
		error("The insert position is out of the boundary.\n");
	
	if (list->length >= MaxSize)
		error("The list is full.");
		
	int j;
	for (j = list->length - 1; j >= i-1; j--)
	{
		list->data[j+1] = list->data[j];		
	}	
	list->data[i-1] = x;
	list->length ++;
	
	printf("Inserted %d at %d.\n", x, i);	
}

/*
 1 <= i <= n
*/
int removeNodeAtLogicIndex(SequentialList * list, int i)
{
	if (list == NULL)
		error("The list can't be NULL.\n");

	int logicIndex = i;
	if (logicIndex < 1 || logicIndex > list->length)
		error ("Wrong position.");
	
	int storageIndex = logicIndex - 1;
	int storageIndexOfNextElement = storageIndex + 1;
	int storageIndexOfLastElement = list->length -1;
	
	int x = list->data[storageIndex];
	printf("removing the element %d at storage index: %d, logic index: %d ...\n", x, storageIndex, logicIndex);
	int count = 0;
	int j;
	for (j=storageIndexOfNextElement; j<=storageIndexOfLastElement; j++)
	{
		printf("moving %d from %d to %d ...\n", list->data[j], j, j-1);
		list->data[j-1]=list->data[j];
		count ++;
	}
		
	list->length--;
	printf("removed %d at %d.\n", x, storageIndex);
	printf("moved %d elements.\n", count);
	return x;
}

/*
 0 <= i <= n -1
*/
int removeNodeAtStorageIndex(SequentialList * list, int i)
{
	if (list == NULL)
		error("The list can't be NULL.\n");

	if (i < 0 || i > list->length - 1)
		error ("Wrong position.");
	
	int x = list->data[i];
	printf("removing the element %d at %d ...\n", x, i);
	int count = 0;
	int j;
	for (j=i+1; j<=list->length - 1; j++)
	{
		printf("moving %d from %d to %d ...\n", list->data[j], j, j-1);
		list->data[j-1]=list->data[j];
		count ++;
	}
		
	list->length--;
	printf("removed %d at %d.\n", x, i);
	printf("moved %d elements.\n", count);
	return x;
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
	SequentialList list = init(n);
	print(&list);
	reverse(&list);
	print(&list);
	//free(&list);
	printf("\n");
}

void test_insert()
{
	printf("Testing insert ...\n");
	SequentialList list = init(10);
	print(&list);
	insert(&list, 7, 777);
	print(&list);
	
	list = init(10);
	print(&list);
	insert(&list, 11, 1111);
	print(&list);
	
	list = init(10);
	print(&list);
	insert(&list, 1, 111);
	print(&list);
	
	list = init(100);
	print(&list);
	insert(&list, 77, 7777);
	print(&list);
	
	//free(&list);
	printf("\n");
}

void test_remove()
{
	printf("Testing delete ...\n");
	SequentialList list = init(10);
	print(&list);
	//removeNodeAtLogicIndex(&list, 7);
	removeNodeAtStorageIndex(&list, 7);
	print(&list);
	
	list = init(10);
	print(&list);
	//removeNodeAtLogicIndex(&list, 1);
	removeNodeAtStorageIndex(&list, 0);
	print(&list);
	
	list = init(10);
	print(&list);
	//removeNodeAtLogicIndex(&list, 10);
	removeNodeAtStorageIndex(&list, 9);
	print(&list);
	
	list = init(10);
	print(&list);
	//removeNodeAtLogicIndex(&list, 11);
	removeNodeAtStorageIndex(&list, 10);
	print(&list);
	
	//free(&list);
	printf("\n");
}

void removeSameFromA(SequentialList * a, SequentialList * b)
{
	int i = 0;
	int j = 0;
	int count = 0;
	
	while (i <= a->length -1 && j <= b->length -1)
	{
		if (a->data[i] == b->data[j])
		{
			removeNodeAtStorageIndex(a, i);
		}
		else if (a->data[i] > b->data[j])
		{
			j ++;		
		}
		else
		{
			i ++;
		}
		
		count ++;
	}
	
	printf("Loop times: %d\n", count);
}

void test_removeSameFromA()
{
	printf("Testing removeSameFromA ...\n");
	int array1[10] = {1, 3, 7, 11, 13, 17, 20, 23, 30, 41};	
	SequentialList a;
	a.length = 0;
	int i;
	for(i=0; i<10; i++)
	{
		a.data[i] =  array1[i];
		a.length ++;
	}
	print(&a);
	
	int array2[8] = {1, 2, 9, 13, 23, 41, 70, 80};
	SequentialList b;
	b.length = 0;
	int j;
	for(j=0; j<8; j++)
	{
		b.data[j] = array2[j];
		b.length ++;
	}
	print(&b);
	
	removeSameFromA(&a, b);
	print(&a);
	print(&b);
}

int main(void)
{
	test_removeSameFromA();
	//test_reverse(10);
	//test_reverse(11);
	
	//test_remove();
	
	return 0;
}
