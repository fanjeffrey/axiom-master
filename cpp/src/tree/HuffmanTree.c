#include <stdio.h>
#include <limits.h>
#include <string.h>

#define n 4
#define m 2 * n - 1

typedef struct
{
    int weight;
    int lchild, rchild, parent;
} HTNode;

typedef HTNode HuffmanTree[m + 1];

void select(HuffmanTree tree, int k, int *minIndex1, int *minIndex2)
{
    int minValue = INT_MAX;

    int i;
    for (i = 1; i <= k; i++)
    {
        if (tree[i].weight <= minValue && tree[i].parent == 0)
        {
            minValue = tree[i].weight;
            *minIndex1 = i;
        }
    }

    minValue = INT_MAX;
    for (i = 1; i <= k; i++)
    {
        if (tree[i].weight <= minValue && tree[i].parent == 0 && i != *minIndex1)
        {
            minValue = tree[i].weight;
            *minIndex2 = i;
        }
    }
}

void constructHuffmanTree(HuffmanTree ht)
{
    int minIndex1, minIndex2;
    int i;

    // init the Huffman tree
    for (i = 1; i <= m; i++)
    {
        ht[i].weight = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
        ht[i].parent = 0;
    }

    // input weight data
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &ht[i].weight);
    }

    for (i = n + 1; i <= m; i++)
    {
        select(ht, i - 1, &minIndex1, &minIndex2);
        printf("minIndex1 = %d, minIndex2 = %d\n", minIndex1, minIndex2);

        ht[i].weight = ht[minIndex1].weight + ht[minIndex2].weight;
        ht[i].lchild = minIndex1;
        ht[i].rchild = minIndex2;
        ht[minIndex1].parent = i;
        ht[minIndex2].parent = i;
    }
}

void printHuffmanTree(HuffmanTree tree)
{
    HTNode t;
    int i;
    for (i = 1; i <= m; i++)
    {
        t = tree[i];
        printf("%2d = %d\tP=%d, L=%d, R=%d\n", i, t.weight, t.parent, t.lchild, t.rchild);
    }
}

typedef struct HuffmanCodeNode
{
    int key;
    char bits[n + 1];
    int len;
} HCNode;

typedef HCNode HuffmanCode[n + 1];

void getHuffmanCode(HuffmanTree ht, HuffmanCode hc)
{
    char cd[n + 1];
    cd[n] = '\0';
    int child, parent;
    int start;
    int i;
    for (i = 1; i <= n; i++)
    {
        start = n;
        child = i;
        while ((parent = ht[child].parent) > 0)
        {
            cd[--start] = (ht[parent].lchild == child) ? '0' : '1';
            child = parent;
        }

        strcpy(hc[i].bits, &cd[start]);
        hc[i].len = n - start;
        hc[i].key = ht[i].weight;
    }
}

void printHuffmanCode(HuffmanCode hc)
{
    HCNode c;
    int i;
    for (i = 1; i <= n; i++)
    {
        c = hc[i];
        printf("%2d = %d\t len=%d, bits=%s\n", i, c.key, c.len, c.bits);
    }
}

int main()
{
    HuffmanTree tree;
    constructHuffmanTree(tree);
    printHuffmanTree(tree);
    HuffmanCode code;
    getHuffmanCode(tree, code);
    printHuffmanCode(code);

    return 0;
}