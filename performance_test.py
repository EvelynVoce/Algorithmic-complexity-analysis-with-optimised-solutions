from matplotlib import pyplot as plt

b = [20, 50, 10, 200, 500, 1000, 2000, 5000, 10000, 20_000, 50_000, 100_000, 200_000, 500_000,
     1_000_000, 2_000_000, 3_000_000]


# def solution1():
#     y = [0, 0, 1, 2, 5, 11, 22, 55, 118, 260, 625, 1212, 2420, 6006, 12365, 25023, 38706]
#
#     plt.title("The relationship between run-time and the number of bricks (Solution 1)")
#     plt.xlabel("Number of bricks")
#     plt.ylabel("Run-time (milliseconds)")
#     plt.plot(b, y, color='blue')
#     # plt.yscale('log')
#     plt.show()
#
#
# def solution2():
#     y = [0, 0, 1, 2, 7, 13, 26, 82, 165, 315, 805, 1644, 3466, 8672, 18173, 37592, 58517]
#
#     plt.title("The relationship between run-time and the number of bricks (solution 2)")
#     plt.xlabel("Number of bricks")
#     plt.ylabel("Run-time (milliseconds)")
#     plt.plot(b, y, color='blue')
#     # plt.yscale('log')
#     plt.show()


def combined():
    y1 = [0, 0, 1, 2, 5, 11, 22, 55, 118, 260, 625, 1212, 2420, 6006, 12365, 25023, 38706]
    y2 = [0, 0, 1, 2, 7, 13, 26, 82, 165, 315, 805, 1644, 3466, 8672, 18173, 37592, 58517]
    y3 = [0, 3, 3, 6, 20, 40, 95, 296, 728, 1443, 4080, 9214, 20749, 60128, 132165, 293921, 484170]

    plt.title("The relationship between run-time and the number of bricks")
    plt.xlabel("Number of bricks")
    plt.ylabel("Run-time (milliseconds)")
    plt.plot(b, y1, color='red', label='Solution A')
    plt.plot(b, y2, color='blue', label='Solution B')
    plt.plot(b, y3, color='green', label='Royal Mathematicians Algorithm')

    plt.legend()
    # plt.xscale('log')
    plt.show()
    print("done")


if __name__ == '__main__':
    # solution1()
    # solution2()
    combined()
