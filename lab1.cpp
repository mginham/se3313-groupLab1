#include <iostream>
#include <vector>
#include <unistd.h>
#include <fstream>
#include <signal.h>

using namespace std;

int main() {
    // Declare and initialize variables
    string userData = "";
    vector<int> children; // Using a vector array so that the array can resize itself as elements are added/removed
    int parentID = -1;
    int currentID = -1;
    
    // Retrieve the parent process PID
    parentID = getpid();

    // Welcome the user
    cout << "\nWelcome" << endl;

    // Continue the loop until the user enters "Done"
    while(userData != "Done") {
        // Prompt the user for input
        cout << "\nPlease enter a word (or type 'Done' to exit): ";
        getline(cin, userData);

        // Fork the process and insert the input into the child array
        children.push_back(fork());

        // Get current process PID
        currentID = getpid();

        if(currentID != parentID) { // if the current process is a child process, create a new file
            string fileName = "";

            // Create a unique file name for each child
            fileName = "child" + to_string(currentID) + ".txt";

            // Create the child file
            ofstream outFile(fileName);

            // Keeps writing to the file every 1 second
            while(true) {
                outFile << userData << endl; // Writes to the file
                outFile.flush(); // Ensures that all the data has been written to the output and clears any data that has been buffered
                sleep(1); // Suspends the process for 1 second
            }
        }
    }

    // Terminate all child processes
    for(vector<int>::iterator i = children.begin(); i != children.end(); i++) {
        kill(*i, SIGKILL);
    }

    // Inform the user that the program is ending
    cout << "\nThe processes have been terminated" << endl;

    return 0;
} // end main