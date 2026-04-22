N = int(input())

squares = []
for i in range(1, int(N**0.5) + 1):
    squares.append(i**2)

print(len(squares))