//
// https://contest.yandex.com/algorithm2015/contest/1239/problems/B/
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

struct Point {
    int x;
    int y;
    int a;
    int aaa;
} point[MAX_N];


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
    int n = getInt();
    int sum = 0;
    FOR(i, n) {
        point[i].x = getInt();
        point[i].y = getInt();
        point[i].a = getInt();
        sum += point[i].a;
    }
    int result = 1200000000;
    if (n == 1) result = point[0].a;
    else if (n == 2) result = abs(point[0].a - point[1].a);
    FOR(i, n) FORE(j, i + 1, n) {
        int dx = point[j].x - point[i].x;
        int dy = point[j].y - point[i].y;
        int a = -dy;
        int b = dx;
        int c = a * point[i].x + b * point[i].y;
        int p1 = 0;
        int p2 = 0;
        int l = point[i].a + point[j].a;
        FORE(k, 0, i) {
            int s = a * point[k].x + b * point[k].y;
            if (s < c) p1 += point[k].a;
        }
        FORE(k, i + 1, j) {
            int s = a * point[k].x + b * point[k].y;
            if (s < c) p1 += point[k].a;
        }
        FORE(k, j + 1, n) {
            int s = a * point[k].x + b * point[k].y;
            if (s < c) p1 += point[k].a;
        }
        p2 = sum - p1 - l;
        if (abs(p1 + l - p2) < result) result = abs(p1 + l - p2);
        if (abs(p1 - p2 - l) < result) result = abs(p1 - p2 - l);
    }
    printf("%d\n", result);
}
