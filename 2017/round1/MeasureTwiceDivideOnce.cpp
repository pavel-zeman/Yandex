// Description
// https://contest.yandex.com/algorithm2017/contest/4541/problems/F/
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

vector<int> neighbors[300010];
bool visited[300010];
queue<int> q;
int last;

void go() {
    while (!q.empty()) {
        last = q.front();
        q.pop();
        for(auto it = neighbors[last].begin(); it != neighbors[last].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

int main(void) {
    int n = getInt();
    FOR(i, n - 1) {
        int u = getInt() - 1;
        int v = getInt() - 1;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }
    q.push(0);
    visited[0] = true;
    go();
    int start = last;

    queue<pair<int, int> > q2;
    q2.push(make_pair(start, 0));
    FOR(i, n) visited[i] = false;
    visited[start] = true;
    int lastDepth = 0;
    while (!q2.empty()) {
        auto p = q2.front();
        lastDepth = p.second;
        q2.pop();
        for(auto it = neighbors[p.first].begin(); it != neighbors[p.first].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                q2.push(make_pair(*it, p.second + 1));
            }
        }
    }
    int res = (lastDepth + 1) / 2 + 1;
    print(res);
}

