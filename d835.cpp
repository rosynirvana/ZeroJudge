#include <cstdio>
#include <vector>
#include <cstdlib>

using std::vector;

int main()
{
  vector<int> r11, r21;
  int w11 = 0, w21 = 0, l11 = 0, l21 = 0;
  int c;
  while((c = getchar()) && c != 'E'){
    if(c == 'W'){
      ++w11;
      ++w21;
    }
    else if(c == 'L'){
      ++l11;
      ++l21;
    }
    if((w11 >= 11 || l11 >= 11) && abs(w11 - l11) >= 2){
      r11.push_back(w11);
      r11.push_back(l11);
      w11 = 0;
      l11 = 0;
    }
    if((w21 >= 21 || l21 >= 21) && abs(w21 - l21) >= 2){
      r21.push_back(w21);
      r21.push_back(l21);
      w21 = 0;
      l21 = 0;
    }
  }
  r11.push_back(w11);
  r11.push_back(l11);
  r21.push_back(w21);
  r21.push_back(l21);
  size_t i = 0;
  while(i!=r11.size()){
    printf("%d:%d\n", r11[i],r11[i+1]);
    i += 2;
  }
  printf("\n");
  i = 0;
  while(i!=r21.size()){
    printf("%d:%d\n", r21[i], r21[i+1]);
    i += 2;
  }
  return 0;
}
