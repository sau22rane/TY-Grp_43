def gcd (x, y) :
        if ((y) == 0):
                return x
        return gcd(y, x % y)

def main () :
        a = 16
        b = 8
        i = 0
        a = gcd(a, b)
        while(i != 5):
                print(i)
                i = i + 1
        print(a)
        return 0

if __name__ == '__main__':
        main()