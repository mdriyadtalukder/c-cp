#include <bits/stdc++.h>
using namespace std;
// head->next points to the second node of the list.
// tail->next points to NULL.
// head->data is the value stored in the first node.
// tail->data is the value stored in the last node.
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
    int length; // track size

public:
    LinkedList()
    {
        head = tail = NULL;
        length = 0;
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
            tail->next = newNode; // oldnode,oldnode2 (<--tail)..so next node will be newnode as tail....
            tail = newNode;
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
        Node *temp = head;
        head = head->next;
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
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
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
        Node *temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next; // head->next=2nd elem
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next; // A=B
        temp->next = newNode;       // B=C
        length++;                   // update size
    }
    void remove(int index)
    {
        // 1. Check for invalid index
        if (index < 0 || index >= length)
        {
            cout << "Invalid index!!\n";
            return;
        }

        // 2. If removing the first node
        if (index == 0)
        {
            pop_front(); // pop_front() already updates length
            return;
        }

        // 3. If removing the last node
        if (index == length - 1)
        {
            pop_back(); // pop_back() already updates length
            return;
        }

        // 4. Removing a middle node
        Node *temp = head;
        // Move to (index - 1)th node (node before the one to delete)
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        Node *toDelete = temp->next; // node we want to remove
        temp->next = toDelete->next; // bypass the node

        delete toDelete; // free memory
        length--;        // update size
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
    int size()
    {

        return length;
    }
    bool isEmpty()
    {
        return size() == 0;
    }

    /// problems
    int middleOfList()
    {


        int length = 0, l = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            length++;
        }

        int key = (length / 2) + 1;

        Node *temp2 = head;
        int ans;
        while (temp2 != NULL)
        {
            l++;
            if (l == key)
            {
                ans = temp2->data;
            }

            temp2 = temp2->next;
        }
        return ans;
    }
};
int main()
{
    LinkedList l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(52);
    l.push_back(52);
    // l.pop_front();
    // l.pop_back();
    // l.insert(4, 3);
    // cout << l.search(2);
    // cout << l.size();
    //  l.remove(0);
    // l.remove(1);
    // l.remove(2);
    // l.remove(3);
    // cout << l.size();
    l.printAll();
    cout << l.middleOfList();

    // for (int val : l)
    // {
    //     cout << val << " ";
    // }
}