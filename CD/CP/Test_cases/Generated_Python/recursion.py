def fact (n) :
	if (n < 1):
		return 1	
	else :
		return n * fact(n - 1)	


def main () :
	n = 10
	print(fact(n))
	return 0

if __name__ == '__main__':
	main()
