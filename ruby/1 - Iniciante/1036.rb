entrada = gets.chomp.split(" ")
$a = entrada[0].to_f
$b = entrada[1].to_f
$c = entrada[2].to_f

def doDelta
	$b**2 - 4 * $a * $c
end

delta = doDelta
if $a == 0
	puts "Impossivel calcular"
elsif delta >= 0 
	result1 = result2 = -$b
	raiz = Math.sqrt(delta)
	result1 += raiz
	result2 -= raiz
	result1 /= 2*$a
	result2 /= 2*$a
	puts ("R1 = " + '%0.5f' % result1)
	puts ("R2 = " + '%0.5f' % result2)
else
	puts "Impossivel calcular"
end
