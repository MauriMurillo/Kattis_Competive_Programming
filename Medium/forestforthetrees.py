import math

xb, yb = input().split(" ")
xb, yb = int(xb), int(yb)
rx1, ry1, rx2, ry2 = input().split(" ")
rx1, ry1, rx2, ry2 = int(rx1), int(ry1), int(rx2), int(ry2)

every_x = xb // math.gcd(xb, (yb % xb))
every_y = (yb * every_x) // xb

first_tree_x = every_x
first_tree_y = every_y

last_tree_x = xb - every_x
last_tree_y = yb - every_y

first_tree_in = False
last_tree_in = False
if (first_tree_x == xb and first_tree_y == yb) or (
    last_tree_x == 0 and last_tree_y == 0
):
    print("Yes")
else:
    if (first_tree_x <= rx2) and (first_tree_x >= rx1):
        if (first_tree_y <= ry2) and (first_tree_y >= ry1):
            first_tree_in = True

    if (last_tree_x <= rx2) and (last_tree_x >= rx1):
        if (last_tree_y <= ry2) and (last_tree_y >= ry1):
            last_tree_in = True

    if first_tree_in and last_tree_in:
        print("Yes")
    else:
        print("No")
        # Find the first tree in our way, two cases, before rectangle or after
        if first_tree_in:
            # must be after the rectangle
            ith = min((rx2 // every_x), (ry2 // every_y)) + 1
            print(ith * every_x, ith * every_y)
        else:
            # must be the first tree
            print(first_tree_x, first_tree_y)
