#include <iostream>
#include "SeqList.h"
#include "LinkList.h"

using namespace std;

template <class T>
void Union(LinearList<T> & la, LinearList<T> & lb)
{
    for(int i = 1; i <= lb.Count(); i++)
    {
        T data = lb.Get(i);
        if (la.Locate(data) == -1)
        {
            la.Insert(data, la.Count() + 1);
        }
    }
}

template <class T>
void Purge(LinearList<T> & la)
{
    int i = 1;

    while(i <= la.Count())
    {
        T data = la.Get(i);

        int j = i + 1;
        while (j <= la.Count())
        {
            if (data == la.Get(j))
            {
                la.Delete(j);
            }

            j ++;
        }

        i ++;
    }
}

template <class T>
void Display(LinearList<T> & list)
{    
    cout << list.Count() << " element(s): ";
    for(int i=1; i<=list.Count(); i++)
    {
        cout << list.Get(i) << " ";
    }
    cout << endl;
}

int main()
{
    LinkList<int> lla;
    for(int i=1; i<=10; i++)
    {
        int val = i * 2;
        lla.Insert(val, lla.Count() + 1);
        cout << val << " inserted. length = " << lla.Count() << endl;
    }
    lla.Insert(10, 10);
    lla.Insert(2, 8);
    lla.Insert(4, 6);
    lla.Insert(2, 2);
    Display(lla);

    cout << "Remove duplicated elements ..." << endl;
    Purge(lla);
    Display(lla);

    SeqList<int> llb;
    for(int i=1; i<=10; i++)
    {
        int val = i * 3;
        llb.Insert(val, llb.Count() + 1);
        cout << val << " inserted. length = " << llb.Count() << endl;
    }    
    Display(llb);

    cout << "Union list A and list B ..." << endl;
    Union(lla, llb);
    Display(lla);

    //
    SeqList<int> sla;
    for(int i=1; i<=10; i++)
    {
        int val = i * 2;
        sla.Insert(val, sla.Count() + 1);
        cout << val << " inserted. length = " << sla.Count() << endl;
    }
    sla.Insert(10, 10);
    sla.Insert(2, 8);
    sla.Insert(4, 6);
    sla.Insert(2, 2);
    Display(sla);

    cout << "Remove duplicated elements ..." << endl;
    Purge(sla);
    Display(sla);

    SeqList<int> slb;
    for(int i=1; i<=10; i++)
    {
        int val = i * 3;
        slb.Insert(val, slb.Count() + 1);
        cout << val << " inserted. length = " << slb.Count() << endl;
    }    
    Display(slb);

    cout << "Union list A and list B ..." << endl;
    Union(sla, slb);
    Display(sla);

    return 0;
}