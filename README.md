Here's the fully formatted version:

markdown
Copy code
# Complex Number Calculator

This is a simple **Complex Number Calculator** written in C++. It demonstrates the use of Object-Oriented Programming (OOP) concepts by defining a `Complex` class and performing addition and subtraction on complex numbers.

## Features

- Accepts user input for real and imaginary parts of complex numbers.
- Supports addition and subtraction operations on complex numbers.
- Includes input validation to handle incorrect input and guide users to re-enter valid data.

## Getting Started

### Prerequisites

To run this code, you’ll need:

- A C++ compiler (e.g., `g++`, which is included in GCC)
- Basic knowledge of compiling and running C++ code

### Compilation

To compile the program, use the following command:

```bash
g++ -o complex_number_calc complex_number_calc.cpp
Usage
After compilation, run the program with:

bash
Copy code
./complex_number_calc
Program Flow
User Input:

The program prompts the user to enter the real and imaginary parts of two complex numbers.
If the user enters invalid input (like a non-numeric value), the program will display an error message and prompt the user to re-enter a valid number.
Operations:

The program performs addition and subtraction of the two complex numbers and displays the results.
Results are displayed in the format a + bi or a - bi, depending on the sign of the imaginary part.
Sample Output:

yaml
Copy code
Enter the first complex number:
Real part: 3.5
Imaginary part: -2.1
Enter the second complex number:
Real part: 1.2
Imaginary part: 4.3
First complex number: 3.5 - 2.1i
Second complex number: 1.2 + 4.3i
Result of addition: 4.7 + 2.2i
Result of subtraction: 2.3 - 6.4i
Code Overview
Complex Class:
Attributes: Stores the real and imaginary parts as float.
Methods:
add(const Complex& c): Adds the calling object with c and returns the result as a new Complex object.
sub(const Complex& c): Subtracts c from the calling object and returns the result.
print(): Prints the complex number in a formatted manner.
Input Validation:
A helper function safeInputFloat prompts the user and validates the input to ensure it’s a valid float. If invalid, it shows an error message and prompts the user to try again.
Contributing
Feel free to fork the repo and submit pull requests if you have improvements or bug fixes!
