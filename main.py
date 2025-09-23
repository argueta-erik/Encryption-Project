p = 67
q = 47
n = p*q	# 3149
phi = (p-1)*(q-1) # 3036
e = 17
d = 893

plaintext = 'H'
ascii_text = ord(plaintext)
print(f"The ASCII value of {plaintext} is {ascii_text}")

cipher_text = ((ascii_text**e) % n)
print(f"Ciphertext is {cipher_text}")

decrypt_text = ((cipher_text**d) % n)
print(f"Decrypted text is {decrypt_text}")
