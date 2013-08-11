#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int convert(char);

int main()
{
    string str;
    while(cin >> str){
        int p2 = convert(str[0]) % 10 * 9 + convert(str[0]) / 10;

        int p3 = 0;
        for(size_t i=1; i <= 8; ++i)
            p3 += (str[i] - '0')* (9-i);

        int p4 = p2 + p3 + str[str.size() - 1] - '0';
        if(p4 % 10 == 0)
            cout << "real\n";
        else
            cout << "fake\n";
    }
    return 0;
}

int convert(char c)
{
    if(c == 'I')
        return 34;
    if(c == 'O')
        return 35;
    if(c == 'W')
        return 32;
    if(c == 'Z')
        return 33;

    if(c >= 'A' && c <= 'H')
        return c-'A'+10;
    if(c >= 'J' && c <= 'N')
        return c-'J'+18;
    if(c >= 'P' && c <= 'V')
        return c-'P'+23;
    if(c >= 'X')
        return c-'X'+30;
}
