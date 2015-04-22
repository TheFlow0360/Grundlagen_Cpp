#include "dynlistdemo.h"

#include <iostream>
#include "dynamicobjectlist.h"
#include "object.h"

using namespace std;

DynListDemo::DynListDemo()
{
}

void DynListDemo::start()
{
  DynamicObjectList list;

  cout << "Created object back, with the name \"" << list.createObject_back("first")->GetName() << endl;
  cout << "Created object back, with the name \"" << list.createObject_back("second")->GetName() << endl;

  cout << "The list has now " << list.getCount() << " elements and a capacity of " << list.getCapacity() << endl;

  list.reserve(10);

  cout << "Created object back, with the name \"" << list.createObject_back("blub")->GetName() << "\"" << endl;
  cout << "Created object back, with the name \"" << list.createObject_back("inner cookie")->GetName() << "\"" << endl;
  cout << "Created object back, with the name \"" << list.createObject_back("back cookie")->GetName() << "\"" << endl;


  cout << "The list has now " << list.getCount() << " elements and a capacity of " << list.getCapacity() << endl;

  // Print out entire content.
  cout << endl << "Current content:" << endl;
  for (unsigned int i = 0; i < list.getCount(); ++i)
  {
    Object* object = list.getAt(i);
    if (object == nullptr)
    {
      cout << "Object number "<< i <<" does not exist! This is unexpected!" << endl;
    }
    else
    {
      cout << "Object number " << i << " has the name " << object->GetName() << endl;
    }
  }


  // Destroy first.
  list.destroyObject(0);
  // Destroy last
  list.destroyObject(list.getCount() - 1);
  // Destroy in between
  list.destroyObject(list.getCount() / 2);
  // Destroy invalid
  list.destroyObject(list.getCount());


  cout << "The list has now " << list.getCount() << " elements and a capacity of " << list.getCapacity() << endl;


  // Get first object and print out index.
  Object* object = list.getAt(0);
  if (object == nullptr)
  {
    cout << "Object number 0 does not exist! This is unexpected!" << endl;
  }
  else
  {
    cout << "Object number 0 has the name \"" << object->GetName() << "\""<< endl;
  }

  // Get invalid
  object = list.getAt((unsigned int)(-1));
  if (object == nullptr)
  {
    cout << "Object number " << (unsigned int)(-1) << " does not exist." << endl;
  }
  else
  {
    cout << "Object number 0 has the name \"" << object->GetName() << "\"" << endl;
  }

  // Print out entire content.
  cout << endl << "Current content:" << endl;
  for (unsigned int i = 0; i < list.getCount(); ++i)
  {
    Object* object = list.getAt(i);
    if (object == nullptr)
    {
      cout << "Object number " << i << " does not exist! This is unexpected!" << endl;
    }
    else
    {
      cout << "Object number " << i << " has the name " << object->GetName() << endl;
    }
  }
}
