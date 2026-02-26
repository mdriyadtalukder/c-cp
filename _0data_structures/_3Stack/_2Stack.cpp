// using list(linkedlist)
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    list<int> v;

public:
    void push(int val)
    {

        v.push_front(val);
    }
    void pop()
    {
        v.pop_front();
    }
    int top()
    {
        return v.front();
    }
    bool empty()
    {
        return v.size() == 0;
    }
    int size()
    {
        return v.size();
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(12);
    s.push(13);
    s.push(14);
    s.pop();
    cout << s.top();
    cout << s.size();
    return 0;
}