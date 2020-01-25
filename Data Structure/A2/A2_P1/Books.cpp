#include "Books.h"
#include <bits/stdc++.h>
using namespace std;
Books::Books()
{
    //ctor
}

void Books :: listAll()
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < books.size()-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < books.size(); j++)
          if (strcmp(books[j].author,books[min_idx].author) < 0 )
            min_idx = j;

        // Swap the found minimum element with the first element
        Books tmp;
        tmp = books[min_idx];
        books[min_idx] = books[i];
        books[i] = tmp;
    }
    for (int i=0;i<books.size();i++)
    {
        cout << "Book Number "<< i+1 << endl;
        cout << " Book Name : "<< books[i].name << endl;
        cout << " Author Name : "<< books[i].author << endl;
        cout << " Year of Publish : "<< books[i].year << endl;
        cout << " Number Of Versions : "<< books[i].numOfVersions << endl << endl;
    }
}


void Books :: searchByName(char s[100])
{
    for (int i=0;i<books.size();i++)
    {
        if (strcmp(books[i].name,s) == 0)
        {

            cout << "The Data of a Book with Name: "<< s << endl;
            cout << " Book Name : "<< " :" << books[i].name << endl;
            cout << " Author Name : "<< " :" << books[i].author << endl;
            cout << " Year of Publish : "<< books[i].year << endl;
            cout << " Number Of Versions : "<< books[i].numOfVersions << endl << endl;
            break;
        }

}
}

void Books :: searchByAuthor(char s1[100])
{
    for (int i=0;i<books.size();i++)
    {
        if (strcmp(books[i].author,s1) == 0)
        {

            cout << "The Data of a Book whose Author is: "<< s1 << endl;
            cout << " Book Name : "<< " :" << books[i].name << endl;
            cout << " Author Name : "<< " :" << books[i].author << endl;
            cout << " Year of Publish : "<< books[i].year << endl;
            cout << " Number Of Versions : "<< books[i].numOfVersions << endl << endl;
            break;
        }

}
}


void Books :: updateAvl(int n,char name[100])
{
    for (int i=0;i<books.size();i++)
    {
        if (strcmp(books[i].name,name) == 0)
        {
            this->books[i].numOfVersions = n;
            break;
        }

    }

}

void Books :: highestNum()
{
    int maximum = 0;
    int index = 0;
    maximum = books[0].numOfVersions;
    for (int i = 1;i<books.size();i++)
    {
        if (maximum < books[i].numOfVersions )
        {
            index = i;
        }
    }
    cout << "The Data of The Book That has the maximum Number of versions : " << endl;
    cout << " Book Name : "<< " :" << books[index].name << endl;
    cout << " Author Name : "<< " :" << books[index].author << endl;
    cout << " Year of Publish : "<< books[index].year << endl;
    cout << " Number Of Versions : "<< books[index].numOfVersions << endl << endl;

}

Books::~Books()
{
    //dtor
}
