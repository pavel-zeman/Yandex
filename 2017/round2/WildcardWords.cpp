// Description
// https://contest.yandex.com/algorithm2017/contest/4574/problems/C/
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


char s[100010];

struct Node {
    int next[26];
    vector<int> positions;
} nodes[2000000];
int totalNodes = 1;
char p[20];

void addNode(int start, int length) {
    int n = 0;
    FOR(i, length) {
        int c = s[i + start] - 'a';
        if (nodes[n].next[c] == 0) {
            nodes[n].next[c] = totalNodes++;
        }
        n = nodes[n].next[c];
    }
    nodes[n].positions.push_back(start);
}

int findNode(int start, int length) {
    int n = 0;
    FOR(i, length) {
        int c = p[start + i] - 'a';
        if (nodes[n].next[c] == 0) return -1;
        n = nodes[n].next[c];
    }
    return n;
}

//char tt[100001];


bool check(int pos, int l, int r) {
    if (p[pos] == '*') {
        while (p[pos] == '*') pos++;
        if (!p[pos]) return true;
        int p2 = pos;
        while (p[p2] && p[p2] != '*') p2++;
        int reml = p2 - pos;
        if (!p[p2]) return r -l + 1 >= reml && !strncmp(s + r - reml + 1, p + pos, reml);
        int n = findNode(pos, reml);
        if (n < 0) return false;
        auto it = lower_bound(nodes[n].positions.begin(), nodes[n].positions.end(), l);
        if (it == nodes[n].positions.end()) return false;
        return r - *it + 1 >= reml && check(p2, *it + reml, r);
    } else {
        int p2 = pos;
        while (p[p2] && p[p2] != '*') p2++;
        int reml = p2 - pos;
        if (!p[p2]) return reml == r - l + 1 && !strncmp(s + l, p + pos, reml);
        return r - l + 1 >= reml && !strncmp(s + l, p + pos, reml) && check(p2, l + reml, r);
    }
}

int main(void) {
    //FOR(i, 100000) tt[i] = rand() % 26 + 'a';
    //printString(tt);
    //return 0;
    int l = getString(s);
    FORE(i, 1, 11) {
        if (i > l) break;
        FOR(j, l - i + 1) addNode(j, i);
    }
    int q = getInt();
    FOR(i, q) {
        int l = getInt() - 1;
        int r = getInt() - 1;
        getString(p);
        printString(check(0, l , r) ? "Yes" : "No");
    }
    //print(totalNodes);
    //getString(s);
}

