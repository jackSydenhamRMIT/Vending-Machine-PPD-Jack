// #include <iostream>
// #include 
#include <sstream>
#include "Display.h"

void Display::show_menu()
{
    std::stringstream s;
    s<<"Main Menu:\n"
    <<"\t1.Display Items\n"
    <<"\t2.Purchase Items\n"
    <<"\t3.Save and Exit\n"
    <<"Administrator-Only Menu:\n"
    <<"\t4.Add Item\n"
    <<"\t5.Remove Item\n"
    <<"\t6.Display Coins\n"
    <<"\t7.Reset Stock\n"
    <<"\t8.Reset Coins\n"
    <<"\t9.Abort Program\n"
    <<"\tSelect your option (1-9):";

   write_or_show(s.str());
}

void Display::write_or_show(std::string s)
{
    if(!fl)
    {
        f.open(path,std::ios::out|std::ios::app);
        f<<s<<std::endl;
        f.close();
    }
    else
        std::cout<<s;
}

void Display::show_help()
{
    return;
}