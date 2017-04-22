//
// http://contest2.yandex.com/algorithm2014/contest/505/problems/D/
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

int invs[1000000];
bool used[100000];

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
    int k = getInt();

    int n = 1;
    while (n * (n - 1) / 2 < k) {
        invs[n] = n * (n - 1) / 2;
        n++;
    }
    printf("%d\n", n);
    FOR(i, n) used[i] = false;

    FOR(i, n) {
        int x = 1;
        if (i != n - 1) {
            while (k - (x - 1) > invs[n - i - 1]) x++;
            k -= x - 1;
        }
        //printf("X:%d ", x);
        FOR(j, n) {
            if (!used[j]) {
                if (--x == 0) {
                    used[j] = true;
                    printf("%d ", j + 1);
                    break;
                }
            }
        }
    }
}
