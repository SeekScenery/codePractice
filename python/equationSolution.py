from random import randint
import numpy as np
# y = ax^2 + bx + c 求解 dy = 2ax + b

def hasSolution(a, b, c) -> int:
    flag = b**b - 4 * a * c
    if flag > 0:
        return 2
    elif flag == 0:
        return 1
    else:
        return 0

def solution(a, b, c):
    count = hasSolution(a, b, c)
    if count == 1:
        # 随机取一个初始点
        x_init = -2*a/b + randint(1, 5)
        while True:
            pass

print(randint(3, 5))








