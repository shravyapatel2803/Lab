def enter_data(x):
    y=1
    while y:
        print("Enter 1 to enter new data\nEnter 0 to exit")
        i = int(input())
        match i:
            case 1:
                key = input("Enter the key: ")
                data = int(input("Enter the data: "))
                x[key]=data
            case 0:
                y=0
def print_data(x):
    y=1
    while y:
        print("Enter 1 for print the data of a particular key\nEnter 0 to exit")
        i = int(input())
        match i:
            case 1:
                key = input("Enter the key:- ")
                if key in x.keys():
                    print("value=",x[key])
                else :
                    print("Key is not found")
            case 0:
                y=0
                print("Thanks")
x={}
enter_data(x)
# y = "shravya"
# if y in x.keys():
#     print("value= ",x[y])
print_data(x)
# print(x)