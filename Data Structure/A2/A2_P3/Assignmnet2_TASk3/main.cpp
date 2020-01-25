#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <numeric>

using namespace std;
using namespace std::chrono;
class searcher{
public:
    vector <string> words;
    vector <string> choose;
    void loadData(fstream & file,int num)
    {
        for (int i=0;i<num;i++)
        {
            char line[100];
            if (!file.eof())
            {

                file >> line;
                words.push_back(line);
                choose.push_back(line);
            }

        }
        file.close();
    }
    // A function implementing Binary search on a sorted array.
    int BinarySearch(string key)
    {
        int lower = 0;
        int upper = words.size();
        while (lower <= upper) {
            int mid = lower + (upper-lower) /2;
            if(key == words[mid])
            {
                return mid;
            }
            if(key < words[mid])
                upper = mid-1;
            else
                lower = mid+1;
            }

        return -1;
    }
    int numOfComparison(string key)
    {
        int counter = 0;
        int lower = 0;
        int upper = words.size();
        while (lower <= upper) {
                counter++;
            int mid = lower + (upper-lower) /2;
            if(key == words[mid])
            {
                return counter;
            }
            if(key < words[mid])
                upper = mid-1;
            else
                lower = mid+1;
            }

        return counter;
    }
    float Time(string key)
    {
        int lower = 0;
        int upper = words.size();
        //double start = high_resolution_clock::now();
        clock_t t;
        t = clock();
        while (lower <= upper) {
            int mid = lower + (upper-lower) /2;
            if(key == words[mid])
            {
                break;
            }
            if(key < words[mid])
                upper = mid-1;
            else
                lower = mid+1;
            }
            t = clock() - t;

//        double stop = high_resolution_clock::now();
//        double duration = duration_cast<nanoseconds>(stop - start);
        return ((float)t)/CLOCKS_PER_SEC;
    }


};

int main()
{

//    for (int i=0;i<50;i++)
//    {
//       cout << rand()%801 << endl;
//    }

    fstream file("words.txt",ios::in|ios::out);
    searcher s;
    int num = 1000;
    s.loadData(file,num);
    vector <float> avgTime;
    vector <int> avgComp;
    ofstream data("data.txt");
    ofstream data1("data1.txt");

    for (int i=0;i<1000;i++)
    {


        int random =rand()%1000;
        string b = s.choose[random];
        int index = s.BinarySearch(b);
        float time = s.Time(b);
        avgTime.push_back(time);
        int comp = s.numOfComparison(b);
        avgComp.push_back(comp);
        data << comp << endl;


    }

    float sumOfTime = 0;
    int sumOfComp = 0;
    sumOfTime = accumulate(avgTime.begin(), avgTime.end(), 0.0);
    sumOfComp = accumulate(avgComp.begin(), avgComp.end(), 0);

    cout << sumOfTime/num << "ms  ," << sumOfComp/num << endl;


    for (int i=0;i<1000;i++)
    {


        int random =rand()%1000;
        int index = s.BinarySearch("Ahmed");
        float time = s.Time("Ahmed");
        avgTime.push_back(time);
        int comp = s.numOfComparison("Ahmed");
        avgComp.push_back(comp);
        data1 << comp << endl;


    }

    sumOfTime = accumulate(avgTime.begin(), avgTime.end(), 0.0);
    sumOfComp = accumulate(avgComp.begin(), avgComp.end(), 0);

    cout << sumOfTime/num << "ms  ," << sumOfComp/num << endl;
//    for (int i=0;i<800;i++)
//    {
//        cout << avgTime[i] << endl;
//    }

//    for (int i=0;i<num;i++)
//    {
//        cout << s.words[i] << " " << s.choose[i] << endl;
//    }

    return 0;
}
