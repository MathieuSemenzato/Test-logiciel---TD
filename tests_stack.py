import unittest
import stack

class TestFIFO(unittest.TestCase):
	def test_add_and_remove(self):
		test_stack = stack.FIFO()
		self.assertEqual(stack.FIFO.insert_data_fifo(test_stack, 12), [12])
		self.assertEqual(stack.FIFO.insert_data_fifo(test_stack, 13), [12,13])
		self.assertEqual(stack.FIFO.insert_data_fifo(test_stack, 11), [12,13,11])
		self.assertEqual(stack.FIFO.insert_data_fifo(test_stack, -5), [13,11,-5])

		self.assertEqual(stack.FIFO.remove_data_fifo(test_stack), [11, -5])
		self.assertEqual(stack.FIFO.remove_data_fifo(test_stack), [-5])
		self.assertEqual(stack.FIFO.remove_data_fifo(test_stack), [])

class TestLIFO(unittest.TestCase):
	def test_add_and_remove(self):
		test_stack = stack.LIFO()
		self.assertEqual(stack.LIFO.insert_data_lifo(test_stack, 12), [12])
		self.assertEqual(stack.LIFO.insert_data_lifo(test_stack, 13), [12,13])
		self.assertEqual(stack.LIFO.insert_data_lifo(test_stack, 11), [12,13,11])
		self.assertEqual(stack.LIFO.insert_data_lifo(test_stack, -5), [12,13,-5])

		self.assertEqual(stack.LIFO.remove_data_lifo(test_stack), [12, 13])
		self.assertEqual(stack.LIFO.remove_data_lifo(test_stack), [12])
		self.assertEqual(stack.LIFO.remove_data_lifo(test_stack), [])

if __name__ == '__main__':
	unittest.main()