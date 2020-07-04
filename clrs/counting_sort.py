def counting_sort(a, b, k):
    c = [0] * (k+1)

    for i in range(len(a)):
        c[a[i]] += 1
    ## c contains number of times i occurs in a
    for i in range(1, len(c)):
        c[i] += c[i-1]
    ## c contains numbers less than or equal to
    ## i in a

    for i in range(len(a)-1, -1, -1):
        print(i, a[i], c[a[i]])
        b[c[a[i]]-1] = a[i]
        c[a[i]] -= 1

    return b

a = [2, 5, 3, 0, 2, 3, 0, 3]
print(counting_sort(a, a[:], 5))
