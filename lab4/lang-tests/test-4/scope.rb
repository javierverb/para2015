#!/bin/env ruby
# encoding: utf-8

=begin
Ruby es de alcance DINAMICO
=end

global_var = 1

def function_a(z)
	print "function_a, z --> ", z
	print "\n"
	print "function_a, global_var --> ", global_var
	print "\n"
	print "resultado de function_a = ", (global_var + z)
	print "\n"
	return global_var + z

end

def function_b(y)
	print "function_b, y --> ", y
	print "\n"
	global_var = y+1
	print "function_b, global_var --> ", global_var
	print "\n"
	print "function_b, return: ", (global_var*y)
	print "\n"
	return function_a(global_var*y)

end

function_b(3)

=begin
	terminado
=end