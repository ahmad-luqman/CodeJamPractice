// CJ2009R1C-AllYourBase-cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <direct.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

#include <iostream>

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
        //printf( "%s \nLength: %d\n", buffer, strlen(buffer) );
        str.assign(buffer);
        free(buffer);
    }
    return str;
}

string GetFullInputfilePath()
{
    string path = GetCurrentDir();
    string filename = "\\input\\A-large-practice.in";
    //string filename = "\\input\\A-small-practice.in";
    //string filename = "\\input\\SampleInput.in";
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

vector<string> ReadLineString(ifstream &ifs)
{
    vector<string> v;
    string str;
    getline(ifs, str);

    std::istringstream oss(str);
    string word;
    while(oss >> word)
        v.push_back(word);
    return v;
}


int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifs(GetFullInputfilePath());
    if (!ifs.is_open())
        return EXIT_FAILURE;

    ofstream ofs("output.txt");

    //T Cases
    int T = ReadLineValue<int>(ifs);

    for (int t = 0; t < T; t++)
    {
        long long output = 0;
        vector<string> inputLine = ReadLineString(ifs);
        string input = inputLine[0];

        int length = input.length();

        int base = length;

        string sortedString = input;
        sort(sortedString.begin(), sortedString.end());

        char lastChar;
        for (int i = 0; i < length; i++)
        {
            if(i>0 && lastChar == sortedString[i])
                base--;
            lastChar = sortedString[i];
        }
        if (base==1)
            base=2;

        map<char, int> alienToNumberMap;

        vector<int> VinAlien;
        bool secondUnique = true;
        int alphabetNumber = 2; //Initialize with 2
        for (int i = 0; i < length; i++)
        {
            if (i==0)//First element be 1
            {
                VinAlien.push_back(1);
                alienToNumberMap[input[i]] = 1;
            }
            else if(secondUnique)//Second unique element be 0 if not 1
            {
                if(input[i]!=input[0])
                {
                    VinAlien.push_back(0);
                    alienToNumberMap[input[i]] = 0;
                    secondUnique = false;
                }
                else
                    VinAlien.push_back(1);
            }
            else
            {
                if(alienToNumberMap.count(input[i])>0)
                    VinAlien.push_back(alienToNumberMap[input[i]]);
                else
                {
                    VinAlien.push_back(alphabetNumber);
                    alienToNumberMap[input[i]] = alphabetNumber;
                    alphabetNumber++;
                }
            }
        }
        //Convert to Number
        int i = 0;
        for_each(VinAlien.rbegin(), VinAlien.rend(), [&](long long v)
        {
            output += pow<long long, long long>((long long)base,(long long)i) * (long long)v;
            i++;
        });
        //int i = 0;
        //long long pow = 1;
        //for_each(VinAlien.rbegin(), VinAlien.rend(), [&](long long v)
        //{
        //    /*long long powAnswer = pow<long long, long long>(base, i);
        //    output += powAnswer * v;*/
        //    output = pow + (long long)v;
        //    pow *= base;
        //    i++;
        //});
        ofs << "Case #" << t + 1 << ": " << output << endl;
    }
    return 0;
}

