/*program to implement string from the user that connsists of '+' symbol */
#include <iostream>
#include "lab7.4.h"  // Including the stack header file
using namespace std;

// Function to process the input string using StackSLL
string processString(string input) {
    StackSLL s;
    
    for (char ch : input) {
        if (ch == '+') {
            if (!s.isEmpty()) {
                s.Pop();  // Remove the immediate left character
            }
        } else {
            s.Push(ch);  // Push non-'+' characters onto the stack
        }
    }

    // Construct the final string from the stack
    string result = "";
    while (!s.isEmpty()) {
        result = s.Pop() + result;  // Pop elements in reverse order
    }
    
    return result;
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;
    
    string output = processString(input);
    cout << "Processed Output: " << output << endl;
    
    return 0;
}
