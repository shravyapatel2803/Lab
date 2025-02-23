class Queue:
    def __init__(self):
        self.items = []  # Changed variable name to "items" to mimic an alternate naming choice

    def is_empty(self):
        return len(self.items) == 0  # Could also use "not self.items" but kept it explicit for clarity

    def enqueue(self, item):
        self.items.append(item)  
        print(f"Added to queue: {item}")  # Reworded to sound more casual

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty. Nothing to remove.")  # Slightly different phrasing
            return None
        removed_item = self.items.pop(0)
        print(f"Removed from queue: {removed_item}")  # Matching the enqueue message
        return removed_item

    def peek(self): 
        if self.is_empty():
            print("Queue is empty. No front element.")
            return None
        return self.items[0]  # Keeping it simple, no unnecessary else clause

    def size(self):
        return len(self.items)  # Could store size separately, but let's keep it dynamic

    def display(self):
        if self.is_empty():
            print("Queue is empty. Nothing to show.")
        else:
            print("Current queue:", self.items)  # Changed message wording slightly


# Simple function to print menu options (could've used a dict but keeping it classic)
def show_menu():
    print("\nQueue Operations:")
    print("1 - Enqueue")
    print("2 - Dequeue")
    print("3 - Peek Front Element")
    print("4 - Check Queue Size")
    print("5 - Show Queue Contents")
    print("6 - Exit")


# Helper function to safely get an integer input
def get_integer_input(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Oops! Please enter a valid number.")


# Standard input function, kept separate in case we later validate strings
def get_string_input(prompt):
    return input(prompt)


# Main program logic
queue = Queue()

while True:
    show_menu()
    choice = get_integer_input("Select an option: ")

    if choice == 1:
        item = get_string_input("Enter item to add: ")
        queue.enqueue(item)
    elif choice == 2:
        queue.dequeue()
    elif choice == 3:
        front = queue.peek()
        if front is not None:
            print(f"Front of the queue: {front}")  # Changed phrasing slightly
    elif choice == 4:
        print(f"Queue has {queue.size()} items.")  # More natural way to present size
    elif choice == 5:
        queue.display()
    elif choice == 6:
        print("Goodbye!")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 6.")
