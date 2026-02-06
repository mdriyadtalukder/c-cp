#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MyVector
{
private:
    T *data;
    size_t size_; /*size_t is an unsigned integer type..it cannot be nagative number..that guaranteed to represent the size of any object in memory, and it’s used for array indices, lengths, and container sizes.*/
    size_t capacity_;

    void reallocate(size_t newCapacity)
    {
        T *newData = new T[newCapacity];
        for (size_t i = 0; i < size_; i++)
            newData[i] = data[i];

        delete[] data;  // free old memory..delete old memory..Old array is gone forever
        data = newData; // Redirect data to NEW memory
        capacity_ = newCapacity;
    }

public:
    /* ================= CONSTRUCTORS ================= */

    MyVector() : size_(0), capacity_(16) // it constructed size as 0 and capacity as 16.it is faster and cleaner
    {
        /*
        size_ = 0;
        capacity_ = 16;..size and capacity initialize then assign..2 step process.

        */
        data = new T[capacity_];
    }

    MyVector(size_t capacity) : size_(0), capacity_(capacity)
    {
        if (capacity < 0)
            throw invalid_argument("Illegal capacity");
        data = new T[capacity_];
    }

    /* ================= SIZE / CAPACITY ================= */

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    /* ================= ELEMENT ACCESS ================= */

    T &at(size_t index)
    {
        if (index < 0 || index >= size_)
            throw out_of_range("Index out of bounds");
        return data[index];
    }

    T &operator[](size_t index)
    {
        if (index < 0 || index >= size_)
            throw out_of_range("Index out of bounds");
        return data[index];
    }

    T &front()
    {
        if (empty())
            throw out_of_range("Vector is empty");
        return data[0];
    }

    T &back()
    {
        if (empty())
            throw out_of_range("Vector is empty");
        return data[size_ - 1];
    }

    /* ================= MODIFIERS ================= */

    void push_back(const T &value)
    {
        if (size_ + 1 >= capacity_)
        {
            capacity_ = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(capacity_);
        }
        data[size_++] = value;
    }

    void pop_back()
    {
        if (empty())
            throw std::out_of_range("Vector is empty");

        data[size_ - 1].~T(); // destroy last element
        size_--;
    }

    void clear()
    {
        for (size_t i = 0; i < size_; i++)
        {
            data[i].~T(); // manually call destructor..Calls destructor of one element..and delete that.
        }
        size_ = 0;
    }

    /* ================= REMOVE METHODS ================= */

    void erase(size_t index)
    {
        if (index >= size_ && index < 0)
            throw out_of_range("Index out of bounds");

        // Allocate new smaller array
        T *newData = new T[size_ - 1]; // keep capacity same, or you can shrink

        for (size_t i = 0,j=0; i < size_; i++, j++)
        {
            if (i == index)
                j--;              // skip the element to erase
            newData[j] = data[i]; // copy other elements
        }

        // Destroy old array
        delete[] data;

        data = newData;
        capacity_ = --size_; // reduce logical size
    }

    // Remove by value (first occurrence)
    bool remove(const T &value)
    {
        for (size_t i = 0; i < size_; i++)
        {
            if (data[i] == value)
            {
                erase(i);
                return true;
            }
        }
        return false;
    }

    /* ================= SEARCH METHODS ================= */

    size_t indexOf(const T &value) const
    {
        for (size_t i = 0; i < size_; i++)
        {
            if (data[i] == value)
                return i;
        }
        return (size_t)-1;
    }

    bool contains(const T &value) const
    {
        return indexOf(value) != (size_t)-1;
    }

    /* ================= ITERATORS ================= */

    T *begin() { return data; }
    T *end() { return data + size_; }

    /* ================= TOSTRING ================= */

    friend ostream &operator<<(ostream &os, const MyVector<T> &v)
    {
        os << "[";
        for (size_t i = 0; i < v.size_; i++)
        {
            os << v.data[i];
            if (i != v.size_ - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }

    /* ================= DESTRUCTOR ================= */

    ~MyVector()
    {
        delete[] data; /*delete[] data frees all memory allocated for the array.
                       For arrays of objects, delete[] also automatically calls the destructor for each element.*/
    }
};
int main()
{
    MyVector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    // cout << v.at(2);
    v.push_back(4);
    v.erase(2);
    v.push_back(34);
    cout << v[2];
}
/*
==================== TIME COMPLEXITY TABLE ====================

CLASS / METHOD / OPERATION            | TIME COMPLEXITY
-------------------------------------------------------
MyVector() constructor                | O(1)
MyVector(capacity) constructor        | O(1)

~MyVector() destructor                | O(n)
(delete[] calls destructor for n elements)

-------------------------------------------------------
size()                                | O(1)
capacity()                            | O(1)
empty()                               | O(1)

-------------------------------------------------------
at(index)                             | O(1)
operator[](index)                    | O(1)
front()                               | O(1)
back()                                | O(1)

-------------------------------------------------------
push_back(value) [average]            | O(1) amortized
push_back(value) [worst case]         | O(n)
(due to reallocate + copy)

pop_back()                            | O(1)

clear()                               | O(n)
(calls destructor for each element)

-------------------------------------------------------
erase(index)                          | O(n)
(shifts elements to the left)

remove(value)                         | O(n)
(search O(n) + erase O(n) → still O(n))

-------------------------------------------------------
indexOf(value)                        | O(n)
(linear search)

contains(value)                       | O(n)
(calls indexOf)

-------------------------------------------------------
begin()                               | O(1)
end()                                 | O(1)

-------------------------------------------------------
operator<< (ostream << vector)        | O(n)
(iterates over all elements)

-------------------------------------------------------
reallocate(newCapacity)               | O(n)
(copies all existing elements)

-------------------------------------------------------
Range-based for loop (for(auto x:v))  | O(n)

=======================================================
*/
