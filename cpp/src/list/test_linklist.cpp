#include <iostream>
#include "LinkList.h"

using namespace std;

template <class T>
void Display(LinkList<T> &list)
{
    cout << list.Count() << " element(s): ";
    for (int i = 1; i <= list.Count(); i++)
    {
        cout << list.Get(i) << " ";
    }
    cout << endl;
}

int main()
{
    LinkList<int> ll;
    cout << "Created a link list..." << endl;
    cout << "length = " << ll.Count() << endl;

    for (int i = 1; i <= 10; i++)
    {
        int val = i * 2;
        ll.Insert(val, ll.Count() + 1);
        cout << val << " inserted. length = " << ll.Count() << endl;
    }
    Display(ll);

    cout << "Reversing ..." << endl;
    ll.Reverse();
    Display(ll);

    cout << "Reversing again ..." << endl;
    ll.Reverse();
    Display(ll);

    int idx = 1;
    int val = ll.Get(idx);
    cout << "Get(" << idx << ") = " << val << "." << endl;
    idx = ll.Locate(val);
    cout << "Locate(" << val << ") = " << idx << "." << endl;
    if (idx == ll.Locate(val))
    {
        cout << val << " is at " << idx << "." << endl;
    }

    idx = 7;
    val = ll.Get(idx);
    if (idx == ll.Locate(val))
    {
        cout << val << " is at " << idx << "." << endl;
    }

    idx = ll.Count();
    val = ll.Get(idx);
    if (idx == ll.Locate(val))
    {
        cout << val << " is at " << idx << "." << endl;
    }

    val = 9999999;
    if (-1 == ll.Locate(val))
    {
        cout << "Unable to locate " << val << "." << endl;
    }

    cout << "Inserting 3 at 3 ..." << endl;
    ll.Insert(3, 3);
    Display(ll);
    cout << "Deleting 3 ..." << endl;
    ll.Delete(3);
    Display(ll);

    cout << "Inserting 0 at 1 ..." << endl;
    ll.Insert(0, 1);
    Display(ll);
    cout << "Deleting 0 ..." << endl;
    ll.Delete(1);
    Display(ll);

    cout << "Inserting 11 at 12 ..." << endl;
    ll.Insert(11, 11);
    Display(ll);
    cout << "Deleting 11 ..." << endl;
    ll.Delete(11);
    Display(ll);
    try
    {
        cout << "call LinkList<int> lla = ll ..." << endl;
        LinkList<int> lla = ll;
        cout << "lla.length = " << lla.Count() << endl;

        cout << "call LinkList<int> llb(ll) ..." << endl;
        LinkList<int> llb(ll);
        cout << "llb.length = " << llb.Count() << endl;
        llb.Insert(77, 7);
        cout << "llb.length = " << llb.Count() << endl;

        cout << "call llb = lla ..." << endl;
        llb = lla;
        cout << "llb.length = " << llb.Count() << endl;
        cout << "lla.length = " << lla.Count() << endl;

        cout << "Splitting llb ..." << endl;
        llb.Insert(88, 8);
        cout << "llb.length = " << llb.Count() << endl;
        LinkList<int> llb2 = llb.Split();
        Display(llb);
        Display(llb2);

        cout << "Splitting llc ..." << endl;
        LinkList<int> llc = ll.Split();
        Display(ll);
        Display(llc);

        cout << "Sorting llc ..." << endl;
        llc.Insert(33, 6);
        llc.Insert(11, 1);
        llc.Insert(20, 2);
        llc.Insert(17, 3);
        llc.Insert(1, 6);
        Display(llc);
        llc.InsertSort();
        Display(llc);
    }
    catch (const char *&ex)
    {
        cout << "Error: " << ex << endl;
    }

    cout << "End." << endl;
    return 0;
}