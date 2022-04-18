#!/usr/bin/python3
""" Project """


def rain(walls):
    """ get water """
    wat = 0
    if len(walls) < 1:
        return wat
    for i in range(len(walls)):
        l = walls[i]
        for j in range(i):
            left = max(l, walls[j])
        r = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(r, walls[j])
        wat += min(l, r) - walls[i]
    return wat
