#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


#define SIEVE_SIZE 32000
#define MAX_FACTOR 100

bool prime[SIEVE_SIZE];
int primes[SIEVE_SIZE];
int primesCount = 0;

int main(int argc, char **argv) {

    FOR(i, SIEVE_SIZE) prime[i] = true;
    FORE(i, 2, SIEVE_SIZE) {
        if (prime[i]) {
            primes[primesCount++] = i;
            int j = i + i;
            while (j < SIEVE_SIZE) {
                prime[j] = false;
                j += i;
            }
        }
    }

    int t;
    scanf("%d", &t);
    FOR(tt, t) {
        int n, k;
        int factors[MAX_FACTOR];
        int factorCount = 0;
        int totalFactors = 0;
        scanf("%d %d", &n, &k);
        FOR(i, primesCount) {
            if (n % primes[i] == 0) {
                factors[factorCount] = 0;
                //printf("Prime: %d ", primes[i]);
                while (n % primes[i] == 0) {
                    n /= primes[i];
                    factors[factorCount]++;
                    totalFactors++;
                }
                factorCount++;
            }
        }
        /*printf("%d %d ", totalFactors, factorCount);
        FOR(i, factorCount) printf("%d ", factors[i]);*/
        if (n > 1) {
            factors[factorCount++] = 1;
            totalFactors++;
        }
        if (k > totalFactors) printf("NO");
        else if (factorCount >= 2) printf("YES");
        else {
            totalFactors -= k;
            printf("%s", totalFactors % 2 == 0 ? "YES" : "NO");
        }
        printf("\n");
    }
}
