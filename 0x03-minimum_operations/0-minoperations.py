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
    while (n > len(h)):
        if (n % len(h) == 0):
            operations += 2
            copy = h
            h = h + copy
        else:
            h = h + copy
            operations += 1
    return (operations)
