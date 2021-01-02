n = gets.to_i
h = Hash.new(0)
n.times do
  h[gets] += 1
end
puts h.max { |x, y| x[1] <=> y[1] }[0]
