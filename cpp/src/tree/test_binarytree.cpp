#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<char> t0;
    cout << ": " << endl
         << t0.PreOrder() << endl;

    string glist1 = "(A(B,C))";
    BinaryTree<char> t1(glist1);
    cout << glist1 << ": " << endl
         << t1.PreOrder() << endl;

    string glist1a = "(A(B,C))";
    BinaryTree<char> t1a(glist1a);
    cout << glist1a << ": " << endl
         << t1a.PreOrderWithArray() << endl;

    string glist1s = "(A(B,C))";
    BinaryTree<char> t1s(glist1s);
    cout << glist1s << ": " << endl
         << t1s.PreOrderWithStack() << endl;

    string glist2 = "(A(B(D,E),C(,F)))";
    BinaryTree<char> t2(glist2);
    cout << glist2 << ": " << endl
         << t2.PreOrder() << endl;

    string glist2a = "(A(B(D,E),C(,F)))";
    BinaryTree<char> t2a(glist2a);
    cout << glist2a << ": " << endl
         << t2a.PreOrderWithArray() << endl;

    string glist2s = "(A(B(D,E),C(,F)))";
    BinaryTree<char> t2s(glist2s);
    cout << glist2s << ": " << endl
         << t2s.PreOrderWithArray() << endl;

    return 0;
}
