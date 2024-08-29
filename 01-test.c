#include <stdio.h>

void main() {
  char first = '4';
  char second = '2';
  char pair[2] = {first, second};
  // when printing 1 we got 49, this working is kinda crazy for me
  int d1= (int)pair[0] - 48;
  int d2 = (int)pair[1] - 48;
  int code = d1*10 + d2;
  printf("%d\n", *pair);
  printf("%d\n", code);
  return;
}

int joinDigits(char d1, char d2) {
  if (d1 >= 48 && d1 <= 58 && d2 >= 48 && d2 <= 58)
    printf("one of the characters is NaN");
  d1 = (int)d1 - 48;
  d2 = (int)d2 - 48;
  return d1*10 + d2;

 
}
