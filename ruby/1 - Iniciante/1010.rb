class Peca
	@codigo
	@quantidade
	@valorUnit
	def initialize(codigo, quantidade, valorUnit)
		@codigo = codigo
		@quantidade = quantidade
		@valorUnit = valorUnit.to_f
	end

	def print
		puts @codigo
		puts @quantidade
		puts @valorUnit
	end
	
	def soma
		@quantidade.to_f * @valorUnit
	end
end

entrada = gets.chomp.split(" ")
peca1 = Peca.new(entrada[0], entrada[1], entrada[2])

entrada = gets.chomp.split(" ")
peca2 = Peca.new(entrada[0], entrada[1], entrada[2])

puts "VALOR A PAGAR: R$ " + ('%.2f' % (peca1.soma + peca2.soma))