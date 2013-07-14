#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_N 1010
#define MAX_M 1010

int main(int argc, char **argv) {
    int n, m;
    char result[MAX_N][MAX_M];
    scanf("%d%d", &n, &m);

    int total = n * m;
    int parts = 0;
    int i = 1;
    while (total >= i) {
        total -= i;
        i++;
        parts++;
    }

    printf("%d\n", parts);
    char letters[2] = {0, 1};
    int currentLetter = 0;
    int part = 1;
    int remaining = parts == 1 ? n * m : 1;
    bool lineChanged = false;

    FOR(i, n) {
        FOR(j, m) {
            result[i][i % 2 == 0 ? j : m - j - 1] = letters[currentLetter];
            remaining--;
            if (remaining == 0) {
                currentLetter ^= 1;
                part++;
                if (lineChanged || j == m - 1 || part == parts) {
                    letters[0] += 2;
                    letters[1] += 2;
                    letters[0] %= 26;
                    letters[1] %= 26;
                    lineChanged = false;
                }
                remaining = part == parts ? part + total : part;
            }
        }
        lineChanged = true;
    }

    FOR(i, n) {
        FOR(j, m) printf("%c", result[i][j] + 'A');
        printf("\n");
    }


}
