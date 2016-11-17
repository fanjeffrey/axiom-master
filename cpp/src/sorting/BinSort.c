#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT_OF_BINS 1000
#define MAX_COUNT_OF_ENTITIES 1000

typedef int KeyType;
typedef struct
{
    KeyType key;
    /*
    other fields go here;
    */
} EntityType;
typedef EntityType EntityList[MAX_COUNT_OF_ENTITIES];
typedef struct entitynode
{
    EntityType entity;
    struct entitynode *next;
} EntityNode;
typedef struct
{
    EntityNode *front;
    EntityNode *end;
} BinNode;
typedef BinNode Bins[MAX_COUNT_OF_BINS];
typedef BinNode *EntityQueue;

void InitQueue(EntityQueue q)
{
    q->front = NULL;
    q->end = NULL;
}

void EnQueue(EntityQueue q, EntityType entity)
{
    EntityNode *pnode = (EntityNode *)malloc(sizeof(EntityNode));
    pnode->entity = entity;
    pnode->next = NULL;

    printf("q = %p; q->end = %p; ", q, q->end);
    if (q && q->end)
    {
        printf("enqueue %d at end ... done.\n", pnode->entity.key);
        q->end->next = pnode;
        q->end = pnode;
    }
    else
    {
        printf("enqueue %d at front ... done.\n", pnode->entity.key);
        q->front = pnode;
        q->end = pnode;
    }
}

int IsQueueEmpty(EntityQueue q)
{
    return (q && q->front) ? 0 : 1;
}

void BinSort(EntityList entities, int countOfEntities, int countOfBins)
{
    Bins bins;
    int i;
    for (i = 0; i < countOfBins; i++)
    {
        InitQueue(&bins[i]);
    }
    printf("Init queue ... done.\n");

    //
    for (i = 0; i < countOfEntities; i++)
    {
        if (entities[i].key < countOfBins && entities[i].key >= 0)
        {
            EnQueue(&bins[entities[i].key], entities[i]);
            printf("Put the entity with key #%d in the bin #%d @%p ... done.\n",
                   entities[i].key,
                   entities[i].key,
                   bins + entities[i].key);
        }
        else
        {
            printf("!!!The entity key number(%d) exceeds the bounds[0 - %d] of the bins!!!\n",
                   entities[i].key,
                   countOfBins - 1);
            exit(1);
        }
    }
    printf("All entities enqueued.\n");

    //
    i = 0;
    while (IsQueueEmpty(&bins[i]))
        i++;
    printf("Found the first entity queue that is not empty at #%d !!!\n", i);

    //
    int head = i;
    int j = head;
    for (i = j + 1; i < countOfBins; i++)
    {
        if (!IsQueueEmpty(&bins[i]))
        {
            bins[j].end->next = bins[i].front;
            printf("Link the queue #%d to #%d ... done. \n", i, j);
            j = i;
        }
    }

    //
    printf("Print the sorted entities ... \n");
    EntityNode *p = bins[head].front;
    while (p)
    {
        printf("%d ", p->entity.key);
        p = p->next;
    }
    printf("\nDone.\n");
}

int main()
{
    EntityList entities;
    int countOfEntities = 10;
    int countOfBins = MAX_COUNT_OF_BINS;

    //
    printf("Please input %d numbers as entities' keys:\n", countOfEntities);
    int i;
    for (i = 0; i < countOfEntities; i++)
    {
        scanf("%d", &entities[i].key);
        if (entities[i].key >= countOfBins || entities[i].key < 0)
        {
            printf("!!!The entity key number(%d) exceeds the bounds[0 - %d] of the bins!!!\n",
                   entities[i].key,
                   countOfBins - 1);
            exit(1);
        }
    }

    printf("Before sorting...\n");
    for (i = 0; i < countOfEntities; i++)
    {
        printf("%d ", entities[i].key);
    }
    printf("\n");

    //
    printf("Start bin sorting...\n");
    BinSort(entities, countOfEntities, countOfBins);

    return 0;
}