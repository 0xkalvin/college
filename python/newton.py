


f = lambda x: x**3 - x**2 - 1
Df = lambda x: 3*x**2 - 2*x


def metodo_de_newton(f, Df, p, e):
    """ Recebe uma função f, sua derivada Df, um ponto p inicial, e um epsilon de parada"""
    
    xn = p
    n = 0
    while(True):
        fxn = f(xn)
        if abs(fxn) < e:
            break
        Dfxn = Df(xn)
        if Dfxn == 0:
            xn = None
            break
        xn = xn - fxn/Dfxn
        n += 1

    return 'Solução encontrada na iteração {}: {}'.format(n, xn) if xn is not None else 'Solução não encontrada.'



print(metodo_de_newton(f, Df, 1, 1e-10))