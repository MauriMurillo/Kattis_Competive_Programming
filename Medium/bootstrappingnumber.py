number = float(input())
left_limit = 0
right_limit = 10
count = 100000
while count:
    mid = (left_limit + right_limit)/2
    ans = mid**mid
    if ans < number:
        left_limit = mid
    elif ans > number:
        right_limit = mid
    else:
        break
    count-=1
print(mid)
