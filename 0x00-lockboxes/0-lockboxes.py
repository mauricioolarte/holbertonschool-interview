#!/usr/bin/python3


def canUnlockAll(boxes):
    boxLen = len(boxes)
    keys = []
    boxesnumbers = []
    for i in range(1, boxLen, 1):
        boxesnumbers.append(i)
    if boxLen == 0 or len(boxes[0]) == 0:
        return False
    for i in range(len(boxes[0])):
        keys.append(boxes[0][i])
    counter = 0
    x = 1
    while(len(boxesnumbers) and counter <= boxLen):
        for key in boxesnumbers:
            if key in keys:
                for m in range(len(boxes[key])):
                    keys.append(boxes[key][m])
                boxesnumbers.remove(key)
        counter += 1

    if len(boxesnumbers) > 0:
        return False
    return True
