require 'bigdecimal'

# puts  123.6 - 123
# x = BigDecimal("123.6") - BigDecimal("123")
# puts x.to_f

entrada = BigDecimal(gets.chomp.to_s)
if entrada >= 0
	if entrada <= 25.0
		puts "Intervalo [0,25]"
	elsif entrada <= 50.0
		puts "Intervalo (25,50]"
	elsif entrada <= 75.0
		puts "Intervalo (50,75]"
	elsif entrada <= 100.0
		puts "Intervalo (75,100]"
	else
		puts "Fora de intervalo"
	end
else
	puts "Fora de intervalo"
end

