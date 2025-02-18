import random
class Rock_paper_scissors:
    def __init__(self):
        y = int(input("Enter how many time you want to play the game:- "))
        i=1
        while(i<=y):
            s = input("Enter your choice:- ").lower()
            n = random.random()
            if(n<=1/3):
                if s=="rock":
                    print(f"You choose {s} and I choose rock")
                    print("Tie")
                    i += 1
                elif s=="paper":
                    print(f"You choose {s} and I choose rock")
                    print("I win")
                    i += 1
                else :
                    print(f"You choose {s} and I choose rock")
                    print("You win")
                    i += 1
            elif(n>1/3 and n<=2/3):
                if s=="rock":
                    print(f"You choose {s} and I choose paper")
                    print("I win")
                    i += 1
                elif s=="paper":
                    print(f"You choose {s} and I choose paper")
                    print("Tie")
                    i += 1
                else:
                    print(f"You choose {s} and I choose paper")
                    print("You win")
                    i += 1
            else:
                if s=="rock":
                    print(f"You choose {s} and I choose scissor")
                    print("You win")
                    i += 1
                elif s == "paper":
                    print(f"You choose {s} and I choose scissor")
                    print("I win")
                    i += 1
                else :
                    print(f"You choose {s} and I choose scissor")
                    print("Tie")
                    i += 1
s = Rock_paper_scissors()