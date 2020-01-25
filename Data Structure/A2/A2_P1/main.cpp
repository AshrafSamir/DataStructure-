#include <bits/stdc++.h>
#include "Books.h"
using namespace std;
//void listBooks(vector <Books> arr);
istream & operator>> (istream & in,Books & b)
{
    cout << "Enter Book name : " ; in.getline(b.name,100);
    cout << "Enter Book Author Name : " ; in.getline(b.author,100);
    in.clear();
    cout << "Enter year Of Publish : " ; in >> b.year;
    cout << "Enter Number of Versions : " ; in >> b.numOfVersions;

    return in;
}
int main()
{
    int choice = 0;

    Books b1;

    while (true)
    {
        cout << "1-Add Book." << endl;
        cout << "2-Print All Books." <<endl;
        cout << "3-Update number of available Versions." << endl;
        cout << "4-Search By Book Name." << endl;
        cout << "5-Search By Author Name." << endl;
        cout << "6-Book with the maximum number of Versions." << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            int b;
            cout << "Enter Number of books To Store : " ; cin >> b;
            cin.ignore();
            for (int i=0;i<b;i++)
            {
                cin >> b1;
                cin.ignore();
                b1.books.push_back(b1);
            }
        }
        else if(choice == 2)
        {
            b1.listAll();
        }
        else if (choice == 3)
        {
            char name[100];
            int n = 0;
            cout << "Enter the name to search : " ; cin.getline(name,100);
            cin.clear();
            cout << "Enter the number to update : "; cin >> n;
            b1.updateAvl(n,name);
            cout << "After Updating Book with name " << name << endl;
            b1.listAll();
        }
        else if (choice == 4)
        {
            char name[100];
            int n = 0;
            cout << "Enter the name to search : " ; cin.getline(name,100);
            b1.searchByName(name);
        }
        else if (choice == 5)
        {
            char author[100];
            int n = 0;
            cout << "Enter the name to search : " ; cin.getline(author,100); cin.clear();
            b1.searchByAuthor(author);
        }
        else if (choice == 6)
        {
        b1.highestNum();
        }
    }



    return 0;
}

//void listBooks(vector <Books> arr)
//{
//    for (int i=0;i<arr.size();i++)
//    {
//        cout << " Book Number "<< " :" << arr[i].name << endl;
//        cout << " Author Name "<< " :" << arr[i].author << endl;
//        cout << " Year of Publish "<< " :" << arr[i].year << endl;
//        cout << " Number Of Versions "<< " :" << arr[i].numOfVersions << endl << endl;
//    }
//}
