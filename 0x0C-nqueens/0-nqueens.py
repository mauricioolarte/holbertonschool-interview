#!/usr/bin/python3
''' N queens algoritm '''

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


# create Board
board = []
for i in range(N):
    board.append([])
    for j in range(N):
        board[i].append(0)
print(board)

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
            # Place this queen in board[i][col]
            board[i][col] = 1

            # recur to place rest of the queens
            if putQueen(board, col + 1) is True:
                return True

            # If placing queen in board[i][col
            # doesn't lead to a solution, then
            # queen from board[i][col]
            board[i][col] = 0

    # if the queen can not be placed in any row in
    # this colum col  then return false
    return False


putQueen(board, 1)
print(board)
