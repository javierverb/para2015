# encoding: utf-8
class Constant(object):
    
    __UNPROTECTED = True
    value = None

    def __init__(self, value):
        super(Constant, self).__init__()
        self.value = value
        self.__UNPROTECTED = False

    def __setattr__(self, *arg):
        if not self.__UNPROTECTED:
            raise Exception("This value is only read")
        else:
            super(Constant, self).__setattr__(*arg)

a = Constant(2)
print a.value
# Dado que la clase Constant prohibe la reasignación de un valor
# Esto generará una excepción al cambiar el valor.
# Sin embargo, la variable a puede apuntar a otros valores :(
# de la forma a = "cambie de valor muajaja"
a.value = 3