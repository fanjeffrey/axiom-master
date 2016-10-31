#include <iostream>
#include <algorithm>
#include <iterator>
#include "SeqList.h"

using namespace std;

template <class T>
void Display(LinearList<T> & list)
{
    cout << "Elements: ";
    T * data = list.Elements();
    copy(data, data + list.Length(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

int main()
{
    SeqList<int> isl;
    isl.Init();
    cout << "Created a sequencial list..." << endl;
    cout << "length = " << isl.Length() << endl;
    
    for(int i=1; i<=10; i++)
    {
        int val = i;
        cout << "Inserting " << val << " at " << isl.Length() << "..." << endl;
        isl.Insert(val, isl.Length() + 1);
        cout << "Inserted. length = " << isl.Length() << endl;
    }
    
    Display<int>(isl);
    
    isl.Delete(7);
    Display<int>(isl);
    
    isl.Insert(7, 3);
    Display<int>(isl);
    
    return 0;
}