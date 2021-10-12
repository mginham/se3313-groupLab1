#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
    // Define variables
    string userData = "user";
    int temp = -1;
    bool exitLoop = false;

    // Receive input and fork
    do {
        // Prompt the user to imput a word and print it
        cout << "Please enter a word (or type 'Done' to exit): ";
        cin >> userData;
        cout << "\nYou entered: " << userData << endl;

        // Fork the process into a parent and a child
        fork();

        // Check if loop should exit
        temp = !userData.compare("Done"); // 1 = equal, 0 = not equal
        if (temp == 1) {exitLoop=true;} // if equal, exit loop
            else if (temp == 0) {exitLoop=false;} // if not equal, continue loop
            else { // if temp returns other, close the loop
                cout << "Something is wrong";
                exitLoop=true;
            }

    } while (exitLoop == false); // Continue the loop until user inputs "Done"

    // Notfy the user and terminate the process
    cout << "\nGoodbye" << endl;
    exit(EXIT_SUCCESS);

    return EXIT_SUCCESS;
} // end Main