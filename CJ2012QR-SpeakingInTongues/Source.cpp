#include <string>
#include <direct.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

#include <iostream>

using namespace std;

#define ull unsigned long long

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
    string filename = "\\input\\A-small-practice.in";
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


int main(int argc, char* argv[])
{
    ifstream ifs(GetFullInputfilePath());
    if (!ifs.is_open())
        return EXIT_FAILURE;

    ofstream ofs("output.txt");

    //T Cases
    int T = ReadLineValue<int>(ifs);
    map<char, char> dict;
    dict[' '] = ' ';
    dict['a'] = 'y';
    dict['b'] = 'h';
    dict['c'] = 'e';
    dict['d'] = 's';
    dict['e'] = 'o';
    dict['f'] = 'c';
    dict['g'] = 'v';
    dict['h'] = 'x';
    dict['i'] = 'd';
    dict['j'] = 'u';
    dict['k'] = 'i';
    dict['l'] = 'g';
    dict['m'] = 'l';
    dict['n'] = 'b';
    dict['o'] = 'k';
    dict['p'] = 'r';
    dict['q'] = 'z';
    dict['r'] = 't';
    dict['s'] = 'n';
    dict['t'] = 'w';
    dict['u'] = 'j';
    dict['v'] = 'p';
    dict['w'] = 'f';
    dict['x'] = 'm';
    dict['y'] = 'a';
    dict['z'] = 'q';

    for (int t = 0; t < T; t++)
    {
        string output = "";
        vector<string> input = ReadLineString(ifs);
        string s;
        for_each(input.begin(), input.end(), [&](string i)
        {
            s = s + " " + i;
        });

        for (int i = 0; i < s.length(); i++)
        {
            output += dict[s[i]];
        }

        ofs << "Case #" << t + 1 << ": " << output << endl;
    }
    return 0;
}
