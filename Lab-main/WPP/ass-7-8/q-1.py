class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def display(self):
        if self.is_empty():
            print("Linked List is empty.")
            return

        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
            return

        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def insert_at_position(self, data, position):
        if position <= 0:
            print("Invalid position. Position should be greater than 0.")
            return

        if position == 1:
            self.insert_at_beginning(data)
            return

        new_node = Node(data)
        current = self.head
        count = 1

        while current and count < position - 1:
            current = current.next
            count += 1

        if not current:
            print("Position out of range.")
            return

        new_node.next = current.next
        current.next = new_node

    def delete_at_beginning(self):
        if self.is_empty():
            print("Linked list is empty. Cannot delete.")
            return

        self.head = self.head.next

    def delete_at_end(self):
        if self.is_empty():
            print("Linked list is empty. Cannot delete.")
            return

        if self.head.next is None:  # Only one node
            self.head = None
            return

        current = self.head
        while current.next.next:  # Traverse to the second-to-last node
            current = current.next
        current.next = None

    def delete_at_position(self, position):
        if self.is_empty():
            print("Linked list is empty. Cannot delete.")
            return

        if position <= 0:
            print("Invalid position. Position should be greater than 0.")
            return

        if position == 1:
            self.delete_at_beginning()
            return

        current = self.head
        count = 1

        while current and count < position - 1:
            current = current.next
            count += 1

        if not current or not current.next:
            print("Position out of range.")
            return

        current.next = current.next.next


def display_menu():
    print("\nLinked List Operations:")
    print("1. Display Linked List")
    print("2. Insert at Beginning")
    print("3. Insert at End")
    print("4. Insert at Position")
    print("5. Delete at Beginning")
    print("6. Delete at End")
    print("7. Delete at Position")
    print("8. Exit")

def get_int_input(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter an integer.")

def get_data_input(prompt):
    return input(prompt)


linked_list = LinkedList()

while True:
    display_menu()
    choice = get_int_input("Enter your choice: ")

    if choice == 1:
        linked_list.display()
    elif choice == 2:
        data = get_data_input("Enter data to insert at beginning: ")
        linked_list.insert_at_beginning(data)
    elif choice == 3:
        data = get_data_input("Enter data to insert at end: ")
        linked_list.insert_at_end(data)
    elif choice == 4:
        data = get_data_input("Enter data to insert: ")
        position = get_int_input("Enter position to insert at: ")
        linked_list.insert_at_position(data, position)
    elif choice == 5:
        linked_list.delete_at_beginning()
    elif choice == 6:
        linked_list.delete_at_end()
    elif choice == 7:
        position = get_int_input("Enter position to delete at: ")
        linked_list.delete_at_position(position)
    elif choice == 8:
        print("Exiting...")
        break
    else:
        print("Invalid choice. Please try again.")