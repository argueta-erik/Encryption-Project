p = 67
q = 87
n = 5829
tot = 5676
m = 79
e = 3937
c = 1237
d = 3277


plaintext = 'H'
ascii_text = ord(plaintext)
print(f"The ASCII value of {plaintext} is {ascii_text}")

cipher_text = ((ascii_text**e) % n)
print(f"Ciphertext is {cipher_text}")

decrypt_text = ((cipher_text**d) % n)
print(f"Decrypted text is {decrypt_text}")
