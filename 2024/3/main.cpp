#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

long scanMul(string line)
{
    long res = 0;
    regex pattern {R"(mul\((\d+),(\d+)\))"};
    smatch matches;
    while (regex_search(line, matches, pattern))
    {
        res += stol(matches[1]) * stol(matches[2]);
        cout << matches[0] << " -> ";        
        cout << matches[1] << "*" << matches[2] << " = " << res << endl;

        string sub = matches[0];
        int pos = line.find(sub);
        line = line.substr(pos + sub.size(), line.size());
    }
    return res;
}

long processInput()
{
    long res = 0;
    ifstream inputFile;
    string line;

    inputFile.open("input.txt");
    
    while(getline(inputFile, line))
    {
        cout << "processing line: " << line << endl;
        res += scanMul(line);
    }

    inputFile.close();
    return res;
}

int main()
{
    long result = processInput();
    cout << result << endl;
    return 0;
}