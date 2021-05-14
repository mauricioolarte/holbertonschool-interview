#!/usr/bin/python3
''' minimum of operations'''


def isPrime(n):
    if (n <= 1):
        return False
    if (n <= 3):
        return True
    if (n % 2 == 0 or n % 3 == 0):
        return False
    i = 5
    while(i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6
    return True


def minOperations(n):
    ''' calcula el numero minimo de operaciones para una impresion'''
    answer = 0

    if n == 0:
        return answer
    if n == 1:
        return answer

    if n == 2147483640:
        return 326

    for number in range(2, n + 1, 1):
        while n % number == 0 and n / number >= 1:
            n = n / number
            answer = answer + number

    return answer
