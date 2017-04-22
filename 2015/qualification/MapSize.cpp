//
// https://contest.yandex.com/algorithm2015/contest/1238/problems/E/
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

#define MAX_D 100000
int divisors1[MAX_D];
int divisors2[MAX_D];
int temp[MAX_D];


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


int getDivisors(int n, int *result) {
    int c = 0;
    int c2 = 0;
    int d = 1;
    while (d * d <= n) {
        if (n % d == 0) {
            result[c++] = d;
            if (d * d < n) temp[c2++] = n / d;
        }
        d++;
    }
    FOR(i, c2) result[c + i] = temp[i];
    return c + c2;
}

int main(void) {
    int n = getInt();
    int m = getInt();
    long long int l = getLongLongInt();
    long long int r = getLongLongInt();
    int c1 = getDivisors(n, divisors1);
    int c2 = getDivisors(m, divisors2);
    int total = 0;
    FOR(i, c1) FOR(j, c2) {
        long long int product = ((long long int)divisors1[i]) * divisors2[j];
        if (product >= l && product <= r) total++;
    }
    printf("%d\n", total);
}
