// Description
// https://contest.yandex.com/algorithm2017/contest/4541/problems/D/
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

int a[1000];
int b[1000];
int bet[1000];

struct Node {
    int v[3];

    bool operator<(const Node &other) const {
        return v[0] < other.v[0] ||
        (v[0] == other.v[0] && v[1] < other.v[1]) ||
        (v[0] == other.v[0] && v[1] == other.v[1] && v[2] < other.v[2]);
    }
};

set<Node> best[1000];


int mm(const int *a) {
    return min(a[0], min(a[1], a[2]));
}

int main(void) {
    int n = getInt();
    char line[10];
    FOR(i, n) {
        getString(line);
        a[i] = getInt();
        b[i] = getInt();
        switch (line[0]) {
            case 'W': bet[i] = 0; break;
            case 'D': bet[i] = 1; break;
            case 'L': bet[i] = 2; break;
        }
    }
    FOR(i, n) {
        Node x;
        FOR(j, 3) x.v[j] = bet[i] == j ? -a[i] : b[i];
        int mn = mm(x.v);
        best[i].insert(x);
        FOR(j, i) {
            for(auto it = best[j].begin(); it != best[j].end(); it++) {
                FOR(k, 3) x.v[k] = it->v[k] + (bet[i] == k ? -a[i] : b[i]);
                //int mn2 = mm(x.v);
                //if (mn2 > mn) {
                    //best[i].clear();
                    best[i].insert(x);
                    //mn = mn2;
                //} else if (mn2 == mn) best[i].insert(x);
            }
        }
        //FOR(j, 3) printf("%d ", best[i][j]);
        //printf("\n");
    }
    int res = 0;
    FOR(i, n) {
        for(auto it = best[i].begin(); it != best[i].end(); it++) {
            int xx = mm(it->v);
            if (xx > res) res = xx;
        }
    }
    if (res < 0) res = 0;
    print(res);
}

