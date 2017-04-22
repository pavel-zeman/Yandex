//
// https://contest.yandex.com/algorithm2015/contest/1241/problems/C/
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
#include <stack>

using namespace std;

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_N 5010

char matrix[MAX_N][MAX_N];
int m, n;



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

int max(int a, int b) {
    return a > b ? a : b;
}

int maximalRectangle() {
    n++;
    int h = 0, w = 0, ret = 0;
    vector<int> height(n, 0);

    for (int i = 0; i < m; ++i) {
        stack<int> s;
        for (int j = 0; j < n; ++j) {
            // set value
            if (j < n - 1) {
                if (matrix[i][j] == 0) height[j] += 1;
                else height[j] = 0;
            }

            // compute area
            while (!s.empty() && height[s.top()] >= height[j]) {
                h = height[s.top()];
                s.pop();
                w = s.empty() ? j : j - s.top() - 1;
                if (h * w > ret) ret = h * w;
            }

            s.push(j);
        }
    }

    return ret;
}


void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    m = getInt();
    n = getInt();
    FOR(i, m) FOR(j, n) matrix[i][j] = 0;
    int k = getInt();
    int ms = 0;
    FOR(kk, k) {
        int x1 = getInt();
        int y1 = getInt();
        int x2 = getInt();
        int y2 = getInt();
        if (x1 > x2) swap(&x1, &x2);
        if (y1 > y2) swap(&y1, &y2);
        if ((x2 - x1) * (y2 - y1) > ms) ms = (x2 - x1) * (y2 - y1);
        if (x1 > 0) x1--;
        if (x2 < m) x2++;
        if (y1 > 0) y1--;
        if (y2 < n) y2++;
        FORE(i, x1, x2) FORE(j, y1, y2) matrix[i][j] = 1;
    }
    printf("%d\n", max(ms, maximalRectangle()));
}
