// Africa2010-ReverseWords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <direct.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

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
    string filename = "\\input\\B-large-practice.in";
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

    int N = ReadLineValue<int>(ifs);

    for (int i = 0; i < N; i++) // For N number of cases
    {
        /*string str;
        getline(ifs, str);*/
        vector<string> v = ReadLineString(ifs);
        
        ofs << "Case #" << i + 1 << ":";
        for_each(v.rbegin(), v.rend(), [&](string s)
        {
            ofs << " " << s;
        });
        ofs << endl;
    }

    return 0;
}

