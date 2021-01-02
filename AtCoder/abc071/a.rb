x, a, b = gets.split.map(&:to_i)
(x - a).abs > (x - b).abs ? puts('B') : puts('A')
