def func(x):
    if x[1] == "PM" and x[0][0] == '1' and x[0][1] == '2':
        return x
    if x[1] == "PM":
        x[0] = str(int(x[0][0] + x[0][1]) + 12) + x[0][2] + x[0][3] + x[0][4]
    if x[1] == "AM" and x[0][0] == '1' and x[0][1] == '2':
        x[0] = "00:" + x[0][3] + x[0][4]
    return x

input_nums = int(input())
res = []
for i in range(input_nums):
    x = input().split()
    x = func(x)
    result = ""
    num = int(input())
    for j in range(num):
        start = input().split()
        end = start[2:]
        start.pop()
        start.pop()
        start = func(start)
        end = func(end)
        if start[0] <= x[0] and end[0] >= x[0]:
            result += "1"
        else:
            result += "0"
    res.append(result)
for x in res:
    print(x)