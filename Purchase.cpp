#include "Display.h"
#include "Purchase.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "Node.h"

using std::cout;

Purchase::Purchase(LinkedList & lst):m_lst(lst)
{
}

Purchase::~Purchase()
{
}

void Purchase::purchase_room(bool Colour)
{
    cout<<"Purchase Item\n"
        <<"-------------\n"
        <<"Please enter the id of the item you wish to purchase:";

    std::string cin_ID;
    cin_ID = get_cin();
    cin_ID = get_cin();
    // std::cin>>cin_ID;
    //Get the input product information
    auto rest = m_lst.find_node(cin_ID);
    if(rest == nullptr)
    {
        return ;
    }

    
    cout<<"You have selected \""<< rest->name << " - " << rest->description << "\".";

    if(Colour){
        cout<<" This will cost you \033[32m$"<<rest->price.dollars<<"."<<rest->price.cents<<"\033[0m\n";
    }
    else if(!(Colour)){
        cout<<" This will cost you $"<<rest->price.dollars<<"."<<rest->price.cents<<"\n";
    }

    cout<<"Please hand over the money - type in the value of each note/coin in cents.\n"
        <<"Press enter or ctrl-d on a new line to cancel this purchase:\n";
    
    int pice;
    int need_p = 100*rest->price.dollars + rest->price.cents;

    if(Colour){
        cout<<"You still need to give us \033[32m$"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<"\033[0m:";
    }
    else if(!(Colour)){
        cout<<"You still need to give us $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";

    }

    //Enter the amount of money paid
    std::vector<int> tmp_save_money;
    std::string pice_s;
    while(1)
    {
        pice_s = get_cin();
        if(pice_s == "")
            return ;
        pice = std::stoi(pice_s);
        if(pice != 200 && pice != 500)
        {
            cout<<"Error: $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<" is not a valid denomination of money. Please try again\n";
            if(Colour){
                cout<<"You still need to give us \033[32m$"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<"\033[0m:";
            }
            else if(!(Colour)){
                cout<<"You still need to give us $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";

            }
        }
        else{
            //Get the amount of money
            //Coin coin = m_lst.get_coin(pice);
            Coin* coin = new Coin(FIVE_CENTS, 5); 
            if(coin->count<=0)
            {
                cout<<"Error: $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<" is not a valid denomination of money. Please try again\n";
                if(Colour){
                    cout<<"You still need to give us \033[32m$"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<"\033[0m:";
                }
                else if(!(Colour)){
                    cout<<"You still need to give us $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";

                }
            }
            else{
                need_p -= pice;
                //Amount of money deducted
                tmp_save_money.push_back(pice);
                //Determine if there is enough money to buy this item
                if(need_p<=0)
                {
                    cout<<"Here is your Meat Pie and your change of $ "<<rest->price.dollars<<"."<<rest->price.cents<<": ";
                    for(int i=0;i<8 && need_p < 0;)
                    {
                        if(need_p+face_value[i] > 0)
                        {
                            ++i;
                        }
                        else{
                            //Money is $ or c
                        if(face_value[i] >= 100)
                            cout<<" $"<<face_value[i]/100;
                            else 
                                cout<<" "<<face_value[i]<<"c";

                            need_p+=face_value[i]; 
                            //change (money)
                            m_lst.change_coin(face_value[i]);
                        }
                    }
                    cout<<"\n";

                    for(auto coin_t : tmp_save_money)
                        m_lst.use_coin(coin_t);

                    // m_lst.display_coin();
                    Display display;
                    display.show_menu();
                    return;
                }
                else
                if(Colour){
                    cout<<"You still need to give us \033[32m$"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<"\033[0m:";
                }
                else if(!(Colour)){
                    cout<<"You still need to give us $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";

                }
            }
        }
    }

}

std::string Purchase::get_cin(bool a)
{
    char s;
    std::string p;

    bool done = false;
    while(!done)
    {
        s = std::cin.get();
        if(s == '\n')
        {
            done = true;
        }
        else
        {
            p += s;
        }
    }
    
    return p;
}
