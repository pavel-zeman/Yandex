//
//
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_N 1010
int n, m, k;

bool used[MAX_N][MAX_N];
int degree[MAX_N];

char c = 0;
int getInt() {
    int r = 0;
    while (!(c == '-' || (c >= '0' && c <= '9') || c == EOF)) c = getc_unlocked(stdin);
    bool minus = c == '-';
    if (minus) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return minus ? -r : r;
}

long long int getLongLongInt() {
    long long int r = 0;
    while (!(c == '-' || (c >= '0' && c <= '9') || c == EOF)) c = getc_unlocked(stdin);
    bool minus = c == '-';
    if (minus) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}


int main(void) {
    n = getInt();
    m = getInt();
    k = getInt();
    FOR(i, n) degree[i] = 0;
    FOR(i, n) FOR(j, n) used[i][j] = false;

    FOR(i, n) {
        while (degree[i] < k) {
            int minDeg = n + 1;
            int minv = 0;
            FORE(j, i + 1, n) if (!used[i][j] && degree[j] < minDeg) {
                minDeg = degree[j];
                minv = j;
            }
            used[i][minv] = used[minv][i] = true;
            degree[i]++;
            degree[minv]++;
            printf("%d %d\n", i + 1, minv + 1);
            m--;
        }
    }
    FOR(i, n) FORE(j, i + 1, n)
        if (i != j && !used[i][j] && m > 0) {
            used[i][j] = used[j][i] = true;
            printf("%d %d\n", i + 1, j + 1);
            m--;
        }
}
