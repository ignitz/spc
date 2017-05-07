nome = gets.chomp
sal_fix = gets.chomp.to_f
venda = gets.chomp.to_f

comissao = 0.15 * venda

puts "TOTAL = R$ " + '%.2f' % (sal_fix + comissao)