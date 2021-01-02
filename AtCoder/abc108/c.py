import math

N, K = map(int, input().split())
tmp = math.floor(N / K)
tmp2 = math.floor(2 * N / K)
if K % 2 != 0:
    print(tmp * tmp * tmp)
else:
    print((tmp2 - tmp) * (tmp2 - tmp) * (tmp2 - tmp) + tmp * tmp * tmp)
