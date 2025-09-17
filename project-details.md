# Overview:
Students will create a program in either C++ or Python that encrypts and decrypts text files using a self-designed algorithm. The project will involve reading text files as input, applying the encryption process, and generating an encrypted output file. Additionally, students will design a decryption mechanism that can reverse the encryption and return the original text.


# Project Components:
1. Custom Algorithm Design:

* Students must develop their own encryption algorithm, ensuring the process involves a reversible transformation.
* The algorithm should provide a basic level of security but does not need to be industry-standard.
* Consider techniques like substitution, shifting, transposition, or any other combination of cryptographic methods.
* Lengthy decision trees involving purely comparative if-else statements is prohibited.
```(i.e. if x == 'A'; if x == 'B'; if x == 'C')```

2. Input and Output:
* The program should accept a text file as input.
* After encryption, the program should create a new file that stores the encrypted message.
* The decryption component should take the encrypted file as input and produce a file with the original message.


3. User Interaction:
* The program should provide a simple menu interface for users to choose between encryption and decryption.
* Include error handling for common scenarios (e.g., missing input files, invalid text formats).

4. Implementation Guidelines:
* Language: Students can choose between C++ or Python.
* File Handling: The program should handle file I/O operations for reading and writing both plain and encrypted text.
* Efficiency Considerations: Students should aim for efficiency in the algorithm and avoid unnecessary computations.
* Security: While the algorithm doesn't need to be complex, it should demonstrate a solid understanding of basic encryption principles.

5. Documentation:
* A clear explanation of how the algorithm works.
* Steps to run the program, including any libraries required (if using Python, students must include necessary imports).
* A user guide for someone unfamiliar with encryption to use the program.

# Deliverables:
1. Source code in either C++ or Python. It will be compiled locally in a VM for grading.
2. An encrypted sample file using a provided plain text file.
3. The decrypted output proving the decryption process works.
4. A brief write-up (1-2 pages) explaining the encryption algorithm and the program.
5. A detailed instruction guide on how to operate the program. If the instructor cannot understand how to run the program, a grade cannot be accurately provided.

# Bonus Challenge:
For additional points, students can:

Implement a more complex algorithm that uses key-based encryption, where a user provides a key to encrypt or decrypt.
Introduce a graphical interface to allow file selection.
NOTE: bonus points are only eligible for programs at the discretion of the instructor. Programs that fail to function may not be eligible for bonus points.

To better assist students in understanding a basic structure, see the following examples that uses the Caesar cipher.
NOTE: You will be implementing your own algorithm. ANY inclusion, no matter its significance, of pre-existing code such as ciphers and algorithms will warrant a 0 on the assignment and a referral for academic dishonesty.