/* 
   Author: Zakaria Almatar
   Date: 11/11/09
   Class: CS202
   Assignment: Program#2
*/
/*
   File name: hash_table.cpp
   Functions: This file has functions definitions of:
              class pics_table:
                 -Constructor 
                 -Destructor
                 -store: adds a picture
                 -retreive: checks a picture
                 -removes: removes a picture
                 -hash: the hashbox function
                 -assign data: copies picture's info to a node
*/
#include <cstdlib>
#include <string.h>
#include <iostream>
#include "hash_table.h"
using namespace std;




/*************************************************************************
***                            Constructor                             ***
*************************************************************************/
//initializes main pointers and set heads to NULL

pics_table::pics_table()
{
  NAME_MAX=71;   //hash table will have 71 head pointers

  //initializing main pointers and setting heads to NULL
  pictures = new picture*[NAME_MAX];
  for(int i=0;i<NAME_MAX;++i)
    pictures[i]=NULL;
}


/*************************************************************************
***                            Destructor                              ***
*************************************************************************/
//deallocates dynamic memory 

pics_table::~pics_table()
{
  picture *temp;  //temporary pointer

  //deallocating dynamic memory in the hash table    
  for(int i=0;i<NAME_MAX;++i)
  {
    while(pictures[i])
    {
      temp = pictures[i];
      pictures[i]=pictures[i]->next;
      delete temp;
    }
  } 
  
  delete [] pictures;
}

/*************************************************************************
***                             Hash by name                           ***
*************************************************************************/
//takes a name and returns an array index
//it adds the curresponding numbers of the first and last two letters of
//the name and returns the remainder of the sum divided by the prime number

int pics_table::hash(char *title)
{
  int i[4];
  int index;

  //taking first and last two letters
  i[0]=title[0];
  i[1]=title[1];
  i[2]=title[strlen(title)-1];
  i[3]=title[strlen(title)-2];

  index=(i[0]+i[1]+i[2]+i[3]) % NAME_MAX;  //adding and dividing

  //returning result
  if (index<NAME_MAX && index >=0)
    return index;
  else
    return -1;
}


/*************************************************************************
***                         Assign Data                                ***
*************************************************************************/
// Copys a pic's information into a node

void pics_table::assign_data(picture *&ptr, char*title, char*descrp)
{
  ptr->title = new char[strlen(title)+1];
  ptr->descrp = new char[strlen(descrp)+1];

  strcpy(ptr->title, title);
  strcpy(ptr->descrp, descrp);
}

/*************************************************************************
***                              Store                                 ***
*************************************************************************/
//stores a pic's info into the hash table

int pics_table::store(char*title, char*descrp)
{
  int index;
  picture *cur;

  index = hash(title); //get index

  if(index==-1)
    return 0;
  else
  {
    if(pictures[index]==NULL)  //if head[index] is null give it a node
    {
      pictures[index] = new picture;
      assign_data(pictures[index], title, descrp);
      pictures[index]->next = NULL;
    }
    else  //if not add node to end of the chain
    {
      cur = pictures[index];
      while(cur->next)
        cur = cur->next;
      cur->next = new picture;
      cur = cur->next;
      assign_data(cur, title, descrp);
      cur->next = NULL;
    }
    return 1;
  }
}

/*************************************************************************
***                        Retrieve by name                            ***
*************************************************************************/
//returns a pointer to the target picture

picture *pics_table::retrieve(char *title)
{
  int index;
  picture *temp, *cur2;
  picture *head2 =NULL;

  index = hash(title);  //get index
  if (index ==-1)
    return NULL;
  else
  {
    if(pictures[index]==NULL)   //if empty return failure
      return NULL;
    else
    {  //copy all pics with the same title
      temp = pictures[index];
      while(temp)
      {
        if(strcmp(temp->title, title)==0)
        {
          if(!head2)
          {
            head2 = new picture;
            assign_data(head2, temp->title, temp->descrp);
            head2->next = NULL;
            cur2 = head2;
          }            
          else
          {
            cur2->next = new picture;
            cur2 = cur2->next;
            assign_data(cur2, temp->title, temp->descrp);
            cur2->next=NULL;
          }
        }
        temp = temp->next;
      }
      return head2; //return head to the new LLL
    }
  }
}


/*************************************************************************
***                               ReMove                               ***
*************************************************************************/
//takes a date and removes all calls made on that date

int pics_table::remove(char *title)
{
  int index;
  picture *temp;
  
  index = hash(title); //get index
   
  if(index == -1)
    return 0;
  else
  {
    if(pictures[index]==NULL)  //if empty returns failure
      return 0;
    else
    {  //deallocating memory
      while(pictures[index])
      {
        if(!strcmp(pictures[index]->title, title))
        {
          temp = pictures[index];
          pictures[index] = pictures[index]->next;

          delete [] temp->title;
          delete [] temp->descrp;
          delete temp;
        }
      }
      return 1;   //returns success     
    }
  } 
}

