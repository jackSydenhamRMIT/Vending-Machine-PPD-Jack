// #include <iostream>
#include "Display.h"
#include "LinkedList.h"

void Display::show_menu(bool Help)
{
    std::cout<<"Main Menu:\n"
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
    <<"\t-- Enhancement Options --\n"
    <<"\t10.Enable/disable Coloured Text\n"
    <<"\t11.Enable/disable User Help Option\n";

    if(Help){
        std::cout<<"\t12.Help";
    }

    std::cout<<"\tSelect your option: ";


}

void Display::show_help()
{
    return;
}