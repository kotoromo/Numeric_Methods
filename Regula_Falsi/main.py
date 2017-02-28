from util import *
from decimal import *
import math

class regula_falsi:

    def __init__(self, function, error, limit = 100, intervals = None, intervals_restriction = None):
        """
            function: lambda function
            error: minimum error
            limit: iteration limit
            intervals: tuple with custom intervals (a, b).
                       If custom intervals are not set,
                       program computes its own intervals

            intervals_restriction: String that indicates a restriction for the
                                   method that computes the intervals. The
                                   strings are: "Positives", "Negatives"

            NOTE: The intervals_restriction parameter is experimental (and broken atm).
            To be fixed soon :9



        """
        #TODO Fix god damn intervals_restriction parameter >:c

        self.function = function
        self.epsilon = float(10000000)
        self.error = error
        self.limit = limit
        self.intervals = intervals
        self.intervals_restriction = intervals_restriction





    def getSetIntervals(self):
        return self.intervals


    def getLimit(self):
        return self.limit

    def getFunction(self):
        return self.function

    def getError(self):
        return self.error

    def getEpsilon(self):
        return self.epsilon

    def setEpsilon(self, val):
        self.epsilon = val

    def start(self):
        iteration = int(0)
        x = float(0)
        x_prev = float(0)

        f = self.getFunction()
        u = util()

        if(self.getSetIntervals() is None):
            a, b = u.getInterval(f, self.intervals_restriction)
        else:
            a, b = self.getSetIntervals()

        a_prev, b_prev = a, b

        while( (iteration is not self.getLimit()) ):
            iteration += 1
            a_prev, b_prev = a, b

            if(self.getEpsilon() <= self.getError()):
                print(
                        "Solution found!: ",
                        x,
                        f(x),
                        "Error: ",
                        self.getEpsilon()
                    )
                return x

            x_prev = x
            x = u.getSlopeByTwoPoints( ( a, f(a) ) , ( b, f(b) ) )

            if ( f(x) is not 0):
                if( u.verifyOppositeSign( f(x), f(b) ) ):
                    a_prev = a
                    a = x
                else:
                    b_prev = b
                    b = x

                self.setEpsilon(
                    u.computeAbsoluteError(f(x), f(x_prev))
                )
            else:
                print(
                        "Solution found!: ",
                        x,
                        f(x),
                        "Error: ",
                        self.getEpsilon()
                    )
                return None
            print(
                "n: " + str(iteration),
                "a: " + str(a_prev),
                "x_n: " + str(x),
                "b: " + str(b_prev),
                "f(a): " + str(f(a_prev)),
                "f(b): " + str(f(b_prev)),
                "f(x): " + str(f(x)),
                "epsilon: " + str(self.getEpsilon()),

            )

        print("Solution could not be found :(")
        return None




    def getX_next(self, a_n, b_n):
        return float(a_n + b_n)/2.0


def main():
    """
    regula_falsi(
        lambda x: ((x-6)*x+4)*x+5,
        0.005,
        limit = 10,
        intervals = (1, 2)
    ).start()

    u = util()
    """

    function = lambda t: 680*(math.log1p(60.0) -  math.log1p(60.0 - t)) - 9.81*t - 11.2

    regula_falsi(
        function,
        0.000001,
        limit = 100000
    ).start()
if __name__ == '__main__':
    main()
