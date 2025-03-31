import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return x**3 - x - 2

def bisection_method(a, b, tol=1e-5):
    if f(a) * f(b) >= 0:
        print("Invalid Interval")
        return None, None  # Return None for both values to avoid unpacking errors
    
    iterations = []  # Store iteration values for plotting
    while (b - a) / 2.0 > tol:
        c = (a + b) / 2.0
        iterations.append(c)  # Store root approximation
        
        if f(c) == 0:
            break
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    
    return c, iterations

# Call the function
root, iters = bisection_method(1, 2)

if root is not None:  # Ensure root is found before plotting
    print(f"Root Found: {root}")

    # Plotting the root finding process
    plt.plot(range(len(iters)), iters, marker="o", linestyle="-", label="Root Approximation")
    plt.xlabel("Iterations")
    plt.ylabel("Root Value")
    plt.legend()
    plt.title("Bisection Method Root Finding Process")
    plt.grid()
    plt.show()
