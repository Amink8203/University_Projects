
import sys
import re


class Queue:
    def __init__(self):
        self.q = []
        self.head = 0
        self.tail = -1

    def getSize(self):
        return self.tail - self.head + 1

    def enqueue(self, value):
        self.tail += 1
        self.q.append(value) 
        

    def dequeue(self):
        self.head += 1
        return self.q[self.head - 1]
        

    def isEmpty(self):
        if self.head > self.tail:
            return True
        else:
            return False 

    def getInOneLine(self):
        temp = self.q[self.head : self.tail + 1]
        ans = ""
        for i in range(0,len(temp)):
            ans += f"{temp[i]} "
        return ans[:len(ans)-1]
        


class Stack:
    def __init__(self, size=10):
        self.top = -1
        self.size = size
        self.stack = []

    def isEmpty(self):
        if self.top == -1:
            return True
        else:
            return False

    def push(self, value):
        if(self.top == len(self.stack) - 1):
            self.stack.append(value)
            self.top += 1
        else:
            self.top += 1
            self.stack[self.top] = value

    def pop(self):
        self.top -= 1
        return self.stack[self.top + 1]

    def put(self, value):
        self.stack[self.top] = value

    def peek(self):
        return self.stack[self.top]

    def expand(self):
        self.size *= 2

    def getInOneLine(self):
        temp = ""
        for i in range(0, self.top + 1):
            temp += f"{self.stack[i]} "
        return temp[:len(temp)-1]
        

    def getSize(self):
        return self.top + 1

    def getCapacity(self):
        return self.size


class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = Node(None)

    def getList(self):
        cur = self.head
        temp = []
        while(cur != None):
            temp.append(cur.data)
            cur = cur.next
        ans = ""
        for i in range(0,len(temp)):
            ans += f"{temp[i]} "
        return ans[:len(ans)-1]
        

    def insertFront(self, new_data):
        if(self.head.data == None):
            self.head.data = new_data
        else:
            new_node = Node(new_data)
            new_node.next = self.head
            self.head = new_node
        

    def insertEnd(self, new_data):
        if(self.head.data == None):
            self.head.data = new_data
        else:
            new_node = Node(new_data)
            cur = self.head
            while(cur.next != None):
                cur = cur.next
            cur.next = new_node
        
    def reverse(self):
        prev = None
        cur = self.head
        while(cur != None):
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        self.head = prev


class Runner:
    dsMap = {'stack': Stack, 'queue': Queue, 'linked_list': LinkedList}
    callRegex = re.compile(r'^(\w+)\.(\w+)\(([\w, ]*)\)$')

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
        args = argsList.split(',') if argsList != '' else []

        method = getattr(self.items[itemName], funcName)
        result = method(*args)
        if result is not None:
            print(result)


def main():
    runner = Runner(sys.stdin)
    runner.run()


if __name__ == "__main__":
    main()