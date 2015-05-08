#!/bin/env ruby
# encoding: utf-8

=begin
Ruby es un lenguaje de tipado DEBIL 
=end

puts "probamos que tipo de tipado tiene Ruby"
a = 10
puts "a = ", a
puts "La variable a, ¿es Integer?"
puts a.is_a?(Integer)
puts "\n"

word = "hola!! "
puts "word = ", word
puts "La variable word, ¿es String?"
puts word.is_a?(String)
puts "\n"

result = word * a
puts "result = ", result
puts "La variable result, ¿es String?"
puts result.is_a?(String)
puts "\n"
