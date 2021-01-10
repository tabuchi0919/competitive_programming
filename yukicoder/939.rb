a, b = gets.split(' ').map(&:to_i)
bs = b.to_s(2)
as = a.to_s(2).rjust(bs.length, '0')

ans = (
  bs.chars.zip(as.chars).inject(1) do |res, ba|
    bb, aa = ba
    if bb == '1' && aa == '0'
      res * 2
    elsif bb == '0' && aa == '1'
      res * 0
    else
      res
    end
  end
)

if ans == 1
  p 1
else
  p ans / 2
end
