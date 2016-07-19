A = gets.chomp.to_f
B = gets.chomp.to_f
media = (3.5*A + 7.5*B)/11
media = media.round(5)
puts "MEDIA = #{media}" 