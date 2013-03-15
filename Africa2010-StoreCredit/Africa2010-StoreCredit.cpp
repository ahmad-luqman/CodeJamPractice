// Africa2010-StoreCredit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <direct.h>
#include <vector>
#include <algorithm>

using namespace std;

string GetCurrentDir()
{
    string str;
    char* buffer;
    // Get the current working directory: 
    if( (buffer = _getcwd( NULL, 0 )) == NULL )
        perror( "_getcwd error" );
    else
    {
        printf( "%s \nLength: %d\n", buffer, strlen(buffer) );
        str.assign(buffer);
        free(buffer);
    }
    return str;
}

string GetFullInputfilePath()
{
    string path = GetCurrentDir();
    string filename = "\\input\\A-large-practice.in";
    stringstream ss;
    ss << path << filename;
    string fullpath = ss.str();
    return fullpath;
}

template<class TYPE>
TYPE ReadLineValue(ifstream &ifs)
{
    string str;
    getline(ifs, str);
    TYPE num;
    stringstream(str) >> num;
    return num;
}

template<class TYPE>
vector<TYPE> ReadLineValues(ifstream &ifs, const size_t l_num)
{
    vector<TYPE> v;
    string str;
    getline(ifs, str);
    stringstream ss(str);

    for (size_t i = 0; i < l_num; i++)
    {
        TYPE value;
        ss >> value;
        v.push_back(value);
    }
    return v;
}

struct item
{
    int value;
    int position;
};

int _tmain(int argc, _TCHAR* argv[])
{
    string str;
    ifstream ifs(GetFullInputfilePath());
    if (!ifs.is_open())
        return EXIT_FAILURE;

    ofstream ofs("output.txt");

    int N = ReadLineValue<int>(ifs);

    for (int i = 0; i < N; i++) // For N number of cases
    {
        int C = ReadLineValue<int>(ifs); // C the amount of credit
        int I = ReadLineValue<int>(ifs); // I the number of items
        vector<int> P = ReadLineValues<int>(ifs, I); // P the vector of Prices
        
        vector<item> PWithPosition;
        int j = 0;
        for_each(P.begin(), P.end(), [&] (int value) 
        {
            item i = { value, j++ };
            PWithPosition.push_back(i); 
        });


        sort(PWithPosition.begin(), PWithPosition.end(), [](const item &a, const item &b) { return a.value < b.value; });

        int head = 0;
        int tail = PWithPosition.size() - 1;
        bool found = false;

        while(1)
        {
            int headValue = PWithPosition[head].value;
            int tailValue = PWithPosition[tail].value;

            if (tailValue > C)
            {
                tail--;
                head=0;
                continue;
            }
            int sum = headValue + tailValue;
            if( sum > C )
            {
                tail--;
                head=0;
            }
            else if( sum == C)
                break;
            else if ( sum < C)
                head++;
        }
        if (PWithPosition[head].position < PWithPosition[tail].position)
            ofs<< "Case #" << i+1 << ": " << PWithPosition[head].position+1 << " " << PWithPosition[tail].position+1 << endl;
        else
            ofs<< "Case #" << i+1 << ": " << PWithPosition[tail].position+1 << " " << PWithPosition[head].position+1 << endl;

    }


    cout << "first line of the file is " << str << ".\n";

    return 0;
}

