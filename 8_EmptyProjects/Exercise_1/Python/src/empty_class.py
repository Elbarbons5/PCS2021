
class ITest:
    def test_method(self, value: int) -> bool:
        pass

class EmptyClass:
    def __init__(self):
        pass

    def empty_method(self, test: ITest):
        return test.test_method(2)