#ifndef MAIN_HEAD_H_INCLUDED
#define MAIN_HEAD_H_INCLUDED

#include <windows.h>
using namespace std;
template <typename T>
struct node
{
    T value;
    node* next;
};
template <typename T>
class circled_list
{

    node<T>* head=0;
    size_t size_=0;

public:
    circled_list(int S);
    ~circled_list();
    size_t size();
    void push_back(T value);
    void remove(int k);
    void insert(int k,T value);
    T& operator [] (const int index);
};
template <typename T>
circled_list<T>::~circled_list()
{
    if(size_==0) return;
    while(size_)
        this->remove(0);

}
template <typename T>
void circled_list<T>::insert(int k,T value)
{

    if(k>=size_)
    {
        cout<<"Index is out of range\n";
        exit(0);
    }
    size_++;
    if(k==0)
        k=size_;
    node<T> *prev=head;
    node<T> *new_=new node<T>;
    new_->value=value;
    for(int i=0;i<k-1;++i)
        prev=prev->next;
    new_->next=prev->next;
    prev->next=new_;
    if(k==size_)
        head=new_;
}
template <typename T>
void circled_list<T>::remove(int k)
{
    if(size_==0) return;
    size_--;
    if(k==0)
    {
        node<T>* cur=head->next;
        head->value=cur->value;
        head->next=cur->next;
        delete cur;
        return;
    }
    node<T>* prev=head;
    for(int i=0;i<k-1;++i)
        prev=prev->next;
    node<T> *to_remove=prev->next;
    prev->next=to_remove->next;
    delete to_remove;
}
template <typename T>
void circled_list<T>::push_back(T value)
{
    if(size_++==0)
    {
        size_=1;
        head=new node<T>;
        head->value=value;
        head->next=head;
        return;
    }

    node<T>* cur=head;
    node<T>* new_=new node<T>;
    new_->value=value;
    new_->next=head;
    for(int i=1;i<size_;++i)
    cur=cur->next;
    cur->next=new_;
}
template <typename T>
T& circled_list<T>:: operator [] (const int index)
    {

        node<T>* cur=head;
        for(int i=0;i<index;++i)
            cur=cur->next;
        return cur->value;
    }
template <typename T>
size_t circled_list<T>:: size()
    {
        return size_;
    }
template <typename T>
circled_list<T>::circled_list(int S)
    {
        size_=S;
        if(S>=1)
        {
            head=new node<T>;
            head->next=head;
        }
        for(int i=1;i<S;++i)
        {
            node<T>* cur=new node<T>;
            cur->next=head->next;
            head->next=cur;
        }
    }
#endif // MAIN_HEAD_H_INCLUDED
