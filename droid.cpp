/* 
   Author: Zakaria Almatar
   Date: 11/11/09
   Class: CS202
   Assignment: Program#2
*/
/*
   File name: droid.cpp
   Functions: This file has functions definitions of:
              class droid:
                 -Constructor 
                 -Destructor
                 -turn on or off: turns the device on/off
                 -take a pic: adds a pic to the pic gallary
                 -pic gallary: search or remove a pic
                 -call: makes a call (not implemented)
                 -p_music: plays music (not implemented)
                 -msgs: controls messages (not implemented)
*/

#include <cstdlib>
#include <iostream>
#include "droid.h"
#include "hash_table.h"
#include <windows.h>
using namespace std;

/*************************************************************************
***                            Constructor                             ***
*************************************************************************/
//initializes main pointers and set heads to NULL
droid::droid()
{
  pics = new pics_table;
}

/*************************************************************************
***                            Destructor                              ***
*************************************************************************/
//deallocates dynamic memory 
droid::~droid()
{
  delete pics;               
}

/*************************************************************************
***                          Turn On or Off                            ***
*************************************************************************/
//If device is on, it turns it off
//If device is off, it turns it on
//always returns 1
int droid::turn_on_or_off()
{
  cout<<"\n** Press the Droid on/off button then hit enter. **\n";
  cin.get();

  if(!status)   //if device is off
  {
    cout<<"Loading.";      //this is just for fun 
    for(int i=0;i<10;++i)
    {
      cout<<".";
      cout.flush();
      Sleep(500);
    }
    cout<<endl<<endl;
    status = 1;
    //welcoming the user
    cout<<"*************************\n";
    cout<<"* Welcome! Droid is on. *\n";
    cout<<"*************************\n";
  }
  else  //if device is on
  {
    cin.ignore();
    cout<<"Exiting.";    //this is just for fun
    for(int i=0;i<10;++i)
    {
      cout<<".";
      cout.flush();
      Sleep(500);

    }
    cout<<endl;
    status = 0;

    cout<<"**************************\n";
    cout<<"* Goodbye! Droid is off. *\n";
    cout<<"**************************\n";
  }
  return 1;
}


/*************************************************************************
***                            Take a pic                              ***
*************************************************************************/
//adds a picture to droid's pics gallary
//returns 1 for success, 0 for failure
int droid::take_pic()
{
  char title[31];       //title of the pic
  char descrp[251];     //description of the pic

  cin.ignore(10,'\n');
  cout<<"\nEnter picture's title: ";    //get title
  cin.get(title,30);
  cin.ignore();
  
  cout<<"\nEnter picture's description: ";   //get description
  cin.get(descrp,250);
  cin.ignore();

  cout<<"\n    *** Smile and hit enter when ready.***\n";
  cin.get();
  
  if(pics->store(title, descrp))   //adding pic into a hash table
  {
    cout<<"\nPicture has been taken and added to your Droid's gallary successfully\n";
    return 1;
  }
  else
  {
    cout<<"\n No picture was taken.\n";
    return 0;
  }
}

/*************************************************************************
***                        Pictures Gallary                            ***
*************************************************************************/
//allows the user to search or remove a pic from gallary
//loops until the user wants to go back. always returns 1;
int droid::pic_gallary()
{
  int choice;        //holds user's choice
  char title[31];    //picture's title
  
  cin.ignore(10,'\n');
  cout<<"    ** Welcome to Droid's picture gallary! **\n";


  do
  {
    cout<<"\nWhat would you like to do?\n";
    cout<<"   1- Search for a picture\n";
    cout<<"   2- Remove a picture\n";
    cout<<"   0- Go back\n";              
    cin>>choice;    //getting choice
    cin.ignore();   
  
    if(choice == 1)   //search
    {
      picture *temp;

      cout<<"\nEnter picture's title: ";
      cin.get(title,30);
      cin.ignore();   
      
      if(!(temp = pics->retrieve(title)))  //check result
        cout<<"No matches were found.\n";
      else
      {  //desplay results
        cout<<"\nSearch resulf for \""<<title<<"\":"<<endl;
        cout<<"Title: "<<temp->title<<endl;
        cout<<"Description: "<<temp->descrp<<endl<<endl<<endl;
        cout<<"Hit enter to go back. ";
        cin.get();

        delete [] temp->title;   //deallocate temp memory
        delete [] temp->descrp;
        delete [] temp;
        temp =NULL;
      }
    }
    else if(choice == 2)   //remove
    {
      cout<<"\nEnter picture's title: ";
      cin.get(title,30);      //get title
      cin.ignore();   
   
      if(pics->remove(title))   //check remove result
        cout<<"\nPicture removal from Droid's gallary was successful.\n";
      else
        cout<<"\nRemoval failed. \n";
       
      cout<<"Hit enter to go back. ";
      cin.get();
    }
    else
      break;
  }while(1);

  return 1;
}

/*************************************************************************
***                              Call                                  ***
*************************************************************************/
//Not implemented
int droid::call()
{
  cin.ignore(10,'\n');
  cout<<"\nDroid: The \"Make a call\" function is not implemented yet.\n";
  cout<<"       Hit enter to go back. ";
  cin.get();
  return 0;
}

/*************************************************************************
***                            Play music                              ***
*************************************************************************/
//Not implemented
int droid::p_music()
{
  cin.ignore(10,'\n');
  cout<<"\nDroid: The \"Play music\" function is not implemented yet.\n";
  cout<<"       Hit enter to go back. ";
  cin.get();
  return 0;
}

/*************************************************************************
***                          Check messages                            ***
*************************************************************************/
// Not implemented
int droid::msgs()
{
  cin.ignore(10,'\n');
  cout<<"\nDroid: The \"Messages\" function is not implemented yet.\n";
  cout<<"       Hit enter to go back. ";
  cin.get();
  return 0;
}
