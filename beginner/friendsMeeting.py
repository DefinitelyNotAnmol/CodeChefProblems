import math

def isPrime(n):
	if n == 1:
		return False
        
	# from 1 to sqrt(n) 
	for x in range(2, (int)(math.sqrt(n))+1):
		if n % x == 0:
			return False 
	return True


def smallestPrime(numbers):
	min = 2520
	for i in range(0, len(numbers)):
		for j in range(i+1, len(numbers)):
			product = numbers[i] * numbers[j]
			if isPrime(product) and product < min:
				min = product

	if min == 2520:
		return -1
	else:
		return min


testCases = int(input())
cases = []
for testNo in range(testCases):
	fakeInput = int(input())	#no need for this input in my code
	numbers = [int(n) for n in input().split()]
	cases.append(numbers)

for case in cases:
	print(smallestPrime(case))