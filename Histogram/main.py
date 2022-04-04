import numpy as np
import matplotlib.pyplot as plt
import matplotlib.pyplot as plt1


matrix = []


M = (int)(input("Nhập số Cột= "))
N = (int)(input("Nhập số Dòng= "))
mucxam = (int)(input("Nhập số mức xám= "))

for i in range(M*N):
    value = (int)(input("Nhập giá trị= "))
    matrix.append(value)

matrix2 = []
dem = 0
for k in range(0, N):
    matrancon = []
    for i in range(0, M):
        matrancon.append(matrix[dem])
        dem = dem + 1
    matrix2.append(matrancon)
print(matrix2)
print("Từ đề bài ta có :")
print("M = ", M)
print("N = ", N)
print("Mức Xám = ", mucxam)
rk = []
nk = []
cdf = []
sk = []
set_matrix = set(matrix)
if (len(set_matrix) >= mucxam):
    for i in set_matrix:
        rk.append(i)
        nk.append(matrix.count(i))
    cdf.append(nk[0])
    for i in range(1, len(nk)):
        cdf.append(cdf[i-1] + nk[i])
    for i in range(len(cdf)):
        kq = round((cdf[i]-min(cdf))/(M*N - min(cdf))*(mucxam-1))
        sk.append(kq)
        print('+ s(', rk[i], ') = round((', cdf[i], '-', min(cdf), ')/(',
              M, '*', N, ' - ', min(cdf), ')*(', mucxam, '-1)) = ', kq)
else:
    for i in range(0, mucxam):
        for j in set(matrix):
            if (i != j):
                set_matrix.add(i)
    for i in set_matrix:
        rk.append(i)
        nk.append(matrix.count(i))
    cdf.append(nk[0])
    for i in range(1, len(nk)):
        cdf.append(cdf[i-1] + nk[i])
    for i in range(len(cdf)):
        kq = round((cdf[i]-min(cdf))/(M*N - min(cdf))*(mucxam-1))
        sk.append(kq)
        print('+ s(', rk[i], ') = round((', cdf[i], '-', min(cdf), ')/(',
              M, '*', N, ' - ', min(cdf), ')*(', mucxam, '-1)) = ', kq)
print('rk: ', rk)
print('nk: ', nk)
print('cdf:', cdf)
print('sk: ', sk)
print("Ma trận cũ: ")
for i in range(len(matrix2)):
    print(matrix2[i])
print("Ma trận mới: ")
matran_new = []
for i in range(len(matrix2)):
    matrannho = []
    for j in range(len(matrix2[i])):
        for k in range(len(rk)):
            if(matrix2[i][j] == rk[k]):
                matrannho.append(sk[k])
    matran_new.append(matrannho)
for i in range(len(matran_new)):
    print(matran_new[i])
rk_moi = []
nk_moi = []
matrix_moi = []

for i in range(len(matran_new)):
    for j in range(len(matran_new[i])):
        matrix_moi.append(matran_new[i][j])
for i in set(matrix_moi):
    rk_moi.append(i)
    nk_moi.append(matrix_moi.count(i))
print('rk mới: ', rk_moi)
print('nk mới: ', nk_moi)
# plt1.style.use('dark_background')
# plt1.title("Đồ thị ")
# plt1.xlabel("rk")
# plt1.ylabel("nk")
# plt1.bar(rk, nk, color='#00CCFF')
# plt1.show()
# plt.title("Đồ thị ")
# plt.xlabel("rk")
# plt.ylabel("nk")
# plt.bar(rk_moi, nk_moi, color='#B40062')
# plt.show()