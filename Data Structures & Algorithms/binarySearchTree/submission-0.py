class TreeNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.leftnode = None
        self.rightnode = None

class TreeMap:
    def __init__(self):
        self.root = None

    def insert(self, key: int, val: int) -> None:
        newNode = TreeNode(key, val)
        if not self.root:
            self.root = newNode
            return

        current = self.root
        while True:
            if key < current.key:
                if current.leftnode:
                    current = current.leftnode
                else:
                    current.leftnode = newNode
                    return
            elif key > current.key:
                if current.rightnode:
                    current = current.rightnode
                else:
                    current.rightnode = newNode
                    return
            else:
                current.value = val
                return
            

    def get(self, key: int) -> int:
        current = self.root
        while current and current.key != key:
            if key < current.key and current.leftnode:
                current = current.leftnode
            elif key > current.key and current.rightnode:
                current = current.rightnode
            else:
                return -1
        return current.value if current else -1
        

    def getMin(self) -> int:
        if not self.root:
            return -1
        return self.findMin(self.root).value

    def findMin(self, node):
        while node and node.leftnode:
            node = node.leftnode
        return node

    def getMax(self) -> int:
        if not self.root:
            return -1
        current = self.root
        while current.rightnode:
            current = current.rightnode
        return current.value

    def remove(self, key: int) -> None:
        self.root = self.remover(self.root, key)

    def remover(self, current, key):
        if not current:
            return None

        if key > current.key:
            current.rightnode = self.remover(current.rightnode, key)
        elif key < current.key:
            current.leftnode = self.remover(current.leftnode, key)
        else:
            if not current.leftnode:
                return current.rightnode
            elif not current.rightnode:
                return current.leftnode
            else:
                minNode = self.findMin(current.rightnode)
                current.key = minNode.key
                current.value = minNode.value
                current.rightnode = self.remover(current.rightnode, minNode.key)
        return current
                

    def getInorderKeys(self) -> List[int]:
        result = []
        self.traverse(self.root, result)
        return result

    def traverse(self, root, result):
        if root:
            self.traverse(root.leftnode, result)
            result.append(root.key)
            self.traverse(root.rightnode, result)

