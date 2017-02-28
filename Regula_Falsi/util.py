from decimal import *
import sys

class util:
    def getInterval(self, function, restriction = None):
        """
            function: lambda function

            Method that obtains the integer intervals where the function
            changes its sign from negative to positive.

            If it finds the function's root within its intervals, it
            returns it.

            returns: Tuple containing the intervals or the function's root
        """
        if(restriction is None):
            sup = 5
            inf = -5
        else:
            if(restriction is "Positives"):
                sup = 2
                inf = 1
            if(restriction is "Negatives"):
                sup = -1
                inf = -2

        while(True):
            for i in range(inf, sup):
                if( (function(i) < 0) and (function(i+1) > 0) is True):
                    return (i, i+1)

                if(function(i) is 0):
                    print("Solution found!: " + str(i))
                    return (i, function(i))

            if(restriction is None):
                inf-=1
                sup+=1

            elif(restriction is "Positives"):
                sup+=1
            elif(restriction is "Negatives"):
                inf-=1

            #print(inf, sup)

    def getMiddleValue(self, a, b):
        """
            Returns a value in-between a and b.

            returns: int
        """
        return (a+b)/2.0


    def computeAbsoluteError(self, x, x_prev):
        """
            Returns the absolute error.

            returns: float
        """
        return abs(
            float(x_prev) - float(x)
        )

    def verifyOppositeSign(self, a, b):
        """
            Returns whether or not a has opposite signs with b.

            returns: boolean
        """
        #if a is a negative number and so is b
        return ( (a < 0) is not (b < 0))

    def getSlopeByTwoPoints(self, a, b):
        """
            a = (x_1, f(x_1))
            b = a = (x_2, f(x_2))
            Returns the pendient by the given points

            returns: float

        """
        m = None

        try:
            m = float(a[0]*b[1] - b[0]*a[1]) / float(b[1] - a[1])
        except ZeroDivisionError as e:
            print(
                    "Singularity found at a = " + str(a[0]) +
                    " f(a) = " + str(a[1]) +
                    " b = " + str(b[0])+
                    " f(b) = " +  str(b[1])
                )

            print("Forcing program to exit. Try with other intervals.")
            sys.exit()

        else:
            pass


        return m
