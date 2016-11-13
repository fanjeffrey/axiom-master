#if !defined(Tree_H)
#define Tree_H

#include <string>
#include <sstream>

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode
{
  public:
    TreeNode() : lchild(nullptr), rchild(nullptr) {}

  private:
    T data;
    TreeNode<T> *lchild;
    TreeNode<T> *rchild;

    //
    friend class Tree<T>;
};

template <typename T>
class Tree
{
  public:
    virtual string PreOrder();

  public:
    Tree() : root(nullptr) {}
    Tree(string &glist) { root = CreateFrom(glist); }

  protected:
    virtual TreeNode<T> *CreateFrom(string &);

  protected:
    TreeNode<T> *root;
};

template <typename T>
TreeNode<T> *Tree<T>::CreateFrom(string &glist)
{
    TreeNode<T> *arr[100];
    TreeNode<T> *p = nullptr, *r = nullptr;
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
            p = new TreeNode<T>;
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
string Tree<T>::PreOrder()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    TreeNode<T> *s[100];
    int top = -1;

    ostringstream os;
    os << "Nodes in pre-order:";

    TreeNode<T> *t = root;
    while (t)
    {
        os << " " << t->data;
        if (t->rchild)
        {
            top++;
            s[top] = t->rchild;
        }

        if (t->lchild)
        {
            t = t->lchild;
        }
        else
        {
            t = s[top];
            top--;
        }
    }

    return os.str();
}

#endif