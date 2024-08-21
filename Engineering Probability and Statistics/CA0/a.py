sum = 0
def func(a, b):
    global sum
    sum += 1
    if b == 0:
        return a
    return func(b, a%b)
c = input()
d = input()
print(func(int(c), int(d)))
print(sum)

