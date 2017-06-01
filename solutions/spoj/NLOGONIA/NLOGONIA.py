'''
Yuri Niitsuma
2011039023
http://br.spoj.com/problems/NLOGONIA/
NLOGONIA
'''

def check_axis(x, y):
    if x == 0 or y == 0:
        return 'divisa'
    elif x > 0 and y > 0:
        return 'NE'
    elif x < 0 and y > 0:
        return 'NO'
    elif x < 0  and y < 0:
        return 'SO'
    else:
        return 'SE'


def main():
    while True:
        k = int(input())
        if k == 0:
            break

        n, m = list(map(int, input().split(' ')))[:2]
        while k > 0:
            x, y = list(map(int, input().split(' ')))[:2]
            print(check_axis(x - n, y - m))
            k-=1

if __name__ == '__main__':
    main()
