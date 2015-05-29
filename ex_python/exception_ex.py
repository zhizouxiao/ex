class AuthError(Exception):
    """docstring for AuthError"""
    def __init__(self, arg):
        super(AuthError, self).__init__()
        self.arg = arg
try:
    raise AuthError("AuthError!")
except AuthError, e:
    print 1
except Exception, e:
    print 2
