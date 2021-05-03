#include "Gui.h"

#include <iostream>
#include <sstream>
#include <string>


using namespace std;


const Gui::MainMenu::MENU_CHOICE Gui::MainMenu::getMenuChoice()
{
    cout << "Would you like to edit the metadata?" << endl;
    cout << "0) Exit program"
    cout << "1) Yes" << endl;
    cout << "2) No"  << endl;
    int choice;
    cin >> choice;
    return (Gui::MENU_CHOICE)choice;
}

int Gui::ProcessingMenu::getMenuChoice()
{
    //  display the menu
    std::string input;
    int menuChoices = 0;
    bool shouldExitMenu = false;
    while( !shouldExitMenu )
    {
        //  reset the flag, we are assuming everything will be ok
        shouldExitMenu = true;
        //  display the menu
        cout << "Enter one or more choies, separated by a comma, or 0 to exit:" << endl;
        cout << "1)  Normalisation" << endl;
        cout << "2)  Noise Gating" << endl;
        cout << "3)  Echo" << endl;
        cout << "0)  Exit Program" << endl;
        //  input the choices
        cin >> input;
        stringstream ss(input);
        //  parse the choices
        menuChoices = 0;
        for (int i; ss >> i;) {
            if( !i ) return Gui::ProcessingMenu::EXIT;
            if( i < 0  ||  i > 3)
            {
                //  display error message and indicate we should not exit the menu
                cout << "Unknown option " << i << endl;
                shouldExitMenu = false;
                break;
            }
            //  ignore comma
            if (ss.peek() == ',')
                ss.ignore();
            //  bit-wise OR the value
            menuChoices |= (1 << i);
        }
    }
    //  return the user's choices
    return menuChoices;    
}


const Gui::FileMenu::MENU_CHOICE Gui::FileMenu::getMenuChoice()
{
    cout << "Would you like to edit the processed file's name?" << endl;
    cout << "0) Exit program" << endl;
    cout << "1) Edit file name" << endl;
    int choice;
    cin >> choice;
    return (Gui::MENU_CHOICE)choice;
}

const Gui::CSVmenu::MENU_CHOICE Gui::CSVmenu::getMenuChoice()
{
    cout << "Would you like to create a CSV file?" << endl; 
    cout << "0) Exit program" << endl;
    cout << "1) Create CSV file" << endl; 
    int choice; 
    cin >> choice;
    return (Gui::MENU_CHOICE)choice;
}
