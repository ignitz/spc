# Não gostei desta implementação. Apanhei demais com symbol e resolvi fazer deste jeito

tabela = Array.new

tabela.push(["Cachorro Quente", 4.00])
tabela.push(["X-Salada", 4.50])
tabela.push(["X-Bacon", 5.00])
tabela.push(["Torrada simples", 2.00])
tabela.push(["Refrigerante", 1.50])


entrada = gets.chomp.split(" ")

print "Total: R$ "
puts '%.2f' % (tabela[entrada[0].to_i-1][1]*entrada[1].to_f).to_f

