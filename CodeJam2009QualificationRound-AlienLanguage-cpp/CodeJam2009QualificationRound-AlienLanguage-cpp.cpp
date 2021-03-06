// CodeJam2009QualificationRound-AlienLanguage-cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <direct.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <regex>

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
    string filename =  "\\input\\A-large-practice.in"; //"\\input\\SimpleData.in";
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

    vector<int> firstLine = ReadLineValues<int>(ifs, 3);
    int L = firstLine[0];
    int D = firstLine[1];
    int N = firstLine[2];
    vector<string> words;

    //read D
    for (int i = 0; i < D; i++)
    {
        vector<string> word = ReadLineString(ifs);
        words.push_back(word[0]);
    }

    //N cases
    for (int i = 0; i < N; i++)
    {
        int match = 0;
        vector<string> patternVector = ReadLineString(ifs);
        string pattern = patternVector[0];

        replace(pattern.begin(), pattern.end(), '(', '[');
        replace(pattern.begin(), pattern.end(), ')', ']');
        regex e(pattern);

        for(int j = 0; j < D; j++)
        {
            if(regex_match(words[j], e))
                match++;
        }
        ofs << "Case #" << i + 1 << ": " << match << endl;
    }

    return 0;
}

