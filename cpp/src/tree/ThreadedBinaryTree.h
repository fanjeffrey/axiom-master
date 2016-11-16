#if !defined(ThreadedBinaryTree_H)
#define ThreadedBinaryTree_H

#include <iostream>

using namespace std;

template <typename T>
class ThreadedBinaryTree;

template <typename T>
class ThreadedBinaryTreeNode
{
  public:
    ThreadedBinaryTreeNode() : lchild(nullptr), ltag(-1), rchild(nullptr), rtag(-1) {}

  private:
    T data;
    ThreadedBinaryTreeNode<T> *lchild;
    int ltag;
    ThreadedBinaryTreeNode<T> *rchild;
    int rtag;

    //
    friend class ThreadedBinaryTree<T>;
};

template <typename T>
class ThreadedBinaryTree
{
  public:
    virtual ThreadedBinaryTreeNode<T> *InOrderPrevious(ThreadedBinaryTreeNode<T> *);
    virtual ThreadedBinaryTreeNode<T> *InOrderNext(ThreadedBinaryTreeNode<T> *);
    virtual void InOrderTraverse(ostream &os = cout);
    virtual void ReverseInOrderTraverse(ostream &os = cout);

  public:
    ThreadedBinaryTree(string &glist);

  protected:
    virtual ThreadedBinaryTreeNode<T> *CreateFromGList(string &glist);
    virtual void InOrderThread(ThreadedBinaryTreeNode<T> *);

  protected:
    ThreadedBinaryTreeNode<T> *root;
};

template <typename T>
ThreadedBinaryTree<T>::ThreadedBinaryTree(string &glist)
{
    root = CreateFromGList(glist);
    InOrderThread(root);
}

template <typename T>
ThreadedBinaryTreeNode<T> *ThreadedBinaryTree<T>::CreateFromGList(string &glist)
{
    ThreadedBinaryTreeNode<T> *arr[100];
    ThreadedBinaryTreeNode<T> *p = nullptr, *r = nullptr;
    int top = -1, k, j = 0;
    char ch;

    for (int i = 0; i < glist.size(); i++)
    {
        ch = glist[i];
        switch (ch)
        {
        case '(':
            top++;
            arr[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = new ThreadedBinaryTreeNode<T>;
            p->data = ch;

            if (r == nullptr)
            {
                r = p;
            }
            else
            {
                switch (k)
                {
                case 1:
                    arr[top]->lchild = p;
                    break;
                case 2:
                    arr[top]->rchild = p;
                    break;
                }
            }
        }
    }

    return r;
}

template <typename T>
void ThreadedBinaryTree<T>::InOrderThread(ThreadedBinaryTreeNode<T> *n)
{
    static ThreadedBinaryTreeNode<T> *pre = nullptr;
    if (n)
    {
        InOrderThread(n->lchild);

        n->ltag = n->lchild ? 0 : 1;
        n->rtag = n->rchild ? 0 : 1;

        if (pre)
        {
            if (pre->rtag == 1)
                pre->rchild = n;
            if (n->ltag == 1)
                n->lchild = pre;
        }

        pre = n;

        InOrderThread(n->rchild);
    }
}

template <typename T>
ThreadedBinaryTreeNode<T> *ThreadedBinaryTree<T>::InOrderNext(ThreadedBinaryTreeNode<T> *n)
{
    if (!n)
        return nullptr;

    if (n->rtag == 1)
    {
        return n->rchild;
    }
    else
    {
        ThreadedBinaryTreeNode<T> *t = n->rchild;
        while (t->ltag == 0)
            t = t->lchild;

        return t;
    }
}

template <typename T>
ThreadedBinaryTreeNode<T> *ThreadedBinaryTree<T>::InOrderPrevious(ThreadedBinaryTreeNode<T> *n)
{
    if (!n)
        return nullptr;

    if (n->ltag == 1)
    {
        return n->lchild;
    }
    else
    {
        ThreadedBinaryTreeNode<T> *t = n->lchild;
        while (t->rtag == 0)
            t = t->rchild;

        return t;
    }
}

template <typename T>
void ThreadedBinaryTree<T>::InOrderTraverse(ostream &os)
{
    if (root)
    {
        ThreadedBinaryTreeNode<T> *t = root;
        while (t->ltag == 0)
        {
            t = t->lchild;
        }

        os << "Nodes in in-order threaded:";
        do
        {
            os << " " << t->data;
        } while (t = InOrderNext(t));

        cout << endl;
    }
    else
    {
        os << "The tree is empty." << endl;
    }
}

template <typename T>
void ThreadedBinaryTree<T>::ReverseInOrderTraverse(ostream &os)
{
    if (root)
    {
        ThreadedBinaryTreeNode<T> *t = root;
        while (t->rtag == 0)
        {
            t = t->rchild;
        }

        os << "Reversing nodes in in-order threaded:";
        do
        {
            os << " " << t->data;
        } while (t = InOrderPrevious(t));

        cout << endl;
    }
    else
    {
        os << "The tree is empty." << endl;
    }
}

#endif