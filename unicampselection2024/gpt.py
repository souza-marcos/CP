def extended_gcd(a: int, b: int) -> tuple[int,int,int]:
    """
    Return (x, y, d) such that x*a + y*b = d = gcd(a, b).
    """
    if b == 0:
        return (1, 0, a)
    x1, y1, d = extended_gcd(b, a % b)
    # x1·b + y1·(a mod b) = d
    # but a mod b = a - (a//b)*b
    return (y1, x1 - (a//b)*y1, d)

def extended_gcd_n(coffs: list[int]) -> tuple[list[int], int]:
    """
    Given a list of integers [a1, a2, ..., an],
    returns (coeffs, g) where
      coeffs = [x1, x2, ..., xn]
      g = gcd(a1,...,an)
    and sum(xi*ai) == g.
    """
    n = len(coffs)
    # start with g = a1 and coeffs = [1,0,0,...]
    g = coffs[0]
    vars = [1] + [0]*(n-1)

    for i in range(1, n):
        u, v, d = extended_gcd(g, coffs[i])
        # scale old coefficients by u
        for j in range(i):
            vars[j] *= u
        vars[i] = v
        g = d

    return vars, g

# Example:
a = [  10,   20,   15,  625]
coeffs, g = extended_gcd_n(a)
print("gcd =", g)            # gcd = 7
print("coeffs =", coeffs)    # e.g. [1, -1, 0, 0] gives 1*30 + (-1)*42 = -12?  – you'll see the true combo
print("check:", sum(c*ai for c,ai in zip(coeffs,a)))
