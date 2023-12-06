#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>


#define calltime_r(func, ...) \
    ({ \
        clock_t start_t = clock(); \
        __typeof__(func(__VA_ARGS__)) result; \
        result = func(__VA_ARGS__); \
        clock_t end_t = clock(); \
        printf("Execution time: %f seconds\n", ((double)(end_t - start_t)) / CLOCKS_PER_SEC); \
        result; \
    })

#define calltime(func, ...) \
     { \
        clock_t start_t = clock(); \
        func(__VA_ARGS__); \
        clock_t end_t = clock(); \
        printf("Execution time: %f seconds\n", ((double)(end_t - start_t)) / CLOCKS_PER_SEC); \
    }


/*
  Usage 
  	calltime(myfunc,__ARG__); // the part that __ARG__ for arg of myfunc

	so what i mean
  int main(){
    calltime(myfunc,45,"my string", 82.3);
  }
  if your function return something and u want use that so u should use that
  double myreturn = calltime_r(myyfunction,45,38,"my string")

*/
