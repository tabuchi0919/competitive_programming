Deg, Dis = map(int, input().split())

if Dis < 15:
    W = 0
elif Dis < 93:
    W = 1
elif Dis < 201:
    W = 2
elif Dis < 327:
    W = 3
elif Dis < 477:
    W = 4
elif Dis < 645:
    W = 5
elif Dis < 831:
    W = 6
elif Dis < 1029:
    W = 7
elif Dis < 1245:
    W = 8
elif Dis < 1467:
    W = 9
elif Dis < 1707:
    W = 10
elif Dis < 1959:
    W = 11
else:
    W = 12

if W == 0:
    Dir = "C"
else:
    if Deg < 112.5 or Deg >= 3487.5:
        Dir = "N"
    elif Deg < 337.5:
        Dir = "NNE"
    elif Deg < 562.5:
        Dir = "NE"
    elif Deg < 787.5:
        Dir = "ENE"
    elif Deg < 1012.5:
        Dir = "E"
    elif Deg < 1237.5:
        Dir = "ESE"
    elif Deg < 1462.5:
        Dir = "SE"
    elif Deg < 1687.5:
        Dir = "SSE"
    elif Deg < 1912.5:
        Dir = "S"
    elif Deg < 2137.5:
        Dir = "SSW"
    elif Deg < 2362.5:
        Dir = "SW"
    elif Deg < 2587.5:
        Dir = "WSW"
    elif Deg < 2812.5:
        Dir = "W"
    elif Deg < 3037.5:
        Dir = "WNW"
    elif Deg < 3262.5:
        Dir = "NW"
    else:
        Dir = "NNW"

print(Dir, W)
