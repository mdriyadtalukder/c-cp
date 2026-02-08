#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *pre;
    Node(int val)
    {
        data = val;
        next = pre = NULL;
    }
};
class DoublyLinkedList
{
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList()
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
        }
        else
        {
            newNode->next = head;
            head->pre = newNode; // head to ekhn 2nd node hyse ..so 2nd node er pre hbe new node ta.
            head = newNode;
        }
        length++;
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
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
        length++;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            throw invalid_argument("list is empty!");
        }
        Node *temp = head;
        head = head->next;

        head->pre = NULL;

        temp->next = NULL;
        delete temp;
        length--;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            throw invalid_argument("list is empty!");
        }
        Node *temp = tail;
        tail = tail->pre;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        temp->pre = NULL;
        delete temp;
        length--;
    }
    void insert(int val, int pos)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Invalid position!!";
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        if (pos == length)
        {
            push_back(val);
            return;
        }

        // move to (pos - 1)th node
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        Node *newNode = new Node(val);

        newNode->next = temp->next;
        newNode->pre = temp;

        temp->next->pre = newNode;
        temp->next = newNode;

        length++;
    }
    void remove(int index)
    {
        // 1. Invalid index
        if (index < 0 || index >= length)
        {
            cout << "Invalid index!!";
            return;
        }

        // 2. Remove first node
        if (index == 0)
        {
            pop_front();
            return;
        }

        // 3. Remove last node
        if (index == length - 1)
        {
            pop_back();
            return;
        }

        // 4. Move to (index - 1)th node
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        // temp -> node before the one to delete
        Node *toDelete = temp->next;

        temp->next = toDelete->next;
        toDelete->next->pre = temp;

        delete toDelete;
        length--;
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
    DoublyLinkedList l;
    l.push_front(1);
    l.push_front(11);
    l.push_front(12);
    l.push_back(33);
    l.push_back(34);
    l.push_front(100);
    l.push_back(200);
    l.pop_front();
    l.pop_front();
    l.pop_back();
    l.insert(300, 2);
    l.remove(2);
    l.printAll();
}