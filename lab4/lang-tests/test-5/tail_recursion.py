# encoding: utf-8
def tail_rec(number):
    if number == 0:
        raise Exception("Hey! show the stack")
    else:
        return 1 + tail_rec(number-1)

tail_rec(5)