# encoding: utf-8

x = 1
def execute():
    
    def fun_a(y):
        print "en fun_a, 'y' vale: ", y
        print "en fun_a, 'x' vale: ", x
        print "en fun_a, x+y vale: ", x+y

    def fun_b():
        y = 3
        x = 0
        print "en fun_b, 'y' vale: ", y
        print "en fun_b, 'x' vale: ", x
        fun_a(123)

    fun_b()

execute()
print "\nPython tiene alcance Estático\n"