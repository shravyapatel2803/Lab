import math

class Shape:
    def area(self):
        raise NotImplementedError("overridden")

    def perimeter(self):
        raise NotImplementedError("overridden")

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius**2

    def perimeter(self):
        return 2 * math.pi * self.radius


def get_float_input(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a number.")

while True:
    print("\nShape Calculator Menu:- ")
    print("1. Calculate Rectangle Area and Perimeter")
    print("2. Calculate Circle Area and Perimeter")
    print("3. Exit")

    choice = input("Enter your choice:- ")

    if choice == '1':
        width = get_float_input("Enter rectangle width:- ")
        height = get_float_input("Enter rectangle height:- ")
        rect = Rectangle(width, height)
        print(f"Rectangle: Area={rect.area()}, Perimeter={rect.perimeter()}")

    elif choice == '2':
        radius = get_float_input("Enter circle radius:- ")
        circle = Circle(radius)
        print(f"Circle: Area={circle.area()}, Perimeter={circle.perimeter()}")

    elif choice == '3':
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please try again.")