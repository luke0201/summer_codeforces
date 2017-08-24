import sys
import heapq

class Seats:
    def __init__(self, n):
        self.seat_que = [-4] * n + [-2, -2] * n

    def push(self, x):
        heapq.heappush(self.seat_que, -x)

    def pop(self):
        seat = -heapq.heappop(self.seat_que)
        return seat

if __name__ == '__main__':
    n, m = (int(x) for x in input().split())
    soldiers = sorted([int(x) for x in input().split()], reverse=True)

    seats = Seats(n)
    for soldier in soldiers:
        while soldier > 0:
            try:
                seat = seats.pop()
                if seat > soldier:
                    seats.push(seat - soldier - 1)
                soldier -= seat
            except IndexError:
                print('NO')
                sys.exit()
    print('YES')