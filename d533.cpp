/* This is not correct perhaps. *
 * == and != is defined for a complex number a+bi (b != 0) *
 * > and < are not defined *
 * Here comes the question: a==1, b==1, c==1, d==1 *
 * It's OK to print "No" because > and < are undefined *
 * and it's also OK to print '=' because the two comples number equal */
 
#include <cstdio>

int main()
{
  int count;
  scanf("%d", &count);
  for(int i=0; i!=count; ++i){
    double a,b,c,d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    if(b == d && d == 0){
      if(a > c)
	printf(">\n");
      else if(a == c)
	printf("=\n");
      else
	printf("<\n");
    }
    else
      printf("No\n");
  }
  return 0;
}
