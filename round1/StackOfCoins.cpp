#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


#define MAX_LEVEL 1000010

int gold[MAX_LEVEL];
int silver[MAX_LEVEL];

int stackCounts[MAX_LEVEL];


int min(int a, int b) {
    return a < b ? a : b;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    FOR(i, MAX_LEVEL) gold[i] = silver[i] = stackCounts[i] = 0;

    FOR(i, n) {
        char line[MAX_LEVEL];
        scanf("%s", line);
        int l = strlen(line);
        stackCounts[l - 1]++;
        FOR(j, l)
            if (line[j] == 'S') silver[j]++; else gold[j]++;
    }

    int total = 0;
    for(int i=MAX_LEVEL-1;i>=0;i--) {
        if (stackCounts[i] > 0) {
            int minSilver = silver[i];
            int minGold = gold[i];
            for(int j=i-1;j>=0;j--) {
                minSilver = min(minSilver, silver[j]);
                minGold = min(minGold, gold[j]);
            }

            int useSilver = min(stackCounts[i], minSilver);
            if (useSilver > 0) {
                total += useSilver;
                stackCounts[i] -= useSilver;
                for(int j=i;j>=0;j--) silver[j] -= useSilver;
            }

            int useGold = min(stackCounts[i], minGold);
            if (useGold > 0) {
                total += useGold;
                for(int j=i;j>=0;j--) gold[j] -= useGold;
            }
        }
    }
    printf("%d", total);


}
