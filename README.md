# staggered-rooks
Repo for the codeforces polygon problem staggered-rooks

### Inpiration for the problem
Contrary to popular belief, the problem is **not** inspired from the $n$ queens problem. This is inspired by one of the many applications of *Bell numbers* - a combinatorial problem solving tool, which first encountered application in counting the *number of partitions* of a given set with cardinality $n$. The answer, by definition, is $B(n)$, the $n$-th Bell number.

### The solution
The provided solution is simply an iterative way to find the $n$-th Bell number (demonstrated on [this](https://en.wikipedia.org/wiki/Bell_number) wikipedia page under `Triangle Scheme for Calculations`).

How the Bell numbers solve the problem is demonstrated below.

Given the $n \times n$ staggered chessboard, number the rows, top to down, $1$ to $n$ and the columns, right to left, $2$ to $n+1$. 

Consider a partition of the set $\{1, 2, ..., n+1\}$ Let the partition contain $i$ and $j$ in the same set iff there is a rook on $(i, j)$. Note that if a rook is placed on $(i, j)$ it is *guaranteed* that $i < j$. It is easily verified that this is a bijective map, and thus every partition uniquely counts a rook configuration. Note that the trivial partition $\{\{1\}, \{2\}, ... \{n+1\}\}$  corresponds to placing $0$ rooks, which we don't want to count anyway, thus we print the final result as $B(n+1) - 1$.

### "Wrong" Solutions
A provided file, `semibruteforce.c` is an example of an $\mathcal{O}(n!)$ solution. The idea is to place rooks one by one, guaranteeing that the next rook placed is *below* the first rook. This prevents overcounting. In the code, we place a rook, make the indices of its position equal to `1` in `rowpos` a=nd `colpos`, set the value of `last` (which represents the last row in which a rook is placed) and call the `solve()` function with these new parameters. This is only *semi*-bruteforce, because once a rook is placed, it increments the counter for the currently placed number of rooks in `ansarr`. Meaning, while constructing a solution for say, $6$ rooks, I also count all solutions for $5$ rooks that I encounter, rather than solving for $5$ rooks seperately.

### "Source" for the problem
The problem is deeply inspired by both the plethora of chessboard/grid problems in competitive programming, and also the previously mentioned result. Although, the result itself is phrased as a problem in the text `A Walk Through Combinatorics` by Miklós Bóna. It is problem $4(a)$ in the chapter on partitions.

### Further extensions
A possible extension of this problem is to replace nonattacking rooks with nonattacking *bishops*. Although I wanted to try and find a neat combinatorial argument for that, I haven't really been able to come up with anything. Although we can still use the semibruteforce approach. Every $i+j$ uniquely defines a "going up" diagonal, and $|i-j|$ define a "going down" diagonal. We'll have to pass in what diagonals are occupied, which can be done in the same way as in the rook problem, but using $i+j$ and $|i-j|$ as indices.
