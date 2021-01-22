s = gets.chomp
c = s.chars.tally.min_by { |a| a[1] }[0]
puts("#{s.chars.find_index(c) + 1} #{c}")
