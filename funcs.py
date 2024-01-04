def max_list_int(list):
	retour = sorted(list, reverse = True)

	return retour[0:3]

def min_list_int(list, N):
	retour = sorted(list, reverse = False)

	return retour[0:N]

def is_premier(N):
	number = abs(N)
	if number == 1 or number == 0:
		return False
	else:
		flag = 0
		for i in range (2, number):
			if number%i == 0:
				flag = 1
				break
		if flag:
			return False
		else:
			return True

def is_arithmetic(list):
	if len(list) < 3:
		print("not enough elements to consider this a suite\n")
		return False
	flag = 0
	first = list[0]
	recurrence = list[1] - list[0]
	for i in range(len(list)):
		if list[i] != first + i*recurrence:
			flag = 1
			break
	if flag:
		return False
	else:
		return True

def is_geometric(list):
	if len(list) < 3:
		print("not enough elements to consider this a suite\n")
		return False
	flag = 0
	first = list[0]
	if list[0] == 0:
		recurrence = list[1]
	else:
		recurrence = list[1]/list[0]
	for i in range(1,len(list)):
		if list[i] != first * recurrence**i:
			flag = 1
			break
	if flag:
		return False
	else:
		return True