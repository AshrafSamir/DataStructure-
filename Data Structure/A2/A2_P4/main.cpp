#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,number;
    bool b=1;
    cout<<"Enter Size of the Vector : ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter Your Vector >> "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>number;
        if(number==0){cout<<"There is a Non-Degenerate Triangle Because of 0 No need for entering any sides "<<endl;return 0;}
        vec.push_back(number);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<(vec.size()-3);i++)
    {
        if(!(vec[i]+vec[i+1]<=vec[i+2])&&(i!=0))
            {
                cout<<"There is a Non-Degenerate Triangle "<<vec[i]<<" "<<vec[i+1]<<" "<<vec[i+2]<<endl;
                b=0;
                break;
            }
    }
    if(b==1)cout<<"Cannot Construct a Non-Degenerate Triangle "<<endl;

    return 0;
}
