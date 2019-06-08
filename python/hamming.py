import os


def get_k_bits(m):
    size = len(m)
    
    k = []
    k.append(int(m[7]) + int(m[6]) + int(m[4]) + int(m[3]) + int(m[1]))
    k.append(int(m[7]) + int(m[5]) + int(m[4]) + int(m[2]) + int(m[1]))
    k.append(int(m[6]) + int(m[5]) + int(m[4]) + int(m[0]))
    k.append(int(m[3]) + int(m[2]) + int(m[1]) + int(m[0]))

    for i in range(4):
        if k[i] % 2 == 0:
            k[i] = 0
        else:
            k[i] = 1
            
    return  k[::-1]

def create_error(m, position):
    new_m = ""
    position -= 1
    for i in range(len(m)):
        if i != position:
            new_m += m[i]
        else:
            new_m += "1" if m[position] == "0" else "0"
    print(new_m)
    return new_m


def get_wrong_bit_position(right_m, wrong_m):
    right_k = get_k_bits(right_m)
    wrong_k = get_k_bits(wrong_m)
    print(right_k)
    print(wrong_k)
    print(wrong_m)

    right_k_value = 0
    wrong_k_value = 0
    for i in range(3, 0, -1):
        right_k_value += right_k[i]*(2**i)
        wrong_k_value += wrong_k[i]*(2**i)
    
    print(right_k_value)
    print(wrong_k_value)
    return right_k_value - wrong_k_value

def get_wrong_bit(position):
    bits = [8, 7, 6, 5, 4, 3, 2, 1]
    return "m" + str(bits[position - 1])


if __name__ == "__main__":
    os.system("clear")
    m = input("enter an 8-bits M code: ")
    error = int(input("enter the error position: "))
    wrong_bit_position = get_wrong_bit_position(m, create_error(m, error))
    print("position is ", wrong_bit_position)
    print("wrong bit is ", get_wrong_bit(wrong_bit_position))

    # m = 00111001
    # m'= 00111101