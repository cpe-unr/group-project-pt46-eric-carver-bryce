#include "CSVmenu.h"
#include <iostream>

void CSVMenu::runCSVMenu(std::vector<Wav *> wavObjects, std::vector<std::string> files){
	int userChoice;
	
	while(userChoice != 0 || userChoice != 1){
		std::cout << "Would you like to create a CSV file?" << std::endl; 
		std::cout << "0) Exit program" << std::endl;
		std::cout << "1) Create CSV file" << std::endl; 
		std::cin >> userChoice;
	}
	
	if(userChoice == 0){
	}
		
	else if(userChoice == 1){
		Wav::makeCSV();
		for(int i = 0; wavObjects.size(); i++){
			wavObjects[i]->addToCSV(files[i]);
		}
	}
}



