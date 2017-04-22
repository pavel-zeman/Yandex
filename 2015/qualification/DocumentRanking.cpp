// Use STL map, which is sorted, to store the document relevance
// https://contest.yandex.com/algorithm2015/contest/1238/problems/C/
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

#define MAX_N 102
#define MAX_D 100010
long long int a[MAX_N];
int n;
int d;
int f[120000];
long long int relevance[MAX_D];
map<long long int, int> docs;



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
    n = getInt();
    FOR(i, n) a[i] = getInt();
    d = getInt();
    FOR(i, d) FOR(j, n) f[i * n + j] = getInt();

    FOR(i, d) {
        long long int total = 0;
        FOR(j, n) total += a[j] * f[i * n + j];
        docs[total] = i;
        relevance[i] = total;
    }

    int q = getInt();
    map<long long int, int>::iterator it;
    int k;
    FOR(i, q) {
        int op = getInt();
        switch (op) {
            case 1:
                k = getInt();
                it = docs.end();
                FOR(i, k) {
                    it--;
                    printf("%d ", it->second + 1);
                }
                printf("\n");
                break;

            case 2:
                d = getInt() - 1;
                int j = getInt() - 1;
                int v = getInt();
                docs.erase(relevance[d]);
                relevance[d] -= a[j] * f[d * n + j];
                f[d * n + j] = v;
                relevance[d] += a[j] * f[d * n + j];
                docs[relevance[d]] = d;
                break;
        }
    }

}
