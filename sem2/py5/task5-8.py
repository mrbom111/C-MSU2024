def compare_with_first(filename):
    file = open(filename, 'r')

    first = None
    greater = 0
    less = 0

    for line in file:
        parts = line.split()
        for word in parts:
            number = float(word)  # Преобразуем слово в число типа float (double)
            
            if first is None:
                first = number
            else:
                if number > first:
                    greater += 1
                elif number < first:
                    less += 1

    file.close()

    if first is None:
        print("the file is empty.")
    elif greater > less:
        print("There are more elements greater than the first one.")
    elif less > greater:
        print("There are more elements less than the first one.")
    else:
        print("There are the same amount of elements greater and less than the first one.")


filename = input("Enter the filename: ")

compare_with_first(filename)
input("Press Enter to exit")
