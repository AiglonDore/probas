import matplotlib.pyplot as plt

def plotValues(X,Y,mult=False):
    if mult:
        for y in Y:
            plt.plot(X,y)
    else:
        plt.plot(X,Y)
    plt.show()