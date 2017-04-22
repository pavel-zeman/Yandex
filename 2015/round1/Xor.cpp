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

bool used[MAX_N];

int main(void) {
    FOR(n, 10) {
        FOR(i, MAX_N) used[i] = false;
        FOR(i, MAX_N * 100) {
            int res = i ^ (i + n);
            if (res < MAX_N) used[res] = true;
        }
        printf("%d ", n);
        FOR(i, MAX_N) if (used[i]) printf("%d ", i);
        printf("\n");
    }

}
