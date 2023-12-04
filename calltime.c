#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void calltime(void (*func)()){
   clock_t start_t = clock();
	func();
   clock_t end_t = clock();
   printf("\nTotal time taken by CPU: %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC );
}

/*
  Usage 
  
  create like something like that

  void test(){
      slowfunc(457,123,20);
    }

  and

  int main(){
    calltime(test);
  }

*/
