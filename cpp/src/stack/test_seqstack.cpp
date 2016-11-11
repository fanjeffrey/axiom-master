#include <iostream>
#include "SeqStack.h"

using namespace std;

int main()
{
    SeqStack<int> ss;
    cout << ss.ToString() << endl;

    int e;
    while (cin >> e)
    {
        ss.Push(e);
    }
    cout << ss.ToString() << endl;

    while (!ss.IsEmpty())
    {
        cout << "Top is " << ss.GetTop() << endl;
        ss.Pop();
        cout << ss.ToString() << endl;
    }

    //
    cout << "<End>" << endl;
    return 0;
}