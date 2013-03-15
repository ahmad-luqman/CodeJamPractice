// CodeJam2008Round1A-MinimumScalarProduct.cpp : Defines the entry point for the console application.
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

long long scalar_product(vector<long long> a, vector<long long> b)
{
    long long product = 0;
    for (int i = 0; i <= a.size()-1; i++)
        product = product + (a[i])*(b[i]);
    return product;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifs(GetFullInputfilePath());
    if (!ifs.is_open())
        return EXIT_FAILURE;

    ofstream ofs("output.txt");

    int T = ReadLineValue<int>(ifs);

    for (int i = 0; i < T; i++)
    {
        int n = ReadLineValue<int>(ifs);
        vector<long long> v1 = ReadLineValues<long long>(ifs, n);
        vector<long long> v2 = ReadLineValues<long long>(ifs, n);

        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());

        long long p = scalar_product(v1, v2);

        ofs << "Case #" << i + 1 << ": " << p << endl;
    }

    return 0;
}

