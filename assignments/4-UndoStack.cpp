/*
Lab Assignment - Undo Stack

This program demonstrates the use of a C++ stack to create
a basic undo system.
*** IDE -> Visual Studio 2026 ***

Key features:
- Stores user actions in a stack
- Handle quit and undo request
- Displays the remaining actions in their original order
- Perserve users stack
- Helper function to copy stack and output actions in order

Note:
This program was modified from the Java starter program to conform to C++ language.
(No input validation, No error handling)

Created by:
- Adam Huynh
- CS 236 Fall Semester LAVC
- 10/15/2026

GitHub repo:
- https://github.com/daTaHere/lavc-cs236--adv-data-structs

*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// prototype
void printStack(stack<string> s);

int main() {
    // instantiate stack
    stack<string> actions;
    string userInput;

    cout << "Enter action (or 'undo' or 'quit'):" << endl;

    while (true) {
        // processe input
        getline(cin >> ws, userInput);

        // end program
        if (userInput == "quit")
            break;

        if (userInput == "undo") {
            // guard aginst empty stack
            if (!actions.empty()) {
                actions.pop();
                cout << "Undo performed" << endl;
            }
        }
        else
            // add to top of stack
            actions.push(userInput);

        // output actions
        printStack(actions);

        cout << "Enter action:" << endl;
    }

    return 0;
}

// function def
void printStack(stack<string> s) {
    // instantiate temp stack
    stack<string> reversedStack;

    // copy element in reverse order
    while (!s.empty()) {
        reversedStack.push(s.top());
        s.pop();
    }

    // output elements in correct order
    cout << "Current actions: [";
    while (!reversedStack.empty()) {
        cout << reversedStack.top();
        reversedStack.pop();
        if (!reversedStack.empty()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
