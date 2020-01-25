#ifndef CONTACT_H
#define CONTACT_H

#include "LinkedList.h"
#include "LinkedList.cpp"

class Contact
{
    private:
        string name;
        LinkedList<string> phone_numbers;
        void addName(string Name);
    public:
        friend class ContactManager ;
        Contact();
        Contact(string name);

        //void addcontacs(int n);
        void addPhoneNumber(string number);
        string getName();
        bool operator<(const Contact & c);
        bool operator==(const Contact & c);
        friend ostream& operator<<(ostream& o, Contact & c);

        virtual ~Contact();
};

#endif // CONTACT_H
