#!/usr/bin/python3

""" module """


def island_perimeter(grid):
    """ returns the perimeter of the island described in grid.
    """

    lenGrid = len(grid[0])
    water = [0] * (lenGrid + 2)
    perimeter = 0

    grid.insert(0, water)
    grid.append(water)

    for row in range(1, len(grid) - 1):
        grid[row].insert(0, 0)
        grid[row].append(0)
        for col in range(1, lenGrid + 1):
            if grid[row][col] == 1:
                if grid[row - 1][col] == 0:
                    perimeter += 1
                if grid[row + 1][col - 1] == 0:
                    perimeter += 1
                if grid[row][col - 1] == 0:
                    perimeter += 1
                if grid[row][col + 1] == 0:
                    perimeter += 1
    return perimeter
