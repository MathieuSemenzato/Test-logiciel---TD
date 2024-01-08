import unittest
import stack

class TestFIFO(unittest.TestCase):
	def test_add_and_remove(self):
		test_stack = stack.Stack()
		self.assertEqual(stack.Stack.insert_data_fifo(test_stack, 12), [12])
		self.assertEqual(stack.Stack.insert_data_fifo(test_stack, 13), [12,13])
		self.assertEqual(stack.Stack.insert_data_fifo(test_stack, 11), [12,13,11])
		self.assertEqual(stack.Stack.insert_data_fifo(test_stack, -5), [13,11,-5])

		self.assertEqual(stack.Stack.remove_data_fifo(test_stack), [11, -5])
		self.assertEqual(stack.Stack.remove_data_fifo(test_stack), [-5])
		self.assertEqual(stack.Stack.remove_data_fifo(test_stack), [])

if __name__ == '__main__':
	unittest.main()