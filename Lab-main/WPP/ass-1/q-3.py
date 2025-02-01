condition = 1
while condition:
    print("Enter 1 to convert feet to inches\nEnter 2 to convert feet to yards\nEnter 3 to convert feet to miles\nEnter 4 to convert feet to milimeter\nEnter 5 to convert feet to centimeter\nEnter 6 to convert feet to meter\nEnter 7 to convert feet to kilometer\nEnter 0 to exit")
    i = int(input())
    match i:
        case 0:
            condition=0
            print("you are exited")
        case 1:
            feet = float(input("Enter your data:-"))
            inches = feet*12
            print(f"{feet}feet={inches}inches")
        case 2:
            feet = float(input("Enter your data:-"))
            yards = feet*(1/3)
            print(f"{feet}feet={yards}yards")
        case 3:
            feet = float(input("Enter your data:-"))
            miles = feet*0.000189394
            print(f"{feet}feet={miles}miles")
        case 4:
            feet = float(input("Enter your data:-"))
            mm = feet*304.8
            print(f"{feet}feet={mm}mm")
        case 5:
            feet = float(input("Enter your data:-"))
            cm = feet*30.48
            print(f"{feet}feet={cm}cm")
        case 6:
            feet = float(input("Enter your data:-"))
            m = feet*0.3048
            print(f"{feet}feet={m}m")
        case 7:
            feet = float(input("Enter your data:-"))
            km = feet*0.0003048
            print(f"{feet}feet={km}km")
        case default:
            print("invalid input")