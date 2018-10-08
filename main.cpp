// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Individual
// source:  Problem 12 on page 503 from Problem Solving with C++, ninth edition.
// Purpose: string splitter
// Author: Salma Essam Soliman          ID: 20170115
// Version: 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//It splits the input according to the delimiter putting the target in an index of a new vector.
vector <string> split (string target, string delimiter);

int main()
{
    string target = "", delimiter = "", newIndex = "";
    int check = 0;

    while (check == 0)
    {
        cout << "Enter your string:\n>> ";
        getline(cin, target);

        cout << "Enter your delimiter:\n>> ";
        getline(cin, delimiter);
        target += delimiter;

        for (int i = 0; i < target.length() - 1; i++)
        {
            newIndex = target[i];
            if (newIndex == delimiter)
            {
                check = 1;
            }
        }
    }
    vector <string> newTarget = split(target, delimiter);

    for (int i = 0; i < newTarget.size(); i++)
    {
        cout << '\"' << newTarget[i] << '\"' << " ";
    }

    return 0;
}

vector <string> split (string target, string delimiter)
{
    vector <string> newTarget;
    string newIndex, newStr = "";
    for (int i = 0; i < target.length(); i++)
    {
        newIndex = target[i];
        if (newIndex == delimiter)
        {
            continue;
        }
        else
        {
            while (newIndex != delimiter)
            {
                newStr += newIndex;
                i++;
                newIndex = target[i];
            }
            newTarget.push_back(newStr);
            newStr = "";
        }
    }

    return newTarget;
}
