n = gets.chomp.to_i
anos = (n / 365)
mes =  (n % 365) / 30
dias = (n % 365) % 30

puts (anos.to_s + " ano(s)")
puts (mes.to_s + " mes(es)")
puts (dias.to_s + " dia(s)")
