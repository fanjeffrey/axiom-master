#include <iostream>
#include "BinaryTree.h"
#include "ThreadedBinaryTree.h"

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
    string glist2 = "(A(B(D(G,H),E),C(,F)))";
    BinaryTree<char> t2(glist2);
    cout << glist2 << ": " << endl
         << t2.PreOrder() << endl
         << t2.PreOrderWithArray() << endl
         << t2.PreOrderWithArray() << endl
         << t2.InOrder() << endl
         << t2.InOrderWithArray() << endl
         << t2.InOrderWithStack() << endl
         << t2.LevelOrder() << endl
         << t2.LevelOrderWithArray() << endl
         << "Depth: " << t2.GetDepth() << endl;

    cout << "Finding 'C'..., ";
    BinaryTreeNode<char> *c = t2.Find('C');
    if (c)
        cout << "Found " << c->GetData() << " @" << c << "!" << endl;
    else
        cout << "Not found!" << endl;
    cout << "Finding 'E'..., ";
    BinaryTreeNode<char> *e = t2.Find('E');
    if (e)
        cout << "Found " << e->GetData() << " @" << e << "!" << endl;
    else
        cout << "Not found!" << endl;

    cout << "A.Level = " << t2.GetLevel('A') << endl
         << "C.Level = " << t2.GetLevel('C') << endl
         << "E.Level = " << t2.GetLevel('E') << endl
         << "H.Level = " << t2.GetLevel('H') << endl;

    ThreadedBinaryTree<char> t3(glist2);
    cout << glist2 << ": " << endl
         << t2.InOrder() << endl;
    t3.InOrderTraverse();
    t3.ReverseInOrderTraverse();

    return 0;
}
