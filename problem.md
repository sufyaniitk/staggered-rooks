# Problem Statement

Alice and Bob are playing chess on an $n\times n$ chessboard. Bob, frustrated after a losing streak, breaks the chessboard in half so that in the $i$-th column from the left, the bottom $i-1$ squares fall off the chessboard.
Bob produces $n$ rooks from his pocket and poses the following challenge to Alice: If Alice could find the total number of ways one could place *any* number of rooks, from $1$ to $n$, in a way that no two rooks attack each other (i.e., no two share a row or a column) on the broken chessboard, he would admit his defeat to Alice.
Alice spends some time and does come to an answer. However, she can't check whether she's right or not. Write a code for Alice to verify her answers.

More formally, for $1 \leq i \leq n$, let $f(i)$ denote the number of non-attacking configurations of $i$ rooks on the broken chessboard. Compute $\sum f(i)$
