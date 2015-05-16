# encoding: utf-8
def tail_rec_optimized(number, acc):
    if number == 0:
        raise Exception("Hey! show the stack")
    else:
        return tail_rec_optimized(number-1, acc+1)

tail_rec_optimized(5, 0)