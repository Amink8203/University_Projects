n = int(input())
ans = [0] * n
for i in range(n):
    ans[i] = int(input())


size = len(ans)
mylist = []
tmp = 0
for i in range(size):
    if ans[i] == 0:
        mylist.append(ans[tmp:i])
        tmp = i + 1
    elif i == size - 1:
        mylist.append(ans[tmp:size])

size = len(mylist)
i = 0
while(True):
    if i == size:
        break
    if len(mylist[i]) == 0:
        mylist.pop(i)
        size -= 1
        i -= 1
    i += 1

size = len(mylist)
num_of_letters = [[0] * (n + 1)] * size
for i in range(size):
    for x in mylist[i]:
        num_of_letters[i][x] += 1

read_letters = [[0] * (n + 1)] * size
for j in range(size):
    count = len(mylist[j])
    i = 0
    while(True):
        if i == count:
            break
        if(num_of_letters[j][mylist[j][i]] % 2 == 1):
            read_letters[j][mylist[j][i]] += 1
            if read_letters[j][mylist[j][i]] == (num_of_letters[j][mylist[j][i]] +1) / 2:
                count += 1
                mylist[j].insert(i,mylist[j][i])
                i += 1
        i += 1

last_show = []
for sublist in mylist:
    new_sublist = [-1] * n
    for i in range(len(sublist)):
        num = sublist[i]
        new_sublist[num - 1] = i
    last_show.append(new_sublist)

all_maxes = [0] * size
for j in range(len(mylist)):
    stack = []
    max_size = 0
    for i in range (len(mylist[j])):
        if not stack:
            stack.append(mylist[j][i])
            max_size = max(max_size, len(stack))
        else:
            top = stack[-1]
            if top == mylist[j][i]:
                last = last_show[j][top-1]
                if last == i:
                    stack.pop()
                else:
                    continue
            else:
                stack.append(mylist[j][i])
                max_size = max(max_size, len(stack))
    if len(stack) > 0:
        all_maxes.append(-1)
    else:
        all_maxes.append(max_size)

flag = 1
for i in range(len(all_maxes)):
    if all_maxes[i] == -1:
        print(-1)
        flag = False
        break
if (flag):
    print(max(all_maxes))
