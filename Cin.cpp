
#include "Cin.h"

Cin::Cin(std::string path,bool fg):m_fg(fg){ 
    if(path != "")
    {
        f.open(path,std::ios::in);
        if(!f.is_open())  
        std::cout<<"open "<<path<<" ERR"<<std::endl;
    }
}

std::string Cin::get_cin()
{
    std::string ret_str;
    if(m_fg)
        ret_str = cin_keyboard();
    else
    { 
        ret_str= cin_file();
    }
    return ret_str;
}

std::string Cin::cin_keyboard()
{
    char s;
    std::string p;
    bool t = true;
    while(t)
    {
        s = std::cin.get();
        if(s == '\n')
        {
            t = false;
        }
        else
        p+=s;
    }
    return p;

}
std::string Cin::cin_file()
{
    std::string ret_s;
    if(!f.eof())
    {
        getline(f,ret_s);
        std::cout<<"-"<< ret_s<<std::endl;
        return ret_s;
    }
    f.close();
    exit(0);
}

