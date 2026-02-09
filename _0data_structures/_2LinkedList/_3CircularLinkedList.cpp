#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class CircularLinkedList
{
    Node *head;
    Node *tail;
    int length;

public:
    CircularLinkedList()
    {
        head = tail = NULL;
        length = 0;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        length++;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode; // oldnode,oldnode2 (<--tail)..so next node will be newnode as tail....
            tail = newNode;
            tail->next = head;
        }
        length++;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty!!";
            return;
        }
        else if (head == tail) // single node
        {
            delete head;
            head = tail = NULL;
            length--;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
        length--;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty!!";
            return;
        }
        else if (head == tail) // single node
        {
            delete head;
            head = tail = NULL;
            length--;
            return;
        }
        Node *temp = tail;
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete temp;
        length--;
    }
    void printAll()
    {
        Node *temp = head->next;
        cout << head->data << " ";
        while (temp != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
    int size()
    {

        return length;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
};
int main()
{
    CircularLinkedList cll;
    cll.push_front(1);
    cll.push_front(12);
    cll.push_front(13);
    cll.push_back(133);
    cll.push_back(345);
    cll.pop_front();
    cll.pop_front();
    cll.pop_back();
    cll.printAll();
}