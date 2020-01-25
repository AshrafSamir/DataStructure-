#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

template<typename T>
	class Node {
	public:

		T value;
		Node* next;

		Node()
		{

		}
	};

template<typename T>
class LinkedList {

private:
	Node<T>* head = NULL;
    Node<T>* last = NULL;
public:
	string delimeter; // optional: just for printing

	LinkedList();
	bool isEmpty();
	void add(T v);
	void addSorted(T v);
	Node<T>* get(T v);
    void showList();
    int getSize();
	// operator overloading for printing
	friend ostream& operator<<(ostream& o, LinkedList<T> & c);
	virtual ~LinkedList();
};

#endif // LINKEDLIST_H
