#include <iostream>
#include "LinkStack.h"

using namespace std;

int main()
{
    LinkStack<int> ls;
    cout << ls.ToString() << endl;

    int e;
    while (cin >> e)
    {
        ls.Push(e);
    }
    cout << ls.ToString() << endl;

    while (!ls.IsEmpty())
    {
        cout << "Top is " << ls.GetTop() << ", popping..." << endl;
        ls.Pop();
        cout << ls.ToString() << endl;
    }

    cout << "<END>" << endl;
    return 0;
}
