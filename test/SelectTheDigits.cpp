#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include <iostream>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define TOTAL 8

int counts[10];
char min[10];
char generated[10];
char digits[100];



void generate(int level, int pos) {
    if (level == 0) {
        if (strncmp(generated, min, 4) < 0) {
            strncpy(min, generated, 4);
        }
    } else {
        FORE(i, pos, TOTAL - level + 1) {
            generated[4 - level] = digits[i];
            generate(level - 1, i + 1);
        }
    }
}

int main(int argc, char **argv) {
    FILE *input = fopen("number.in", "r");
    FILE *output = fopen("number.out", "a");
    fscanf(input, "%s", digits);
    min[0] = min[1] = min[2] = min[3] = '9';
    min[4] = 0;

    generate(4, 0);

    fprintf(output, "%s", min);

    fclose(input);
    fclose(output);
}
