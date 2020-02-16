from math import pi

def circle_area(radius):
    if type(radius) not in [int, float]:
        raise ValueError("The radius must be a non-negative real number. ")
    elif radius < 0:
        raise ValueError("The radius cannot be negative.")
    return pi*(radius**2)

