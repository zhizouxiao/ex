class Equ(object):
    """docstring for Equ"""
    def __init__(self, _id, level, qua, _type):
        super(Equ, self).__init__()
        self.id = _id
        self.level = level
        self.qua = qua
        self.type = _type

    def __repr__(self):
        return str(self.id)


e1 = Equ(1, 1, 4, 4)
e2 = Equ(2, 3, 3, 3)
e3 = Equ(3, 2, 2, 1)

def func(a, b):
    if a.level < b.level:
        return 1
    return -1


print sorted([e1, e2, e3], cmp=func)
