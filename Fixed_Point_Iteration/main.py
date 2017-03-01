from util import *

"""
    How the method works:
    We must propose an auxiliary function Phi(x) = x for our function f(x) = 0
    This function Phi(x) is equal to f(x) + x = x

    As we get values for x from Phi, we find an approximation for f(x) = 0's
    root.

"""

class fixed_point:

    def __init__(self, function, error, x_0, ite_lim = 100):
        self.function = function
        self.error = error
        self.x_0 = x_0
        self.phi = lambda x: function(x) + x
        self.limit = ite_lim

    def getError(self):
        return self.error

    def getX_0(self):
        return self.x_0

    def getIterationLimit(self):
        return self.limit

    def start(self):
        u = util()
        f = self.function
        phi = self.phi
        epsilon = float(10000000000000000000)
        x = self.x_0
        x_prev = float(0)
        iteration = 0

        while (self.getError() < epsilon and iteration is not self.getIterationLimit()):
            iteration += 1
            x_prev = x
            x = phi(x)
            epsilon = u.computeAbsoluteError(x, x_prev)

            print(
                "n: " + str(iteration),
                "x_" + str(iteration)+": " + str(x),
                "f(x_n): " + str(f(x)),
                "epsilon: " + str(epsilon),
            )

        if(iteration is self.getIterationLimit()):
            print("Solution could not be found :c")

        print(
                "Solution found!: ",
                x,
                f(x),
                "Error: ",
                epsilon
            )

def main():
    function = lambda x: x**2 - 0.5
    x_0 = -0.5

    fixed_point(function, 0.001, x_0).start()

if __name__ == '__main__':
    main()
