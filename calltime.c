#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

#define calltime(func, ...) \
	CALLTIME((void (*)(va_list))func, __VA_ARGS__)

void CALLTIME(void (*func)(va_list),...){
   clock_t start_t = clock();
	va_list args;
	va_start(args, func);
	func(args);
	va_end(args);
   clock_t end_t = clock();
   printf("\nTotal time taken by CPU: %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC );
}


/*
  Usage 
  	calltime(myfunc,__ARG__); // the part that __ARG__ for arg of myfunc

	so what i mean
  int main(){
    calltime(myfunc,45,"my string", 82.3);
  }

*/
