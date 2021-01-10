a = gets.to_i

if a >= 17
  p a - 7
else
  ans = nil
  (2..30).each do |i|
    ans = i if a.to_s(i) == '17'
  end
  if ans
    puts ans
  else
    p(-1)
  end
end
