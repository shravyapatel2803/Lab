import numpy as np

def justify_strings(arr, width=15):
    left_justified = np.char.ljust(arr, width, '_')
    right_justified = np.char.rjust(arr, width, '_')
    center_justified = np.char.center(arr, width, '_')
    return left_justified, right_justified, center_justified

# Take user input
n = int(input("Enter the number of test cases you want to check: "))
data_list = []  # Use a list first

for i in range(n):
    s = input("Enter data: ")
    data_list.append(s)
arr = np.array(data_list, dtype=str)
left, right, center = justify_strings(arr)

print("\nLeft Justified:")
print(left)

print("\nRight Justified:")
print(right)

print("\nCentered:")
print(center)

l,r,c = justify_strings(arr)
# print(f"{l};{r};{c}")
# print("Left Justified:")
# print(l)
# print("\nRight Justified:")
# print(r)
# print("\nCentered:")
# print(c)
print(arr)