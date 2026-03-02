#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    list<int> lst;

public:
    // push -> insert at back
    void push(int x)
    {
        lst.push_back(x);
    }

    // pop -> remove from front
    void pop()
    {
        if (lst.empty())
        {
            cout << "Queue is empty\n";
            return;
        }
        lst.pop_front();
    }

    // front -> return first element
    int front()
    {
        if (lst.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return lst.front();
    }

    // size -> return number of elements
    int size()
    {
        return lst.size();
    }

    // empty -> check if queue is empty
    bool empty()
    {
        return lst.empty();
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl; // 10
    cout << q.size() << endl;  // 3

    q.pop();

    cout << q.front() << endl; // 20
    cout << q.empty() << endl; // 0 (false)

    return 0;
}