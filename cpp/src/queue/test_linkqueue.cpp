#include <iostream>
#include <sstream>
#include "LinkQueue.h"

using namespace std;

int main()
{
    LinkQueue<int> lq;
    cout << lq.ToString() << endl;

    int i = 111;
    lq.Enqueue(i);
    cout << lq.ToString() << endl;

    string input;
    int e;
    while (getline(cin, input) && input != "\0")
    {
        stringstream(input) >> e;
        lq.Enqueue(e);
        cout << lq.ToString() << endl;
        input = "";
    }
    cout << lq.ToString() << endl;
    cout << "The front is " << lq.GetFront() << endl;

    cout << "Dequeuing ..." << endl;
    lq.Dequeue();
    cout << "The front is " << lq.GetFront() << endl;
    cout << lq.ToString() << endl;

    return 0;
}