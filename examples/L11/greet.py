def greetListPrint(L):
    for name in L:
        print("Hello "+name+"!")

def greetList(L):
    greetings = []
    for name in L:
        greetings.append("Hello "+name+"!")
    return greetings
