#include<iostream>
#include<cstdlib>
#include <string>
using namespace std;

template <typename T>
class dynamic_array
{
private:
    int m_size;
    T* m_data;

public:
    dynamic_array()
    {
        this->m_size = 0;
        this->m_data = NULL;
    }
    dynamic_array(const dynamic_array<T>& a)
    {
        this->m_size = a.m_size;
        this->m_data = new T[m_size];
        for (int i = 0; i < m_size; ++i)
            m_data[i] = a.m_data[i];
    }
    dynamic_array(int size, T* ms)
    {
        this->m_size = size;
        m_data = new T[size];
        for (int i = 0; i < size; i++)
        {
            this->m_data[i] = ms[i];
        }
    }
    ~dynamic_array()
    {
        delete[] m_data;
    }
    void push_back(T val)
    {
        this->m_size += 1;
        m_data[m_size - 1] = val;
    }
    int size()
    {
        return m_size;
    }
    T& operator[] (int i)
    {
        return m_data[i];
    }
    void fun(T find, dynamic_array<T> da)
    {
        char m = '*';
        for (int i = 0; i < da.m_size; i++)
        {
            if (da.m_data[i] == find)
            {
                da.m_data[i] = m;
            }
        }
        for (int i = 0; i < da.m_size; i++)
        {
            cout << "Element of arr [" << i << "] :" << da.m_data[i] << endl;
        }
    }
};

template<typename T>
ostream& operator << (ostream& out, dynamic_array<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}


int main()
{
    int size;
    char* ms;
    char num;
    cout << "Input size: ";
    cin >> size;
    ms = new char[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Input element of array [" << i << "]: ";
        cin >> ms[i];
    }
    dynamic_array<char> arr(size, ms);
    cout << "\n" << arr << endl;
    cout << "Input number for search: ";
    cin >> num;
    dynamic_array<char> m;
    m.fun(num, arr);
    return 0;
}
