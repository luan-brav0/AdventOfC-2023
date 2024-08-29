#include <stdio.h>

#define DOC "2abc2\n\
               pqr3stu8vwx\n\
               a1b2c3d4e5f\n\
               treb7uchet\n"

/* cal values
 * first and last nums in line
 * array of pairs*/

int isNumber(char* c) {
  if (*c >= '0' && *c <= '9')
    return 1;
  else
    return 0;
}

int joinDigits(char* d1, char* d2) {
  if (isNumber(d1) == 0 && isNumber(d2) == 0)
    printf("one of the characters is NaN");
  *d1 = (int)*d1 - 48;
  *d2 = (int)*d2 - 48;
  return *d1*10 + *d2;
}

int main () {
  int doc_len = sizeof(DOC)/sizeof(DOC[0]);
  int lines = 0;
  for (int i = 0; DOC[i] != '\0'; i++) 
    if (DOC[i] == '\n') 
      lines++;
  printf("Lines: %d\n", lines);
  char pairs[lines][1];
  int keys[lines];
  int curLine;

  for (int i = 0; DOC[i] != '\0'; i++) {
    char* c = &DOC[i];
    if (DOC[i] == '\n') {
      keys[curLine] = joinDigits(&pairs[curLine][1], &pairs[curLine][2]); 
      curLine++;
      continue;
    }
    if (isNumber(c) == 1) {
      printf("N: %c @ %d:%d\n", *c, curLine, i);
      if (pairs[curLine][0] == '\0')
        pairs[curLine][0] = *c;
      else
        pairs[curLine][1] = *c;
    }
    printf("N%d: %s\n", curLine, pairs[curLine]);
  }
  
  printf("Pairs: %s\n", pairs);
  int total = 0;
  for (int i=0; keys[i] != '\0'; i++) {
    printf("%d\n", keys[i]);
    total += keys[i];
  }

  printf("Total: %d\n", total);
  return 0;
}

  /* until string is fully read
   * for every char before \n
   * check for number */
 
