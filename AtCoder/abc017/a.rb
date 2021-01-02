puts(
  gets.split(' ').map(&:to_i).inject(:*) / 10 + gets.split(' ').map(&:to_i).inject(:*) / 10 + gets.split(' ').map(&:to_i).inject(:*) / 10
)
