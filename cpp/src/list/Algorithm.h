#if !defined(Algorithm_H)
#define Algorithm_H

#include <iostream>
#include "LinearList.h"

using namespace std;

template <class T>
void Union(LinearList<T> &la, LinearList<T> &lb)
{
    for (int i = 1; i <= lb.Count(); i++)
    {
        T data = lb.Get(i);
        if (la.Locate(data) == -1)
        {
            la.Insert(data, la.Count() + 1);
        }
    }
}

template <class T>
void Purge(LinearList<T> &la)
{
    int i = 1;

    while (i <= la.Count())
    {
        T data = la.Get(i);

        int j = i + 1;
        while (j <= la.Count())
        {
            if (data == la.Get(j))
            {
                la.Delete(j);
            }

            j++;
        }

        i++;
    }
}

template <class T>
void Display(LinearList<T> &list, ostream &output = cout)
{
    output << list.Count() << " element(s): ";
    for (int i = 1; i <= list.Count(); i++)
    {
        output << list.Get(i) << " ";
    }
    output << endl;
}

template <class T>
void Split(Linear)

#endif
