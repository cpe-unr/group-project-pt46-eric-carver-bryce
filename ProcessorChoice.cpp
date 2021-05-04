#include "ProcessorChoice.h"
void ProcessorChoice::GetInput(){
	if (wavObject->isStereo() && wavObject->is16Bit()){
		Processor<SixteenBitStereo> processor((SixteenBitStereo*) wavObject);
		std::cout << "Apply Normalization (0 [false] or 1 [true]): " << std::flush;
		int x;
		std::cin >> x;
		if(x){
			float y = 1;
			while(y>0){
				std::cout << "What decibel level (should be negative): " << std::flush;
				std::cin >> y;
				if(y>0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NormalizeDecibels(y);
		}
		std::cout << "Apply NoiseGate (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0 || y>100){
				std::cout << "What minimum percent (should be positive and between 0 and 100): " << std::flush;
				std::cin >> y;
				if(y<0 || y>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NoiseGatePercent(y);
		}
		std::cout << "Apply Echo (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0){
				std::cout << "How many seconds (should be positive): " << std::flush;
				std::cin >> y;
				if(y<0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			float z = -1;
			while(z<0 || z>100){
				std::cout << "What percent should each echo be scaled by (should be positive and between 0 and 100): " << std::flush;
				std::cin >> z;
				if(z<0 || z>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.EchoSeconds(y, z);
		}
	}else if (wavObject->isStereo() && !wavObject->is16Bit()){
		Processor<EightBitStereo> processor((EightBitStereo*) wavObject);
		std::cout << "Apply Normalization (0 [false] or 1 [true]): " << std::flush;
		int x;
		std::cin >> x;
		if(x){
			float y = 1;
			while(y>0){
				std::cout << "What decibel level (should be negative): " << std::flush;
				std::cin >> y;
				if(y>0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NormalizeDecibels(y);
		}
		std::cout << "Apply NoiseGate (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0 || y>100){
				std::cout << "What minimum percent (should be positive and between 0 and 100): " << std::flush;
				std::cin >> y;
				if(y<0 || y>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NoiseGatePercent(y);
		}
		std::cout << "Apply Echo (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0){
				std::cout << "How many seconds (should be positive): " << std::flush;
				std::cin >> y;
				if(y<0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			float z = -1;
			while(z<0 || z>100){
				std::cout << "What percent should each echo be scaled by (should be positive and between 0 and 100): " << std::flush;
				std::cin >> z;
				if(z<0 || z>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.EchoSeconds(y, z);
		}
	}else if (!wavObject->isStereo() && wavObject->is16Bit()){
		Processor<SixteenBitMono> processor((SixteenBitMono*) wavObject);
		std::cout << "Apply Normalization (0 [false] or 1 [true]): " << std::flush;
		int x;
		std::cin >> x;
		if(x){
			float y = 1;
			while(y>0){
				std::cout << "What decibel level (should be negative): " << std::flush;
				std::cin >> y;
				if(y>0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NormalizeDecibels(y);
		}
		std::cout << "Apply NoiseGate (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0 || y>100){
				std::cout << "What minimum percent (should be positive and between 0 and 100): " << std::flush;
				std::cin >> y;
				if(y<0 || y>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NoiseGatePercent(y);
		}
		std::cout << "Apply Echo (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0){
				std::cout << "How many seconds (should be positive): " << std::flush;
				std::cin >> y;
				if(y<0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			float z = -1;
			while(z<0 || z>100){
				std::cout << "What percent should each echo be scaled by (should be positive and between 0 and 100): " << std::flush;
				std::cin >> z;
				if(z<0 || z>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.EchoSeconds(y, z);
		}
	}else if (!wavObject->isStereo() && !wavObject->is16Bit()){
		Processor<EightBitMono> processor((EightBitMono*) wavObject);
		std::cout << "Apply Normalization (0 [false] or 1 [true]): " << std::flush;
		int x;
		std::cin >> x;
		if(x){
			float y = 1;
			while(y>0){
				std::cout << "What decibel level (should be negative): " << std::flush;
				std::cin >> y;
				if(y>0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NormalizeDecibels(y);
		}
		std::cout << "Apply NoiseGate (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0 || y>100){
				std::cout << "What minimum percent (should be positive and between 0 and 100): " << std::flush;
				std::cin >> y;
				if(y<0 || y>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.NoiseGatePercent(y);
		}
		std::cout << "Apply Echo (0 [false] or 1 [true]): " << std::flush;
		std::cin >> x;
		if(x){
			float y = -1;
			while(y<0){
				std::cout << "How many seconds (should be positive): " << std::flush;
				std::cin >> y;
				if(y<0){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			float z = -1;
			while(z<0 || z>100){
				std::cout << "What percent should each echo be scaled by (should be positive and between 0 and 100): " << std::flush;
				std::cin >> z;
				if(z<0 || z>100){
					std::cout << "Invalid input!" << std::endl;
				}
			}
			processor.EchoSeconds(y, z);
		}
	}
}
