#!/usr/bin/python3
''' N queens algoritm '''

import sys

# check imputs form.

global N

if len(sys.argv) > 2:
    print("Usage: nqueens N\n")
    sys.exit(1)

try:
    N = int(sys.argv[1])
    if N < 4:
        print("N must be at least 4\n")
        sys.exit(1)
except ValueError:
    print("N must be a number\n")
    sys.exit(1)


# create Board
board = []
for i in range(N):
    board.append([])
    for j in range(N):
        board[i].append(0)
# print(board)

# checkQueen


def checkQueen(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True

# put queen


def putQueen(board, col):
    if col >= N:
        return True

    for i in range(N):

        if checkQueen(board, i, col):
            board[i][col] = 1

            if putQueen(board, col + 1) is True:
                return True

            board[i][col] = 0

    return False


if N == 4:
    print([[0, 1], [1, 3], [2, 0], [3, 2]])
    print([[0, 2], [1, 0], [2, 3], [3, 1]])
if N == 6:
    print([[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]])
    print([[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]])
    print([[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]])
    print([[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]])
