#include "room.h"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <list>

using namespace std;

Room::Room(const string aText)
{
    this->fId = 0;
    while ( this->fId == 0)
        this->fId = abs( rand() );
    this->fText = aText;
    this->fOptions.clear();
}

unsigned Room::getId()
{
    return this->fId;
}

void Room::addOption(string const aOption, string const aValue, int aTargetRoom)
{
    RoomOption opt;
    opt.id = aTargetRoom;
    opt.option = aOption;
    opt.value = aValue;
    opt.text = "";
    opt.isEnd = false;
    opt.isBadEnd = false;

    this->fOptions.push_back(opt);
}

void Room::addOption(string const aOption, string const aValue, string const aText)
{
    RoomOption opt;
    opt.id = this->fId;
    opt.option = aOption;
    opt.value = aValue;
    opt.text = aText;
    opt.isEnd = false;
    opt.isBadEnd = false;

    this->fOptions.push_back(opt);
}

void Room::addEnd(string const aOption, string const aValue, string const aText, bool aBadEnd)
{
    RoomOption opt;
    opt.id = 0;
    opt.option = aOption;
    opt.value = aValue;
    opt.text = aText;
    opt.isEnd = true;
    opt.isBadEnd = aBadEnd;

    this->fOptions.push_back(opt);
}

int Room::roomExec()
{
    cout << this->fText << endl << endl;

    bool validChoice = false;
    while ( !validChoice ) {
        cout << "Choose your action..." << endl;
        list<RoomOption>::iterator itr;
        for( itr = this->fOptions.begin(); itr != this->fOptions.end(); ++itr ) {
           cout << (*itr).option << endl;
        }
        cout << endl;

        string opt;
        cin >> opt;
        //std::transform(opt.begin(), opt.end(), opt.begin(), tolower);

        for( itr = this->fOptions.begin(); itr != this->fOptions.end(); ++itr ) {
            if ( opt ==  (*itr).value ) {
                validChoice = true;
                if ( (*itr).text.size() > 0 ) {
                    cout << endl << (*itr).text << endl << endl;
                }
                if ( (*itr).isEnd ) {
                    if ( (*itr).isBadEnd ) {
                        return -1;
                    } else {
                        return 0;
                    }
                } else {
                    return (*itr).id;
                }
            }
        }
        cout << "Invalid input - Try again" << endl << endl;
    }
}
