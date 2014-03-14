
#include <stdio.h>

int main()
{
   int i[] = {3, 5}; 
   int *p = i; 
   int j = --*p++; 
   
   printf("j = %d\n\n", j);
   system("pause");
   return 0;
}
