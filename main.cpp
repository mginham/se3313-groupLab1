#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
    // Define variables
    string userData = "user";

    // Prompt the user to imput their name and print it in a hello
    cout << "Please enter your name: ";
    cin >> userData;
    cout << "\nHello " << userData << endl;

    // Fork the process into a parent and a child
    fork();

    // Prompt the user to terminate the process
    cout << "\nPlease enter 'Done' to terminate this process: ";
    cin >> userData;

    cout << "\nGoodbye" << endl;

    return 0;
} // end Main