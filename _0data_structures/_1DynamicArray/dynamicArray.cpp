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
        if (index >= size_)
            throw out_of_range("Index out of bounds");
        return data[index];
    }

    T &operator[](size_t index)
    { // no bounds check
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
            throw out_of_range("Vector is empty");

        data[size_ - 1] = 0;
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
        if (index >= size_)
            throw out_of_range("Index out of bounds");

        // Call destructor of the removed element
       // data[index].~T();

        // Shift remaining elements left
        for (size_t i = index; i < size_ - 1; i++)
            data[i] = data[i + 1];

        size_--;
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
    MyVector<string> v(3);

    v.push_back("am");
    v.push_back("jam");
    v.push_back("kk");

    v[1] = "kola";

    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.empty() << endl;
    cout << v.indexOf("kk") << endl;
    cout << v.contains("kk") << endl;
    cout << v << endl;

    v.remove("kola");
    cout << v << endl;
    v.clear();

    for (auto x : v)
        cout << x << " ";
}
