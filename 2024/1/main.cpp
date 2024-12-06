#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


void parse(string line, vector<long> &va, vector<long> &vb)
{
    int pos = line.find(" ");
    string ta = line.substr(0, pos);
    string tb = line.substr(pos + 1);

    long a = stol(ta);
    long b = stol(tb);

    va.push_back(a);
    vb.push_back(b);
}

void readInput(vector<long> &va, vector<long> &vb)
{
    ifstream inputFile;
    string line;

    inputFile.open("input.txt");
    
    while(getline(inputFile, line))
    {
        parse(line, va, vb);
    }

    inputFile.close();
}

long distance(vector<long> &va, vector<long> &vb)
{
    long total = 0;
    for (int i = 0; i < va.size(); i++)
    {
        long d = va[i] - vb[i];
        total += d < 0 ? -d : d;
    }
    return total;
}

void occurence(vector<long> &vec, map<long, int> &occ)
{
    for (long v : vec)
    {
        if (occ.count(v))
        {
            occ[v] = ++occ[v];
        }
        else
        {
            occ.insert(std::make_pair(v, 1));
        }
    }
}

long similarity(vector<long> &vec, map<long, int> &occ)
{
    long sim = 0;
    for (long v : vec)
    {
        if (occ.count(v))
        {
            sim += v * occ[v];
        }
    }
    return sim;
}

int main()
{
    vector<long> va, vb;
    map<long, int> bOccurence;
    readInput(va, vb);

    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());

    cout << "distance: " << distance(va, vb) << endl;

    occurence(vb, bOccurence);

    cout << "similarity: " << similarity(va, bOccurence) << endl;
}

