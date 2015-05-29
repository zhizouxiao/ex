
def g(func):
    """docstring for g"""
    func(1)

def fname():
    """docstring for fname"""

    a = []
    def func(b):
        """docstring for func"""
        a.append(1)

    g(func)
    print a


fname()

