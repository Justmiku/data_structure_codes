class stacknode:
    def __init__(self):
        self.data = None
        self.next = None


class stacklinked:
    def __init__(self):
        self.head = None
        self.count = 0

    def push(self, data):
        new_node = stacknode()
        new_node.data = data
        new_node.next = self.head
        self.head = new_node
        self.count = self.count+1

    def pop(self):
        # if(self.count == 0):
        #        print('stack is empty')
        print(self.head.data)
        self.head = self.head.next
        #self.count = self.count-1

    def length(self):
        return(self.count)

    def peep(self):
        print(self.head.data)

    def is_empty(self):
        if(self.count == 0):
            print('Yes')
        else:
            print('No')


mystack = stacklinked()
mystack.push(5)
mystack.push(3)
mystack.push(4)
mystack.push(6)
print(mystack.length())
mystack.pop()
mystack.peep()
mystack.pop()
mystack.is_empty()
