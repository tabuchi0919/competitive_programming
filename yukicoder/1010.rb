x, y, h = gets.split(' ').map(&:to_i)
x *= 1000
y *= 1000

ans = 0
while true
  x, y = y, x if x > y
  if x > h
    y *= 2
    h *= 4
    ans += 1
  elsif y > h
    x *= 2
    h *= 4
    ans += 1
  else
    break
  end
end

puts ans
