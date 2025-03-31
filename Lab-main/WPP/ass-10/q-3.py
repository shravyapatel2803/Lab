import numpy as np
def magic_square(n):
    if n % 2 == 1:
        magic = np.zeros((n, n), dtype=int)
        i, j = 0, n // 2
        for num in range(1, n * n + 1):
            magic[i, j] = num
            i_new, j_new = (i - 1) % n, (j + 1) % n
            if magic[i_new, j_new]:
                i += 1
            else:
                i, j = i_new, j_new
    else:
        magic = np.zeros((n, n), dtype=int)
        p = np.arange(1, n * n + 1).reshape(n, n)
        mask = np.array([[1, 0] * (n // 2), [0, 1] * (n // 2)] * (n // 2))
        magic[mask == 1] = p[mask == 1]
        magic[mask == 0] = p[::-1, ::-1][mask == 0]
    return magic

for n in range(4, 9):
    print(f"Magic Square for N={n}:")
    print(magic_square(n))
    print()
