p(gets.split(' ').map(&:to_i).inject(1, &:*) % 1_000_000_007)
