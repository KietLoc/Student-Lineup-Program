#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream file("LineUp.txt"); //Assign file to be used
    if (!file) 
    {
        cerr << "Error: could not open LineUp.txt" <<endl; //Error message when files can't open
        return 1;
    }

    string name;
    int count = 0;
    string first, last;

    while (file >> name) //Read names in file until the end of the file then sort names
    {
        if (count == 0) 
        {
            first = last = name;
        }
        else 
        {
            if (name < first) first = name;
            if (name > last) last = name;
        }
        ++count;
    }

    if (count == 0) //Last error check
    {
        cout << "No students found." << endl;
    }
    else //Print results
    {
        cout << "Number of students: " << count << endl;
        cout << "Front of the line: " << first << endl;
        cout << "End of the line: " << last << endl;
    }

    return 0;
}
