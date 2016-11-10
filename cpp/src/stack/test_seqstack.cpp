#include <iostream>
#include "SeqStack.h"

using namespace std;

int main()
{
    SeqStack<int> ss;

    cout << (ss.IsEmpty() ? "Empty" : "Not Empty") << endl;
    
    cout << "<End>" << endl;
    return 0;
}