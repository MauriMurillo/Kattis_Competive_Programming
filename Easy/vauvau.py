input_data = input()
dogs = input_data.split()
input_data = input()
people = input_data.split()

dog1 = int(dogs[0]) + int(dogs[1])
dog2 = int(dogs[2]) + int(dogs[3])

for peop in people:
    peop1 = int(peop) % dog1
    peop2 = int(peop) % dog2
    if peop1 > int(dogs[0]) or peop1 == 0:
        if peop2 > int(dogs[2]) or peop2 == 0:
            print("none")
        else:
            print("one")
    else:
        if peop2 > int(dogs[2]) or peop2 == 0:
            print("one")
        else:
            print("both")
