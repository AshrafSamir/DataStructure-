#include "Contact.h"

Contact::Contact()
{
    //ctor
}

Contact::Contact(string name)
{
        this->name = name;
}

void Contact::addName(string name)
{
   this->name = name;
}

void Contact::addPhoneNumber(string number)
{
    phone_numbers.addSorted(number);
}
string Contact::getName()
{
    return name;
}

bool Contact::operator<(const Contact & c)
 {
     if(c.name < this->name)return true;
     else return false;
 }

Contact::~Contact()
{
    //dtor
}
