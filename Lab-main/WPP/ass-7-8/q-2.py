class Queue:
    def __init__(self):
        self.queue = []  # Use a list to represent the queue

    def is_empty(self):
        return len(self.queue) == 0

    def enqueue(self, item):
        self.queue.append(item)  # Add to the rear of the queue
        print(f"Enqueued: {item}")

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty. Cannot dequeue.")
            return None
        else:
            item = self.queue.pop(0)  # Remove from the front
            print(f"Dequeued: {item}")
            return item

    def peek(self): #returns the front element without removing it
        if self.is_empty():
            print("Queue is empty.")
            return None
        else:
            return self.queue[0]

    def size(self):
        return len(self.queue)

    def display(self):
        if self.is_empty():
            print("Queue is empty.")
        else:
            print("Queue:", self.queue)


def display_menu():
    print("\nQueue Operations:")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Peek")
    print("4. Size")
    print("5. Display")
    print("6. Exit")


def get_int_input(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter an integer.")


def get_data_input(prompt):
    return input(prompt)


queue = Queue()

while True:
    display_menu()
    choice = get_int_input("Enter your choice: ")

    if choice == 1:
        item = get_data_input("Enter item to enqueue: ")
        queue.enqueue(item)
    elif choice == 2:
        queue.dequeue()
    elif choice == 3:
        front_element = queue.peek()
        if front_element is not None:
            print(f"Front element: {front_element}")
    elif choice == 4:
        print("Queue size:", queue.size())
    elif choice == 5:
        queue.display()
    elif choice == 6:
        print("Exiting...")
        break
    else:
        print("Invalid choice. Please try again.")