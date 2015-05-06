"""
python tiene alcance estatico ??
"""

global_var = 1

def function_a(z):
	print "function_a, z-> ", z
	print "function_a, global_var-> ", global_var
	print "return: ", global_var+z
	return global_var+z

def function_b(y):
	print "function_b, y-> ", y
	global_var = y+1
	print "function_b, global_var-> ", global_var
	return function_a(global_var*y)

function_b(3)