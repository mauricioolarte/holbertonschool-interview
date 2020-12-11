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
  while(counter < boxLen):
    for k in range(1, boxLen, 1):
      if k in keys:
        for m in range(len(boxes[k])):
          keys.append(boxes[k][m])
    counter += 1
    k = 1

  for j in boxesnumbers:
    if j not in keys:
      return False
  return True
  
  
  print(keys)