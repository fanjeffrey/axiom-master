#include <iostream>
#include <string>
#include "SeqStack.h"

using namespace std;

bool ParenthesisMatches(string s)
{
    SeqStack<char> ss;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            ss.Push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (ss.IsEmpty())
                return false;

            ss.Pop();
        }
    }

    return ss.IsEmpty();
}

bool SymmetryString(string s)
{
    SeqStack<char> ss;

    int h = s.size() / 2;
    for (int i = 0; i < h; i++)
    {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}

string Conversion(int n, int d)
{
    SeqStack<int> ss;
    ostringstream os;

    int r = 0;
    if (n == 0)
        ss.Push(r);

    while (n)
    {
        r = n % d;
        ss.Push(r);
        n = n / d;
    }

    while (!ss.IsEmpty())
    {
        os << ss.GetTop();
        ss.Pop();
    }

    return os.str();
}

int main()
{
    string s1 = "((1+2)*(3-4))";
    cout << ParenthesisMatches(s1) << endl;
    s1 = "((1+2)*(3-4)";
    cout << ParenthesisMatches(s1) << endl;
    s1 = "(1+2)*(3-4))";
    cout << ParenthesisMatches(s1) << endl;

    string s2 = "abcdcba";
    cout << SymmetryString(s2) << endl;
    s2 = "abcddcba";
    cout << SymmetryString(s2) << endl;
    s2 = "123";
    cout << SymmetryString(s2) << endl;

    //
    cout << "Conversion(0, 2) = " << Conversion(0, 2) << endl;
    cout << "Conversion(1, 2) = " << Conversion(1, 2) << endl;
    cout << "Conversion(2, 2) = " << Conversion(2, 2) << endl;
    cout << "Conversion(3, 2) = " << Conversion(3, 2) << endl;
    cout << "Conversion(4, 2) = " << Conversion(4, 2) << endl;
    cout << "Conversion(8, 2) = " << Conversion(8, 2) << endl;
    cout << "Conversion(9, 2) = " << Conversion(9, 2) << endl;

    return 0;
}