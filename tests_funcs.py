import unittest
import funcs

class TestMaxListInt(unittest.TestCase):
	def test_isequal(self):
		self.assertEqual(funcs.max_list_int([1,1,1,1,1]), [1,1,1])
		self.assertEqual(funcs.max_list_int([1,1,3,3,3]), [3,3,3])
		self.assertEqual(funcs.max_list_int([1,1,1,3,3]),[3,3,1])

	def test_classic(self):
		self.assertEqual(funcs.max_list_int([0,1,2,3,4,5]), [5,4,3])
		self.assertEqual(funcs.max_list_int([-5,-4,-3,-2,-1]), [-1,-2,-3])
		self.assertEqual(funcs.max_list_int([-3, -7, 0, 2, -1]), [2,0,-1])

	def test_double(self):
		self.assertEqual(funcs.max_list_int([-4,-3,-4,-3,-5]), [-3,-3,-4])


class TestMinListInt(unittest.TestCase):
	def test_isequal(self):
		self.assertEqual(funcs.min_list_int([1,1,1,1,1], 2), [1,1])
		self.assertEqual(funcs.min_list_int([1,1,3,3,3], 4), [1,1,3,3])

	def test_classic(self):
		self.assertEqual(funcs.min_list_int([0,1,2,3,4,5], 3), [0,1,2])
		self.assertEqual(funcs.min_list_int([-5,-4,-3,-2,-1], 2), [-5,-4])
		self.assertEqual(funcs.min_list_int([-3, -7, 0, 2, -1], 4), [-7,-3,-1,0])

	def test_double(self):
		self.assertEqual(funcs.min_list_int([-4,-3,-4,-3,-5], 3), [-5,-4,-4])


class TestIsPremier(unittest.TestCase):
	def test_NegativeNumber(self):
		self.assertEqual(funcs.is_premier(-12), False)
		self.assertEqual(funcs.is_premier(-1), False)
		self.assertEqual(funcs.is_premier(-2), True)
		self.assertEqual(funcs.is_premier(-89), True)
		self.assertEqual(funcs.is_premier(-50), False)

	def test_PositiveNumber(self):
		self.assertEqual(funcs.is_premier(12), False)
		self.assertEqual(funcs.is_premier(1), False)
		self.assertEqual(funcs.is_premier(2), True)
		self.assertEqual(funcs.is_premier(89), True)
		self.assertEqual(funcs.is_premier(50), False)

	def test_zero(self):
		self.assertEqual(funcs.is_premier(0), False)

class TestisArithmeticSuite(unittest.TestCase):
	def test_freeze(self):
		self.assertEqual(funcs.is_arithmetic([1,1,1,1,1]), True)
		self.assertEqual(funcs.is_arithmetic([1,0,0,0,0]), False)
		self.assertEqual(funcs.is_arithmetic([0,1,1,1,1]), False)
		
	def test_classic(self):
		self.assertEqual(funcs.is_arithmetic([1,1,3,5,7]), False)
		self.assertEqual(funcs.is_arithmetic([1,3,5,7,9]), True)
		self.assertEqual(funcs.is_arithmetic([0,2,4,6,8]), True)
		self.assertEqual(funcs.is_arithmetic([0,2,4,6]), True)
		self.assertEqual(funcs.is_arithmetic([1,4,7]), True)

	def test_not_enough_data(self):
		self.assertEqual(funcs.is_arithmetic([1]), False)
		self.assertEqual(funcs.is_arithmetic([1, 3]), False)

class TestisGeometricSuite(unittest.TestCase):
	def test_freeze(self):
		self.assertEqual(funcs.is_geometric([1,1,1,1,1]), True)
		self.assertEqual(funcs.is_geometric([1,0,0,0,0]), True)
		self.assertEqual(funcs.is_geometric([0,1,1,1,1]), False)
		
	def test_classic(self):
		self.assertEqual(funcs.is_geometric([1,1,3,5,7]), False)
		self.assertEqual(funcs.is_geometric([1,2,4,8,16]), True)
		self.assertEqual(funcs.is_geometric([6,18,54,162]), True)		
		self.assertEqual(funcs.is_geometric([1,2,4]), True)
		self.assertEqual(funcs.is_geometric([6,18,54]), True)

	def test_not_enough_data(self):
		self.assertEqual(funcs.is_arithmetic([1]), False)
		self.assertEqual(funcs.is_arithmetic([1, 3]), False)

if __name__ == '__main__':
	unittest.main()