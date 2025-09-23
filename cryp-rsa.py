# Set up prime numbers:
p = 11
q = 13

# Step 2: Calculate key values
# Private Key: (n, d)
# Public Key: (n, e)

# Calculate n
n = p*q		# 143

# Calculate phi
phi = (p-1)*(q-1)	# 120

# Calculate e
e = 17		# so long as coprime with phi

# Calculate d
d = 113



# Encryption: c = m**e % n
# Decryption: m = c**d % n

plaintext = 'H'
ascii_text = ord(plaintext)
print(f"The ASCII value of {plaintext} is {ascii_text}")

cipher_text = ((ascii_text**e) % n)
print(f"Ciphertext is {cipher_text}")

decrypt_text = ((cipher_text**d) % n)
print(f"Decrypted text is {decrypt_text}")
