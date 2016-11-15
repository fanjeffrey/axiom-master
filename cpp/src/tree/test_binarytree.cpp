#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    /*
    BinaryTree<char> t0;
    cout << ": " << endl
         << t0.PreOrder() << endl         
         << t0.InOrder() << endl;
    */

    //
    string glist1 = "(A(B,C))";
    BinaryTree<char> t1(glist1);
    cout << glist1 << ": " << endl
         << t1.PreOrder() << endl
         << t1.PreOrderWithArray() << endl
         << t1.PreOrderWithStack() << endl;

    //
    string glist2 = "(A(B(D,E),C(,F)))";
    BinaryTree<char> t2(glist2);
    cout << glist2 << ": " << endl
         << t2.PreOrder() << endl
         << t2.PreOrderWithArray() << endl
         << t2.PreOrderWithArray() << endl;

    //
    BinaryTree<char> t3(glist2);
    cout << glist2 << ": " << endl
         << t3.InOrder() << endl
         << t3.InOrderWithArray() << endl
         << t3.InOrderWithStack() << endl;

    return 0;
}
