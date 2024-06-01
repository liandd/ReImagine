#include<bits/stdc++.h>
#define lli long long int
/*
int main(){
    lli n = 0, g = 0, res = 0, a = 0, b = 0, tmp = 0;
    bool flagTriangular = false;
    while(scanf("%lld", &n) && (n > 0)){
        res = (-1 + sqrt(1 + 8 * static_cast<double>(n))) / 2;
        g = res * (res + 1) >> 1;
        (n == g) ? flagTriangular = true: flagTriangular = false;
        (n == 1) ? a = 1, b = 1 : (n == 2) ? a = 1, b = 2 : (flagTriangular && ((res & 1) == 0)) ? a = res, b = 1 : (flagTriangular && ((res & 1))) ? a = 1, b = res : tmp = 1 ;



    }
    return 0;
}*/
int main() {
   bool flag = false;
   lli n = 0, x = 1, y = 1, r = 0, g = 0;
   while(scanf("%lld", &n) && (n > 0)){
      r = (-1 + (lli)sqrt(1 + 8 * (double)n)) / 2;
	  g = r * (r + 1) >> 1;
	  (n == g) ? flag = true : flag = false;
	  if(n == 1)
	     x = y = 1;
	  else if (n==2){
	     x = 1;
	     y = 2;
	  }	
      else{
	     if(flag && ((r & 1)==0)) {
	        x = r;				              
            y = 1;					  
         }
	     else if(flag && (r & 1)){
	        x = 1;
	        y = r;
	     }
	     else if ((r & 1) == 0){			      
            x = r + 1 -(n - g - 1);		 	     
            y = 1 + n - g - 1;
	     }		
         else {
	       y = r + 1 -(n - g - 1);
	       x = 1 + n - g - 1;
	     }
      }						
      printf ("%lld %lld\n", x, y);
   }
   return 0;
}
