#!/usr/bin/python3
"""program that solves the N queens problem"""

import sys


def queens(n):
    """program that solves the N queens problem"""
    trail = []
    sets = set()
    for column in range(n):
        trail.append([0, column])
        sets.add(column)

    road = []
    while trail:
        [row, column] = trail.pop(0)
        while road and (row < road[0][0]):
            road.pop(0)
        if road and (row == road[0][0]):
            road[0] = [row, column]
        else:
            road.insert(0, [row, column])

        nextsrows = row + 1
        death = set()
        for (i, j) in road:
            death.add(j)
            distance = nextsrows - i
            if j - distance >= 0:
                death.add(j - distance)
            if j + distance < n:
                death.add(j + distance)

        safe = sets.difference(death)
        if not safe:
            if nextsrows == n:
                temp = road.copy()
                temp.reverse()
                print(temp, flush=True)
            road.pop(0)
        else:
            safe = list(safe)
            safe.reverse()
            for position in safe:
                trail.insert(0, [nextsrows, position])


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)

    try:
        n = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)
    queens(n)
