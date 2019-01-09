def rempo(m, n):
	product = m * n
	remainder = product % 3
	return remainder


testCases = int(input())
cases = []
for testNo in range(testCases):
	numbers = [int(n) for n in input().split()]
	cases.append(numbers)

for testCase in cases:
	print(rempo(testCase[0], testCase[1]))