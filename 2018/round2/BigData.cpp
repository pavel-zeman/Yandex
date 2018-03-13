// Description
// https://contest.yandex.com/algorithm2018/contest/7736/problems/B/
#include <bits/stdc++.h>
using namespace std;

#define FOR(c, m) for(int c=0;c<(int)(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)
#define LLI long long int
#define MOD 1000000007


char ccc = 0;
int getInt() {
    int r = 0;
    while (!(ccc >= '0' && ccc <= '9')) ccc = getc_unlocked(stdin);
    while (ccc >= '0' && ccc <= '9') {
        r = r * 10 + (ccc - '0');
        ccc = getc_unlocked(stdin);
    }
    return r;
}

int getString(char *start) {
    char *data = start;
    while (!(ccc > ' ' && ccc <= '~')) ccc = getc_unlocked(stdin);
    while (ccc > ' ' && ccc <= '~') {
        *data++ = ccc;
        ccc = getc_unlocked(stdin);
    }
    *data = 0;
    return data - start;
}


int getSignedInt() {
    int r = 0;
    while (!(ccc == '-' || (ccc >= '0' && ccc <= '9'))) ccc = getc_unlocked(stdin);
    bool minus = ccc == '-';
    if (minus) ccc = getc_unlocked(stdin);
    while (ccc >= '0' && ccc <= '9') {
        r = r * 10 + (ccc - '0');
        ccc = getc_unlocked(stdin);
    }
    return minus ? -r : r;
}

long long int getLongLongInt() {
    long long int r = 0;
    while (!(ccc >= '0' && ccc <= '9')) ccc = getc_unlocked(stdin);
    while (ccc >= '0' && ccc <= '9') {
        r = r * 10 + (ccc - '0');
        ccc = getc_unlocked(stdin);
    }
    return r;
}


template <class type> void print(type a) {
    if (a < 0) {
        putc_unlocked('-', stdout);
        a = -a;
    }
    if (a == 0) {
        putc_unlocked('0', stdout);
    } else {
        char result[20];
        int resSize = 0;
        while (a > 0) {
            result[resSize++] = '0' + a % 10;
            a /= 10;
        }
        while (--resSize >= 0) putc_unlocked(result[resSize], stdout);
    }
    putc_unlocked('\n', stdout);
}

void printString(const char *str) {
    while (*str) putc_unlocked(*str++, stdout);
    putc_unlocked('\n', stdout);
}

int power(int a, int b) {
    int sq = a;
    int result = 1;
    while (b > 0) {
        if ((b & 1) == 1) result = result * (LLI)sq % MOD;
        sq = sq * (LLI)sq % MOD;
        b >>= 1;
    }
    return result;
}

int inv(int a) {
    return power(a, MOD - 2);
}

template <class type> type gcd(type a, type b) {
    return b == 0 ? a : gcd(b, a % b);
}

void fail() {
    *((char *)0) = 0;
}

double cpu() {
    return clock() / (double)CLOCKS_PER_SEC;
}

#define MAX_N 100010
int a[MAX_N];
int ha[10];
int b[MAX_N];
int hb[10];

int n, m;

int sum(int *d, int c) {
    int res = 0;
    FOR(i, c) res += d[i];
    return res;
}

int fp(int *d, int v) {
    FOR(i, MAX_N) if (d[i] == v) return i;
}

#define MUL 1000000000

int main(void) {
    n = getInt();
    m = getInt();
    FOR(i, n) a[i] = getInt();
    FOR(i, m) b[i] = getInt();
    FOR(i, n) ha[a[i]]++;
    FOR(i, m) hb[b[i]]++;
    int maxa = 9;
    while (!ha[maxa]) maxa--;
    int maxb = 9;
    while (!hb[maxb]) maxb--;

    LLI result = 0;
    if (maxa == 0) {
        result = sum(b, m) + (n - 1) * maxb;
    } else if (ha[maxa] == 1) {
        int pos = fp(a, maxa);
        result = m * (LLI)maxa * MUL + (sum(a, n) - maxa) * (LLI)MUL +
            sum(b, m) + b[0] * pos + b[m - 1] * (n - 1 - pos);
    } else {
        int pos1 = fp(a, maxa);
        int pos2 = n - 1;
        while (a[pos2] != maxa) pos2--;

        int pb = fp(b, maxb);
        result = m * (LLI)maxa * MUL + sum(b, m) + (sum(a, n) - maxa) * (LLI)MUL;
        if (pb == 0) {
            result += pos2 * b[0] + b[m - 1] * (n - 1 - pos2);
        } else if (pb == m - 1) {
            result += pos1 * b[0] + b[m - 1] * (n - 1 - pos1);
        } else {
            result += pos1 * b[0] + (pos2 - pos1) * maxb + b[m - 1] * (n - 1 - pos2);
        }
    }
    print(result);
}

