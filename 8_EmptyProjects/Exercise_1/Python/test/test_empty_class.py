from unittest import TestCase, mock

import src.empty_class as empty_class


class TestEmptyClass(TestCase):
    def test_empty_method(self):
        empty_object = empty_class.EmptyClass()

        test_mock = mock.Mock(spec=empty_class.ITest) # Mock the object of interface ITest
        test_mock.test_method.return_value = True # Set the return of the method test_method to True

        try:
            self.assertEqual(empty_object.empty_method(test_mock), True)
        except Exception as ex:
            self.fail()

        test_mock.test_method.assert_called_once() # Check if the method is called
        test_mock.test_method.assert_called_with(2) # Check if test_method is called with input value=2

        test_mock.test_method.reset_mock() # Reset mock
        test_mock.test_method.side_effect = RuntimeError('Boom') # Throw exception on method call
        try:
            empty_object.empty_method(test_mock)
            self.fail()
        except Exception as ex:
            self.assertEqual(ex.args[0], "Boom")
