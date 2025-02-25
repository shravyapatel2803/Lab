
class password_manager:
    def __init__(self):
        self.old_password=[]
    def get_Password(self):
        if  self.old_password == []:
            print("Please add password first")
            return None
        return self.old_password[-1]
    def set_Password(self,password):
        if password in self.old_password:
            return "Password is already present"
        self.old_password.append(password)
        return "Password has been set"
    def is_correct(self, password_attempt):
        current_password = self.get_Password()
        if current_password is None:
            return False
        return password_attempt == current_password
s = password_manager()
while True:
    print("Enter '1' to get password\nEnter '2' to set password\nEnter '3' to check password\nEnter '4' to exit")
    y = int(input("Enter your choice:- "))
    match y:
        case 1 : print(s.get_Password())
        case 2 : 
            sh = input("Enter your new password:- ")
            print(s.set_Password(sh))
        case 3 :
            password_attempt = input("Enter your password to check:- ")
            if s.is_correct(password_attempt):
                print("Password is correct")
            else:
                print("Password is incorrect")
        case 4 :
            print("Exiting.....")
            break
        case default :
            print("Invalid choice try again")
