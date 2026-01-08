def test1(n):
    i = n                   
    while i>0:              
        for j in range(i):  # n + n/2 + n/4 + ... + 1 = 2n
            print(j)        
        i /= 2
        
def test2(n):
    for i in range(n):      # n
        for j in range(i, n):  # n - 1
            print(i, j)     # n*n = n^2

def test3(n):
    i = 1                   
    while i < n:              
        for j in range(i):  # 1+3+9+...+n = n
            print(j)        # O(n)
        i *= 3
 
 
print("test3:",test3(5))