"""
PYTHON es un lenguaje de tipado DEBIL
"""

def tipado_debil():
	a = 23
	print "a = ", a
	print "a es", type(a) 
	print "\n"
	
	word = "hola a todos"
	print "word = ", word
	print "word es", type(word)
	print"\n"
	
	resultado = word * a
	print "resultado = ", resultado
	print"\n"
	print "resultado es", type(resultado)
	print"\n"

tipado_debil()
