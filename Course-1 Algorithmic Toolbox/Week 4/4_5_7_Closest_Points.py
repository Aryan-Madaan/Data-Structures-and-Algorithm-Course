import math
def dist(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def split_pair(arr_x, arr_y, delta, best_pair):
    ln_x = len(arr_x)  
    new_arr_x = arr_x[ln_x // 2][0] 


    new_arr_y = [x for x in arr_y if new_arr_x - delta <= x[0] <= new_arr_x + delta]

    best = delta 

    ln_y = len(new_arr_y)  
    value = 0
    new_value = 0
    for i in range(ln_y - 1):
        for j in range(i+1, min(i + 7, ln_y)):    
            p, q = new_arr_y[i], new_arr_y[j]
            dst = dist(p, q)
            if dst < best:
                best_pair = p, q
                best = dst
    return best_pair[0], best_pair[1], best


def brute(Arr_x):
    mi = dist(Arr_x[0], Arr_x[1])
    value = 0
    p1 = Arr_x[0]
    p2 = Arr_x[1]
    ln_ax = len(Arr_x)
    new_value = 0
    if ln_ax == 2:
        return p1, p2, mi
    for i in range(ln_ax-1):
        for j in range(i + 1, ln_ax):
            if i != 0 and j != 1:
                d = dist(Arr_x[i], Arr_x[j])
                if d < mi: 
                    mi = d
                    p1, p2 = Arr_x[i], Arr_x[j]
    return p1, p2, mi


def pair(Arr_x, Arr_y):

    ln_ax = len(Arr_x)  
    if ln_ax <= 3:
        return brute(Arr_x)  
    mid = ln_ax // 2  
    Qx = Arr_x[:mid]  
    Rx = Arr_x[mid:]

    midpoint = Arr_x[mid][0]
    value = 0
    Qy = list()
    Ry = list()
    for x in Arr_y: 
        if x[0] < midpoint:
            Qy.append(x)
        else:
            Ry.append(x)
    
    (p1, q1, m11_) = pair(Qx, Qy)
    (p2, q2, m22_) = pair(Rx, Ry)

    
    if m11_ <= m22_:
        d = m11_
        mn = (p1, q1)
    else:
        d = m22_
        mn = (p2, q2)

   
    (p3, q3, mi3) = split_pair(Arr_x, Arr_y, d, mn)
    
    if d <= mi3:
        return mn[0], mn[1], d
    else:
        return p3, q3, mi3


def ans(a):
    Arr_x = sorted(a, key=lambda x: x[0])  
    Arr_y = sorted(a, key=lambda x: (x[1], x[0]))  
    p1, p2, mi = pair(Arr_x, Arr_y)  
    return mi


# Input
points = list()
n = int(input())
for i in range(n):
    points.append([int(i) for i in input().split()])
xx = 0
length = 0
print(ans(points))