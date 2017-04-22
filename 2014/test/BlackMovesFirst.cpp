//
// http://contest2.yandex.com/algorithm2014/contest/502/problems/A/
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


#define EMPTY 0
#define WR 1
#define WK 2
#define BK 3
#define ATTACKED 4


int board[8][8];

void read(int *x, int *y) {
    char temp[4];
    scanf("%s", temp);
    *x = temp[0] - 'a';
    *y = temp[1] - '1';
}

int abs(int a) {
    return a < 0 ? -a : a;
}

bool canMove(int x, int y) {
    FOR(i, 8) FOR(j, 8)
        if (abs(x - i) <= 1 && abs(y - j) <= 1 && (x != i || y != j)) {
            if (board[i][j] == EMPTY || board[i][j] == WK || board[i][j] == WR) return true;

        }
    return false;
}

int main(void) {
    int bkx, bky, wkx, wky, wrx, wry;
    read(&wkx, &wky);
    read(&wrx, &wry);
    read(&bkx, &bky);

    FOR(i, 8) FOR(j, 8) board[i][j] = EMPTY;
    board[wkx][wky] = WK;
    board[wrx][wry] = WR;


    int x = wrx + 1;
    while (x < 8 && board[x][wry] == EMPTY) board[x++][wry] = ATTACKED;
    if (x < 8 && board[x][wry] == WK) board[x][wry] = ATTACKED;

    x = wrx - 1;
    while (x >= 0 && board[x][wry] == EMPTY) board[x--][wry] = ATTACKED;
    if (x >=0 && board[x][wry] == WK) board[x][wry] = ATTACKED;

    int y = wry + 1;
    while (y < 8 && board[wrx][y] == EMPTY) board[wrx][y++] = ATTACKED;
    if (y < 8 && board[wrx][y] == WK) board[wrx][y] = ATTACKED;

    y = wry - 1;
    while (y >= 0 && board[wrx][y] == EMPTY) board[wrx][y--] = ATTACKED;
    if (y >= 0 && board[wrx][y] == WK) board[wrx][y] = ATTACKED;


    FOR(i, 8) FOR(j, 8) if (abs(i - wkx) <= 1 && abs(j - wky) <= 1 && board[i][j] == EMPTY) {
        board[i][j] = ATTACKED;
    }

    if (abs(wkx - bkx) <= 1 && abs(wky - bky) <= 1) {
        printf("Strange");
    } else if (board[bkx][bky] == EMPTY && canMove(bkx, bky)) {
        printf("Normal");
    } else if (board[bkx][bky] == ATTACKED && canMove(bkx, bky)) {
        printf("Check");
    } else if (board[bkx][bky] == EMPTY && !canMove(bkx, bky)) {
        printf("Stalemate");
    } else if (board[bkx][bky] == ATTACKED && !canMove(bkx, bky)) {
        printf("Checkmate");
    }
}

