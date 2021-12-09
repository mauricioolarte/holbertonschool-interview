#!/usr/bin/python3

""" Pascal's Triangle """


def pascal_triangle(n):
    """returns a list of lists of integers the Pascal’s triangle of n.
    """

    if n <= 0:
        return []

    pascal_triangle = [[1]]

    for row in range(1, n):
        line = [1] * (row + 1)
        pascal_triangle.append(line)
        for col in range(1, row):
            pascal_triangle[row][col] = pascal_triangle[row-1][col-1]
            pascal_triangle[row][col] += pascal_triangle[row-1][col]

    return pascal_triangle
