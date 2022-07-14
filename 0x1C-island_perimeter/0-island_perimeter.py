#!/usr/bin/python3
"""
Project
"""


def island_perimeter(grid):
    """
    Island perimeter
    """

    perimeter = 0
    m = len(grid)
    n = len(grid[0])

    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                for x, y in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                    l, s = i + x, j + y
                    # print(l, s)
                    if l >= m or s >= n or l < 0 or s < 0 or grid[l][s] == 0:
                        perimeter += 1

    return perimeter
