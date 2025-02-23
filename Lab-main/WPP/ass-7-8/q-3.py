class Bank:
    def __init__(self, name):
        self.name = name
        self.customers = {}

    def create_account(self, customer_name, initial_balance=0):
        if customer_name in self.customers:
            print(f"Customer {customer_name} already has an account!")
        else:
            self.customers[customer_name] = initial_balance
            print(f"Account created for {customer_name} with balance {initial_balance}.")

    def deposit(self, customer_name, amount):
        if customer_name in self.customers:
            if amount <= 0:
                print("Invalid deposit amount. Please enter a positive value.")
                return
            self.customers[customer_name] += amount
            print(f"Deposited {amount} to {customer_name}'s account. New balance: {self.customers[customer_name]}")
        else:
            print(f"Customer {customer_name} does not exist!")

    def withdraw(self, customer_name, amount):
        if customer_name in self.customers:
            if amount <= 0:
                print("Invalid withdrawal amount. Please enter a positive value.")
                return
            if self.customers[customer_name] >= amount:
                self.customers[customer_name] -= amount
                print(f"Withdrew {amount} from {customer_name}'s account. New balance: {self.customers[customer_name]}")
            else:
                print("Insufficient funds!")
        else:
            print(f"Customer {customer_name} does not exist!")

    def display_accounts(self):
        if not self.customers:
            print("No accounts in this bank.")
            return

        print("\nBank Accounts:")
        for name, balance in self.customers.items():
            print(f"{name}: ${balance}")


def get_float_input(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a number.")

def get_customer_name():
    while True:
        name = input("Enter customer name: ")
        if name.strip():  # Check if name is not empty or just whitespace
            return name.strip()
        else:
            print("Customer name cannot be empty.")



my_bank = Bank("MyLocalBank")

while True:
    print("\nBank Menu:")
    print("1. Create Account")
    print("2. Deposit")
    print("3. Withdraw")
    print("4. Display Accounts")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        name = get_customer_name()
        initial_balance = get_float_input("Enter initial balance (or 0 for default): ")
        my_bank.create_account(name, initial_balance)

    elif choice == '2':
        name = get_customer_name()
        amount = get_float_input("Enter deposit amount: ")
        my_bank.deposit(name, amount)

    elif choice == '3':
        name = get_customer_name()
        amount = get_float_input("Enter withdrawal amount: ")
        my_bank.withdraw(name, amount)

    elif choice == '4':
        my_bank.display_accounts()

    elif choice == '5':
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please try again.")