def maior(a, b)
	(a + b + (a-b).abs)/2
end

entrada = gets.chomp.split(" ")
a = entrada[0].to_i
b = entrada[1].to_i
c = entrada[2].to_i
a = maior(a, b)
a = maior(a, c)

puts (a.to_s + " eh o maior")