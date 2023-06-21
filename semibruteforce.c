#include <stdio.h>

void solve(long n, int r, long arr[][n], int last, int* rowpos, int* colpos, int* ansarr) {
    long ans = 0;
    long empty = 0;

    for (long i = last+1; i < n; i++) for (long j = 0; j < n; j++) if (arr[i][j] == 0 && rowpos[i] == 0 && colpos[j] == 0) empty++;
    // "empty" here is where I can safely place a rook

    long occrows = 0;
    for (int i = 0; i < n; i++) occrows+=rowpos[i]; // this will be useful

    if (r > n - occrows) {
        return; // impossible to place more rooks than free rows
    }
    if (r == 1) {
        ansarr[n+1] += empty; // we can't really tell what number of rooks to increment here, so just increment a filler index
        return;
    }
    if (empty == 0)  return; // nothing to be done here
    if (r > empty) {
        solve(n, empty, arr, last, rowpos, colpos, ansarr); // 4 rooks and 3 empty squares can still contain a solution for 2 rooks, probably
        return;
    }

    for (long i = last + 1; i < n; i++) {
        for (long j = 0; j < n; j++) {
            if(rowpos[i] == 1 || colpos[j] == 1 || arr[i][j] == -1) continue; // can't place a rook here
            ansarr[n - r + 1]++; // increment the number of solutions found
            arr[i][j] = 1; // placed the rook (this isn't necessary but it's a neat looking statement originally for debugging)

            rowpos[i] = 1; colpos[j] = 1; // setup for the main step
            solve(n, r-1, arr, i, rowpos, colpos, ansarr); // the main step
          
            rowpos[i] = 0; colpos[j] = 0; // once all the recursive iterations for this rook position are done, we remove the rook from here
            arr[i][j] = 0; // again, not really necessary. I could save about *n* time if I remove the board array entirely. But in the face of
          // n! I've optimised essentially nothing
        }
    }
    return;
}

int main() {

    long n; scanf("%ld", &n);

    long arr[n][n];
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n-i; j++) arr[i][j] = 0;
        for (long j = n-i; j < n; j++) arr[i][j] = -1; // just initialising the board
    }

    long ans = 0;

    int row_pos[n]; int col_pos[n]; int ansarr[n+2];

    for (int i = 0; i < n; i++) {
        row_pos[i] = 0;
        col_pos[i] = 0;
        ansarr[i] = 0;
    } ansarr[n] = 0; ansarr[n+1] = 0; // will need the extra index as a filler

    solve(n, n, arr, -1, row_pos, col_pos, ansarr); // here it goes
    for (int i = 0; i < n+2; i++) ans += ansarr[i]; // extracting the answer
    printf("%ld\n", ans); // printing the answer (duh)

    return 0;
}
