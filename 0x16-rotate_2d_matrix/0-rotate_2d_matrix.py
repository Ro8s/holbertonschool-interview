#!/usr/bin/python3
""" rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """ rotate 2D Matrix """
    n = len(matrix[0])
    for i in range(0, n):
        for j in range(i, n):
            t = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = t
    for j in range(n):
        matrix[j].reverse()
