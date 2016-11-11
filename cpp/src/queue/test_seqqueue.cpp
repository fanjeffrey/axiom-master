#include <iostream>
#include <sstream>
#include "SeqQueue.h"

using namespace std;

int main()
{
    SeqQueue<int> sq;
    cout << sq.ToString() << endl;

    string input;
    int e;
    while (getline(cin, input) && input != "\0")
    {
        if (sq.IsFull())
        {
            sq.Dequeue();
        }

        stringstream(input) >> e;
        sq.Enqueue(e);
        cout << endl
             << sq.ToString() << endl;

        input = "";
    }
    cout << sq.ToString() << endl;

    cout << "The front is: " << sq.GetFront() << endl;

    return 0;
}