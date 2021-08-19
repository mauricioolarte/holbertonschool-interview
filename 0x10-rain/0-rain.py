#!/usr/bin/python3
""" rain problem """


def rain(walls):
    length = len(walls)
    if (length < 3):
        return 0
    index = 0
    res = 0
    while (index < length - 1):
        if walls[index] > 0 and walls[index] > walls[index + 1]:
            wl = walls[index]
            idxL = index
            wr = 0
            idxR = 0
            for value in range(index + 1, length):
                if walls[value] > wl:
                    wr = walls[value]
                    idxR = value
                    break
                elif walls[value] > 0 and walls[value] > wr:
                    wr = walls[value]
                    idxR = value
            if wr == 0:
                index += 1
                continue
            else:
                for val in range(idxL + 1, idxR):
                    height = min(walls[idxR], walls[idxL])
                    res += height
                index = idxR
                continue
        index += 1
    return res
