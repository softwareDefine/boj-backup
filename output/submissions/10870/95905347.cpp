n = int(input(""))

def f(k):

	if k<=0:		return 0

	if k<=2:

		return k	

	return f(k-1)+f(k-2)

print(f(n-1))