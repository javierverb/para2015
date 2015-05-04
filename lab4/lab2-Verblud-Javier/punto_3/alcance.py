# encoding: utf-8

def execute():

    y = 2 

    def Q(x):
        print "Estático pues: x+y=", x+y

    def rewrite():
        y = 3
        Q(90)
        
    rewrite()

execute()