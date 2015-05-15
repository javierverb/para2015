def recursion(ac, result):
    print ac
    return recursion(ac+1, result*2)

recursion(0, 1)