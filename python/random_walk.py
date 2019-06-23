import random


def random_walk(n):
    """ Return coordinates after 'n' blocks random walk """
    x, y = 0 , 0
    for i in range(n):
        (dx, dy) = random.choice([(0, 1), (0, -1), (1, 0), (-1, 0)])
        x += dx
        y += dy
    return (x, y)

def test_random_walk():
    for i in range(25):
        walk = random_walk(10)
        print(walk, "Distance from home = ", abs(walk[0]) + abs(walk[1]))


test_random_walk()