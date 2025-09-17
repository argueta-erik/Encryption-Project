# Simply, trying to read a file within the folder
try:
    with open("plaintext.txt", "r") as file:
        content = file.read()
        print(content)
except FileNotFoundError:
    print("File not found")