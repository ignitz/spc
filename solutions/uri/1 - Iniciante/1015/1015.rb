class Ponto
	attr_reader :x, :y
	def initialize(x, y)
		@x = x.to_f
		@y = y.to_f
	end
end

def distancia(pontoA, pontoB)
	'%.4f' % Math.sqrt((pontoA.x - pontoB.x)**2 + (pontoA.y - pontoB.y)**2)
end

entrada = gets.chomp.split(" ")
pontoA = Ponto.new(entrada[0], entrada[1])
entrada = gets.chomp.split(" ")
pontoB = Ponto.new(entrada[0], entrada[1])
puts distancia(pontoA, pontoB)