# kalvin 31894666

alfa = .8

M = [
    [0, 0, 1],
    [.5, 0, 0],
    [.5, 1, 0],
]


def jacobi(M):
    tamanho = len(M)
    rj = [1.0/tamanho for  i in range(tamanho)]
    solucao = [1.0/tamanho for i in range(tamanho)]

    for k in range(100):
        p = [x for x in solucao]
        for i in range(tamanho):
            pi = 0.0
            for j in range(tamanho):
                pi += alfa * M[i][j] * p[j]
            pi += (1-alfa) * rj[i]
            solucao[i] = pi

    return solucao

print(jacobi(M))