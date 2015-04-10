#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <list>

class Room
{
private:

    struct RoomOption {
        unsigned int id;
        std::string option;
        std::string value;
        std::string text;
        bool isEnd;
        bool isBadEnd;
    };

    std::list<RoomOption> fOptions;
    int fId;
    std::string fText;
public:
    Room(std::string const aText);

    unsigned int getId();
    void addOption(std::string const aOption, std::string const aValue, int aTargetRoom);
    void addOption(std::string const aOption, std::string const aValue,std::string const  aText);
    void addEnd(std::string const aOption, std::string const aValue, std::string const aText, bool aBadEnd = false);

    int roomExec();
};

#endif // ROOM_H
