def func(filename):
    try:
        file = open(filename, 'r')
    except FileNotFoundError:
        print("File error")
        return -1

    sum_ = 0
    sum_max = None

    for line in file:
        for word in line.split():
            x = float(word)

            if sum_max is None:
                sum_max = x

            sum_ += x

            if sum_ > sum_max:
                sum_max = sum_

            if sum_ <= 0:
                sum_ = 0
    if (sum_max is None):
        print("File is empty")
        return -2
    file.close()
    return sum_max
    

print(func("f.txt"))
input("Press Enter to exit")
