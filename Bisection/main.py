from util import *
from decimal import *

class biseccion:

    def __init__(self, function, error, limit = 100):
        """
            function: lambda function
            error: the minimum error
            limit: Iteration limit
        """

        self.function = function
        self.a = Decimal(0)
        self.b = Decimal(0)
        self.error = error
        self.epsilon = Decimal(10000000)
        self.limit = limit

    def getLimit(self):
        return self.limit

    def getError(self):
        return self.error

    def getEpsilon(self):
        return self.epsilon

    def setEpsilon(self, val):
        self.epsilon = val

    def set_a(self, val):
        self.a = val

    def get_a(self):
        return self.a

    def set_b(self, val):
        self.b = val

    def get_b(self):
        return self.b

    def getFunction(self):
        """
            Returns the function of which we want to find it's roots.

            returns: Lambda function
        """

        return self.function

    def start(self):
        """
            Starts computing the function's root within the interval
            [a, b]. Returns the root or if it exceeds a certain iteration
            limit, returns None.

            returns: Decimal or None
        """

        """
            How the method works:
                Every iteration we get a middle value x_n between a and b.
                Every iteration, if f(x_n) is positive, we update the value
                of a to f(x_n), else, we update the value of b to f(x_n).
        """
        iteration = int(0)
        x_n = Decimal(0)
        x_prev = Decimal(0)

        f = self.function
        u = util()

        a_prev = Decimal(0)
        b_prev = Decimal(0)

        self.a, self.b = u.getInterval(f)

        while((iteration is not self.getLimit())):
            iteration+=1
            b_prev = self.get_b()
            a_prev = self.get_a()

            #print("a", a_prev, "b", b_prev)

            #if the epsilon is less than the error
            if(self.getEpsilon() <= self.getError()):
                print(
                        "Solution found!: ",
                        x_n,
                        f(x_n),
                        "Error: ",
                        self.getError()
                    )
                return x_n

            #We calculate x_n
            x_n = u.getMiddleValue(self.get_a(), self.get_b())

            #if x_n is not a root...
            if ( f(x_n) is not 0):

                #if f(x_n) and f(a) have opposite signs....
                if(f(x_n)*f(self.get_a()) > 0):
                    x_prev = self.get_a()
                    self.set_a(x_n)
                elif(f(x_n)*f(self.get_a()) < 0):
                    x_prev = self.get_b()
                    self.set_b(x_n)

                self.setEpsilon(
                    u.computeAbsoluteError(x_n, x_prev)
                )

            else:
                print(
                        "Solution found!: ",
                        x_n,
                        f(x_n),
                        "Error: ",
                        self.getError()
                    )
                return None
            print(
                "n: " + str(iteration),
                "a: " + str(a_prev),
                "x_n: " + str(x_n),
                "b: " + str(b_prev),
                "f(a): " + str(f(a_prev)),
                "f(b): " + str(f(b_prev)),
                "f(x_n): " + str(f(x_n)),
                "epsilon: " + str(self.getEpsilon()),

            )

        print("Solution could not be found :(")
        return None





def main():
    getcontext().prec = 4
    obj = biseccion((lambda x: (x**2) - 2), 0.001, limit = 11)
    obj.start()

    #print(util().verifyOppositeSign(1, 4))

if __name__ == '__main__':
    main()
