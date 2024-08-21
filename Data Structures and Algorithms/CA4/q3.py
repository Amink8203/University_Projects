def dfs(graph, first_node, seen_nodes):
    print(first_node, second_node=' ')
    seen_nodes[first_node] = True

    for v in graph[first_node]:
        if not seen_nodes[v]:
            dfs(graph, v, seen_nodes)

def bfs_two_nodes(tree, first_node, second_node):
    seen_nodes = []
    num = len(tree)
    for _ in range(num+1):
        seen_nodes.append(0)
    temp = []
    for _ in range(num+1):
        temp.append(-1)
    seen_nodes[first_node] = 1
    queue = [first_node]

    while len(queue) != 0:
        u = queue.pop(0)
        k = 0
        while k < len(tree[u]):
            if seen_nodes[tree[u][k]] != 1:
                temp[tree[u][k]] = u
                seen_nodes[tree[u][k]] = 1
                queue.append(tree[u][k])
            k += 1

    result = []
    u = second_node

    while u != -1:
        result.append(u)
        u = temp[u]

    result.reverse()
    return result

n = int(input())
tree = {int(a) : [] for a in range(1,n+1)}
for i in range(n-1):
    u , v = input().split()
    u , v  = int(u),int(v)
    tree[u].append(v) 
    tree[v].append(u)

leaves = list(map(int,input().split()))
root_to_first_leaf = bfs_two_nodes(tree,1,leaves[0])
root_to_first_leaf.pop()
lst = []
for i in range(len(leaves) - 1):
    if leaves[i] == leaves[i+1]:
        continue
    temp = bfs_two_nodes(tree,leaves[i],leaves[i+1])
    if i != len(leaves) - 2:
        temp.pop()
    lst += temp

leaf_to_root = bfs_two_nodes(tree,leaves[len(leaves)-1],1)
leaf_to_root.pop()
leaf_to_root.pop(0)
result = root_to_first_leaf + lst + leaf_to_root
if len(result) == ((2*n)-2):
    for i in range(len(result)):
        print(result[i],end=" ")
else:
    print(-1)