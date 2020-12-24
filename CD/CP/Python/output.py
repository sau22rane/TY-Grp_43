def gcd (x, y) :
        if ((y) == 0):
                return x
        return gcd(y, x % y)

def main () :
        a = 2
        b = 8
        a = gcd(a, b)
        print(a)
        return 0

if __name__ == '__main__':
        main()