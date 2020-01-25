#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    Queue *head = NULL;
    Queue *last = NULL;

    public:
    T data;
    Queue *next;

    Queue();
    Queue(T value , int intial_size);
    bool isEmpty();
    void Push(T Value);
    T Pop();
    T top();
    int Size();
    void showList();
    ~Queue()
    {
        while(head!=NULL)
        {
            Queue *tmp = new Queue;
            tmp = head->next;
            delete head;
            head=tmp;
        }
    }
};

template <typename T>
Queue<T>::Queue()
{

}

template <typename T>
Queue<T>::Queue(T value , int intial_size)
{
        for(int i=0;i<intial_size;i++)Push(value);

}

template <typename T>
bool Queue<T>::isEmpty()
{
    if(head == NULL)return true;
    else return false;
}
template <typename T>
void Queue<T>::Push(T value)
{
    if(isEmpty())
    {
        Queue *temp = new Queue;
        temp->data = value;
        temp->next = NULL;
        head = temp;
        last = temp;
    }
    else
        {
            Queue *temp = new Queue;
            temp->data = value;
            temp->next = NULL;
            last->next = temp;
            last = temp;

        }
}
template <typename T>
T Queue<T>::top()
{
    if(isEmpty())
    {
        cout<<"The list is already empty. \n";
        return 0;
    }
    else
    {
        return head->data;
    }

}
template <typename T>
T Queue<T>::Pop()
{
    if(isEmpty())
    {
        cout<<"The list is already empty. \n";
        return 0;
    }
    else if(head == last)
    {
        int value = head->data;
        head = NULL;
        last = NULL;
        return value ;
    }
    else
        {
            Queue *current = new Queue;
            current = head;
                    head = head->next;
                    int value = current->data;
                    current = NULL ;
                    return value;


        }
}
template <typename T>
 int Queue<T>::Size()
{
    Queue *current = new Queue;
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
template <typename T>
void Queue<T>::showList()
{
    Queue *current = new Queue;
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
            cout<<current->data<<endl;
            current=current->next;
        }
    }
}

char menu()
{
    char choice;

    cout<<"Menu\n";
    cout<<"1.Push item.\n";
    cout<<"2.Pop item.\n";
    cout<<"3.Show list.\n";
    cout<<"4.Number of elements.\n";
    cout<<"5.Get Front item.\n";
    cout<<"6.Exit\n";
    cin>>choice;

    return choice;
}

int main()
{

    Queue<int> s1(0,10);
    char choice;
    int number;


    do{
            choice = menu();
            switch(choice)
            {
                case'1':cout<<"Please enter a number :\n";
                        cin>>number;
                        s1.Push(number);
                        break;
                case'2':cout<<"Item "<<s1.Pop()<<" Deleted"<<endl;
                        break;
                case'3':s1.showList();
                        break;
                case'4':cout<<"the number of elements :\n";
                        cout<<s1.Size()<<endl;
                        break;
                case'5':cout<<"Front item : "<<s1.top()<<endl;
                        break;
                default:
                    cout<<"Exiting\n";
            }

    }while(choice != '6');


    return 0;
}
