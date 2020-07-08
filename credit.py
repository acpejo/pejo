from cs50 import get_int
def main():
    n = get_int("Number: ")
    if flag(n) == True:
        if (n - n % (10 ** 12)) / (10 ** 12) == 4 or (n - n % (10 ** 15)) / (10 ** 15) == 4:
            print("VISA")

        elif (n - n % (10 ** 13)) / (10 ** 13) == 34 or (n - n % (10 ** 13)) / (10 ** 13) == 37:
            print("AMEX")

        elif (n - n % (10 ** 14)) / (10 ** 14) == 51 or (n - n % (10 ** 14)) / (10 ** 14) == 52 or (n - n % (10 ** 14)) / (10 ** 14) == 53 or (n - n % (10 ** 14)) / (10 ** 14) == 54 or (n - n % (10 ** 14)) / (10 ** 14) == 55:
            print("MASTERCARD")

        else:
            print("INVALID")

    else:
        print("INVALID")

def flag(number):
    even = odd = tmp = 0
    for x in range(len(str(number))):
        if x % 2 == 0:
            odd += (number % (10 ** (x + 1)) - number % (10 ** x)) / (10 ** x)

        else:
            tmp = 2 * (number % (10 ** (x + 1)) - number % (10 ** x)) / (10 ** x)
            if tmp >= 10:
                even += tmp % 10 + (tmp - tmp % 10) / 10
            else:
                even += tmp

    if (even + odd) % 10 == 0:
        return True
    else:
        return False

main()