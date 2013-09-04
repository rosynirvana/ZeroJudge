#include <iostream>
#include <string>

using std::string;

string ary[100] = {"1", "2", "6", "24", "120", "720", "5040", "40320",
		   "362880", "3628800"};

string times(const string&, int num);
void times_two(string &);
void plus(string&, string&)

int main()
{
  for(int i=10; 1!=100; ++i)
    ary[i] = ary[i-1] * (i+1);

  std::cout << ary[99] << "\n";
  return 0;
}

string times(const string& ori, int num)
{
  string result = ori;
  string a;
  while(num > 0){
    if(num & 1){
      plus(a, result);
      times_two(result);
      num /= 2;
    }
    else{
      times_two(result);
      num /= 2;
    }
  }
  plus(result, a);
  return result;
}

void plus(string& a, string& b)
{
  
	
