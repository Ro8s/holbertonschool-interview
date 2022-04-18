#!/usr/bin/python3
""" Project """


def rain(walls):
    """ get water """
    wat = 0
    if len(walls) < 1 or type(walls) is not list:
        return wat
    for i in range(len(walls)):
        l = walls[i]
        for j in range(i):
            l = max(l, walls[j])
        r = walls[i]
        for j in range(i + 1, len(walls)):
            r = max(r, walls[j])
        wat += min(l, r) - walls[i]
    return wat
