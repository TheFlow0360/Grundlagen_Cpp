#include <iostream>
#include "common/consoletools.h"
#include "Task1/adventure.h"

using namespace std;

int main(int argc, char *argv[]) {
    if ( argc > 1 ) {
        // TODO
    } else {
        ConsoleTools::printBox("Basics of C++ Programming");

        string option = "";
        bool decisionValid = false;
        while ( !decisionValid ) {
            cout << "Choose action..." << endl;
            // TODO: loop folders and get all existing tasks
            cout << "0 - Task 1: Adventure" << endl;
            cout << "X - Exit" << endl << endl;
            cin >> option;
            if ( option == "0" ) {
                    decisionValid = true;
                    Adventure task1;
                    task1.Start();
            } else if ( ( option == "x" ) || ( option == "X" ) ) {
                break;
            } else {
                cout << "Invalid input - Try again" << endl;
            }
        }
    }
    return 0;
}

