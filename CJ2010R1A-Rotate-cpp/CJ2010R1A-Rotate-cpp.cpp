// CJ2010R1A-Rotate-cpp.cpp : Defines the entry point for the console application.
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
    //string filename = "\\input\\A-large-practice.in";
    //string filename = "\\input\\A-small-practice.in";
    string filename = "\\input\\SampleInput.in";
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

void printBoard(vector<vector<char>> b)
{
    for (size_t i = 0; i < b.size(); i++)
    {
        for (size_t j = 0; j < b.size(); j++)
        {
            cout<< b[i][j] << " ";
        }
        cout<<endl;
    }
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
        string output;
        vector<int> NAndK = ReadLineValues<int>(ifs, 2);
        int N = NAndK[0];
        int K = NAndK[1];

        vector<vector<char>> b(N, vector<char>(N)); 
        for (int i = 0; i < N; i++)//Read Board
        {
            vector<string> v = ReadLineString(ifs);
            string row = v[0];
            for (int j = 0; j < N; j++)//Read into b from the string
            {
                b[i][j] = row[j];
            }
        }
        printBoard(b);

        bool nonDotRow = false;
        //Rotate & gravity operation
        for (int i = 0; i < N; i++)//all rows
        {
            int head;
            int tail = N-1;
            for (int j = N - 1; j >= 0 ; j--)
            {
                head = j;
                if (b[i][head] != '.')
                {
                    swap(b[i][head], b[i][tail]);
                    tail--; 
                }
            }
        }

        cout<<endl;
        printBoard(b);
        //Find if 

        ofs << "Case #" << t + 1 << ": " << output << endl;
    }
    return 0;
}

