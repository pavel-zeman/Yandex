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


int count = 0;
int factors[100];
int currentFactors[100];
int divisorCount = 0;
int divisors[10000];

void solve(int divisorNumber, int currentFactorCount, int remaining) {
    // do not continue, if there is no way to solve the problem
    if (count > 0 && currentFactorCount < count && divisorNumber < divisorCount) {
        int temp = remaining;
        FOR(i, count + 1 - currentFactorCount) temp /= divisors[divisorNumber];
        if (temp == 0) return;
    }

    // find divisor
    while (divisorNumber < divisorCount && remaining % divisors[divisorNumber] != 0 ) divisorNumber++;
    if (divisorNumber < divisorCount) {
        int temp = remaining / divisors[divisorNumber];
        currentFactors[currentFactorCount] = divisors[divisorNumber];
        if (temp <= divisors[divisorNumber]) {
            currentFactors[currentFactorCount] = remaining;
        }

        // try to use the divisor
        solve(divisorNumber + 1, currentFactorCount + 1, remaining / currentFactors[currentFactorCount]);

        // try it without the divisor
        solve(divisorNumber + 1, currentFactorCount, remaining);
    } else {
        // we are at the end, so count the factors
        if (remaining > 1) currentFactors[currentFactorCount++] = remaining;
        if (currentFactorCount > count) {
            FOR(i, currentFactorCount) factors[i] = currentFactors[i];
            count = currentFactorCount;
        }
    }

}

int main(int argc, char **argv) {
    FILE *input = fopen("proddiff.in", "r");
    FILE *output = fopen("proddiff.out", "wa");

    int number;
    fscanf(input, "%d", &number);
    FORE(i, 1, 100000) if (number % i == 0) divisors[divisorCount++] = i;

    solve(0, 0, number);

    fprintf(output, "%d\n", count);
    FOR(i, count) {
        fprintf(output, "%s%d", i == 0 ? "" : " ", factors[i]);
    }

    fclose(input);
    fclose(output);
}
