#include <cstddef>   // for size_t
#include <stdexcept> // for basic exceptions

template <typename T>
class Xlist;

template <typename T>
struct Xnode
{
private:
    T data{T()};
    Xnode<T> *next{nullptr};
    Xnode<T> *prev{nullptr};

public:
    using iterator = Xnode<T>;
    using const_iterator = const Xnode<T>;
    friend Xlist<int>;

    Xnode() {}
    Xnode(const T &x, Xnode<T> *n = nullptr, Xnode<T> *p = nullptr) : data{x}, next{n}, prev{p} {};

    T &operator*()
    {
        return this->data;
    }
    iterator operator++()
    {
        return this->next;
    }
    iterator operator--()
    {
        return this->prev;
    }
    T *operator->()
    {
        return &(this->data);
    }
};

template <typename T>
class Xlist
{
private:
    Xnode<T> *head{nullptr}; // ptr to first element
    Xnode<T> *tail{nullptr}; // ptr last element
    Xnode<T> nil;            // hypothetical past-end element
    size_t xlist_size{0};

public:
    using iterator = Xnode<T>;
    using const_iterator = const Xnode<T>;

    Xlist() {}

    ~Xlist()
    {
        
    }
    bool empty() { return !xlist_size; }

    size_t size() const { return xlist_size; }

    iterator begin()
    {
        if (empty())
            return nil;
        return *head;
    }

    iterator end()
    {
        if (empty())
            return nil;
        return *head;
    }

    void push_front(const T &x)
    {
        if (empty())
        {
            head = tail = new Xnode<T>(x);
        }
        else
        {
            head->prev = new Xnode<T>(x,head,nullptr);
            head = head->prev;
        }
        xlist_size++;
    }

    void push_back(const T& x)
    {
        if(empty())
        {
            head = tail = new Xnode<T>(x);
        }
        else
        {
            tail->next = new Xnode<T>(x,nullptr,tail);
        }
        xlist_size++;
    }

};
