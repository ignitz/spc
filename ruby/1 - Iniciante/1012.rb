class Figura
	@a
	@b
	@c
	def initialize(a, b, c)
		@a = a.to_f
		@b = b.to_f
		@c = c.to_f
	end
end

class TrianguloRetangulo < Figura
	def area
		puts "TRIANGULO: " + '%.3f' % ((@a * @c)/2.0)
	end
end

class Circulo < Figura
	def area
		puts "CIRCULO: " + '%.3f' % (3.14159*@c**2)
	end
end

class Trapezio < Figura
	def area
		puts "TRAPEZIO: " + '%.3f' % ((@a + @b)*@c/2.0)
	end
end

class Quadrado < Figura
	def area
		puts "QUADRADO: " + '%.3f' % (@b**2)
	end
end

class Retangulo < Figura
	def area
		puts "RETANGULO: " + '%.3f' % (@a * @b)
	end
end

class Entrada
	attr_accessor :a, :b, :c
	def initialize(args)
		if args.length == 3
			@a = args[0]
			@b = args[1]
			@c = args[2]
		end
	end

end

args = gets.chomp.split(" ")
entrada = Entrada.new(args)

triangulo = TrianguloRetangulo.new(entrada.a, entrada.b, entrada.c)
circulo = Circulo.new(entrada.a, entrada.b, entrada.c)
trapezio = Trapezio.new(entrada.a, entrada.b, entrada.c)
quadrado = Quadrado.new(entrada.a, entrada.b, entrada.c)
retangulo = Retangulo.new(entrada.a, entrada.b, entrada.c)

triangulo.area
circulo.area
trapezio.area
quadrado.area
retangulo.area
