
import numpy as np

# Considering only 4*4 images

M = (int)(input("Cột = "))
N = (int)(input("Hàng = "))
L = (int)(input("Dung lượng ban đầu = "))


intensity_array = np.zeros((N,M))

for i in range(N): 
    for j in range(M):
        print("Matrix[",i,j,"]= ")
        intensity_array[i,j] = float(input())


print("\nMatrix= ", intensity_array," \n")
rows = intensity_array.shape[0]
cols = intensity_array.shape[1]

int_string = np.zeros((rows*cols))
idx = 0

#Creating a string of all intensity values

for i in range(0,rows): 
    for j in range(0,cols):
        int_string[idx] = intensity_array[i,j]
        idx = idx+1
        

crs = "" ; # currently recognized sequence
curr = "" ; # current sequence

output = {}
out_idx = 0

dict_val = {}
dict_idx = 0

for i in range(0,255) :
    dict_val[str(i)] = i
        
#next unused location
dict_idx = 258

curr = int_string[0]

crs = str(int(curr))

for i in range(1,idx) :
    curr = int_string[i]
    
    t_str = crs + "-" + str(int(curr))
    
    #print("t_str is " + t_str)
    
    if t_str in dict_val :
        #print(t_str + " Already exists");
        crs = t_str;
    else:
        # if not found in the dictionary
    
        #print("Creating a new entry for the dictionary ")
        output[out_idx] = dict_val[crs]
        #print("Output " , + output[int(out_idx)])
        out_idx = out_idx + 1;
        crs = str(int(curr));
        
        # add the new entery to the dictionary
        dict_val[t_str] = dict_idx;
        dict_idx = dict_idx + 1
    

#Last entry will always be found in the dictionary
if crs in dict_val : 
    output[out_idx] = dict_val[crs]
    #print("Output " , + output[int(out_idx)])
    out_idx = out_idx + 1;
    
#printing the encoded output
print(output.values());
    
print("\nDung lượng ảnh trước khi nén= ", L*M*N)

dic = {8:0, 9:0, 10:0, 11: 0, 12:0}
for i in output.values():
    if i>= 0 and i<= 255:
        dic[8] += 1
    elif i>= 256 and i<= 511:
        dic[9] += 1
    elif i>= 512 and i<= 1023:
        dic[10] += 1
    elif i>= 1024 and i<= 2047:
        dic[11] += 1
    elif i>= 2048 and i<= 4095:
        dic[12] += 1

print(dic)
temp = 0
for i in dic:
    temp += dic.get(i) * i
print("\nDung lượng ảnh sau khi nén= ", temp)
print("\nTỷ số nén= ", L*M*N/temp)
print("\nDữ liệu dư thừa= ", 1-(temp/(L*M*N)))


