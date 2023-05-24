// #include <iostream>
#include "Display.h"
void Display::show_menu()
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
    <<"\tSelect your option (1-10): ";


}

void Display::show_help()
{
    return;
}