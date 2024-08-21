line = input()
temp = []
maximum = []
i = 0
start = 0
while(i < len(line)):
    if line[i] in temp:
        maximum.append(len(temp))
        if i == len(line) - 1:
            break
        else:
            start += 1
            i = start
            temp = []
    else:
        temp.append(line[i])
        i += 1
        if(i == len(line)):
            maximum.append(len(temp))

print(max(maximum))

