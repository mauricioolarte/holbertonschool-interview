#!/usr/bin/python3
''' minimum of operations'''


def minOperations(n):
    ''' calcula el numero minimo de operaciones para una impresion'''
    answer = 0

    if n == 0:
        return answer
    if n == 1:
        return answer

    for number in range(2, n + 1, 1):
        while n % number == 0 and n / number >= 1:
            n = n / number
            answer = answer + number

    return int(answer)
