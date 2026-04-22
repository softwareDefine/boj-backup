import math
n = int(input(""))
k = n / (2 + math.sqrt(3))
print(n ** 2 - (3 / 2 * n * n / math.sqrt(3) + 1 / 2 * k * k / math.sqrt(3)))
