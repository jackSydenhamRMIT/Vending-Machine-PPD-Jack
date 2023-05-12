#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <string>
#include <fstream>

class Display
{
    private:
        std::ofstream f;
        std::string path;
        bool fl = false;
public:
    Display(std::string output,bool ft){
        path = output;
        fl = ft;
    }
    void show_menu();
    void show_help();

    void write_or_show(std::string s);
};


#endif //DISPLAY_H