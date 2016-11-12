#if !defined(SeqQueue_H)
#define SeqQueue_H

#include <sstream>
#include "Queue.h"

#define QueueSize 1000

template <typename T>
class SeqQueue : public Queue<T>
{
  public:
    virtual void Enqueue(T &);
    virtual void Dequeue();
    virtual T &GetFront();
    virtual bool IsEmpty() { return front == rear; }
    virtual bool IsFull() { return (rear + 1) % QueueSize == front; }
    virtual string ToString();

  public:
    SeqQueue();

  protected:
    virtual int Count() { return rear >= front ? rear - front : rear + QueueSize - front; }

  protected:
    T elements[QueueSize];
    int front, rear;
};

template <typename T>
SeqQueue<T>::SeqQueue() : front(0), rear(0) {}

template <typename T>
void SeqQueue<T>::Enqueue(T &e)
{
    if (IsFull())
    {
        throw "Error: the queue is full.";
    }

    elements[rear] = e;
    rear = (rear + 1) % QueueSize;
}

template <typename T>
void SeqQueue<T>::Dequeue()
{
    if (IsEmpty())
    {
        throw "Error: the queue is empty.";
    }

    front = (front + 1) % QueueSize;
}

template <typename T>
T &SeqQueue<T>::GetFront()
{
    if (IsEmpty())
    {
        throw "Error: the queue is empty.";
    }

    return elements[front];
}

template <typename T>
string SeqQueue<T>::ToString()
{
    ostringstream os;

    if (IsEmpty())
    {
        os << Count() << " elements [front=" << front << ", rear= " << rear << "].";
    }
    else
    {
        os << Count() << " elements [front=" << front << ", rear= " << rear << "]:";
        for (int i = 0; i < Count(); i++)
        {
            os << " " << elements[((front + i) % QueueSize)];
        }
    }

    return os.str();
}

#endif