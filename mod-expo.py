# Fact 2:
# Given p and q, it's easy to find their product, n = pq

p = 67
q = 87
n = p*q		# n = 5829
tot = (p-1)*(q-1)


# Let m and c be integers between 0 and n-1
# Let e be an odd integer between 3 and n-1 that is relatively prime to p-1 and q-1
m = 79
e = 3937

# Given n, m, and e, it's easy to compute c = m^e mod n
c = m**e % n




# Given only n, e, c, and the prime factors p and q, it's easy to recover the
# value m such that c = m**e mod n.

d = 3277

print(f"p={p}, q={q}, n={n}, tot={tot}, m={m}, e={e}, c={c}, d={d}")
