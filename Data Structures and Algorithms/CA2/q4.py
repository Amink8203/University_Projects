class Shoes:
    def __init__(self,pi,si,idx) -> None:
        self.pi = pi
        self.si = si
        self.jump = []
        self.max_zeros = 0
        self.idx = idx
 
n , b = list(map(int,input().split()))
heights = list(map(int,input().split()))
my_list = []

for i in range(b):
    p , q= list(map(int,input().split()))
    my_list.append(Shoes(p,q,i))

my_list.sort(key = lambda x: x.si)  

for i in range(b):
    sublist = []
    for j in range(n):
        if my_list[i].pi >= heights[j]:
            sublist.append(1)
        else:
            sublist.append(0)
    my_list[i].jump = sublist

for i in range(b):
    stack = []
    max_size = 0
    size = 0
    for j in range(n):
        if my_list[i].jump[j] == 1:
            stack.clear()
            size = 0
        else:
            stack.append(0)
            size += 1
            max_size = max(size,max_size)
    my_list[i].max_zeros = max_size

my_list.sort(key = lambda x: x.idx)  

for i in range(b):
    if my_list[i].si > my_list[i].max_zeros:
        print(1)
    else:
        print(0)

            
            