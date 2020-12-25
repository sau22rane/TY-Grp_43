def gcd (x, y) :
        if ((y) == 0):
                return x
        return gcd(y, x % y)

def main () :
        a = 16
        b = 8
        b = gcd(a, b)
        while (b != 2):
                print(b)
                b = b - 1

        print(a)
        return 0

if __name__ == '__main__':
        main()