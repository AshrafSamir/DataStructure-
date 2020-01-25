#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
#include "Treap.h"
#include "ContactManager.h"
using namespace std;


ostream& operator<<(ostream& o, Contact & c)
{
    o << c.name <<": "; c.phone_numbers.showList(); o<<endl;
}

int main()
{
    srand(time(NULL));

    ContactManager c;
    c.addcontacs();
    cout<<endl;

    c.displayNumber("01227410064");
//    cout<<endl;
//    Treap<int, int> test ;
//    test.insert(1, 50);
//    test.insert(6, 60);
//    test.insert(3, 20);
//    test.insert(7, 80);
//    test.insert(4, 40);
//    test.insert(2, 30);
//    test.insert(5, 70);
//    cout<<endl;
//
//    cout << "Inorder traversal of the modified tree \n";
//    test.print();
//
//    test.search(4);

    return 0;
}
