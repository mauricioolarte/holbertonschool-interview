#!/usr/bin/python3
''' N queens algoritm
'''

import sys

# check imputs form.

global N

if len(sys.argv) > 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    N = int(sys.argv[1])
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)
except ValueError:
    print("N must be a number")
    sys.exit(1)


def queens(n, i, a, b, c):
    if i < n:
        for j in range(n):
            if j not in a and i + j not in b and i - j not in c:
                yield from queens(n, i + 1, a + [j], b + [i + j], c + [i - j])
    else:
        yield a


for solution in queens(N, 0, [], [], []):
    res = []
    for i in range(len(solution)):
        res.append([i, solution[i]])
    print(res)
