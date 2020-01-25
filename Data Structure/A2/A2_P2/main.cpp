#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <bits/stdc++.h>

using namespace std;
void Erasing(map<string,int> wordsCounter)
{
    map<string,int>::iterator it;
    for(it=wordsCounter.begin();it!=wordsCounter.end();it++)
    {
        if(it->first[0]=='a' || it->first[0]=='A')
            {
                wordsCounter.erase(it->first);
                break;
            }
    }
}

int main()
{
    int n;
    string word;
    map<string,int> wordsCounter;
    map<string,int>::iterator it;
    cout<<"How many words u wanna count ? ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Add word >> ";
        cin>>word;
        if(wordsCounter[word]>=1)
        {
            wordsCounter[word]++;
        }
        else
        {
          wordsCounter[word]=1;
        }
    }
    cout<<endl;
    cout<<endl;
    for(it=wordsCounter.begin();it!=wordsCounter.end();it++)cout<<it->first<<'\t'<<it->second<<endl;
    cout<<"All elements with word start with 'a' Erased "<<endl;
    bool b;
    while(b==1){
    for(it=wordsCounter.begin();it!=wordsCounter.end();it++)
    {
        if(it->first[0]=='a' || it->first[0]=='A')
            {
                wordsCounter.erase(it->first);
                b=1;
                break;
            }
            b=0;
    }
    }
    for(it=wordsCounter.begin();it!=wordsCounter.end();it++)cout<<it->first<<'\t'<<it->second<<endl;
    return 0;
}
