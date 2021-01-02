a, b = gets.split.map(&:to_i)
s = gets
if s.match(/\d{#{a}}-\d{#{b}}/)
  puts 'Yes'
else
  puts 'No'
end
