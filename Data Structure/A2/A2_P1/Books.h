#ifndef BOOKS_H
#define BOOKS_H

#include <vector>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
class Books
{
    public:
        char name[100];
        char author[100];
        int year;
        int numOfVersions;
        vector <Books> books;

        Books();
        //Books addBooks(Books & b);
        void listAll();
        void searchByName(char s[100]);
        void searchByAuthor(char s1[100]);
        void highestNum();
        void updateAvl(int n,char name[100]);
        virtual ~Books();


};

#endif // BOOKS_H
