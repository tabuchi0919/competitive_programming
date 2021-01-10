s = gets.chomp
l = s.length
if s.chars.uniq.length == l
  puts 'YES'
else
  puts 'NO'
end
