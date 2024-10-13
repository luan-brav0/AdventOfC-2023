#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


void usage(char* arg0) {
    printf("USAGE: %s <file>", arg0);
}

int main(int argc, char** argv) {
    FILE* file;
    if (argc < 2){
        fprintf(stderr, "ERROR: Missing file name as argument");
        usage(argv[0]);
        exit(1);
    } else if (argc > 2){
        fprintf(stderr, "ERROR: Too many arguments");
        usage(argv[0]);
        exit(1);
    }

    // char fileName[256] = argv[1];
    char fileName[256];
    strncpy(fileName, argv[1], sizeof(fileName) - 1);
    file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Could not open or read from file \"%s\"\n", fileName);
        exit(1);
    }

    char line[256];
    int total;
    while(fgets(line, sizeof(line), file)){
        int first = 0, last = 0;
        for(char* c = line; *c; c++) {
            if (*c == '\n') {
                if (!last) {
                    last = first;
                }
                printf("Summing %d * 10 to %d\nTotal: %d\n", first, last, total);
                total += (first * 10) + last;
                printf("Summed total: %d\n", total);
            } else if (!isdigit(c)) {
                printf("Skipping %c\n", *c);
                continue;
            } else if (!first) {
                // first = atoi(c); // doesn't work for this if c[x] are also a numbers
                first = *c - '0';
                printf("set first: char: %c first: %d\n", *c, first);
                assert(first < 10);
            } else {
                // last = atoi(c);
                last = *c - '0';
                printf("set last: char: %c last: %d\n", *c, last);
                assert(last < 10);
            }
        }
    }

    fclose(file);
    printf("total = %d\n", total);
    return 0;
}
