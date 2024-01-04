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