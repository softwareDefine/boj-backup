#include <cstdio>
using namespace std;
 
int main() {
   int n, k, i;
   int sum = 0;
    
    scanf("%d %d ",&n,&k);
 
   for (i = 1; i <= k; i++) {  
      sum += i;
   }
   n -= sum;
 
   if (n < 0) {  
      printf("%d",-1);
   }
   else {
      if (n % k == 0)  
       printf("%d",k-1);
       else if (n % k != 0)  
       printf("%d",k);
   }
}
 