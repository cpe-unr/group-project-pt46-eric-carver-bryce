#ifndef GUI_H
#define GUI_H

namespace Gui
{
    namespace MainMenu
    {
        
    
    enum MENU_CHOICE
        {
        EXIT = 0,
        EDIT_METADATA = 1
       
        
        };
     MENU_CHOICE getMenuChoice();

    }
    
    namespace ProcessingMenu
    {
        const int UNKNOWN = -1;
        const int EXIT = 0;
        const int NORMALISATION = 2;
        const int NOISE_GATING = 4;
        const int ECHO = 8;
        int getMenuChoice();
    }
    
    namespace FileMenu
    {
        enum MENU_CHOICE
        {
            EXIT = 0,
            EDIT_FILE_NAME = 1
        };
     MENU_CHOICE getMenuChoice();
    }
    
    namespace CSVMenu
    {
        enum MENU_CHOICE
        {
            EXIT = 0,
            MAKE_CSV = 1
        };
         MENU_CHOICE getMenuChoice();
    }
};

#endif
