"""
PYTHON es un lenguaje de tipado DEBIL
"""

def tipado_debil():
	num = 23
	print "num = ", num
	print "num es", type(num) 
	print "\n"
	
	word = "hola a todos"
	print "word = ", word
	print "word es", type(word)
	print"\n"
	
	result = word * num
	print "result = ", result
	print"\n"
	print "result es", type(result)
	print"\n"
	print("Python es de tipado DEBIL\n")

tipado_debil()
