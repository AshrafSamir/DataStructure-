#ifndef TREAP_H
#define TREAP_H
#include <bits/stdc++.h>
using namespace std;


template<typename T,typename V>
class Treap
{
    public:

        Treap();
        void insert(T key, V value);
        V search(T key);
        void print();
        friend ostream& operator<<(ostream &o, Treap<T, V> root);
        virtual ~Treap();

    protected:

    private:

        T key;
        V value ;
        int priority;
        Treap *left, *right;
        Treap<T, V> *root = NULL;

        Treap<T, V>* insert(Treap<T, V>*& root, T key, V value);
        Treap<T, V>* search(Treap<T, V>* root, T key);
        void inorder(Treap<T, V>* root);
        Treap<T, V>* rightRotate(Treap<T, V> *y);
        Treap<T, V>* leftRotate(Treap<T, V> *x);
        Treap<T, V>* newNode(Treap<T, V>*& root,T key, V value);


};

#endif // TREAP_H
