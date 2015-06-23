#ifndef ADVENTURE_H
#define ADVENTURE_H

#include <list>
#include "../common/taskbase.h"
#include "room.h"

class Adventure : public TaskBase
{
private:
    std::list<Room> fRooms;
    void loadRooms();
    Room getRoom(unsigned int const aId);
public:
    Adventure();
    void start();
};

#endif // ADVENTURE_H
