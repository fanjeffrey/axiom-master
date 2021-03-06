#if !defined(BinaryTree_H)
#define BinaryTree_H

#include <string>
#include <sstream>
#include "../stack/SeqStack.h"
#include "../queue/SeqQueue.h"

using namespace std;

template <typename T>
class BinaryTree;

template <typename T>
class BinaryTreeNode
{
  public:
    BinaryTreeNode() : lchild(nullptr), rchild(nullptr) {}
    T GetData() { return data; }

  private:
    T data;
    BinaryTreeNode<T> *lchild;
    BinaryTreeNode<T> *rchild;

    //
    friend class BinaryTree<T>;
};

template <typename T>
class BinaryTree
{
  public:
    virtual string PreOrder();
    virtual string PreOrderWithArray();
    virtual string PreOrderWithStack();
    virtual string InOrder();
    virtual string InOrderWithArray();
    virtual string InOrderWithStack();
    virtual string LevelOrder();
    virtual string LevelOrderWithArray();
    virtual int GetDepth();
    virtual BinaryTreeNode<T> *Find(const T &);
    virtual int GetLevel(const T &);

  public:
    BinaryTree() { root = CreateFromConsole(); }
    BinaryTree(BinaryTreeNode<T> *r) : root(r){};
    BinaryTree(string &glist) { root = CreateFromGList(glist); }

  protected:
    virtual BinaryTreeNode<T> *CreateFromConsole();
    virtual BinaryTreeNode<T> *CreateFromGList(string &);
    virtual void PrintPreOrder(BinaryTreeNode<T> *, ostringstream &);
    virtual void PrintInOrder(BinaryTreeNode<T> *, ostringstream &);
    virtual int GetDepth(BinaryTreeNode<T> *);
    virtual BinaryTreeNode<T> *Find(BinaryTreeNode<T> *, const T &);
    virtual int GetLevel(BinaryTreeNode<T> *, const T &, int);

  protected:
    BinaryTreeNode<T> *root;
};

// Creates from console input, like "ABC@D@E#".
// @ means a NULL node.
// # means end.
template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::CreateFromConsole()
{
    BinaryTreeNode<T> *root, *n;
    root = nullptr;

    BinaryTreeNode<T> *queue[100];
    int front = 1, rear = 0;

    char ch = getchar();
    while (ch != '#')
    {
        n = nullptr;

        if (ch != '@')
        {
            n = new BinaryTreeNode<T>;
            n->data = T(ch);
            n->lchild = n->rchild = nullptr;
        }

        queue[++rear] = n;

        if (rear == 1)
        {
            root = n;
        }
        else
        {
            if (n && queue[front])
            {
                if (rear % 2 == 0)
                {
                    queue[front]->lchild = n;
                }
                else
                {
                    queue[front]->rchild = n;
                }
            }

            if (rear % 2 != 0)
            {
                front++;
            }
        }

        ch = getchar();
    }

    return root;
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::CreateFromGList(string &glist)
{
    BinaryTreeNode<T> *arr[100];
    BinaryTreeNode<T> *p = nullptr, *r = nullptr;
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
            p = new BinaryTreeNode<T>;
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

// Pre-order with recursion
template <typename T>
string BinaryTree<T>::PreOrder()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in pre-order with recursion :";

    PrintPreOrder(root, os);

    return os.str();
}

template <typename T>
void BinaryTree<T>::PrintPreOrder(BinaryTreeNode<T> *n, ostringstream &os)
{
    if (n)
    {
        os << " " << n->data;
        PrintPreOrder(n->lchild, os);
        PrintPreOrder(n->rchild, os);
    }
}

// Pre-order with array
template <typename T>
string BinaryTree<T>::PreOrderWithArray()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in pre-order with array:";

    int top = -1;
    BinaryTreeNode<T> *stack[100];
    stack[++top] = root;
    BinaryTreeNode<T> *t;
    while (top > -1)
    {
        t = stack[top--];
        if (t)
        {
            os << " " << t->data;
            stack[++top] = t->rchild;
            stack[++top] = t->lchild;
        }
    }

    return os.str();
}

// Pre-order with stack
template <typename T>
string BinaryTree<T>::PreOrderWithStack()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in pre-order with stack:";

    SeqStack<BinaryTreeNode<T> *> stack;
    stack.Push(root);
    BinaryTreeNode<T> *t;
    while (!stack.IsEmpty())
    {
        t = stack.GetTop();
        stack.Pop();
        if (t)
        {
            os << " " << t->data;
            stack.Push(t->rchild);
            stack.Push(t->lchild);
        }
    }

    return os.str();
}

// In-order with recursion
template <typename T>
string BinaryTree<T>::InOrder()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in in-order with recursion:";

    PrintInOrder(root, os);

    return os.str();
}

template <typename T>
void BinaryTree<T>::PrintInOrder(BinaryTreeNode<T> *n, ostringstream &os)
{
    if (n)
    {
        PrintInOrder(n->lchild, os);
        os << " " << n->data;
        PrintInOrder(n->rchild, os);
    }
}

// In-order with array
template <typename T>
string BinaryTree<T>::InOrderWithArray()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in pre-order with array:";

    int top = -1;
    BinaryTreeNode<T> *stack[100];
    stack[++top] = root;
    while (top > -1)
    {
        while (stack[top])
        {
            top++;
            stack[top] = stack[top - 1]->lchild;
        }

        top--;

        if (top > -1)
        {
            os << " " << stack[top]->data;
            stack[top] = stack[top]->rchild;
        }
    }

    return os.str();
}

// In-order with stack
template <typename T>
string BinaryTree<T>::InOrderWithStack()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in in-order with stack:";

    BinaryTreeNode<T> *t;
    SeqStack<BinaryTreeNode<T> *> stack;
    stack.Push(root);
    while (!stack.IsEmpty())
    {
        while (stack.GetTop())
        {
            stack.Push(stack.GetTop()->lchild);
        }

        stack.Pop();

        if (!stack.IsEmpty())
        {
            t = stack.GetTop();
            os << " " << t->data;

            stack.Pop();

            stack.Push(t->rchild);
        }
    }

    return os.str();
}

// Level-order traversal
template <typename T>
string BinaryTree<T>::LevelOrder()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in level-order:";
    os << " " << root->data;

    BinaryTreeNode<T> *t;
    SeqQueue<BinaryTreeNode<T> *> queue;
    queue.Enqueue(root);
    while (!queue.IsEmpty())
    {
        t = queue.GetFront();
        queue.Dequeue();

        if (t->lchild)
        {
            os << " " << t->lchild->data;
            queue.Enqueue(t->lchild);
        }

        if (t->rchild)
        {
            os << " " << t->rchild->data;
            queue.Enqueue(t->rchild);
        }
    }

    return os.str();
}

// Level-order traversal with array
template <typename T>
string BinaryTree<T>::LevelOrderWithArray()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in level-order:";
    os << " " << root->data;

    BinaryTreeNode<T> *t;
    int front = 0;
    int rear = 0;
    BinaryTreeNode<T> *queue[100];
    queue[rear++] = root;
    while (front != rear)
    {
        t = queue[front++];

        if (t->lchild)
        {
            os << " " << t->lchild->data;
            queue[rear++] = t->lchild;
        }

        if (t->rchild)
        {
            os << " " << t->rchild->data;
            queue[rear++] = t->rchild;
        }
    }

    return os.str();
}

//
template <typename T>
int BinaryTree<T>::GetDepth()
{
    return GetDepth(root);
}

template <typename T>
int BinaryTree<T>::GetDepth(BinaryTreeNode<T> *node)
{
    if (!node)
        return 0;

    int depthLeft = GetDepth(node->lchild);
    int depthRight = GetDepth(node->rchild);

    if (depthLeft > depthRight)
        return depthLeft + 1;
    else
        return depthRight + 1;
}

//
template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::Find(const T &t)
{
    return Find(root, t);
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::Find(BinaryTreeNode<T> *n, const T &t)
{
    BinaryTreeNode<T> *p;

    if (!n)
    {
        p = nullptr;
    }
    else if (n->data == t)
    {
        p = n;
    }
    else
    {
        p = Find(n->lchild, t);
        if (!p)
        {
            p = Find(n->rchild, t);
        }
    }

    return p;
}

//
template <typename T>
int BinaryTree<T>::GetLevel(const T &t)
{
    return GetLevel(root, t, 1);
}

template <typename T>
int BinaryTree<T>::GetLevel(BinaryTreeNode<T> *n, const T &t, int levelToSearch)
{
    static int level = 0;

    if (!n)
    {
        level = 0;
    }
    else if (n->data == t)
    {
        level = levelToSearch;
    }
    else
    {
        GetLevel(n->lchild, t, levelToSearch + 1); // go to the lchild at the next level
        if (level == 0)
        {
            GetLevel(n->rchild, t, levelToSearch + 1); // go to the lchild at the next level
        }
    }

    return level;
}

#endif