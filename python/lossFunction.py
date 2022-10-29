import numpy as np


#------------------------------------#
# loss 函数实现
def BCELoss(predict, target):
    temp =  -(target * np.log(predict) + (1 - target) * np.log(1-predict))
    return np.mean(temp)

box1 = [[20, 40], [40, 60]]
box2 = [[30, 30], [60, 60]]

x1 = max(box1[0][0], box2[0][0])
y1 = max(box1[0][1], box2[0][1])

x2 = min(box1[1][0], box2[1][0])
y2 = min(box1[1][1], box2[1][1])

if __name__ == "__main__":
    preArray = np.array([0.6, 0.72, 0.1])
    tarArray = np.array([1, 1, 0])
    loss = BCELoss(preArray, tarArray)
    loss = BCELoss(0.2, 1)
    print(loss)
    print([x1, y1])
    print([x2, y2])
    print(max(box1[0], box2[0]))
