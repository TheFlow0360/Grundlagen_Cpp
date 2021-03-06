#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "common/consoletools.h"
#include "Task01/adventure.h"
#include "Task02/scopedemo.h"
#include "Task03/dynlistdemo.h"
#include "Task04/program.h"
#include "Task05/program.h"
#include "Task06/program.h"
#include "Task07/main.h"
#include "Task08/program.h"
#include "Task09/program.h"
#include "Task10/program.h"
#include "Task11/main.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {

    srand(time(NULL));
    if ( argc > 1 ) {
        // TODO start task given by parameter
    } else {
        ConsoleTools::printBox("Basics of C++ Programming");

        string option = "";
        bool decisionValid = false;
        while ( !decisionValid ) {
            cout << "Choose action..." << endl;
            cout << " 0 - Task 1: Adventure" << endl;
            cout << " 1 - Task 2: Scope Time Measurement" << endl;
            cout << " 2 - Task 3: Dynamic Object List" << endl;
            cout << " 3 - Task 4: Fixed random code" << endl;
            cout << " 4 - Task 5: Extended Dynamic Object List" << endl;
            cout << " 5 - Task 6: Expression Tree" << endl;
            cout << " 6 - Task 7: Own Vector implementation" << endl;
            cout << " 7 - Task 8: EPIC STAR WARS BATTLE END GAME FANTASY" << endl;
            cout << " 8 - Task 9: Logger" << endl;
            cout << " 9 - Task 10: Hybrid Array" << endl;
            cout << "10 - Task 11: Abstract Factory" << endl;
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
                Task3::DynListDemo task3;
                task3.start();
            } else if ( option == "3" ) {
                decisionValid = true;
                Task4::Program task4;
                task4.start();
            } else if ( option == "4" ) {
                decisionValid = true;
                Task5::Program task5;
                task5.start();
            } else if ( option == "5" ) {
                decisionValid = true;
                Task6::Program task6;
                task6.start();
            } else if ( option == "6" ) {
                decisionValid = true;
                Task7::VectorDemo task7;
                task7.start();
            } else if ( option == "7" ) {
                decisionValid = true;
                Task8::Program task8;
                task8.start();
            } else if ( option == "8" ) {
                decisionValid = true;
                Task9::Program task9;
                task9.start();
            } else if ( option == "9" ) {
                decisionValid = true;
                Task10::Program task10;
                task10.start();
            } else if ( option == "10" ) {
                decisionValid = true;
                Task11::AbstractFleetFactory task11;
                task11.start();
            } else if ( ( option == "x" ) || ( option == "X" ) ) {
                break;
            } else {
                cout << "Invalid input - Try again" << endl;
            }
        }
    }
    return 0;

    } catch(const std::exception&) {
#ifndef DEBUG
        cout << "The program encountered an error and will now be terminated. View the logfile for further information.";
#endif
        return EXIT_FAILURE;
    }

}

