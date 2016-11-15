#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<char> t0;
    cout << ": " << endl
         << t0.PreOrder() << endl         
         << t0.InOrder() << endl;

    //
    string glist1 = "(A(B,C))";
    BinaryTree<char> t1(glist1);
    cout << glist1 << ": " << endl
         << t1.PreOrder() << endl;
    BinaryTree<char> t1a(glist1);
    cout << glist1 << ": " << endl
         << t1a.PreOrderWithArray() << endl;
    BinaryTree<char> t1s(glist1);
    cout << glist1 << ": " << endl
         << t1s.PreOrderWithStack() << endl;

    //
    string glist2 = "(A(B(D,E),C(,F)))";
    BinaryTree<char> t2(glist2);
    cout << glist2 << ": " << endl
         << t2.PreOrder() << endl;

    BinaryTree<char> t2a(glist2);
    cout << glist2 << ": " << endl
         << t2a.PreOrderWithArray() << endl;

    BinaryTree<char> t2s(glist2);
    cout << glist2 << ": " << endl
         << t2s.PreOrderWithArray() << endl;

    //
    BinaryTree<char> t3(glist2);
    cout << glist2 << ": " << endl
         << t3.InOrder() << endl;

    return 0;
}
