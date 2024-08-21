def dfs(graph, u, visited):
    visited[u] = True

    for v in graph[u]:
        if not visited[v]:
            dfs(graph, v, visited)
n , m = input().split()
n , m  = int(n),int(m)
graph = [[] for _ in range(n)]
firsts = []
seconds = []
for i in range(m):
    u , v = input().split()
    u , v  = int(u),int(v)
    firsts.append(u)
    seconds.append(v)
    graph[v-1].append(u-1)

lst_1 = []
lst_2 = []
checked = []
for a in range(len(graph)):
    if len(graph[a]) == 0:
        continue
    lst_1.append(a)
    checked.append(a)
    for b in graph[a]:
        if b in checked and a in checked:
            continue
        else:
            lst_2.append(b)

lst_1 = []
lst_2 = []
checked = []
checked.append(firsts[0])
checked.append(seconds[0])
lst_1.append(firsts[0])
lst_2.append(seconds[0])
for num in range(1,m):
    if firsts[num] in checked and seconds[num] in checked:
        continue
    elif firsts[num] in checked:
        if firsts[num] in lst_1:
            lst_2.append(seconds[num])
            checked.append(seconds[num])
        if firsts[num] in lst_2:
            lst_1.append(seconds[num])
            checked.append(seconds[num])
    elif seconds[num] in checked:
        if seconds[num] in lst_1:
            lst_2.append(firsts[num])
            checked.append(firsts[num])
        if seconds[num] in lst_2:
            lst_1.append(firsts[num])
            checked.append(firsts[num])
    else:
        checked.append(firsts[num])
        checked.append(seconds[num])
        lst_1.append(firsts[num])
        lst_2.append(seconds[num])

if (len(lst_1) + len(lst_2)) == m:
    print(-1)

else:
    print(len(lst_1))
    for t in lst_1:
        print(t, end=" ")