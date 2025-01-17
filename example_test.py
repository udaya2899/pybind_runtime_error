import unittest
from pybind11_abseil import status
import example_bindings

class ExampleTest(unittest.TestCase):
    def test_example_not_found(self):
        try:
            example_bindings.example()
        except status.StatusNotOk as e:
            self.assertEqual(
                str(e), 'NOT_FOUND: Resource not found.'
            )
        except Exception as e:
            print(f"Caught exception type: {type(e)}")
            print(f"Caught exception: {e}")
            self.fail("status.StatusNotOk not raised")  # Fail if no exception


if __name__ == '__main__':
    unittest.main()
