import sys
import re


INVALID_INDEX = 'invalid index'
OUT_OF_RANGE_INDEX = 'out of range index'
EMPTY = 'empty'


class MinHeap:

    class Node:
        def __init__(self,key):
            self.key = key

    def __init__(self):
        self.heap_arr = []

    def handle_error(self,index):
        length = len(self.heap_arr)
        if not isinstance(index, int):
            raise Exception("invalid index")
        if index < 0 or index >= length:
            raise Exception("out of range index")
        if length == 0:
            raise Exception("empty")
    

    def bubble_up(self, index):
        self.handle_error(index)
        # parent_idx = (index -1)//2
        while index > 0:
            if (index -1)//2 >= 0 and self.heap_arr[(index -1)//2].key > self.heap_arr[index].key:
                self.heap_arr[index].key, self.heap_arr[(index -1)//2].key = self.heap_arr[(index -1)//2].key,self.heap_arr[index].key
            else:
                break
            index = (index -1)//2


        

    def bubble_down(self, index):
        self.handle_error(index)
        length = len(self.heap_arr)
        smallest = index
        # left_idx = (2 * index) + 1
        # right_idx = (2 * index) + 2
        while (2 * index) < length:
            if (2 * index) + 1 < length and self.heap_arr[smallest].key > self.heap_arr[(2 * index) + 1].key:
                smallest = (2 * index) + 1
            if (2 * index) + 2 < length and self.heap_arr[smallest].key > self.heap_arr[(2 * index) + 2].key:
                smallest = (2 * index) + 2
            if index != smallest:
                self.heap_arr[index].key, self.heap_arr[smallest].key = self.heap_arr[smallest].key, self.heap_arr[index].key
                index = smallest
            else:
                break



    def heap_push(self, value):
        new_node = self.Node(value)
        self.heap_arr.append(new_node)
        self.bubble_up(len(self.heap_arr)-1)

    def heap_pop(self):
        length = len(self.heap_arr)
        if length == 0:
            raise Exception("empty")
        root_val = self.heap_arr[0].key
        self.heap_arr[0].key = self.heap_arr[length - 1].key
        self.heap_arr.pop()
        length = len(self.heap_arr)
        if length != 0:
            self.bubble_down(0)
        return root_val


    def find_min_child(self, index):
        self.handle_error(index)
        left_idx = (2 * index) + 1
        right_idx = (2 * index) + 2
        smallest = left_idx
        if (2 * index) < len(self.heap_arr):
            if self.heap_arr[left_idx].key > self.heap_arr[right_idx].key:
                smallest = right_idx
        return smallest

    def heapify(self, *args):
        for x in args:
            self.heap_push(x)


class HuffmanTree:
    class Node:
        def __init__(self,left,right,num,letter):
            self.left = left
            self.right = right
            self.num = num
            self.letter = letter
            self.code = str()

    def __init__(self):
        self.root = None
        self.nums = []
        self.letters = []
        self.encode = {}


    def set_letters(self, *args):
        self.letters = args
        temp = {}
        for i in self.letters:
            temp[i] = ""
        self.encode = temp

    def set_repetitions(self, *args):
        self.nums = args

    def calc(self,code,n):
        code_num = code + n.code
        if n.left != None:
            self.calc(code_num,n.left)
        if n.right != None:
            self.calc(code_num,n.right)
        if (n.left == None) and (n.right == None):
            self.encode[n.letter] = code_num

    def build_huffman_tree(self):
        n_lst = []
        for i in range(len(self.letters)):
            new_node = self.Node(None,None,self.nums[i],self.letters[i])
            n_lst.append(new_node)
        while len(n_lst) > 1:
            n_lst.sort(key = lambda n : (n.num))
            left = n_lst[0]
            right = n_lst[1]
            left.code = "0"
            right.code = "1"
            root = self.Node(left,right,(right.num)+(left.num),"")
            self.root = root
            n_lst = n_lst[2:]
            n_lst.append(root)
        self.calc("",self.root)
            



    def get_huffman_code_cost(self):
        temp = 0
        ans = 0
        for x in self.encode:
            ans += self.nums[temp] * len(self.encode[x])
            temp = temp + 1
        return ans

    def text_encoding(self, text):
        temp = {}
        for x in text:
            if x in temp:
                temp[x] += 1
            else:
                temp[x] = 1
        nums = list(temp.values())
        letters = list(temp.keys())
        self.nums = nums
        self.letters = letters
        tmp = {}
        for x in self.letters:
            tmp[x] = ""
        self.encode = tmp
        self.build_huffman_tree()


class Bst:
    class Node:
        def __init__(self,key):
            self.parent = None
            self.left = None
            self.right = None
            self.key = key

    def __init__(self):
        self.root = self.Node(None)

    def insert(self, key):
        new_node = self.Node(key)
        if self.root.key == None:
            self.root = new_node
            return
        par = self.Node(None)
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
    
    def inorder_rec(self,node):
        if node != None:
            self.inorder_rec(node.left)
            print(node.key, end=" ")
            self.inorder_rec(node.right)
    
    def inorder(self):
        self.inorder_rec(self.root)


class Runner:
    dsMap = {'min_heap': MinHeap, 'bst': Bst, 'huffman_tree': HuffmanTree}
    callRegex = re.compile(r'^(\w+)\.(\w+)\(([\w, \-"\']*)\)$')

    def __init__(self, inputSrc):
        self.input = inputSrc
        self.items = {}

    def run(self):
        for line in self.input:
            line = line.strip()
            action, _, param = line.partition(' ')
            actionMethod = getattr(self, action, None)
            if actionMethod is None:
                return
            actionMethod(param)

    def make(self, params):
        itemType, itemName = params.split()
        self.items[itemName] = self.dsMap[itemType]()

    def call(self, params):
        regexRes = self.callRegex.match(params)
        itemName, funcName, argsList = regexRes.groups()

        args = [x.strip() for x in argsList.split(',')] if argsList != '' else []
        args = [x[1:-1] if x[0] in ('"', "'") else int(x) for x in args]

        method = getattr(self.items[itemName], funcName)
        try:
            result = method(*args)
        except Exception as ex:
            print(ex)
        else:
            if result is not None:
                print(result)


def main():
    runner = Runner(sys.stdin)
    runner.run()


if __name__ == "__main__":
    main()
