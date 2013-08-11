#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int hh, mm;
	while(std::cin >> hh >> mm){
		bool atSchool = true;
		if(hh < 7)
			atSchool = false;
		else if(hh > 16)
			atSchool = false;
		else if(hh == 7 && mm < 30)
			atSchool = false;

		if(atSchool)
			std::cout << "At School\n";
		else
			std::cout << "Off School\n";
	}
	return 0;
}