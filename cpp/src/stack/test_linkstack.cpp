#include <iostream>
#include "LinkStack.h"

using namespace std;

int main()
{
    LinkStack<int> ls;
    cout << (ls.IsEmpty() ? "Empty." : "Not empty.") << endl;

    cout << "<END>" << endl;
    return 0;
}
