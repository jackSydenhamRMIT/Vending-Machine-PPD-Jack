#include <iostream>
#include "LinkedList.h"

/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/
int main(int argc, char **argv)
{
    /* validate command line arguments */
    // TODO
    
    // Check if 3 command line parameters have been entered
    if (argc != 3){
        std::cerr << "Error:invalid arguments passed in. " << std::endl;
        std::cerr << "Correct arguments are:"<< std::endl << argv[0] << " <stockfile> <coinsfile>" << std::endl;
        std::cerr << "Where <stockfile> and <coinfile> are two valid files in the expected format." << std::endl;
        return EXIT_FAILURE; 
    }

    std::ifstream stockFile(argv[1]);
    if (!stockFile) {
    std::cerr << "Error: Failed to open stock file." << std::endl;
    return EXIT_FAILURE;
    } 
    std::ifstream coinsFile(argv[2]);
    if (!coinsFile) {
    std::cerr << "Error: Failed to open coins file." << std::endl;
    return EXIT_FAILURE;
    } 

    std::cout << "Just a test, nothing implemented yet!" << std::endl;
    
    return EXIT_SUCCESS;
}
