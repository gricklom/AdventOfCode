#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class Dir 
{
    unknown,
    increase,
    decrease
};

vector<long> split(string text, string delim)
{
    vector<long> v;

    do
    {
        auto p = text.find(delim);
        if (p == text.npos)
        {
            v.push_back(stol(text));
            text = "";
        }
        else
        {
            v.push_back(stol(text.substr(0, p)));
            text.erase(0, p + delim.size());
        }        
    } while (!text.empty());
    

    return v;
}

bool isSafe(vector<long> numbers)
{
    cout << "isSafe: ";
    for (auto n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;

    if (numbers.size() == 1)
    {
        // just one number
        return true;
    }

    Dir d = Dir::unknown;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        long a = numbers[i];
        long b = numbers[i+1];

        long c = b - a;
        if ((c > 3) || (c < -3) || (c == 0))
        {
            return false;
        }
        if (d == Dir::unknown)
        {
            d = c < 0 ? Dir::decrease : Dir::increase;
        }
        else if (d != (c < 0 ? Dir::decrease : Dir::increase))
        {
            return false;
        }
    }

    return true;
}

bool makeSafe(vector<long> numbers)
{
    if (isSafe(numbers)) 
    {
        return true;
    }

    for (int skip = 0; skip < numbers.size(); skip++)
    {
        vector<long> vec;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (i != skip)
            {
                vec.push_back(numbers[i]);
            }
        }
        cout << "vec: ";
        for (auto v : vec)
            cout << v << " ";
        cout << endl;
        if (isSafe(vec)) 
        {
            return true;
        }
    }

    return false;
}

int processInput()
{
    int res = 0;
    ifstream inputFile;
    string line;

    inputFile.open("input.txt");
    
    while(getline(inputFile, line))
    {
        cout << "processing line: " << line << endl;
        if (makeSafe(split(line, " ")))
        {
            cout << "Safe" << endl;
            res++;
        }
        else
        {
            cout << "Unsafe" << endl;
        }
    }

    inputFile.close();
    return res;
}

int main()
{
    int safeLines = processInput();
    cout << safeLines << endl;
    return 0;
}