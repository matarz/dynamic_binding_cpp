/* 
   Author: Zakaria Almatar
   Date: 11/11/09
   Class: CS202
   Assignment: Program#1
*/
/*
   File name: iphone.h
   Contains: Prototypes of the following classes and structures: 
            -class iphone: represents an apple iphone device
*/

#include <cstdlib>
#include <iostream>
#include "device_ABC.h" 
using namespace std;

class pics_table;   //forward declaration

class iphone: public device_ABC
{
  public:

    //constructor: allocats memory
    iphone(); 
    
    //destructor: deallocates memory
    ~iphone(); 

    //turns device on or off
    virtual int turn_on_or_off();
    
    //adds a pic
    virtual int take_pic();

    //search for a pic or remove a pic for gallary
    virtual int pic_gallary();

    //makes a call
    virtual int call();

    //music player
    virtual int p_music();

    //messages
    virtual int msgs();

  private:
    pics_table *pics;  //pointer to a hash table
};


