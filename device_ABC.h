/* 
   Author: Zakaria Almatar
   Date: 11/11/09
   Class: CS202
   Assignment: Program#1
*/
/*
   File name: device_ABC.h
   Contains: Prototypes of the following classes and structures: 
            -class device_ABC: an abstarct base class for a device
*/
#ifndef DEVICE_ABC_H
#define DEVICE_ABC_H

class pics_table;
class device_ABC
{
  public:

    //constructor
    device_ABC(); 
    
    //destructor
    ~device_ABC(); 

    //turn a device on/off
    virtual int turn_on_or_off() = 0;
    
    //adds a picture
    virtual int take_pic() = 0;
    
    //search/remove a picture
    virtual int pic_gallary() = 0;

    //make a call
    virtual int call() = 0;

    //play music
    virtual int p_music() = 0;

    //display messages
    virtual int msgs() = 0;
    
    //check if device is on/off
    int check_status();

    protected:
      int status;   //1 for on. 0 for off
};

#endif
