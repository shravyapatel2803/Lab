class BankAccount:
    def __init__(self, acc_number, balance=0):
        self.acc_number = acc_number
        self.balance = balance

    def deposit(self, amount):
        if amount <= 0:
            print("Invalid deposit amount. Please enter a positive value.")
            return

        self.balance += amount
        print(f"Deposited {amount}. New balance: {self.balance}")

    def withdraw(self, amount):
        if amount <= 0:
            print("Invalid withdrawal amount. Please enter a positive value.")
            return

        if amount > self.balance:
            print("Insufficient balance!")
        else:
            self.balance -= amount
            print(f"Withdrawn {amount}. Remaining balance: {self.balance}")

    def display(self):
        print(f"Account: {self.acc_number}, Balance: {self.balance}")


def get_float_input(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a number.")

def get_account_number():
    while True:
        acc_number = input("Enter your account number: ")
        if acc_number.isalnum(): 
            return acc_number
        else:
            print("Invalid account number. Please use alphanumeric characters.")


account = None  

while True:
    print("\nBank Account Menu:")
    print("1. Create Account")
    print("2. Deposit")
    print("3. Withdraw")
    print("4. Display Balance")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        acc_number = get_account_number()
        account = BankAccount(acc_number)  
        print(f"Account {acc_number} created.")

    elif choice == '2':
        if account:
            amount = get_float_input("Enter deposit amount: ")
            account.deposit(amount)
        else:
            print("No account created. Please create an account first.")

    elif choice == '3':
        if account:
            amount = get_float_input("Enter withdrawal amount: ")
            account.withdraw(amount)
        else:
            print("No account created. Please create an account first.")

    elif choice == '4':
        if account:
            account.display()
        else:
            print("No account created. Please create an account first.")

    elif choice == '5':
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please try again.")