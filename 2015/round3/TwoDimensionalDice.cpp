//
// https://contest.yandex.com/algorithm2015/contest/1241/problems/A/
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
#include <math.h>

using namespace std;

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


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

int abs(int x) {
    return x < 0 ? -x : x;
}

int main(void) {
    double h = getInt();
    double l = getInt();
    double hSum = getInt() + getInt();
    double lSum = getInt() + getInt();
    double angle = atan(h / l);
    double hFactor = angle / M_PI * 2;
    double lFactor = 1 - hFactor;

    printf("%.10lf\n", hSum / 2 * hFactor + lSum / 2 * lFactor);
}
