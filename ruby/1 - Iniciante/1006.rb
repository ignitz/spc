a = gets.chomp.to_f
b = gets.chomp.to_f
c = gets.chomp.to_f

media = (2.0*a + 3.0*b+5.0*c)/(2.0 + 3.0 + 5.0)

saida = "MEDIA = " + '%.1f' % media
puts saida