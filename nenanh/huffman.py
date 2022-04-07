# A Huffman Tree Node
from re import S


class node:
    def __init__(self, freq, symbol, left=None, right=None):
        # frequency of symbol
        self.freq = freq

        # symbol name (character)
        self.symbol = symbol

        # node left of current node
        self.left = left

        # node right of current node
        self.right = right

        # tree direction (0/1)
        self.huff = ''

# utility function to print huffman
# codes for all symbols in the newly
# created Huffman tree


bit2 = []
index2 = []


def printNodes(node, val=''):
    # huffman code for current node
    newVal = val + str(node.huff)
    L2 = 0
    # if node is not an edge node
    # then traverse inside it
    if(node.left):
        printNodes(node.left, newVal)
    if(node.right):
        printNodes(node.right, newVal)

        # if node is edge node then
        # display its huffman code
    if(not node.left and not node.right):

        print(f"{node.symbol} -> {newVal} ->{len(newVal)}")
        bit2.append(len(newVal))
        index2.append(node.symbol)


# characters for huffman tree
ipString = input("Input: ")
lsize = (int)(input("Dung lượng gốc l = "))
M = (int)(input("M = "))
N = (int)(input("N = "))

dicString = {}
for strIp in ipString:
    if strIp in dicString:
        dicString[strIp] += 1
    else:
        dicString[strIp] = 1


chars = []
# frequency of characters
freq = []
for i in dicString:
    chars.append(i)
    freq.append(dicString.get(i))

temp = 0
for i in freq:
    temp += i

for i in range(len(chars)):
    print(chars[i], " || ", freq[i], " || ", freq[i] / temp)
Ltb = 0
for i in freq:
    Ltb += (i/temp) * lsize
print("\nGiá trị trung bình biểu diễn cho mỗi mức xám trước khi nén ltb= ", Ltb)
print("Dung lượng ảnh I trước khi nén= ", Ltb*M*N)

print('-----------------')

# list containing unused nodes
nodes = []

# converting characters and frequencies
# into huffman tree nodes
for x in range(len(chars)):
    nodes.append(node(freq[x], chars[x]))

while len(nodes) > 1:
    # sort all the nodes in ascending order
    # based on theri frequency
    nodes = sorted(nodes, key=lambda x: x.freq)

    # pick 2 smallest nodes
    left = nodes[0]
    right = nodes[1]

    # assign directional value to these nodes
    left.huff = 1
    right.huff = 0

    # combine the 2 smallest nodes to create
    # new node as their parent
    newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)

    # remove the 2 nodes and add their
    # parent as new node among others
    nodes.remove(left)
    nodes.remove(right)
    nodes.append(newNode)

# Huffman Tree is ready!
printNodes(nodes[0])

Ltb2 = 0
for i in range(2, 0):
    Ltb2 += (i/temp) * bit2[i]
j = 0
for i in index2:
    Ltb2 += freq[int(i)]/temp * bit2[j]
    j = j+1

print("Dung lượng ảnh I sau khi nén = ", Ltb2*M*N)
c = Ltb/Ltb2
print("Tỉ lệ nén = ", c)
print("Dữ liệu dư thừa = ", 1-1/c)
