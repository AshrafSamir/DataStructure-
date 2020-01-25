#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include "LinkedList.h"
#include "Contact.h"
#include "Treap.h"
#include "Treap.cpp"
#include <fstream>
#include <iostream>

using namespace std;

class ContactManager
{
    private:
//        LinkedList<Contact> contacts;
        Treap<string, string> tree;
    public:
        ContactManager();
//        bool loadFromFile(string fileName);
        void addcontacs();
        void displayNumber(string phone_number);
        friend ostream& operator<<(ostream& o, ContactManager & c);
};

#endif // CONTACTMANAGER_H
