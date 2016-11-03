#include <iostream>
#include "LinkList.h"

using namespace std;

template <class T>
void Display(LinkList<T> & list)
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
    LinkList<int> ll;
    cout << "Created a link list..." << endl;
    cout << "length = " << ll.Count() << endl;

    for(int i = 1; i <= 10; i++)
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
    Display<int>(ll);
    cout << "Deleting 3 ..." << endl;
    ll.Delete(3);
    Display<int>(ll);

    cout << "Inserting 0 at 1 ..." << endl;
    ll.Insert(0, 1);
    Display<int>(ll);
    cout << "Deleting 0 ..." << endl;
    ll.Delete(1);
    Display<int>(ll);

    cout << "Inserting 11 at 12 ..." << endl;
    ll.Insert(11, 11);
    Display<int>(ll);
    cout << "Deleting 11 ..." << endl;
    ll.Delete(11);
    Display<int>(ll);

    return 0;
}