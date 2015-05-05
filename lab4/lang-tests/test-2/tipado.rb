#!/bin/env ruby
# encoding: utf-8

=begin
Ruby es un lenguaje de tipado DEBIL 
=end

puts "probamos que tipo de tipado tiene Ruby"
a = 12
b = 3.14
puts "a = ",  a
puts "La variable a, ¿es Integer?"
puts a.is_a?(Integer)
puts "\n"

puts "b = ",  b
puts "La variable b, ¿es Float?"
puts b.is_a?(Float)
puts "\n"

result = a + b
puts "result = ", result
puts "La variable result, ¿es Float?"
puts result.is_a?(Float)