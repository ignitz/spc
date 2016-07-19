class Notas
	attr_accessor :n
	attr_accessor :cem
	attr_accessor :cinq
	attr_accessor :vinte
	attr_accessor :dez
	attr_accessor :cinco
	attr_accessor :dois
	attr_accessor :um
	
	def initialize(n)
		@n = n
		@cem = 0
		@cinq = 0
		@vinte = 0
		@dez = 0
		@cinco = 0
		@dois = 0
		@um = 0
	end

	def print
		puts n
		puts "#{@cem} nota(s) de R$ 100,00"
		puts "#{@cinq} nota(s) de R$ 50,00"
		puts "#{@vinte} nota(s) de R$ 20,00"
		puts "#{@dez} nota(s) de R$ 10,00"
		puts "#{@cinco} nota(s) de R$ 5,00"
		puts "#{@dois} nota(s) de R$ 2,00"
		puts "#{@um} nota(s) de R$ 1,00"
	end
end

def just_do_it(p)
	counter = 0
	while $n/p != 0 do
		$n -= p
		counter += 1			
	end
	return counter
end

$n = gets.chomp.to_i
notas = Notas.new($n)
notas.cem = just_do_it(100)
notas.cinq = just_do_it(50)
notas.vinte = just_do_it(20)
notas.dez = just_do_it(10)
notas.cinco = just_do_it(5)
notas.dois = just_do_it(2)
notas.um = just_do_it(1)

notas.print