#include <iostream>
#include <string>
#include <limits> // Include this to use numeric_limits

using namespace std;

class Complex {
protected:
    float real;
    float imag;

public:
    Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    void setReal(float r) { real = r; }
    void setImag(float i) { imag = i; }
    float getReal() const { return real; }
    float getImag() const { return imag; }

    Complex add(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex sub(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    void print() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " - " << -imag << "i" << endl;
        }
    }
};

// Function to safely read a float value
float safeInputFloat(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) { // Check if input is a float
            break;          // Input is valid, exit loop
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    return value;
}

int main() {
    cout << "Enter the first complex number:\n";
    float real1 = safeInputFloat("Real part: ");
    float imag1 = safeInputFloat("Imaginary part: ");
    Complex myComp1(real1, imag1);

    cout << "Enter the second complex number:\n";
    float real2 = safeInputFloat("Real part: ");
    float imag2 = safeInputFloat("Imaginary part: ");
    Complex myComp2(real2, imag2);

    Complex resultComp;

    cout << "First complex number: ";
    myComp1.print();
    cout << "Second complex number: ";
    myComp2.print();

    resultComp = myComp1.add(myComp2);
    cout << "Result of addition: ";
    resultComp.print();

    resultComp = myComp1.sub(myComp2);
    cout << "Result of subtraction: ";
    resultComp.print();

    return 0;
}
