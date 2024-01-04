import unittest
import funcs

class TestMaxListInt(unittest.TestCase):
	def test_max_list_int(self):
		self.assertEqual(funcs.max_list_int([0,1,2,3,4,5]), [3,4,5])
		self.assertEqual(funcs.max_list_int([-5,-4,-3,-2,-1]), [-1,-2,-3])
		self.assertEqual(funcs.max_list_int([-4,-3,-4,-3,-5]), [-5,-4,-3])
		self.assertEqual(funcs.max_list_int([1,1,1,1,1]), [1])
		self.assertEqual(funcs.max_list_int([-3, -7, 0, 2, -1]), [-1,0,2])

if __name__ == '__main__':
	unittest.main()