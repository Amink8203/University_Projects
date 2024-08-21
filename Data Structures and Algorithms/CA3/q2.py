class Bst:
    class Node:
        def __init__(self,key,index):
            self.parent = None
            self.left = None
            self.right = None
            self.key = key
            self.index = index

    def __init__(self):
        self.root = self.Node(None,None)

    def insert(self, key,index):
        new_node = self.Node(key,index)
        if self.root.key == None:
            self.root = new_node
            return
        par = self.Node(None,None)
        temp = self.root
        while temp != None:
            par = temp
            if new_node.key < temp.key:
                temp = temp.left
            else:
                temp = temp.right
        new_node.parent = par
        if new_node.key < par.key:
            par.left = new_node
        else:
            par.right = new_node
        return new_node
    
    def inorder_rec(self,node):
        if node != None:
            self.inorder_rec(node.left)
            print(node.key, end=" ")
            self.inorder_rec(node.right)
    
    def inorder(self):
        self.inorder_rec(self.root)
    
    def find_ans(self,par,a,b):
        if par == None:
            return
        if par.key < a.key and par.key < b.key:
            return self.find_ans(par.right,a,b)
        if par.key > a.key and par.key > b.key:
            return self.find_ans(par.left,a,b)
        return par
        

count = int(input())
nums = list(map(int,input().split()))
a , b = input().split()
a , b  = int(a),int(b)
node_a = None
node_b = None
bst = Bst()
for i in range(count):
    if i == 0:
        tmp = bst.insert(nums[i],i+1)
        if (i+1) == a:
            node_a = tmp
        if (i+1) == b:
            node_b = tmp
        continue
    temp = bst.insert(nums[i],i+1)
    print(temp.parent.key,end=" ")
    if (i+1) == a:
            node_a = temp
    if (i+1) == b:
        node_b = temp

ans = bst.find_ans(bst.root,node_a,node_b)
print("")
print(ans.index)
