def add_inversions(A, left, middle, right, l, r):
    merge_inv = 0
    n1 = middle - left + 1
    n2 = right - middle
    L = A[left : middle+1]
    R = A[middle+1 : right+1]
    i = 0
    j = 0

    for k in range(left, right+1):
        if (i == n1):
            merge_inv += n1 - i
            A[k] = R[j]
            j += 1
        elif (j == n2):
            A[k] = L[i]
            i += 1
        elif (L[i] > R[j]):
            merge_inv += n1 - i
            A[k] = R[j]
            j += 1
        elif (L[i] <= R[j]):
            A[k] = L[i]
            i += 1

    return (merge_inv + l + r)

def count_inversions(A, left, right):
    if (left >= right):
        return 0
    else:
        middle = (left + right) // 2
        l = count_inversions(A, left, middle)
        r = count_inversions(A, middle+1, right)
        return add_inversions(A, left, middle, right, l, r)

l = [5, 2, 4, 7, 1, 3, 2, 6]
print(count_inversions(l, 0, len(l)-1))
        
