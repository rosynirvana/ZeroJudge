#include <iostream>
#include <cmath>
int main()
{
    double a, b, c;
    while(std::cin >> a){
        std::cin >> b >> c;
        double j = b*b - 4*a*c;
        if(j > 0){
            double x1 = (sqrt(j) -  b)/2/a;
            double x2 = (-sqrt(j) - b)/2/a;
            if(x1 == -0)
                x1 = 0;
            if(x2 == -0)
                x2 = 0;
            std::cout << "Two different roots x1=" << x1 << " , x2=" << x2 << "\n";
        }
        else if(j == 0){
            double x = b/2/a/(-1);
            if(x == -0)
                x = 0;
            std::cout << "Two same roots x=" << x << "\n";
        }
        else
            std::cout << "No real root\n";
    }
    return 0;
}
