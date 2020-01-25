#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else return false;
}

template <typename T>
void LinkedList<T>::add(T v)
{
    if(isEmpty())
    {
        Node<T>* tmp = new Node<T>;
        tmp->value = v;
        tmp->next = NULL;
        head = tmp;
        last = tmp;
    }
    else
    {
        Node<T>* tmp = new Node<T>;
        tmp->value = v;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }

}

template <typename T>
void LinkedList<T>::addSorted(T v)
{
    add(v);
    bool unsorted = true;
    int count = 0 ;
    Node<T>* next = new Node<T>;
    Node<T>* cur = new Node<T>;
    cur = head;

    while(unsorted)
    {
        unsorted = false;
        while (cur != NULL)
        {
            if(cur->next==NULL)
            {
               cur = head;
               unsorted = true;
               count++;
               break;
            }
            next = cur->next;
            if(next->value < cur->value)
            {
                ///swap
                T tmp ;
                tmp = cur->value;
                cur->value = next->value;
                next->value = tmp;

                unsorted = true;
                break;
            }
            cur = cur->next;
        }
        if(count == getSize())break;
    }
    //return cur;
}

template <typename T>
Node<T>* LinkedList<T>::get(T v)
{
    Node<T> *current = new Node<T>;
    current = head;
    if(isEmpty())
    {
        cout<<"The list is already empty. \n";
    }
    else
    {
        cout<<"The list content : \n";
        while(current!=NULL)
        {
            if(current == v)return current;
            current=current->next;
        }
    }
}

template <typename T>
void LinkedList<T>::showList()
{
    Node<T> *current = new Node<T>;
    current = head;
    if(isEmpty())
    {
        cout<<"The list is already empty. \n";
    }
    else
    {
        //cout<<"The list content : \n";
        while(current!=NULL)
        {
            cout<<"-"<<current->value;
            current=current->next;
        }
    }
}

template <typename T>
int LinkedList<T>::getSize()
{
    Node<T>* current = new Node<T>;
    current = head;
    int count = 0;
    if(isEmpty())
    {
        cout<<"The list is already empty. \n";
    }
    while(current!=NULL)
    {
        current=current->next;
        count++;
    }
    return count;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
        while(head!=NULL)
        {
            Node<T> *tmp = new Node<T>;
            tmp = head->next;
            delete head;
            head=tmp;
        }
}
