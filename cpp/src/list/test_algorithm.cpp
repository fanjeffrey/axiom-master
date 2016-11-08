#include <iostream>
#include "SeqList.h"
#include "LinkList.h"
#include "Algorithm.h"

using namespace std;

int main()
{
    LinkList<int> lla;
    for (int i = 1; i <= 10; i++)
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
    for (int i = 1; i <= 10; i++)
    {
        int val = i * 3;
        llb.Insert(val, llb.Count() + 1);
        cout << val << " inserted. length = " << llb.Count() << endl;
    }
    Display(llb);

    cout << "Subtract list B from list A ..." << endl;
    Subtract(lla, llb);
    Display(lla);

    cout << "Union list A and list B ..." << endl;
    Union(lla, llb);
    Display(lla);

    //
    cout << "\n----------------------\n";

    //
    SeqList<int> sla;
    for (int i = 1; i <= 10; i++)
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
    for (int i = 1; i <= 10; i++)
    {
        int val = i * 3;
        slb.Insert(val, slb.Count() + 1);
        cout << val << " inserted. length = " << slb.Count() << endl;
    }
    Display(slb);

    cout << "Subtract list B from list A ..." << endl;
    Subtract(sla, slb);
    Display(sla);

    cout << "Union list A and list B ..." << endl;
    Union(sla, slb);
    Display(sla);

    return 0;
}