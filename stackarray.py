class stackarray:
    def __init__(self):
        self.list = []

    def push(self, data):
        self.list.append(data)

    def length(self):
        return (len(self.list))

    def is_empty(self):
        if(self.length() == 0):
            return ('Yes')
        else:
            return ('No')

    def pop(self):
        if(self.is_empty() == 'Yes'):
            print('error. stack is empty')
        else:
            return (self.list.pop())

    def peep(self):
        if(self.is_empty() == 'Yes'):
            print('error ,stack is empty')
        else:
            return (self.list[-1])


mystack = stackarray()
mystack.push(5)
mystack.push(3)
mystack.push(4)
mystack.push(6)
print(mystack.length())
print(mystack.is_empty())
print(mystack.pop())
print(mystack.peep())
print(mystack.pop())
