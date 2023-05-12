
#include "Purchase.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include "Node.h"

using std::cout;

Purchase::Purchase(LinkedList &lst, LinkedList &coin, Cin &in, Display &put) : m_lst(lst), m_coin(coin), m_in(in), m_put(put)
{
}

Purchase::~Purchase()
{
}

void Purchase::purchase_room()
{
    {
        std::stringstream s;
        s << "Purchase Item\n"
          << "-------------\n"
          << "Please enter the id of the item you wish to purchase:";
        m_put.write_or_show(s.str());
    }

    std::string cin_ID;
    // cin_ID = m_in.get_cin();
    cin_ID = m_in.get_cin();
    auto rest = m_lst.find_node(cin_ID);
    if (rest != nullptr)
    {
        int pice;
        int need_p = 100 * rest->price.dollars + rest->price.cents;

        {
            std::stringstream s;
            s << "You have selected \"" << rest->name << " - " << rest->description << "\"."
              << "This will cost you $ " << rest->price.dollars << "." << rest->price.cents << "\n"
              << "Please hand over the money - type in the value of each note/coin in cents.\n"
              << "Press enter or ctrl-d on a new line to cancel this purchase:\n"
              << "You still need to give us " << std::fixed << std::setprecision(2) << (need_p / 100.00) << ":";
            m_put.write_or_show(s.str());
        }
        // Enter the amount of money paid
        std::vector<int> tmp_save_money;
        std::string pice_s = " ";
        pice_s = m_in.get_cin();
        while (pice_s != "")
        {
            pice = std::stoi(pice_s);
            if (pice != 200 && pice != 500)
            {
                std::stringstream s;
                s << "Error: $" << std::fixed << std::setprecision(2) << (need_p / 100.00) << " is not a valid denomination of money. Please try again\n"
                  << "You still need to give us " << std::fixed << std::setprecision(2) << (need_p / 100.00) << ":";
                m_put.write_or_show(s.str());
            }
            else
            {
                // Get the amount of money
                Coin coin = m_coin.get_coin(pice);
                if (coin.count <= 0)
                {
                    std::stringstream s;
                    s << "Error: $" << std::fixed << std::setprecision(2) << (need_p / 100.00) << " is not a valid denomination of money. Please try again\n"
                      << "You still need to give us " << std::fixed << std::setprecision(2) << (need_p / 100.00) << ":";
                    m_put.write_or_show(s.str());
                }
                else
                {
                    need_p -= pice;
                    // Amount of money deducted
                    tmp_save_money.push_back(pice);
                    // Determine if there is enough money to buy this item
                    if (need_p <= 0)
                    {
                        std::stringstream s;
                        s << "Here is your Meat Pie and your change of $ " << rest->price.dollars << "." << rest->price.cents << ": ";

                        for (int i = 0; i < 8 && need_p < 0;)
                        {
                            if (need_p + face_value[i] > 0)
                            {
                                ++i;
                            }
                            else
                            {
                                // Money is $ or c
                                if (face_value[i] >= 100)
                                    s << " $" << face_value[i] / 100;
                                else
                                    s << " " << face_value[i] << "c";

                                need_p += face_value[i];
                                // change money
                                m_coin.change_coin(face_value[i]);
                            }
                        }
                        s << "\n";
                        m_put.write_or_show(s.str());
                        for (auto coin_t : tmp_save_money)
                            m_coin.use_coin(coin_t);
                        return;
                    }
                    else
                    {
                        std::stringstream s;
                        s << "You still need to give us " << std::fixed << std::setprecision(2) << (need_p / 100.00) << ":";
                        m_put.write_or_show(s.str());
                    }
                }
            }
            pice_s = m_in.get_cin();
        }
    }
}

// std::string Purchase::get_cin(bool a)
// {
//     char s;
//     std::string p;
//     while(1)
//     {
//         s = std::cin.get();
//         if(s == '\n')
//         {
//             return p;
//         }
//         p+=s;
//     }
//     return p;
// }
