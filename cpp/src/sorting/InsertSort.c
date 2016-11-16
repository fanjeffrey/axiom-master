#include <stdio.h>

#define MAXSIZE 100

typedef int KeyType;
typedef struct
{
    KeyType key;
} RecType;
typedef RecType SeqList[MAXSIZE + 1];

void InsertSort(SeqList R, int n)
{
    int i, j;
    for (int i = 2; i <= n; i++)
    {
        if (R[i].key < R[i - 1].key)
        {
            R[0] = R[i];
            for (j = i - 1; R[0].key < R[j].key; j--)
            {
                R[j + 1] = R[j];
            }

            R[j + 1] = R[0];
        }
    }
}

int main()
{
    return 0;
}