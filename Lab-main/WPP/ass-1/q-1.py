# Create the following lists using a for loop.
# (a) A list consisting of the integers 0 through 49
x=[i for i in range(50)]
print(x)
#  Create the following lists using a for loop.
# (b) A list containing the squares of the integers 1 through 50.
y=[i*i for i in range(1,51)]
print(y)
# Create the following lists using a for loop.
# (c) The list ['a','bb','ccc','dddd', ...] that ends with 26 copies of the letter z

z=[chr(i)*(i-96) for i in range(97, ord('z')+1)]
print(z)