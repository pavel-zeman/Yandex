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

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int xa = getInt();
    int ya = getInt();
    int xb = getInt();
    int yb = getInt();
    if (xa > xb) {
        swap(&xa, &xb);
        swap(&ya, &yb);
    }
    unsigned long long int dist = xb - xa;
    unsigned long long int f = ya + yb;
    unsigned long long int r = dist * dist + f * f;
    printf("%llu.00000000000000000000", r);
}
