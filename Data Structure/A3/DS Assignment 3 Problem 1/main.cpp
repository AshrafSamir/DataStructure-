#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class List
{
        T data;
        List *next;
        List *prev;

public:

class Iterator : public std::iterator<std::bidirectional_iterator_tag,List<T>*>
{
    List<T>* itr;

     Iterator(List<T>* n) : itr(n)
    {
    }

public:

    Iterator()  : itr(nullptr)
    {
    }

    void swap(Iterator& other) noexcept
    {
        using std::swap;
        swap(itr, other.iter);
    }



    Iterator& operator++ ()
    {
        assert(itr != nullptr && "Out-of-bounds iterator increment!");
        itr = itr->next;
        return *this;
    }
    Iterator& operator-- ()
    {
        assert(itr != nullptr && "Out-of-bounds iterator decrement!");
        itr = itr->prev;
        return *this;
    }
    Iterator operator-- (int)
    {
        assert(itr != nullptr && "Out-of-bounds iterator decrement!");
        Iterator tmp(*this);
        itr = itr->prev;
        return tmp;
    }

    bool operator == (const Iterator& rhs) const
    {
        return itr == rhs.itr;
    }

    bool operator != (const Iterator& rhs) const
    {
        return itr != rhs.itr;
    }

    T& operator* () const
    {
        assert(itr != nullptr && "Invalid iterator dereference!");
        return itr->data;
    }

    T& operator-> () const
    {
        assert(itr != nullptr && "Invalid iterator dereference!");
        return itr->data;
    }

};




    List()
    {

    }
    List(T value , int intial_size)
    {

    }
    bool isEmpty(List *&head);
    void insertAsFirst(List *&head,List *&last,T number);
    void insertt(List *&head,List *&last,T number);
    void remoove(List *&head,List *&last);
    void showList(List *current);
    int countNodes(List *current);
    T End(List *current);
    T Begin(List *head);
    ~List()
    {

    }

};

char menu()
{
    char choice;

    cout<<"Menu\n";
    cout<<"1.Add item.\n";
    cout<<"2.Remove item.\n";
    cout<<"3.Show list.\n";
    cout<<"4.Number of elements.\n";
    cout<<"5.Exit\n";

    cin>>choice;

    return choice;
}
template<typename T>
bool List<T>::isEmpty(List *&head)
{
    if(head == NULL)
    {
        return true;
    }
    else return false;
}
template<typename T>
void List<T>::insertAsFirst(List *&head,List *&last,T number)
{
    List *tmp = new List;
    tmp->data = number;
    tmp->next = NULL;
    head = tmp;
    last = tmp;
}
template<typename T>
void List<T>::insertt(List *&head,List *&last,T number)
{
    if(isEmpty(head))
    {
        insertAsFirst(head,last,number);
    }
    else
    {
        List *tmp = new List;
        tmp->data = number;
        tmp->next = NULL;
        tmp->prev = last;
        last->next = tmp;
        last = tmp;

    }
}
template<typename T>
void List<T>::remoove(List *&head,List *&last)
{
    if(isEmpty(head))
    {
        cout<<"The list is already empty. \n";
    }
    else if(head == last)
    {
        delete head;
        head == NULL;
        last == NULL;
    }
    else
    {
        List *tmp = head;
        head->next->prev = NULL;
        head=head->next;
        delete tmp;
    }
}
template <typename T>
void List<T>::showList(List *current)
{
    if(isEmpty(current))
    {
        cout<<"The list is already empty. \n";
    }
    else
    {
        cout<<"The list content : \n";
        while(current!=NULL)
        {
            cout<<current->data<<endl;
            current=current->next;
        }


    }
}
template <typename T>
int List<T>::countNodes(List *current)
{
    int count = 0;
    if(isEmpty(current))
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
template <typename T>
T List<T>::End(List *current)
{
    if(isEmpty(current))
    {
        cout<<"The list is already empty. \n";
        return;
    }
    while(current!=NULL)
    {
        current=current->next;
        if(current->next == NULL)
        {
            return current->data;
        }
    }

}
template <typename T>
T List<T>::Begin(List *head)
{
    if(isEmpty(head))
    {
        cout<<"The list is already empty. \n";
        return;
    }
    return head->data;

}

int main()
{
    List<int>  *head=NULL;
    List<int> *last=NULL;
    List<int> i;

    char choice;
    int number;


    do{
            choice = menu();
            switch(choice)
            {
                case'1':cout<<"Please enter a number :\n";
                        cin>>number;
                        i.insertt(head,last,number);
                        break;
                case'2':i.remoove(head,last);
                        break;
                case'3':i.showList(head);
                        break;
                case'4':cout<<"the number of elements :\n";
                        cout<<i.countNodes(head)<<endl;
                        break;
                default:
                    cout<<"Exiting\n";
            }

    }while(choice != '5');

    return 0;
}
