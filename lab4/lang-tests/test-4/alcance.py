"""
python tiene alcance ESTÁTICO
"""

global_var = 1

def function_a(z):
	print "function_a, z-> ", z
	print "function_a, global_var-> ", global_var
	print "return: ", (global_var+z)
	return (global_var + z)

def function_b(y):
	print "function_b, y-> ", y
	global global_var
	global_var = y+1
	print "function_b, global_var-> ", global_var
	print "function_b, return: ", (global_var * y)
	return function_a(global_var * y)

function_b(3)
"""
terminado
"""
