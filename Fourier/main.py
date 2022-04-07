import numpy as np
import math
col = (int)(input("Số cột= "))
row = (int)(input("Số hàng= "))

matrix = []
for i in range(col):
    arr = []
    for j in range(row):
        print("Maxtrix[",i,j,"] ")
        value = (int)(input("= "))
        arr.append(value)
    matrix.append(arr)

print(matrix)

def dft(matrix, col, row):
    rows = row
    cols = col
    output_img = np.zeros((rows, cols), complex)
    for m in range(0, rows):
        for n in range(0, cols):
            for x in range(0, rows):
                for y in range(0, cols):
                    output_img[m][n] += matrix[x][y] * \
                        np.exp(-1j*2*math.pi*(m*x/rows+n*y/cols))
    return output_img

def dftnguoc(matrix, col, row):
    rows = row
    cols = col
    output_img = np.zeros((rows, cols), complex)
    for m in range(0, rows):
        for n in range(0, cols):
            for x in range(0, rows):
                for y in range(0, cols):
                    output_img[m][n] += matrix[x][y] * \
                        np.exp(1j*2*math.pi*(m*x/rows+n*y/cols))
    return (1/(col*row))*output_img


print("------------Xuôi----------")
print(dft(matrix, col, row))
print("------------Ngược----------")

print(dftnguoc(dft(matrix, col, row), col, row))
