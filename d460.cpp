#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int age;
	while(std::cin >> age){
		int price;
		if(age < 6)
			price = 0;
		else if(age < 12)
			price = 590;
		else if(age < 18)
			price = 790;
		else if(age < 60)
			price = 890;
		else
			price = 399;

		std::cout << price << "\n";
	}
	return 0;
}