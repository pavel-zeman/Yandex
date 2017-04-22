// Simple brute force solution
// https://contest.yandex.com/algorithm2015/contest/1238/problems/A/
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

#define MAX_N 200
#define MAX_W 40

char input[MAX_W * 10];
char words[MAX_N][MAX_W];

int main(void) {
    char temp[MAX_W * MAX_N];
    gets(input);
    gets(temp);
    int wordCount = atoi(temp);
    gets(temp);
    int pos = 0;
    FOR(i, wordCount) {
        int start = pos;
        while (temp[pos] >= 'a' && temp[pos] <= 'z') pos++;
        temp[pos] = 0;
        pos++;
        strcpy(words[i], temp + start);
    }

    bool last = false;
    bool correct = true;
    pos = 0;
    while (!last) {
        int start = pos;
        while (input[pos] >= 'a' && input[pos] <= 'z') pos++;
        if (input[pos] == 0 || input[pos] == 10 || input[pos] == 13) last = true;
        input[pos] = 0;
        pos++;
        bool found = false;
        FOR(i, wordCount) if (!strcmp(input + start, words[i])) found = true;
        if (!found) correct = false;
    }
    puts(correct ? "Correct" : "Misspell");
}
