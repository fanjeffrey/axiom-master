#include <iostream>
#include <algorithm>
#include <iterator>
#include "SeqList.h"

using namespace std;

template <class T>
void Display(SeqList<T> & list)
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
    try{
        SeqList<int> isl;
        cout << "Created a sequencial list..." << endl;
        cout << "length = " << isl.Count() << endl;
        
        for(int i=1; i<=11; i++)
        {
            int val = i * 2;
            isl.Insert(val, isl.Count() + 1);
            cout << val << " inserted. length = " << isl.Count() << endl;
        }    
        Display(isl);

        cout << "Reversing ..." << endl;
        isl.Reverse();
        Display(isl);

        cout << "Reversing again ..." << endl;
        isl.Reverse();
        Display(isl);
        
        int idx = 1;
        int val = isl.Get(idx);
        cout << "Get(" << idx << ") = " << val << "." << endl;
        idx = isl.Locate(val);
        cout << "Locate(" << val << ") = " << idx << "." << endl;
        if (idx == isl.Locate(val))
        {
            cout << val << " is at " << idx << "." << endl;
        }

        idx = 7;
        val = isl.Get(idx);
        if (idx == isl.Locate(val))
        {
            cout << val << " is at " << idx << "." << endl;
        }

        idx = isl.Count();
        val = isl.Get(idx);
        if (idx == isl.Locate(val))
        {
            cout << val << " is at " << idx << "." << endl;
        }

        val = 9999999;
        if (-1 == isl.Locate(val))
        {
            cout << "Unable to locate " << val << "." << endl;
        }

        cout << "Inserting 3 at 3 ..." << endl;
        isl.Insert(3, 3);
        Display(isl);
        cout << "Deleting 3 ..." << endl;
        isl.Delete(3);
        Display(isl);

        cout << "Inserting 0 at 1 ..." << endl;
        isl.Insert(0, 1);
        Display(isl);
        cout << "Deleting 0 ..." << endl;
        isl.Delete(1);
        Display(isl);

        cout << "Inserting 11 at 11 ..." << endl;
        isl.Insert(11, 11);
        Display(isl);
        cout << "Deleting 11 ..." << endl;
        isl.Delete(11);
        Display(isl);
    }
    catch(const char* ex)
    {
        cout << ex << endl;
    }
    
    return 0;
}