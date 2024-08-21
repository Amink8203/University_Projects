from collections import deque

el_num = int(input())
numbers = list(map(int,input().split()))
pos = {0: 0}


for i in range(el_num):
    pos[numbers[i]] = i

stack = deque()
prev = [-1] * el_num

for i in range(el_num, 0, -1):
    while len(stack) != 0:

        if pos[stack[-1]] < pos[i]:
            prev[pos[i]] = pos[stack[-1]]
            break

        else:
            stack.pop()
    stack.append(i)


print(0)

stack = deque()
result = 0
for i in range(1, el_num + 1):
    while len(stack) != 0:
        if stack[-1] < pos[i]:
            break
        else:
            result -= 1
            stack.pop()
    
    if  len(stack) == 0 and prev[pos[i]] != -1:
        result += 1
        stack.append(pos[i])
    

    elif prev[pos[i]] != -1 and prev[pos[i]] != prev[stack[-1]]:
        result += 1
        stack.append(pos[i])
    
    
    print(result)
