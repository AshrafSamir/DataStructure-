#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool CheckPal(string str)
{
    stack<char> st;
    for(int i=0,j=str.length()-1;i<str.length();i++,j--)
        {
            st.push(str[i]);
            if(st.top()!=str[j])return false;
//            if(str[i]!=str[j])return false;
            if(i==j)break;
        }

        return true;
}

int main()
{
    string str;
	cout<<"Enter an expression:  ";
	cin>>str;
	if(CheckPal(str))
		cout<<"Palindrome\n";
	else
		cout<<"Not Palindrome\n";
    return 0;
}
