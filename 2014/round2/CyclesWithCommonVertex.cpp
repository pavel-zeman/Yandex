//
// http://contest2.yandex.com/algorithm2014/contest/505/problems/A/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

using namespace std;

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


char c = 0;
int getInt() {
    int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}


int main(void) {
    int n = getInt();
    int k = getInt();
    long long int total = 0;
    if (n == 1) {
        int x = getInt();
        total = (x + 1) / k;
    } else {
        int minStart = (k - 2) / 2;
        int minEnd = k - 2 - minStart;
        FOR(i, n) {
            int x = getInt();
            int remain = x - minStart - minEnd - 1;
            if (remain >= 0) {
                total += remain / k + 1;
                if (remain % k == 0) {
                    if (minStart != minEnd) minStart = minEnd;
                }
            }
        }
    }
    printf("%lld\n", total);
}
