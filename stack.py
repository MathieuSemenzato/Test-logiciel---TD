class FIFO:
	def __init__(self):
		self.values = []
		self.max_element = 3 # indique une taille maximale pour la pile
	
	def insert_data_fifo(self, data):
		# on part du principe que data est un entier (une seule valeur à la fois) à inscrire
		if len(self.values) == self.max_element:
			for i in range (len(self.values)-1):
				self.values[i] = self.values[i+1]
			self.values[len(self.values)-1] = data
		else:
			self.values.append(data)

		return self.values

	def remove_data_fifo(self):
		# on part du principe qu'une seule valeur est retirée à la fois
		if len(self.values) == 0:
			print("ne peut pas depiler car la pile est vide\n")
		else:
			del self.values[0]

		return self.values

class LIFO:
	def __init__(self):
		self.values = []
		self.max_element = 3 # indique une taille maximale pour la pile

	def insert_data_lifo(self, data):
		pass

	def remove_data_lifo(self):
		pass