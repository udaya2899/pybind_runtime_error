import unittest
from pybind11_abseil import status
import example_bindings

class ExampleTest(unittest.TestCase):
    def test_example_not_found(self):
        try:
            example_bindings.example()
        except status.StatusNotOk as e:
            self.assertEqual(
                str(e), 'Resource not found. [NOT_FOUND]'
            )


if __name__ == '__main__':
    unittest.main()
