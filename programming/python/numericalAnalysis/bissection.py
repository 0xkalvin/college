def f(x):
    return(x-2**-x)

def bisseccao(f, a, b, e):
    if f(a)*f(b) > 0:
        print("Extremos devem ter sinais opostos")
    else:
        while (b - a)/2.0 > e:
            media = (a + b)/2.0
            if f(media) == 0:
                return(media) 
            elif f(a)*f(media) < 0:
                b = media
            else:
                a = media
        
        return(media)

resultado = bisseccao(f, 0, 1, 0.00001)

print(round(resultado, 5))
