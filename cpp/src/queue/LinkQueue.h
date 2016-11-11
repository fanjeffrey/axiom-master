#if !defined(LinkQueue_H)
#define LinkQueue_H

#include <sstream>
#include "Queue.h"

using namespace std;

template <typename T>
class LinkQueue;

template <typename T>
class QueueNode
{
  public:
    QueueNode() { next = NULL; }

  private:
    T data;
    QueueNode<T> *next;

    //
    friend class LinkQueue<T>;
};

template <typename T>
class LinkQueue : public Queue<T>
{
  public:
    virtual void Enqueue(T &);
    virtual void Dequeue();
    virtual T &GetFront();
    virtual bool IsEmpty() { return rear->next == rear; }
    virtual bool IsFull() { return false; }
    virtual string ToString();

  public:
    LinkQueue();
    virtual ~LinkQueue();

  protected:
    QueueNode<T> *rear;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
    rear = new QueueNode<T>;
    rear->next = rear;
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
    QueueNode<T> *t;

    while (rear->next != rear)
    {
        t = rear->next;
        rear->next = t->next;
        delete t;
    }

    delete rear;
}

template <typename T>
void LinkQueue<T>::Enqueue(T &e)
{
    if (IsFull())
    {
        throw "Error: the queue is full.";
    }

    QueueNode<T> *n = new QueueNode<T>;
    n->data = e;
    n->next = rear->next;
    rear->next = n;
    rear = n;
}

template <typename T>
void LinkQueue<T>::Dequeue()
{
    if (IsEmpty())
    {
        throw "Error: the queue is empty.";
    }

    QueueNode<T> *t = rear->next;
    rear->next = t->next;
    delete t;
}

template <typename T>
T &LinkQueue<T>::GetFront()
{
    if (IsEmpty())
    {
        throw "Error: the queue is empty.";
    }

    return rear->next->next->data;
}

template <typename T>
string LinkQueue<T>::ToString()
{
    ostringstream os;

    if (IsEmpty())
    {
        os << "0 elements." << endl;
    }
    else
    {
        os << "Elements:";
        QueueNode<T> *t = rear->next->next;
        while (t != rear->next)
        {
            os << " " << t->data;
            t = t->next;
        }
    }

    return os.str();
}

#endif