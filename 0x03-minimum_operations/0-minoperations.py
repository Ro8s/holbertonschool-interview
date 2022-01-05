#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    operations = 0
    if (n < 0 or type(n) != int):
        return (operations)
    h = "H"
    copy = "H"
    if (n == len(h)):
        return (operations)
    while (1):
        if (n == len(h)):
            break
        elif (n > len(h)):
            if (n % len(h) == 0):
                operations += 2
                copy = h
                h = h + copy
                continue
            else:
                h = h + copy
                operations += 1
                continue
    return (operations)
