from decimal import *

class util:
    def getInterval(self, function):
        """
            function: lambda function

            Method that obtains the integer intervals where the function
            changes its sign from negative to positive.

            If it finds the function's root within its intervals, it
            returns it.

            returns: Tuple containing the intervals or the function's root
        """

        sup = 5
        inf = -5

        while(True):
            for i in range(inf, sup):
                if( (function(i) < 0) and (function(i+1) > 0) is True):
                    return (i, i+1)

                if(function(i) is 0):
                    print("Solution found!: " + str(i))
                    return (i, function(i))

            inf-=1
            sup+=1

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
        return abs(float((x_prev)-float(x)))

    def verifyOppositeSign(self, a, b):
        """
            Returns whether or not a has opposite signs with b.

            returns: boolean
        """
        #if a is a negative number and so is b
        return ( (a < 0) is not (b < 0))
