str = input()
smiley, frowny = False, False
for i in range(0, len(str)-1):
    if str[i] == ":":
        if str[i + 1] == ")":
            smiley = True
        if str[i + 1] == "(":
            frowny = True
if smiley:
    if frowny:
        print("double agent")
    else:
        print("alive")
else:
    if frowny:
        print("undead")
    else:
        print("machine")
