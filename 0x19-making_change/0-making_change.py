#!/usr/bin/python3
""" 0. Change comes from within
"""


def makeChange(coins, total):
    """ Given a pile of coins of different values,
                   determine the fewest number of coins needed to meet a given amount
                         total.
    """

    if total <= 0:
        return 0
    if coins is None or coins == []:
        return -1
    coins = sorted(coins, reverse=True)
    counter = 0
    for i in coins:
        if i <= total:
            counter += int(total / i)
            total = total % i
        if total == 0:
            return counter
    return -1
