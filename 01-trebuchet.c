#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define DOC "2abc2\n\
               pqr3stu8vwx\n\
               a1b2c3d4e5f\n\
               treb7uchet\n"

int main() {
    int first, last, result;
    //for (char* input = strtok(DOC, "\n"); input != NULL; input = strtok(NULL, "\n")) {
        printf("input %s\n", input);
        for (char* i = input; *i; i++) {
            printf("i %c\n", *i);
            if (isdigit(*i)) {
                if (!first)
                    first = atoi(i);
                last = atoi(i);
            }
        }
        if (first && !last)
            last = first;
        result += (first*10) + last;
        printf("%d\n", result);
    }

    printf("result: %d\n", result);
    assert(result == 142);
    return 0;
}

  /* until string is fully read
   * for every char before \n
   * check for number */

