def func(filename):
    try:
        file = open(filename, 'r')
    except FileNotFoundError:
        print("File error")
        return -1

    temp_sum = 0
    sum_max = None

    for line in file:
        for word in line.split():
            x = float(word)

            if sum_max is None:
                sum_max = x

            temp_sum += x

            if temp_sum > sum_max:
                sum_max = temp_sum

            if temp_sum <= 0:
                temp_sum = 0
    if (sum_max is None):
        print("File is empty")
        return -2
    file.close()
    return sum_max
    

print(func("f.txt"))
input("Press Enter to exit")
