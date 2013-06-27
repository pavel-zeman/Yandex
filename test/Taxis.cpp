#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include <iostream>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAXN 500100

long long int m, d;
int n;
long long dist[MAXN];


int sign(long long int a) {
    if (a < 0) return -1;
    return a > 0 ? 1 : 0;
}

int cmp(const void *v1, const void *v2) {
     return sign(*(long long int *)v2 - *(long long int *)v1);
}


int main(void) {
    FILE *input = fopen("taxi.in", "r");
    FILE *output = fopen("taxi.out", "a");
    fscanf(input, "%lld%lld%d", &m, &d, &n);
    FOR(i, n) fscanf(input, "%lld", &dist[i]);

    long long joker = -1;
    int jokerPos = -1;
    FOR(i, n) if (dist[i] >= m - d && (joker == -1 || dist[i] < joker)) {
        joker = dist[i];
        jokerPos = i;
    }
    if (jokerPos == -1) {
        fprintf(output, "0");
        fclose(output);
        return 0;
    }

    if (jokerPos != n - 1) {
        dist[jokerPos] = dist[n - 1];
        dist[n - 1] = joker;
    }

    qsort(dist, n - 1, sizeof(dist[0]), cmp);


    long long int pos = 0;
    int use = 0;
    while (pos < d && use < n - 1) {
        if (dist[use] > d - pos) {
            pos += dist[use] - (d - pos);
            use++;
        } else
            break;
    }
    if (pos >= m) {
        // nothing
    } else if (pos >= d) {
        use++;
    } else {
        pos += joker - (d - pos);
        use++;
        if (pos < m) use = 0;
    }

    fprintf(output, "%d", use);

    fclose(input);
    fclose(output);
}
