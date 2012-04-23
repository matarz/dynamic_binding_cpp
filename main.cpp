#include <cstdlib>
#include <iostream>
#include "droid.h"
#include "iphone.h"
#include "n73.h"
using namespace std;


int menu();

int main()
{
  device_ABC * i;
  droid droid_1;
  iphone iphone_1;
  n73 n73_1;

  int choice;
  char answer;
  int j;
   
  do
  {  
    cout<<"\nWelcome! Please choose a device:\n";
    cout<<"   1- Motorola Droid\n";
    cout<<"   2- iPhone\n";
    cout<<"   3- Nokia N73\n";
    cout<<"   0- Quit\n";

    cin>>choice;
  
    if(choice == 1)
      i = &droid_1;
    else if (choice == 2)
      i = &iphone_1;
    else if (choice == 3)
      i = &n73_1;
    else
      return 0;

    if(!i->check_status())
    {
      cout<<"\nThis device is turned off. Would you like to turn it on (Y/N)? ";                      
      cin>>answer;
      cin.ignore();
      if(answer == 'Y' || answer == 'y')
        i->turn_on_or_off();
    }

    if(i->check_status())
    {
      do
      {
        choice = menu(); 

        if(choice == 1)
           i->take_pic();
        else if(choice == 2)
           i->pic_gallary();
        else if(choice == 3)
           i->call();
        else if(choice == 4)
           i->p_music();
        else if(choice == 5)
           i->msgs();
        else if(choice == 6)
        {
           i->turn_on_or_off();
           break;
        }
        else
          break;
      }while(1);
    }  
  }while(1);

   
  system("PAUSE");
  return 0;
}


int menu()
{
  int choice;

  cout<<"\nWhat would you like to do?\n";
  cout<<"   1- Take a picture\n";
  cout<<"   2- Show picture gallary\n";
  cout<<"   3- Make a call\n";
  cout<<"   4- Play music\n";
  cout<<"   5- Messages\n";
  cout<<"   6- Turn off\n";
  cout<<"   0- Go back\n";              

  cin>>choice;   

  return choice;
}
