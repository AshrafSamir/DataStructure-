#include "ContactManager.h"

using namespace std;

ContactManager::ContactManager()
{
    //ctor
}

void ContactManager::addcontacs()
{
    map<string, vector<string>> mymap;
    map<string, vector<string>>::iterator it;
    vector<string> v;
    int count = 0;
    string name,number;

    fstream file;
    file.open("all-contacts.in");

    while(!file.eof())
    {
         getline(file ,number ,' ');
         if(file.fail())break;
         getline(file ,name ,'\n');

        //cout<<"Add new contact : ";
        //cin>>number;
        //(cin,name);
        tree.insert(number,name);
        if(mymap[name].size() >= 1)
        {
            mymap[name].push_back(number);
            v.clear();
        }
        else
        {
            v.push_back(number);
            mymap[name] = v;
            v.clear();
        }

    }

    Contact c[mymap.size()];
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        c[count].addName(it->first);
        for(x:it->second)c[count].addPhoneNumber(x);
        count++;
    }
    cout<<endl;
    cout<< "The contact list :\n";
    cout<<endl;
    for(x:c)cout<<x;
    file.close();

}


void ContactManager::displayNumber(string phone_number)
{
     tree.search(phone_number);
}
