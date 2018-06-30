#include <iostream>
#include <cstdlib>
#include <string>

template<typename T>
class Stack
{
    public:
        Stack();
        ~Stack();

        void push(const T& value);
        T    pop();

        inline T    peek() const;
        inline bool empty() const;
        inline void clear();

    private:

        struct node
        {
            T value;
            node* next;
        } *top;
    
    template<typename T1>
    friend std::ostream& operator<<(std::ostream& os, const Stack<T1>& s);
};



template<typename T>
Stack<T>::Stack():top(nullptr)
{}

template<typename T>
Stack<T>::~Stack()
{
    clear();
}

template<typename T>
void Stack<T>::push(const T& value) 
{
    node* tmp  = new node;
    tmp->value = value;
    tmp->next  = top;
    top        = tmp;
}

template<typename T>
T Stack<T>::pop()
{
    if (empty())
    {
        throw "Stack is empty!";
    }
    
    node *tmp  = top->next;
    T 	 value = top->value;
    
    delete top;
    top = tmp;
        
    return value;
}


template<typename T>
inline T Stack<T>::peek() const
{
    if (empty())
    {
        throw "Stack is empty!";
    }
    
    return top->value;      
}

template<typename T>
inline bool Stack<T>::empty() const
{
    return !top;
}

template<typename T>
inline void Stack<T>::clear()
{
    while(!empty())
    {
        pop();
    }
    
    top = nullptr;
}

template<typename T1>
std::ostream& operator<<(std::ostream& os, const Stack<T1>& s)
{
    typename Stack<T1>::node *tmp = s.top;
    
    while(tmp)
    {
        os << tmp->value << " ";
        tmp = tmp->next;
    }
    
    return os;
} 