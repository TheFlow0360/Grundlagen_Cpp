#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "common/consoletools.h"
#include "Task1/adventure.h"
#include "Task2/scopedemo.h"
#include "Task3/dynlistdemo.h"
#include "Task4/program.h"

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if ( argc > 1 ) {
        // TODO start task given by parameter
    } else {
        ConsoleTools::printBox("Basics of C++ Programming");

        string option = "";
        bool decisionValid = false;
        while ( !decisionValid ) {
            cout << "Choose action..." << endl;
            cout << "0 - Task 1: Adventure" << endl;
            cout << "1 - Task 2: Scope Time Measurement" << endl;
            cout << "2 - Task 3: Dynamic Object List" << endl;
            cout << "3 - Task 4: Fixed random code" << endl;
            cout << "X - Exit" << endl << endl;
            cin >> option;
            if ( option == "0" ) {
                decisionValid = true;
                Adventure task1;
                task1.start();
            } else if ( option == "1" ) {
                decisionValid = true;
                ScopeDemo task2;
                task2.start();
            } else if ( option == "2" ) {
                decisionValid = true;
                DynListDemo task3;
                task3.start();
            } else if ( option == "3" ) {
                decisionValid = true;
                Task4 task4;
                task4.start();
            } else if ( ( option == "x" ) || ( option == "X" ) ) {
                break;
            } else {
                cout << "Invalid input - Try again" << endl;
            }
        }
    }
    return 0;
}

