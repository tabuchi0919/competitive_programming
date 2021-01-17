puts gets.chomp.reverse.chars.each_slice(3).map { |a| a.join + ',' }.join.chop.reverse
