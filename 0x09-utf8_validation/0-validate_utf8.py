#!/usr/bin/python3
"""
Test UTF-8
"""


def validUTF8(data):
    """
    validate if data array is UTF format
    """
    validator = 0
    mask1 = 1 << 7
    mask2 = 1 << 6
    for num in data:
        mask = 1 << 7
        if validator == 0:
            while mask & num:
                validator += 1
                mask = mask >> 1
            if validator == 0:
                continue
            if validator == 1 or validator > 4:
                return False
        else:
            if not (num & mask1 and not (num & mask2)):
                return False
        validator -= 1
    return validator == 0

    return True
