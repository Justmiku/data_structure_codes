class node:
    def __init__(self, data, n=None):
        self.data = data
        self.next = n


class linkedlist:
    def __init__(self, r=None):
        self.root = r
        self.count = 0

    def add(self, data):
        new_node = node(data, self.root)
        self.root = new_node
        self.count = self.count+1

    def trasverse(self):
        while(self.root != None):
            print(self.root.data)
            self.root = self.root.next

    def find(self, d):
        k = 0
        while(self.root != None):
            k = k+1
            if(self.root.data == d):
                print(self.root.data)
                break
            else:
                self.root = self.root.next
        print('k')
        print(k)


mylist = linkedlist()
mylist.add(5)
mylist.add(6)
mylist.add(8)
mylist.add(4)
mylist.add(2)
mylist.add(3)
mylist.add(6)
mylist.add(8)
mylist.add(4)
mylist.add(2)
mylist.add(7)
print(mylist.count)
mylist.find(3)
