# raio = gets.chomp
# area = Math::PI * (raio.to_f)**2 # to_f converte pra float
# puts "A=#{area.round(4)}" # .round() precisão de casas decimais

# O PI é determinado
PI = 3.14159
raio = gets.chomp
area = PI * (raio.to_f)**2 # to_f converte pra float
print "A="
puts '%.4f' % area
