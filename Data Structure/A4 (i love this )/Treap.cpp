#include "Treap.h"
#include <bits/stdc++.h>
using namespace std;

template<typename T,typename V>
Treap<T,V>::Treap()
{

}

template<typename T,typename V>
void Treap<T, V>::insert(T key, V value)
{
    insert(root, key, value);
}

template<typename T,typename V>
V Treap<T, V>::search(T key)
{
    Treap<T, V>* tmp = search(root, key);
    if(tmp == nullptr)
    {
        cout<<key<<endl;
        exit(0);
    }
    else
    {
        cout<<tmp->value;
        return tmp->value;
    }

}

template<typename T,typename V>
Treap<T, V>* Treap<T, V>::newNode(Treap<T, V>*& root,T key , V value)
{
    Treap<T, V>* temp = new Treap<T, V>;
    temp->key = key;
    temp->value = value;
    temp->priority = rand()%100;
    temp->left = temp->right = NULL;
    root = temp;
    return temp;
}

template<typename T,typename V>
void Treap<T, V>::print()
{
    inorder(root);
}

template<typename T,typename V>
Treap<T, V>* Treap<T, V>::rightRotate(Treap<T, V> *y)
{
    Treap<T, V> *x = y->left , *T2 = x->right;

    x->right = y;
    y->left  = T2;

    return x;
}

template<typename T,typename V>
Treap<T, V>* Treap<T, V>::leftRotate(Treap<T, V> *x)
{
    Treap<T, V> *y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

template<typename T,typename V>
Treap<T, V>* Treap<T, V>::search(Treap<T, V>* root, T key)
{
	if (root == nullptr)
		return root;

	if (root->key == key)
		return root;

	if (key < root->key)
		return search(root->left, key);

	return search(root->right, key);
}

template<typename T,typename V>
Treap<T, V>* Treap<T, V>::insert(Treap<T, V>*& root, T key, V value)
{
    if (root == nullptr)
    {
        newNode(root,key, value);
        return root ;
    }


    if (key <= root->key)
    {
        root->left = insert(root->left, key, value);

        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else
    {
        root->right = insert(root->right, key, value);

        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}

template<typename T,typename V>
void Treap<T, V>::inorder(Treap<T, V>* root)
{
    if (root)
    {

        inorder(root->left);
        cout << "key: "<< root->key<< " | value: "<< root->value << " | priority: %d "
            << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->key;
        if (root->right)
            cout << " | right child: " << root->right->key;
        cout << endl;
        inorder(root->right);
    }
}

template<typename T,typename V>
Treap<T,V>::~Treap()
{
    //dtor
}
