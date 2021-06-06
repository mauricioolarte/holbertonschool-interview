#!/usr/bin/python3
''' this is for ...'''
import sys
import signal
from datetime import datetime


def isIp(ip):
    try:
        values = ip.split(".")
        for value in values:
            if int(value) > 255 or int(value) < 0:
                return 1
        return 0
    except ValueError:
        return 1


def isDate(date):
    try:
        datetime.strptime(date, "%Y-%m-%d %H:%M:%S.%f")
        return 0

    except ValueError:
        return 1


def isString(string):
    if string == "GET /projects/260 HTTP/1.1":
        return 0
    else:
        return 1


def isStatus(status):
    if status in ['200', '301', '400', '401', '403', '404', '405', '500']:
        return 0
    else:
        return 1


def isFileSize(size):
    try:
        if int(size) >= 0 and int(size) < 1025:
            return 0
        else:
            return 1
    except ValueError:
        return 1


def countStatus(status, totals):

    for key, value in totals.items():
        if key == status:
            totals[key] = totals[key] + 1
            # print(totals.get(status))
    return totals


# def printAnswer(signal, frame):
#     print(("File size: {}").format(fileSize))
#     for value, key in statuss.items():
#         if key > 0:
#             print(("{}: {}").format(value, key))
#     sys.exit(0)


count = 0
fileSize = 0
statuss = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

# signal.signal(signal.SIGINT, printAnswer)

for line in sys.stdin:
    count = count + 1
    params = line.split(" - ")
    checkIp = isIp(params[0])
    if checkIp == 0 and len(params) > 1:
        checkDate = isDate(params[1][1:26])
        checkString = isString(params[1][29:57])
        checkStatus = isStatus(params[1][58:61])
        # print(params[1][58:61])
        checkFileSize = isFileSize(params[1][62:-1])
        # print(params[1][62:-1])
        statuss = countStatus(params[1][58:61], statuss)
        try:
            fileSize = fileSize + int(params[1][62:-1])
        except ValueError:
            fileSize = fileSize + 0
        # print(fileSize)

    if checkIp == 1 or checkDate == 1 or checkStatus == 1:
        continue
    if checkFileSize == 1:
        continue
    # print(line.split(" - "))
    # print(count)
    if count == 10:
        print(("File size: {}").format(fileSize))
        for value, key in statuss.items():
            if key > 0:
                print(("{}: {}").format(value, key))
        count = 0
sys.exit(0)
