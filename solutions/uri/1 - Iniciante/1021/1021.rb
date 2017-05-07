class Notas
	attr_accessor :cem
	attr_accessor :cinq
	attr_accessor :vinte
	attr_accessor :dez
	attr_accessor :cinco
	attr_accessor :dois
	attr_accessor :um

	def print
		puts "NOTAS:"
		puts "#{@cem} nota(s) de R$ 100.00"
		puts "#{@cinq} nota(s) de R$ 50.00"
		puts "#{@vinte} nota(s) de R$ 20.00"
		puts "#{@dez} nota(s) de R$ 10.00"
		puts "#{@cinco} nota(s) de R$ 5.00"
		puts "#{@dois} nota(s) de R$ 2.00"
	end
end

class Moedas
	attr_accessor :umReal
	attr_accessor :cinq
	attr_accessor :vinteCinco
	attr_accessor :dez
	attr_accessor :cinco
	attr_accessor :um

	def print
		puts "MOEDAS:"
		puts "#{@umReal} moeda(s) de R$ 1.00"
		puts "#{@cinq} moeda(s) de R$ 0.50"
		puts "#{@vinteCinco} moeda(s) de R$ 0.25"
		puts "#{@dez} moeda(s) de R$ 0.10"
		puts "#{@cinco} moeda(s) de R$ 0.05"
		puts "#{@um} moeda(s) de R$ 0.01"
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

entrada = gets.chomp
$n = entrada.to_i

notas = Notas.new
notas.cem = just_do_it(100)
notas.cinq = just_do_it(50)
notas.vinte = just_do_it(20)
notas.dez = just_do_it(10)
notas.cinco = just_do_it(5)
notas.dois = just_do_it(2)

notas.print

# Ajuste pra trabalhar com inteiro
$n = (entrada.to_f * 100.0).to_i % 100 + $n * 100

moedas = Moedas.new
moedas.umReal = just_do_it(100)
moedas.cinq = just_do_it(50)
moedas.vinteCinco = just_do_it(25)
moedas.dez = just_do_it(10)
moedas.cinco = just_do_it(5)
moedas.um = just_do_it(1)

moedas.print