import heapq
n , d = input().split()
n , d  = int(n),int(d)
lst = []
dictio = {}
for _ in range(n):
    lst.append(list(map(int,input().split())))

for i in range(len(lst)):
    lst[i][0],lst[i][2] = lst[i][2],lst[i][0]
    lst[i][0] *= -1
lst.sort(key=lambda x:x[2])

for i in range(len(lst)):
    lst[i].append(i)

for i in range(len(lst)):
    dictio[i] = lst[i]
heap = []
i = 0
count = 1
i = 0
while count <= d:
    while i < n and count == dictio[i][2]:
        if dictio[i][1] > 0:
            heapq.heappush(heap,dictio[i])
        i += 1
    if len(heap) != 0:
        biggest = heapq.heappop(heap)
        dictio[biggest[3]][1] -= 1
        if dictio[biggest[3]][1] > 0:
            heapq.heappush(heap,dictio[biggest[3]])
    count += 1
    
ans = 0
if len(heap) == 0:
    print(0)
else:
    for i in range(len(heap)):
        ans += heap[i][0] * heap[i][1]
    
print(-1 * ans)




