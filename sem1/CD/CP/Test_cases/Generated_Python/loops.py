def main () :
	i = 1
	fib = 1
	target = 10
	temp = 0
	while (i < target) :
		temp = fib
		fib += temp
		i+=1
	
	print(fib)
	return 0

if __name__ == '__main__':
	main()
