#include <stdio.h>

int foo(void *ptr) {
  /* foo takes two ints and add them */
  int *pte = (int *)ptr;
  int x = pte[0];
  int y = pte[1];

  return x + y;
}

int bar(void *ptr) {
  /* bar takes an int and a string and concatenates them */
  void **pte = (void **)ptr;  // Treat the input as an array of void pointers.
  int *x_ptr = (int *)pte[0]; // First element is a pointer to int.
  char *y = (char *)pte[1];   // Second element is a string.

  printf("%s%d\n", y, *x_ptr);

  return 0;
}

int main(void) {
  // test one
  int x = 1;
  int y = 2;
  int arr[2] = {x, y};
  int z = foo((void *)arr);
  printf("Test 1: %d\n", z);

  // test two
  int a = 3;
  char *b = "a = ";
  void *arr2[2] = {&a, b};
  bar((void *)arr2);
  return 0;
}
