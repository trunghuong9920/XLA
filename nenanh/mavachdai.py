from itertools import count
from tabnanny import check
import numpy as np


def arrbin(num):
    arr = []
    for i in range(2,len(bin(num))):
        arr.append(bin(num)[i])
    return len(arr)

bit = (int)(input("Số bit đầu = "))

M = (int)(input("Nhập số cột = "))
N = (int)(input("Nhập số hàng = "))

matrix = []
print("Nhập ma trận liên tục trái qua phải")
for i in range(N):
    for j in range(M):
        print("Matrix[",i,j,"] :")
        st = (int)(input("="))
        matrix.append(st)
print("IP = ",matrix,"\n")
countArr = []
check = matrix[0]
count = 0
nb = 0
for i in matrix:
    if i == check:
        count +=1
        if nb == M*N-1:
            arr = [count,check]
            countArr.append(arr)
    else:
        arr = [count,check]
        countArr.append(arr)
        count = 1
        check = i
        if nb == M*N-1:
            arr = [count,check]
            countArr.append(arr)
    nb += 1
    

print(countArr)
print("Số cặp= ",len(countArr))

max0 = 0
max1 = 0

for i in countArr:
    if i[0] > max0:
        max0 = i[0]
    if (int)(i[1]) > max1:
        max1 = (int)(i[1])

lenghBitAffter = M * N * bit

lenghBitBefore = len(countArr) * (arrbin(max0) + arrbin(max1))
print("Độ dài trước khi mã hóa = ", lenghBitAffter)
print("Độ dài sau khi mã hóa = ", lenghBitBefore)
print("Dùng ",arrbin(max0), " bit để mã hóa số lượng các bit lặp")
print("Dùng ",arrbin(max1), " bit để mã hóa số lượng các mức xám")

print("Tỉ số nén= ",lenghBitAffter/lenghBitBefore)
print("Dữ liệu dư thừa= ",(1 - (lenghBitBefore/lenghBitAffter)))