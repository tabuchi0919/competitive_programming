n = gets.to_i
ans = 0
n.times do
  a, b = gets.split
  h1, m1 = a.split(':').map(&:to_i)
  h2, m2 = b.split(':').map(&:to_i)
  ans += (h2 * 60 + m2 - h1 * 60 - m1) % 1440
end
puts ans
