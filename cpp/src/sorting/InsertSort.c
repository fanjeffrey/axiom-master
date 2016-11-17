#include <stdio.h>

#define MAXSIZE 100

typedef int KeyType;
typedef struct
{
    KeyType key;
    /*
    other fields go here;
    */
} EntityType;
typedef EntityType EntityList[MAXSIZE + 1];

void InsertSort(EntityList entities, int countOfEntities)
{
    int i, j;
    for (int i = 2; i <= countOfEntities; i++)
    {
        if (entities[i].key < entities[i - 1].key)
        {
            entities[0] = entities[i];
            for (j = i - 1; entities[0].key < entities[j].key; j--)
            {
                entities[j + 1] = entities[j];
            }

            entities[j + 1] = entities[0];
        }
    }
}

int main()
{
    EntityList entities;
    int countOfEntities = 10;
    int i;
    for (i = 1; i <= countOfEntities; i++)
    {
        scanf("%d", &entities[i].key);
    }

    printf("Before sorting...\n");
    for (i = 1; i <= countOfEntities; i++)
    {
        printf("%d ", entities[i].key);
    }
    printf("\n");

    //
    InsertSort(entities, countOfEntities);
    printf("After insert sorting...\n");
    for (i = 1; i <= countOfEntities; i++)
    {
        printf("%d ", entities[i].key);
    }
    printf("\n");

    return 0;
}