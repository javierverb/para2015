"""
PYTHON es un lenguaje de tipado DEBIL
"""

def tipado_debil():
    num = 10
    print "num = ", num
    print "num es", type(num) 
    print "\n"
    
    word = "hola a todos\n"
    print "word = ", word
    print "word es", type(word)
    
    result = word * num
    print "result:"
    print result
    print "result es", type(result)
    print("Python es de tipado DEBIL\n")

tipado_debil()
