import re

def custom_tokenizer(text):
    pattern = r"""
        (?:\d{1,3}(?:,\d{3})*(?:\.\d+)?) |  # Numbers with commas or decimals
        (?:\b\d{2}/\d{2}/\d{4}\b) |        # Dates like 12/05/2023
        (?:https?://[^\s]+) |             # URLs
        (?:@[a-zA-Z0-9_]+) |              # Social media handles
        (?:[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}) | # Emails
        (?:\w+) |                       # Words
        (?:[.,!?;:'"-])                  # Punctuations
    """
    return re.findall(pattern, text, re.VERBOSE)


def get_text_input():
    while True:
        text = input("Enter the text to tokenize: ")
        if text.strip(): 
            return text
        else:
            print("Text cannot be empty. Please enter some text.")


while True:
    print("\nCustom Tokenizer:")
    print("1. Tokenize Text")
    print("2. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        text = get_text_input()
        tokens = custom_tokenizer(text)
        print("\nTokens:")
        for token in tokens:
            print(token)

    elif choice == '2':
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please try again.")