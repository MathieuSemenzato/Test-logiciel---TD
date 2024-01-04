def max_list_int(list):
	retour = sorted(list, reverse = True)

	return retour[0:3]

def min_list_int(list, N):
	retour = sorted(list, reverse = False)

	return retour[0:N]
