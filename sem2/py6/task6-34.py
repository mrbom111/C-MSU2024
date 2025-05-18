def count_last_local_minimum_length(filename):
    try:
        file = open(filename, 'r')
    except FileNotFoundError:
        print("Файл не найден.")
        return 0

    current_length = None
    last_minimum_length = 0
    previous = None

    for line in file:
        for word in line.split():
            number = float(word)

            if current_length is None:
                current_length = 1
                last_minimum_length = 1

            elif current_length > 0:
                if number > previous:
                    last_minimum_length = current_length
                    current_length = 0
                elif number < previous:
                    current_length = 1
                    last_minimum_length = 1
                elif number == previous:
                    current_length += 1
                    last_minimum_length = current_length

            elif current_length == 0 and number < previous:
                current_length = 1
                last_minimum_length = 1

            previous = number

    file.close()
    if previous is None:
        print("Файл пуст.")
    return last_minimum_length


filename = input("Введите имя файла: ")
result = count_last_local_minimum_length(filename)
if result > 0:
    print("Количество элементов в последнем локальном минимуме: %d" % result)
else:
    print("Не удалось найти локальный минимум.")
    
input("Press Enter to exit")
