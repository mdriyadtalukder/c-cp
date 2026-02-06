#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic object is created..it wont delete
        // Node newNode(val);//static object is created..which will be remove after executing function
        if (head == NULL)
        {
            head = tail = newNode; // head null means no node is added in linkedlist.. so head and tail will point this only one 1st node.and will add.
        }
        else
        {
            newNode->next = head; // newnode,oldnode,oldnode2....newNode k dereference kore er value access kre tar next value k head assign krlm..
            head = newNode;
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode; // oldnode,oldnode2 (<--tail)..so next node will be newnode as tail....
            tail = newNode;
        }
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty!!";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty!!";
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position!!";
            return;
        }
        if (pos == 0)
        {
            push_front(val);
        }
        Node *temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next; // head->next=2nd elem
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next; // A=B
        temp->next = newNode;       // B=C
    }
    int search(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    void printAll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_back(4);
    // l.pop_front();
    // l.pop_back();
    l.insert(4, 0);
    l.printAll();
    cout << l.search(2);

    // for (int val : l)
    // {
    //     cout << val << " ";
    // }
}