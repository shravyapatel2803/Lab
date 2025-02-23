class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

    def __add__(self, other):
        
        new_salary = self.salary + other.salary
        return Employee(f"{self.name} & {other.name}", new_salary)

    def __sub__(self, other):
        
        return self.salary - other.salary

    def __str__(self):
        return f"Employee: {self.name}, Salary: {self.salary}"


def get_employee_info():
    name = input("Enter employee name: ")
    while True:
        try:
            salary = float(input("Enter employee salary: "))
            if salary >= 0:  
                return name, salary
            else:
                print("Salary must be non-negative.")
        except ValueError:
            print("Invalid salary. Please enter a number.")


while True:
    print("\nEmployee Operations:")
    print("1. Create Employee 1")
    print("2. Create Employee 2")
    print("3. Combine Employees (Salary)")
    print("4. Compare Salaries (Difference)")
    print("5. Display Employee Information")
    print("6. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        name1, salary1 = get_employee_info()
        emp1 = Employee(name1, salary1)
        print(emp1)  

    elif choice == '2':
        name2, salary2 = get_employee_info()
        emp2 = Employee(name2, salary2)
        print(emp2)  

    elif choice == '3':
        if 'emp1' in locals() and 'emp2' in locals():  
            combined_emp = emp1 + emp2
            print(f"Combined Employee: {combined_emp}")
        else:
            print("Please create both employees first.")

    elif choice == '4':
        if 'emp1' in locals() and 'emp2' in locals():  
            salary_diff = emp1 - emp2
            print(f"Salary difference: {salary_diff}")
        else:
            print("Please create both employees first.")

    elif choice == '5':
        if 'emp1' in locals():
            print(emp1)
        if 'emp2' in locals():
            print(emp2)

    elif choice == '6':
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please try again.")