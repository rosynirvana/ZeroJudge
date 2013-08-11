#include <iostream>
#include <cstdio> /*for getchar() to consume a '\n'*/
#include <sstream>

int main()
{
	int n;
	std::cin >> n;
	for(int i=0; i!=n; ++i){
		int x, y, z, w, n, m;
		std::cin >> x >> y >> z >> w >> n >> m;
		int poison_level = 0;
		getchar(); /* consume the '\n' */
		std::string input;
		std::getline(std::cin, input);
		if(input.size() != 0){
			
			std::stringstream buf;
			buf << input;

			int temp;
			while(buf >> temp){
			//std::cout << temp << " ";
				m -= poison_level * n;
				if(m <= 0)
					break;
				if(temp == 1)
					m += x;
				else if(temp == 2)
					m += y;
				else if(temp == 3)
					m -= z;
				else if(temp == 4){
					m -= w;
					poison_level += 1;
				}
				//std::cout << m << " ";
				if(m <= 0)
					break;
			}
		}
		if(m > 0)
			std::cout << m <<"g\n";
		else
			std::cout << "bye~Rabbit\n";
	}
	return 0;
}