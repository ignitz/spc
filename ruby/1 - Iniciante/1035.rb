# Teste de Seleção 1
entrada = gets.chomp.split(" ")
a = entrada[0].to_i
b = entrada[1].to_i
c = entrada[2].to_i
d = entrada[3].to_i

if (b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0)
	puts "Valores aceitos"
else
	puts "Valores nao aceitos"
end