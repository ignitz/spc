n = gets.chomp.to_i
horas = (n/60)/60
minutos = (n/60) % 60
segundos = n % 60
print horas
print ":"
print minutos
print ":"
puts segundos
