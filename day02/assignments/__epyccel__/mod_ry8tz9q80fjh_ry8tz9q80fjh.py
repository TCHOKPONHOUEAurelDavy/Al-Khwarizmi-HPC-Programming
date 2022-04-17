def factorial(n : int)->int:
    if n==1 or n==0:
        return 1
    return n*factorial(n-1)
