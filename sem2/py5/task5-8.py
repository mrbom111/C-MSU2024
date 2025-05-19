def compare_with_first(filename):
    file = open(filename, 'r')

    first = None
    numbers = []

    for line in file:
        parts = line.split()
        for word in parts:
            number = float(word)  # Преобразуем слово в число типа float (double)
            numbers.append(number)

    file.close()

    if not numbers:
        print("the file is empty.")
        return

    first = numbers[0]
    counter = sum((1 if x > first else -1 if x < first else 0) for x in numbers[1:])

    if counter > 0: 
        print("There are more elements greater than the first one.")
    elif counter < 0: 
        print("There are more elements less than the first one.")
    else:
        print("There are the same amount of elements greater and less than the first one.")


filename = input("Enter the filename: ")

compare_with_first(filename)
input("Press Enter to exit")
