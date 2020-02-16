import unittest
from circle import circle_area
from math import pi

class TestCircleArea(unittest.TestCase):
    def test_area(self):
        self.assertAlmostEqual(circle_area(1), pi)
        self.assertAlmostEqual(circle_area(0), 0)
        self.assertAlmostEqual(circle_area(2.1), pi * 2.1 ** 2)
    
    def test_values(self):
        self.assertRaises(ValueError, circle_area, -2)

    def test_types(self):
        self.assertRaises(ValueError, circle_area, "radius")
        self.assertRaises(ValueError, circle_area, True)
        self.assertRaises(ValueError, circle_area, 3+5j) #complex number
        
        
