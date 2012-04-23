/* 
   Author: Zakaria Almatar
   Date: 11/11/09
   Class: CS202
   Assignment: Program#2
*/
/*
   File name: device_ABC.cpp
   Functions: This file has functions definitions of:
              class device_ABC:
                 -Constructor
                 -Destructor
                 -check status: checks if device is on/off
*/

#include <cstdlib>
#include <iostream>
#include "device_ABC.h" 
using namespace std;

/*************************************************************************
***                            Constructor                             ***
*************************************************************************/
//initializes status to 0 (off)
device_ABC::device_ABC()
{
  status = 0;    //off         
}

/*************************************************************************
***                             Destructor                             ***
*************************************************************************/
//
device_ABC::~device_ABC()
{}

/*************************************************************************
***                            Check Status                            ***
*************************************************************************/
//returns device status
int device_ABC::check_status()
{
  return status;
}


