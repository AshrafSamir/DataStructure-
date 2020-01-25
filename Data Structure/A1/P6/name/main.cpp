#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StudentName
{
    public:
        string name;
        StudentName(string nam)
        {
            int counter=0,len=nam.size();
            for(int i=0;i<len;i++)
            {
                if(nam[i]==' ')counter++;
            }
            if(counter>=2)
                {
                    name=nam;
                    cout<<name;
                }
            else
                {
                    string valid;
                    for(int i=0;i<len;i++)
                        {
                            if(nam[i]==' ')
                            {
                                for(int j=i;j<len;j++)valid=valid+nam[j];
                                //cout<<valid;
                                name=(nam+valid);
                            }
                        }
                    cout<<name<<endl;
                    bool yes=false;
                    for(int i=0;i<len;i++)
                        {
                            if(nam[i]==' ')yes=true;
                        }
                    if(yes==false)
                    {
                       for(int i=0;i<len;i++)valid=valid+nam[i];
                       name=(nam+" "+valid+" "+valid);
                       cout<<name;
                    }
                }
        }

};

int main()
{
    StudentName nam("ashraf samir ali");


    return 0;
}
