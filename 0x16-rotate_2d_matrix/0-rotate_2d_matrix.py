#!/usr/bin/python3
"""0. Rotate 2D Matrix
"""


def swap(m, i, j, param=None):
    """interchange the values of an matrix
    """
    if not param:
        m[i][j] = m[i][j] * m[j][i]
        m[j][i] = m[i][j] // m[j][i]
        m[i][j] = m[i][j] // m[j][i]
    else:
        m[i][j] = m[i][j] * m[i][param]
        m[i][param] = m[i][j] // m[i][param]
        m[i][j] = m[i][j] // m[i][param]


def rotate_2d_matrix(matrix):
    """Rotates a matrix in place clockwise.
    """
    for i in range(len(matrix)):
        for j in range(i + 1, len(matrix[i])):
            swap(matrix, i, j)

    for i in range(len(matrix)):
        s = 0
        param = len(matrix) - 1
        while s < param:
            swap(matrix, i, s, param)
            s += 1
            param -= 1
