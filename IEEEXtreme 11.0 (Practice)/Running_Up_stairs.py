t = input()


for i in range(t):
    n = input()
    if(n == 1):
        print(1)
    else:
        a = 1
        b = 1
        for j in range(n-1):
            x = a + b
            a = b
            b = x

        print(x)
