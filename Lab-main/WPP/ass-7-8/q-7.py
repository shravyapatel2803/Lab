import math

class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2)

    def angle_with_x_axis(self):
        return math.atan2(self.y, self.x)

    def __str__(self):
        return f"Vector2D({self.x}, {self.y})"

class Vector3D(Vector2D):
    def __init__(self, x, y, z):
        super().__init__(x, y)
        self.z = z

    def magnitude(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

    def __str__(self):
        return f"Vector3D({self.x}, {self.y}, {self.z})"


def get_float_input(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a number.")

def create_vector(dimension):
    if dimension == 2:
        x = get_float_input("Enter x-coordinate: ")
        y = get_float_input("Enter y-coordinate: ")
        return Vector2D(x, y)
    elif dimension == 3:
        x = get_float_input("Enter x-coordinate: ")
        y = get_float_input("Enter y-coordinate: ")
        z = get_float_input("Enter z-coordinate: ")
        return Vector3D(x, y, z)
    else:
        print("Invalid dimension.")
        return None

def display_vector_info(vector):
    if vector:
        print(vector, "Magnitude:", vector.magnitude())
        if isinstance(vector, Vector2D):  
            angle = vector.angle_with_x_axis()
            print("Angle with x-axis:", angle)



while True:
    print("\nVector Operations:")
    print("1- Create 2D Vector")
    print("2- Create 3D Vector")
    print("3- Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        vector = create_vector(2)
        display_vector_info(vector)
    elif choice == 2:
        vector = create_vector(3)
        display_vector_info(vector)
    elif choice == 3:
        break
    else:
        print("Invalid choice.")
