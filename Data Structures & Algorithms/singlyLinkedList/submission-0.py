class LinkedListNode:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

class LinkedList:
    
    def __init__(self):
        self.head = LinkedListNode(-1)
        self.tail = self.head
    
    def get(self, index: int) -> int:
        curr = self.head.next
        count = 0
        while curr and count < index:
            curr = curr.next
            count += 1
        if curr is None:
            return -1
        else:
            return curr.value

    def insertHead(self, val: int) -> None:
        new = LinkedListNode(val)
        new.next = self.head.next
        self.head.next = new
        if self.tail == self.head:
            self.tail = new

    def insertTail(self, val: int) -> None:
        self.tail.next = LinkedListNode(val)
        self.tail = self.tail.next

    def remove(self, index: int) -> bool:
        i = 0
        current = self.head
        while i < index and current:
            current = current.next
            i += 1
        if current and current.next:
            if current.next == self.tail:
                self.tail = current
            current.next = current.next.next
            return True
        return False

    def getValues(self) -> List[int]:
        values = []
        current = self.head.next
        while current != None:
            values.append(current.value)
            current = current.next
        return values