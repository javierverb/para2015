#!/bin/env ruby
# encoding: utf-8

=begin
Ruby es un lenguaje de tipado DEBIL 
=end

puts "probamos que tipo de tipado tiene Ruby"
num = 10
puts "num = ", num
puts "La variable a, ¿es Integer?"
puts num.is_a?(Integer)
puts "\n"

word = "hola!! "
puts "word = ", word
puts "La variable word, ¿es String?"
puts word.is_a?(String)
puts "\n"

result = word * num
puts "result = ", result
puts "La variable result, ¿es String?"
puts result.is_a?(String)
puts "\n"
puts "Ruby es de tipado DEBIL"
puts "\n"