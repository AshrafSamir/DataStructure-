#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double power1(int a, int n){

    if(n==0)return 1;
    if(n==1)return a;
    else return (a*power1(a,n-1));

}
double power2(int a, int n){

    if(n==0)return 1;
    if(n==1)return a;
    else if(n%2==0) return (power2(a,n/2)*power1(a,n/2));
    else return (power2(a,(n+1)/2)*power1(a,(n+1)/2))/a;

}

int main()
{
 cout<<power1(5,3)<<endl;
 cout<<power1(5,0)<<endl;
 cout<<power1(5,1)<<endl;
 cout<<power1(5,4)<<endl;
 cout<<power2(5,4)<<endl;
 cout<<power2(5,8)<<endl;
 cout<<power2(5,5)<<endl;
 cout<<power2(5,3)<<endl;
 cout<<power2(5,7)<<endl;
 cout<<power2(5,6)<<endl;
 cout<<power2(5,0);

    return 0;
}
