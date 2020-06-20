import math

l = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]

max_here = -math.inf
max_so_far = -math.inf

for i in range(len(l)):
    if (l[i] > (max_here + l[i])):
        pl = i
        ph = i
        max_here = l[i]
    elif ((max_here + l[i]) > l[i]):
        ph = i
        max_here += l[i]

    if (max_here > max_so_far):
        low = pl
        high = ph
        max_so_far = max_here

print(low, high, max_so_far)

    
    
        
