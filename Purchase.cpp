
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

void Purchase::purchase_room()
{
    cout<<"Purchase Item\n"
        <<"-------------\n"
        <<"Please enter the id of the item you wish to purchase:";

    std::string cin_ID;

    std::cin>>cin_ID;

    cin_ID = get_cin();
    cin_ID = get_cin();
    // std::cin>>cin_ID;
    //Get the input product information

    auto rest = m_lst.find_node(cin_ID);
    if(rest == nullptr)
    {
        return ;
    }

    cout<<"You have selected \""<< rest->name <<" - Yummy Beef in ... by pastry\"."
        <<"This will cost you $ "<<rest->price.dollars<<"."<<rest->price.cents<<"\n"
        <<"Please hand over the money - type in the value of each note/coin in cents.\n"
        <<"Press enter or ctrl-d on a new line to cancel this purchase:\n";
    
    int pice;
    int need_p = 100*rest->price.dollars + rest->price.cents;
    cout<<"You still need to give us "<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";

    while(std::cin>>pice)
    {

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
            cout<<"You still need to give us "<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";

            continue;
        }
        int coin_cont = m_lst.get_coin(pice);
        if(coin_cont<=0)
        {
            cout<<"Error: $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<" is not a valid denomination of money. Please try again\n";
            cout<<"You still need to give us "<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";
            continue;
        }
        need_p -= pice;
        if(need_p<=0)
        {

            cout<<"Here is your Meat Pie and your change of $ "<<rest->price.dollars<<"."<<rest->price.cents<<": $2 $1 50c";
            for(int i=0;i<8 && need_p == 0;)
            {
                if(need_p+face_value[i] > 0)
                {
                    ++i;
                    continue;
                }
                
                if(face_value[i] >= 100)
                    cout<<" $"<<face_value[i]/100;
                else 
                    cout<<" "<<face_value[i]<<"c";

                need_p+=face_value[i];
            }
            cout<<"\n";
            return;
        }
        else
        cout<<"You still need to give us "<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";
    }

}

        }
        else{
            //Get the amount of money
            Coin coin = m_lst.get_coin(pice);
            if(coin.count<=0)
            {
                cout<<"Error: $"<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<" is not a valid denomination of money. Please try again\n";
                cout<<"You still need to give us "<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";
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
                    return;
                }
                else
                cout<<"You still need to give us "<<std::fixed<<std::setprecision(2)<<(need_p/100.00)<<":";
            }
        }
    }

}

std::string Purchase::get_cin(bool a)
{
    char s;
    std::string p;
    while(1)
    {
        s = std::cin.get();
        if(s == '\n')
        {
            return p;
        }
        p+=s;
    }
    return p;
}

