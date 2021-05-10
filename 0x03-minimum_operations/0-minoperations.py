#!/usr/bin/python3
''' minimum of operations'''


def minOperations(n):
    ''' calcula el numero minimo de operaciones para una impresion'''

    if n == 1:
        return 2
    if n == 0:
        return 0
    primos = []
    numbers = []
    i = 1
    while (i < n):
        i = i + 1
        numbers.append(i)

    for number in numbers:
        counter = 0
        i = 1
        while (i < number):
            if (number % i == 0):
                counter = counter + 1
            i = i + 1
        if counter < 2:
            primos.append(number)

    n1 = n
    answer = 0
    for number in primos:
        while n1 % number == 0 and n1 / number >= 1:
            n1 = n1 / number
            answer = answer + number

    return (answer)
