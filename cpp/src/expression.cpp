#include <iostream>
#include <string>
#include "queue/SeqQueue.h"
#include "stack/SeqStack.h"

using namespace std;

int Priority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void ConvertToPostExp(string &str, SeqQueue<char> *q)
{
    SeqStack<char> s;
    char c = '#';
    s.Push(c);

    char t;

    for (int i = 0; i < str.size(); i++)
    {
        c = str[i];

        switch (c)
        {
        case ' ':
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            q->Enqueue(c);
            break;
        case '(':
            s.Push(c);
            break;
        case ')':
        case '#':
            do
            {
                t = s.GetTop();
                //cout << "t is " << t << endl;
                s.Pop();
                if (t != '(' && t != '#')
                {
                    q->Enqueue(t);
                }
            } while (t != '(' && !s.IsEmpty());
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (Priority(c) <= Priority(s.GetTop()))
            {
                t = s.GetTop();
                q->Enqueue(t);
                s.Pop();
            }
            s.Push(c);
            break;
        }

        //cout << "handling " << c << " at " << i << endl;
        //cout << "stack: " << s.ToString() << endl;
        //cout << "queue: " << q->ToString() << endl;
    }
}

int Evaluate(SeqQueue<char> *q)
{
    SeqStack<int> s;
    char c;
    int x, y, r, d;
    while (!q->IsEmpty())
    {
        c = q->GetFront();

        if (c >= '0' && c <= '9')
        {
            d = c - '0';
            s.Push(d);
        }
        else
        {
            //cout << "before: " << s.ToString() << endl;
            y = s.GetTop(); // y is the right operand
            s.Pop();
            x = s.GetTop();
            s.Pop();
            switch (c)
            {
            case '+':
                r = x + y;
                break;
            case '-':
                r = x - y;
                break;
            case '*':
                r = x * y;
                break;
            case '/':
                r = x / y;
                break;
            }
            s.Push(r);
            //cout << "after: " << s.ToString() << endl;
        }

        q->Dequeue();
    }

    return s.GetTop();
}

int main()
{
    SeqQueue<char> q;
    string s1 = "4+2*3#";
    ConvertToPostExp(s1, &q);
    cout << q.ToString() << endl;
    cout << " = " << Evaluate(&q) << endl;

    string s2 = "9-(2+4*7)/5+3#";
    SeqQueue<char> q2;
    ConvertToPostExp(s2, &q2);
    cout << q2.ToString() << endl;
    cout << " = " << Evaluate(&q2) << endl;

    string s3 = "9-((2+4)*7)/5+3#";
    SeqQueue<char> q3;
    ConvertToPostExp(s3, &q3);
    cout << q3.ToString() << endl;
    cout << " = " << Evaluate(&q3) << endl;

    return 0;
}