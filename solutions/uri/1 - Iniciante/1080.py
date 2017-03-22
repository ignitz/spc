max_number = (0, None)

for i in range(0, 100):
    x = int(input())
    if x > max_number[0]:
        max_number = (x, i + 1)

print(max_number[0])
print(max_number[1])
