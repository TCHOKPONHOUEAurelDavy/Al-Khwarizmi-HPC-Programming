def f(a):
    return 4.0 / (1. + a * a)

def pi(n, h):
#     print("Execution of PI in parallel with", nb_tasks,"threads")
    #$ omp parallel
    for k in range(100):
        Pi_calc = 0.
        for i in range(n):
            x = h * (i + 0.5)
            Pi_calc += f(x)

        Pi_calc = h * Pi_calc
    return Pi_calc
