class circularqueue:
    def __init__(self):
        self.head = 0
        self.tail = 0
        self.count = 0
        self.queue = []
        self.maxsize = 8

    def enqueue(self, data):
        if(self.count == 8):
            print("queue is full")
        else:
            self.queue.append(data)
            self.tail = (self.tail+1) % self.maxsize
            self.count = self.count+1

    def dequeue(self):
        if(self.count == 0):
            print('queue is empty')
        else:
            print(self.queue[self.head])
            self.head = (self.head+1) % self.maxsize
            self.count = self.count-1

    def size(self):
        print(self.count)

    def is_full(self):
        if(self.count == self.maxsize):
            print('Yes')
        else:
            print('No')


myqueue = circularqueue()
myqueue.enqueue(5)
myqueue.enqueue(1)
myqueue.enqueue(6)
myqueue.enqueue(4)
myqueue.enqueue(4)
myqueue.enqueue(4)
myqueue.enqueue(4)
myqueue.enqueue(4)
myqueue.enqueue(4)
myqueue.size()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
myqueue.dequeue()
