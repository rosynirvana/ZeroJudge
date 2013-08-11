#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::reverse;

string my_plus(const string&, const string&);
string my_minus(const string&, const string&);
string mul(const string&, const string&);
string div(const string&, const string&);

static string base_minus(const string&, const string&);
static string base_mul(const string&, int a);

int main()
{
    string input;
    while(getline(cin, input)){
        if(input.size() == 0)
        break;
        size_t first_blank = input.find(' ');
        size_t second_blank = first_blank + 2;

        char op = input[first_blank + 1];
        string num1 = input.substr(0, first_blank - 0);
        string num2 = input.substr(second_blank + 1, input.size() - second_blank - 1);

        switch(op){
        case '+':
            cout << my_plus(num1, num2) << "\n";
            break;
        case '-':
            cout << my_minus(num1, num2) << "\n";
            break;
        case '*':
            cout << mul(num1, num2) << "\n";
            break;
        case '/':
            cout << div(num1, num2) << "\n";
            break;
        }
        input.clear();
    }
    return 0;
}

string my_plus(const string& num1, const string& num2)
{
    string r;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    bool carry = false;
    for(; i>=0 && j>=0; --i, --j){
            r.push_back((num1[i] - '0' + num2[j] - '0' + (carry ? 1 : 0)) % 10 + '0' );
            num1[i] - '0' + num2[j] - '0' + (carry ? 1 : 0) >= 10 ? carry = true : carry = false;
    }

    if(i >= 0)
        for(; i>=0; --i){
            r.push_back((num1[i] - '0' + (carry ? 1 : 0)) % 10 + '0');
            if(num1[i] == '9' && carry)
                carry = true;
            else
                carry = false;
        }
    else if(j >= 0)
        for(; j>=0; --j){
            r.push_back((num2[j] - '0' + (carry ? 1 : 0)) % 10 + '0');
            if(num2[j] == '9' && carry)
                carry = true;
            else
                carry = false;
        }

    reverse(r.begin(), r.end());
    return r;
}

string my_minus(const string& num1, const string& num2)
{
    bool neg;
    int temp = num1.compare(num2);
    if(temp == 0)
        return "0";
    if(temp > 0)
        neg = false;
    else
        neg = true;

    string r;
    if(temp > 0)
        r = base_minus(num1, num2);
    else
        r = base_minus(num2, num1);

    if(neg)
        r.push_back('-');
    reverse(r.begin(), r.end());

    return r;
}

string base_minus(const string& num1, const string& num2)
{
    string r;
    bool carry;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    for(; i>=0 && j >=0; --i, --j){
        if(num1[i] >= num2[j]){
            r.push_back(num1[i] - num2[j] + '0');
            carry = false;
        }
        else{
            r.push_back(num1[i] + 10 - num2[j] +'0');
            carry = true;
        }
    }
    for(; i>=0; --i){
        if(carry && num1[i] > '0'){
            r.push_back(num1[i] - 1);
            carry = false;
        }
        else if(carry && num1[i] == '0')
            r.push_back('9');
        else if(!carry)
            r.push_back(num1[i]);
    }
    reverse(r.begin(), r.end());

    return r;
}

string mul(const string& num1, const string& num2)
{
    int i = num2.size() - 1;
    string r = "0";
    for(; i>=0; --i){
        string temp = base_mul(num1, num2[i] - '0');
        temp.append(string(num2.size()-1-i,'0'));
        r = my_plus(r, temp);
    }
    return r;
}

string div(const string& num1, const string& num2)
{
    if(num1.compare(num2) < 0)
        return "0";
    string r;
    string num1_c = num1;
    while(num1_c.compare(num2)){
        string sub = num1_c.substr(0,num2.size());
        if(sub.compare(num2) == 1){
            int i;
            bool equal = false;
            string temp = num2;
            for(i = 1; i < 10; ++i){
                if (sub.compare(temp) < 0){equal = false;
                    break;}
                else if(sub.compare(temp) == 0){
                    equal = true;
                    break;
                }
                else{
                    temp = my_plus(temp, num2);
                }
            }
           
            r.push_back(i-1+'0' + (equal?1:0));
        }
        else if(sub.compare(num2) == 0)
            r.push_back('1');
        else
            r.push_back('0');
        num1_c = my_minus(num1_c, num2);
    }

    size_t not_zero = 0;
    for(; not_zero != r.size(); ++not_zero)
        if(r[not_zero] != '0')
            break;
    
    return r.substr(not_zero, r.size() - not_zero);
}

string base_mul(const string& num, int a)
{
    string r;
    int i = num.size() - 1;
    int carry = 0;
    for(; i>=0; --i){
        int temp = (num[i] - '0') * a + carry;
        r.push_back(temp % 10 + '0');
        carry = temp / 10;
    }
    if(carry != 0)
        r.push_back(carry + '0');

    reverse(r.begin(), r.end());
    return r;
}
