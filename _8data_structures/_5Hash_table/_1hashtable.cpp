#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
class HashTable
{
    struct Node
    {
        K key;
        V value;
        Node *next;

        Node(K k, V v)
        {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    Node **table;
    int capacity;
    int count; // number of elements in hash table

    // Custom hash functions
    int hashFunction(const K &key)
    {
        if constexpr (is_same<K, int>::value)
        {
            return key % capacity;
        }
        else if constexpr (is_same<K, string>::value)
        {
            int sum = 0;
            for (char c : key)
                sum += (int)c;
            return sum % capacity;
        }
        else
        {
            return hash<K>{}(key) % capacity;
        }
    }

public:
    HashTable() // HashTable(int cap)
    {
        // capacity = cap;
        capacity = 10;
        count = 0;
        table = new Node *[capacity];
        for (int i = 0; i < capacity; i++)
            table[i] = nullptr;
    }

    // ~HashTable()
    // {
    //     // free memory
    //     for (int i = 0; i < capacity; i++)
    //     {
    //         Node *temp = table[i];
    //         while (temp != nullptr)
    //         {
    //             Node *nextNode = temp->next;
    //             delete temp;
    //             temp = nextNode;
    //         }
    //     }
    //     delete[] table;
    // }

    void insert(K key, V value)
    {
        // key er maddhome index khujbe then dekhbe empty nki index..empty hole head a add krbe r empty na thkle last e and same key thkle just value update krbe..
        int index = hashFunction(key);
        Node *head = table[index];

        // If bucket empty
        if (head == nullptr)
        {
            table[index] = new Node(key, value);
            count++;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                temp->value = value; // update existing key
                return;
            }

            if (temp->next == nullptr)
                break;

            temp = temp->next;
        }

        // Insert at end to preserve order
        temp->next = new Node(key, value);
        count++;
    }

    void remove(K key)
    {
        // key er maddome index ber krbe then dekbe oi index e oi key ase nki ..thkle delete krbe..
        int index = hashFunction(key);
        Node *curr = table[index];
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                if (prev == nullptr) // head node
                    table[index] = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                count--;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "Key not found\n";
    }

    V get(K key)
    {
        int index = hashFunction(key);
        Node *temp = table[index];

        while (temp != nullptr)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }

        throw runtime_error("Key not found");
    }

    bool search(K key)
    {
        int index = hashFunction(key);
        Node *temp = table[index];

        while (temp != nullptr)
        {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }

        return false;
    }

    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << i << " -> ";
            Node *temp = table[i];
            while (temp != nullptr)
            {
                cout << "(" << temp->key << "," << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
    int size()
    {
        return count;
    }

    bool empty()
    {
        return count == 0;
    }
};

int main()
{
    // HashTable<string, int> ht(10);
    HashTable<int, string> ht;

    // ht.insert("a", 10);
    // ht.insert("b", 20);
    // ht.insert("c", 30);
    // ht.insert("k", 40);
    // ht.insert("u", 50);

    // ht.display();

    // cout << "\nSearch for 'b': " << ht.search("b") << endl;
    // cout << "Value of 'c': " << ht.get("c") << endl;

    // cout << "\nAfter removing 'b' and 'k':\n";
    // ht.remove("b");
    // ht.remove("k");

    ht.insert(101, "america");
    ht.insert(203, "UK");
    ht.insert(999, "AUS");
    ht.insert(1001, "vegas");
    ht.insert(321, "floria");

    ht.display();

    cout << "\nSearch for 'b': " << ht.search(999) << endl;
    cout << "Value of 'c': " << ht.get(203) << endl;

    cout << "\nAfter removing 'b' and 'k':\n";
    ht.remove(203);
    ht.remove(1001);

    ht.display();
    cout << "\nSize: " << ht.size() << endl;
    cout << "Is empty? " << ht.empty() << endl;

    return 0;
}