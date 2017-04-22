//
// http://contest2.yandex.com/algorithm2014/contest/502/problems/C/
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

#define MAX_N 1001


long long int nominator[MAX_N];
long long int denominator[MAX_N];
bool used[MAX_N];


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

long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    int n = getInt();
    FOR(i, n) {
        long long int a = getInt(), b = getInt(), c = getInt();
        long long int s = a + b + c;
        long long int v1 = (s - 2 * a) * (s - 2 * b) * (s - 2 * c);
        long long int v2 = s;
        long long int g = gcd(v1, v2);
        nominator[i] = v1 / g;
        denominator[i] = v2 / g;
    }
    int max = 0;
    FOR(i, n) used[i] = false;
    FOR(i, n)
        if (!used[i]) {
            int t = 1;
            FORE(j, i + 1, n)
                if (!used[j] && nominator[j] == nominator[i] && denominator[j] == denominator[i]) {
                    used[j] = true;
                    t++;
                }
            if (t > max) max = t;
        }
    printf("%d", max);

}

