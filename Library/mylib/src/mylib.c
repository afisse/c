#include "mylib.h"
#include <stdio.h>

void mylib_mul (int a, int b) {
  printf ("%d * %d = %d\n", a, b, a*b);
}

void mylib_add (int a, int b) {
  printf ("%d + %d = %d\n", a, b, a+b);
}

void mylib_sub (int a, int b, int c) {
  printf ("%d - %d - %d= %d\n", a, b, c, a-b-c);
}

void mylib_xxx (int a, int b) {
  printf ("%d xxx %d = %d\n", a, b, (a-b+42)%10);
}

void mylib_say_hello(){
  printf ("hello\n");
}

void mylib_say_fuck(char* s){
  printf ("fuck\n");
}
