number = gets.chomp.to_i
horas = gets.chomp.to_i
valor = gets.chomp.to_f

puts "NUMBER = #{number}"

salario = "SALARY = U$ " + ('%.2f' % (valor * horas))
puts salario