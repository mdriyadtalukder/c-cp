#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MyVector
{
private:
    T *data;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t newCapacity)
    {
        T *newData = new T[newCapacity];
        for (size_t i = 0; i < size_; i++)
            newData[i] = data[i];

        delete[] data; // free old memory
        data = newData;
        capacity_ = newCapacity;
    }

public:
    /* ================= CONSTRUCTORS ================= */

    MyVector() : size_(0), capacity_(16)
    {
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
        if (size_ >= capacity_)
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
        size_--;
    }

    void clear()
    {
        size_ = 0; // memory kept (same as std::vector)
    }

    /* ================= REMOVE METHODS ================= */

    // remove at index (Java removeAt)
    T erase(size_t index)
    {
        if (index >= size_)
            throw out_of_range("Index out of bounds");

        T removedValue = data[index];
        for (size_t i = index; i < size_ - 1; i++)
            data[i] = data[i + 1];

        size_--;
        return removedValue;
    }

    // remove by value (Java remove)
    bool remove(const T &value)
    {
        size_t index = indexOf(value);
        if (index == (size_t)-1)
            return false;
        erase(index);
        return true;
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
        delete[] data;
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

    for (auto x : v)
        cout << x << " ";
}
