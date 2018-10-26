class node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None


class linkedlist:
    def __init__(self):
        self.head = None
        self.count = 0
        self.tail = None

    def insert_at_beg(self, data):
        if(self.count == 0):
            new_node1 = node()
            new_node2 = node()
            new_node1.next = new_node2
            new_node2.prev = new_node1
            self.head = new_node1
            self.tail = new_node2
            new_node = node()
            new_node.data = data
            new_node.prev = self.tail.prev
            new_node.next = self.head.next
            self.head.next = new_node
            self.tail.prev = new_node
            self.count = self.count+1
        else:
            new_node = node()
            new_node.data = data
            new_node.next = self.head.next
            new_node.prev = self.head.next.prev
            self.head.next = new_node
            new_node.next.prev = new_node
            self.count = self.count+1

    def insert_at_end(self, data):
        if(self.count == 0):
            new_node1 = node()
            new_node2 = node()
            new_node1.next = new_node2
            new_node2.prev = new_node1
            self.head = new_node1
            self.tail = new_node2
            new_node = node()
            new_node.data = data
            new_node.prev = self.tail.prev
            new_node.next = self.head.next
            self.head.next = new_node
            self.tail.prev = new_node
            self.count = self.count+1
        else:
            new_node = node()
            new_node.data = data
            new_node.prev = self.tail.prev
            new_node.next = self.tail.prev.next
            self.tail.prev = new_node
            new_node.prev.next = new_node
            self.count = self.count+1

    def insert_in_middle(self, data, after):
        current = self.head.next
        while (current.data != after):
            current = current.next
        new_node = node()
        new_node.data = data
        new_node.next = current.next
        new_node.prev = current.next.prev
        current.next = new_node
        new_node.next.prev = new_node
        self.count = self.count+1

    def trasverse(self):
        current1 = self.head.next
        while (current1.next != None):
            print(current1.data)
            current1 = current1.next

    def remove_from_beg(self):
        self.head.next.next.prev = self.head.next.prev
        self.head.next = self.head.next.next
        self.count = self.count-1

    def remove_from_end(self):
        self.tail.prev.prev.next = self.tail.prev.next
        self.head.prev = self.tail.prev.prev
        self.count = self.count-1


mylist = linkedlist()
mylist.insert_at_beg(5)
mylist.insert_at_beg(7)
mylist.insert_at_beg(3)
mylist.insert_at_beg(8)
mylist.insert_at_end(1)
mylist.insert_at_end(3)
mylist.insert_in_middle(7, 5)
print(mylist.count)
mylist.trasverse()
print("@@@@@@@@@@@@@")
mylist.remove_from_beg()
mylist.remove_from_end()
mylist.trasverse()
