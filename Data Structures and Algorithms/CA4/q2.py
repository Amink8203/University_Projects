from collections import deque
class Sequence:
    def __init__(self,num,h,par,rt):
        self.parent = par
        self.height = h
        self.nums = num
        self.root = rt
num_inp = int(input())
t_inp = int(input())

root = "0"
nums = [0,1,2,3,4,5,6,7,8,9]
nums = list(map(str,nums))
idx = 1
while idx < num_inp:
    root = root + nums[idx]
    idx = idx + 1

perm = []

q = deque()
q.append(Sequence(root,0,0,0))
elems = dict()
sz = dict()

while q:
    temp = q.popleft()
    try:
        if elems[temp.nums] == True:
            pass

    except:
        elems[temp.nums] = True
        sz[temp.nums] = temp.height
        idx1 , idx2 = 0 , 0
        while idx1 < num_inp:
            idx2 = idx1 + 1
            string = ''
            change_string2 = ''
            while idx2 < num_inp:
                string = temp.nums
                change_string2 = string[0:idx1] + ''.join(reversed(string[idx1:idx2+1])) + string[idx2+1:]
                q.append(Sequence(change_string2,temp.height + 1,0,0))
                idx2 = idx2 + 1
            idx1 = idx1 + 1

hash_map = {}
res = dict()
tmp = 0
while tmp < t_inp:
    inter = input()
    tmp1 , tmp2 = inter.split()
    final_ans = ''
    idx1 , idx2 = 0 , 0
    while idx1 < num_inp:
        hash_map[tmp1[idx1]] = nums[idx1]
        idx1 = idx1 + 1
    while idx2 < num_inp:
        final_ans += hash_map[tmp2[idx2]]
        idx2 = idx2 + 1
    res[tmp] = sz[final_ans]
    tmp = tmp + 1

for ans in list(res.values()):
    print(ans)