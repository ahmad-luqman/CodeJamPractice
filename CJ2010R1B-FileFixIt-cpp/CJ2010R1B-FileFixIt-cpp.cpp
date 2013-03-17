// CJ2010R1B-FileFixIt-cpp.cpp : Defines the entry point for the console application.
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

vector<string> ParsePossibleDirectories(string path)
{
    vector<string> directories;
    for (int i = 0; i < path.length(); i++)
    {
        if(path[i]=='/' && i!=0)
            directories.push_back(path.substr(0, i));
        if(i == path.length()-1)
            directories.push_back(path);
    }
    return directories;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifs(GetFullInputfilePath());
    if (!ifs.is_open())
        return EXIT_FAILURE;

    ofstream ofs("output.txt");

    //T Cases
    int T = ReadLineValue<int>(ifs);

    for (int i = 0; i < T; i++)
    {
        int count = 0;
        vector<int> NAndM = ReadLineValues<int>(ifs, 2);
        int N = NAndM[0];
        int M = NAndM[1];
        map<string, string> currentDirectories;

        //vector<string> N_paths;
        for (int j = 0; j < N; j++)
        {
            vector<string> pathVector = ReadLineString(ifs);
            //N_paths.push_back(pathVector[0]);

            vector<string> dirs = ParsePossibleDirectories(pathVector[0]);
            for (int k = 0; k < dirs.size(); k++)
            {
                if (currentDirectories.count(dirs[k]) < 1)
                    currentDirectories[dirs[k]]=dirs[k];
            }
        }
        //vector<string> M_paths;
        for (int j = 0; j < M; j++)
        {
            vector<string> pathVector = ReadLineString(ifs);
            //M_paths.push_back(pathVector[0]);
            vector<string> dirs = ParsePossibleDirectories(pathVector[0]);
            for (int k = 0; k < dirs.size(); k++)
            {
                if (currentDirectories.count(dirs[k]) < 1)
                {
                    currentDirectories[dirs[k]]=dirs[k];
                    count++;
                }
            }
        }
        ofs << "Case #" << i + 1 << ": " << count << endl;
    }

    return 0;
}

