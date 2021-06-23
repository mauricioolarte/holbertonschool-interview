#!/usr/bin/python3
''' check if array is a utf endcoded'''


def validUTF8(data):
	''' check array '''
    for bite in data:
        if bite < 0 or bite > 255:
            return False
    return True
