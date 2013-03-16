// CJ2010R1C-RopeIntranet-cpp.cpp : Defines the entry point for the console application.
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

//template<class T>
class point
{
    public :
        point (int p_x,int p_y) : x(p_x),y(p_y){}

        int x;
        int y;

};

class PointPair
{
public:
    PointPair (point _p1, point _p2): p1(_p1), p2(_p2){}
    point p1;
    point p2;
};

//From http://www.smipple.net/snippet/sparkon/%5BC%2B%2B%5D%202D%20lines%20segment%20intersection%20
bool intersect(point a,point b,point c,point d)
{
    if (a.x == c.x && a.y == c.y ||
        a.x == d.x && a.y == d.y ||
        b.x == c.x && b.y == c.y ||
        b.x == d.x && b.y == d.y   )
        return false;

    int den = ((d.y-c.y)*(b.x-a.x)-(d.x-c.x)*(b.y-a.y));
    if (den == 0)
        /* The two lines are parallel */
        return false;
    int num1 = ((d.x - c.x)*(a.y-c.y) - (d.y- c.y)*(a.x-c.x));
    int num2 = ((b.x-a.x)*(a.y-c.y)-(b.y-a.y)*(a.x-c.x));
    float u1 = (float)num1/(float)den;
    float u2 = (float)num2/(float)den;
    //std::cout << u1 << ":" << u2 << std::endl;
    if (den == 0 && num1  == 0 && num2 == 0)
        /* The two lines are coincidents */
        return true;

    if (u1 <0 || u1 > 1 || u2 < 0 || u2 > 1)
        /* Lines do not collide */
        return false;
    /* Lines DO collide */
    return true;
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
        //N Wires
        int N = ReadLineValue<int>(ifs);
        vector<PointPair> pointsPair;
        for (int j = 0; j < N; j++)
        {
            vector<int> p = ReadLineValues<int>(ifs, 2);
            pointsPair.push_back(PointPair(point(0, p[0]), point(1, p[1])));
        }

        int count = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (j != k)
                {
                    if (intersect(pointsPair[j].p1, pointsPair[j].p2, pointsPair[k].p1, pointsPair[k].p2))
                        count ++;
                }
            }
        }
        ofs << "Case #" << i + 1 << ": " << count/2 << endl;
    }

    return 0;
}

