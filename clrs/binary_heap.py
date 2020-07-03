def parent(i):
    return (i // 2 - 1)

def left(i):
    return (2 * i + 1)

def right(i):
    return (2 * i + 2)

def swap(a, x, y):
    a[x], a[y] = a[y], a[x]
    
def heapify(a, i):
    largest = i
    
    if ((left(i) < len(a)) and (a[left(i)] > a[i])):
        largest = left(i)
    if ((right(i) < len(a)) and (a[right(i)] > a[largest])):
        largest = right(i)

    if (largest != i):
        swap(a, i, largest)
        return heapify(a, largest)
            
def make_heap(a):
    for i in range(((len(a)-1) // 2), -1, -1):
        heapify(a, i)
        print(a)

l = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
make_heap(l)
print(l)
        
