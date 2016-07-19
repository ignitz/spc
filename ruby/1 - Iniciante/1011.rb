class Esfera
	@radius
	def initialize(radius)
		@radius = radius.to_f
	end
	
	def volume
		(4.0/3.0)*3.14159*@radius**3
	end
end

esfera = Esfera.new(gets.chomp)
puts "VOLUME = " + '%.3f' % esfera.volume