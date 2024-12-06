#include <iostream>
#include <fstream>
#include <vector>
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

int main()
{
    vector<long> va, vb;
    readInput(va, vb);

    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());

    cout << distance(va, vb) << endl;
}

