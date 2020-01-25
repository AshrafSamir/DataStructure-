#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const string open = "/*";
const string close = "*/";
bool truePair(char opening,char closing)
{
    if(opening=='(' && closing == ')') return true;
    else if(opening=='[' && closing == ']') return true;
    else if(opening=='{' && closing == '}') return true;
    else return false;
}
bool checkBrackets(string str)
{
    stack<char> toCheck;
    stack<string> comment;
    for(int i=0; i<str.length(); i++)
    {


        if(str[i] == '(' || str[i] == '[' || str[i] == '{' )
            {
                toCheck.push(str[i]);
            }
        else if(str[i]=='/' && str[i+1]=='*')
        {
            comment.push("/*");
            i++;
        }
        else if( str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if(toCheck.empty()||!(truePair(toCheck.top(),str[i])))return false;
            else toCheck.pop();
        }
        else if(str[i]=='*' && str[i+1]=='/')
        {
            if(!(comment.top()=="/*"))return false;
            else comment.pop();
            i++;
        }
    }
    return toCheck.empty()&&comment.empty()?true:false;
}
int main()
{
	string str;
	cout<<"Enter an expression:  ";
	cin>>str;
	if(checkBrackets(str))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";

    return 0;
}
