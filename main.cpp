#include <iostream>
#include "common/consoletools.h"
#include "Task1/adventure.h"

using namespace std;

int main(int argc, char *argv[]) {
    if ( argc > 1 ) {
        // TODO
    } else {
        ConsoleTools::printBox("Grundlagen der C++ Programmierung", '*');
        cout << "Choose Task to execute" << endl;
        // TODO: loop folders and get all existing tasks
        cout << "0 - Task 1: Adventure" << endl;
        int option = -1;
        cin >> option;
        switch ( option ) {
            case 0: {
                Adventure task1;
                task1.Start();
            }
        }
    }
    return 0;
}

