# encoding: utf-8

y = 2
def execute():

    def Q(x):
        print "Estático pues: x+y=", x+y

    def rewrite():
        y = 3
        Q(90)
        
    rewrite()

execute()