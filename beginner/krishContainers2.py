no_of_containers = int(input())
containers = [0] * no_of_containers

no_of_days = int(input())

for i in range(no_of_days):
	range_ = [int(n) for n in input().split()]
	for i in range(range_[0]-1, range_[1]):
		containers[i] += 1

containers.sort(reverse=True)
no_of_queries = int(input())
answer = []

for queryNo in range(no_of_queries):
	query = int(input())
	j = 0
	count = 0
	while j < no_of_containers and containers[j] >= query:
		count += 1
		j += 1
	answer.append(count)

for count in answer:
	print(count)