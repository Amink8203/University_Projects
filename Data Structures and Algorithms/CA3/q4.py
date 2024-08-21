def steps(n,nums,S):
    sequence = {}
    for i in range(n):
        sequence[i+1] = []
    steps = 0
    def find_min(node):
        nonlocal steps
        state = None
        if node in S:
            state = True
        else:
            state = False
        
        for x in sequence[node]:
            state ^= find_min(x)

        if state:
            steps += 1
            S.discard(node)
            # for child in sequence[node]:
            #     S.discard(child)
        return state
    find_min(1)
    if len(S) == 0:
        return steps
    else:
        return -1
    # return steps
    
n , q = input().split()
n , q  = int(n),int(q)
nums = list(map(int,input().split()))
# nums.insert(0,1)
Q = []
for i in range(q):
    Q.append(list(map(int,input().split())))
    Q[i].pop(0)
    

for i in range(q):
    a = Q[i]
    print(steps(n,nums,set(Q[i])))
