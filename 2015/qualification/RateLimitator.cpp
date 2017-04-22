// Simple math
// https://contest.yandex.com/algorithm2015/contest/1238/problems/D/
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

#define MAX_N 100020
#define SECOND 1000000000

int x;
int y;
int n;
long long int data[MAX_N];


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
    scanf("%d / %d", &x, &y);
    scanf("%d", &n);
    FOR(i, n) scanf("%lld", &data[i]);
    if (y == 1) {
        // x requests per second
        long long int t = 0;
        FOR(i, n) {
            if (i < x) printf("%lld ", t = data[i]);
            else {
                long long int m = data[i - x] + SECOND;
                if (m < t) m = t;
                if (m < data[i]) m = data[i];
                data[i] = m;
                t = m;
                printf("%lld ", t);
            }
        }
    } else {
        // one request in y seconds
        long long int t = 0;
        FOR(i, n) {
            if (data[i] < t) data[i] = t;
            t = data[i];
            printf("%lld ", t);
            t += ((long long int)y) * SECOND;
        }
    }
}
