def input_list():
    num = []
    while True:
        input_data = input()
        if input_data == "":
            break
        else:
            num.append(int(input_data))
    return num
num_list = input_list()
num_list.sort()
print(num_list[1])