p = 67
q = 87
n = 5829 # (67 - 1) * (87 - 1)
e = 3937
L = 2838
d = 439

plaintext = 'H'
ascii_text = ord(plaintext)
print(f"The ASCII value of {plaintext} is {ascii_text}")

# c = ENCRYPT(m) = m**e mod n
encrypted = (ascii_text**3937) % 5829

print(f"The ciphertext is now {encrypted}")

# m = DECRYPT(c) = c**d mod n
decryption = (encrypted**439) % 5829

print(f"The decrypted ascii value is {decryption}")
