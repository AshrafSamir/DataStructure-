#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> inventory;

/*int Fac(int n)
    {
        if((n==1)||(n==0))return 1;
        int f=1;
        for(int i=1;i<=n;i++)
            {
                  f=f*i;
            }
            return f;
    }

int nPr(int n)
{
    return (Fac(n)/Fac(n-n));
}*/

void RecPermute(string soFar, string rest)
{


if (rest == ""){ // No more characters
bool isWrote=0;
for(int i=0;i<inventory.size();i++){
    if(inventory[i]==soFar)isWrote=1;
}
inventory.push_back(soFar);
if(isWrote==0){
        cout << soFar << endl;

} // Print the word

}
else // Still more chars
// For each remaining char
for (int i = 0; i < rest.length(); i++) {
string next = soFar + rest[i]; // Glue next char
string remaining = rest.substr(0, i)+ rest.substr(i+1);
RecPermute(next, remaining);
}
}
// "wrapper" function
void ListPermutations(string s) {
RecPermute("", s);
}


int main()
{
    ListPermutations("makka");
    for(int i=0;i<120;i++)cout<<">>>>>>>>>"<<inventory[i];


    return 0;
}
