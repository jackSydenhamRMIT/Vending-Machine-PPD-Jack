#include <iostream>
#include "LinkedList.h"
#include "Purchase.h"
#include "Display.h"

/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/
int main(int argc, char **argv)
{
    /* validate command line arguments */
    // TODO
    LinkedList linkedlist;
    // Check if 3 command line parameters have been entered
    if (argc != 3){
        std::cerr << "Error:invalid arguments passed in. " << std::endl;
        std::cerr << "Correct arguments are:"<< std::endl << argv[0] << " <stockfile> <coinsfile>" << std::endl;
        std::cerr << "Where <stockfile> and <coinfile> are two valid files in the expected format." << std::endl;
        EXIT_FAILURE; 
    }

    const char* StockFile = argv[1];
    const char* CoinsFile = argv[2];

    linkedlist.loadStockData(StockFile);
    linkedlist.loadCoinsData(CoinsFile);  

    Purchase purchase(linkedlist);
    Display display;

    display.show_menu();

    int num = 0;
    while(std::cin>>num)
    {
        if(num == 1)
        {

        }
        else if(num == 2)
        {
            purchase.purchase_room();
        }
          //display.show_menu();
    }


}
