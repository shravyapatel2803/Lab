class Converter:
    def __init__(self,data,type):
        feet = data
        match type:
            case "inches" :
                inches = data*12
                print(f"{data}feet = {inches}inches")
            case "yards":
                yards = feet*(1/3)
                print(f"{feet}feet = {yards}yards")
            case "miles":
                miles = feet*0.000189394
                print(f"{feet}feet = {miles}miles") 
            case "mm":
                mm = feet*304.8
                print(f"{feet}feet = {mm}mm")
            case "cm":
                cm = feet*30.48
                print(f"{feet}feet = {cm}cm")
            case "m":
                m = feet*0.3048
                print(f"{feet}feet = {m}m")
            case "km":
                km = feet*0.0003048
                print(f"{feet}feet = {km}km")
y = True
while y:
    print("Enter 'inches' to convert feet to inches\nEnter 'yards' to convert feet to yards\nEnter 'miles' to convert feet to miles\nEnter 'mm' to convert feet to milimeter\nEnter 'cm' to convert feet to centimeter\nEnter 'm' to convert feet to meter\nEnter 'km' to convert feet to kilometer\nEnter 'exit' to exit")
    condition = input().lower()
    if condition=="exit":
        print("You are exited")
        y = False
    else:
        data = int(input("Enter your data:- "))
        s = Converter(data,condition)