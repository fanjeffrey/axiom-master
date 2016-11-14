#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    string glist1 = "(A(B,C))";
    Tree<char> t1(glist1);
    cout << glist1 << ": " << endl << t1.PreOrder() << endl;

    string glist2 = "(A(B(D,E),C(,F)))";
    Tree<char> t2(glist2);
    cout << glist2 << ": " << endl << t2.PreOrder() << endl;

    return 0;
}
