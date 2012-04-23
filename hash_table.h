/* 
   Author: Zakaria Almatar
   Date: 11/11/09
   Class: CS202
   Assignment: Program#1
*/
/*
   File name: hash_table.h
   Contains: This file has prototypes of the hash table class: 
            -Struct picture: represents a picture
            -Class pics_table: represents a gallary (table) of pictures. 
*/
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;


struct picture  //structure which holds information of a picture
{
  char *title, *descrp;   //title and description pointers
  picture *next;
};       

class pics_table
{
  public:
    pics_table();     //initialize main pointers and set head to NULL
    ~pics_table();    //deallocates dynamic memory
    int store(char*title, char*descrp); //stores a pic's info
    picture *retrieve(char *title);     //looks for a pic 
    int remove(char *title);            //removes a pic

  private:
    //copies data to a node;
    void assign_data(picture *&ptr, char*title, char*descrp); 
    int hash(char *title);  // hashbox
    picture **pictures;     //pointer to hash table
    int NAME_MAX;           //prime number
};






