#include <iostream>
#include <cmath>
#include <concepts> // C++20 for concepts
using namespace std;
// Concept to ensure only numeric types are allowed
template <typename T>
concept Numeric = is_arithmetic_v<T>;

// Scientific Calculator Template Class
template <Numeric T>
class ScientificCalculator {
public:
    // Constructor
    ScientificCalculator() {}

    // Basic Arithmetic Operations
    T add(T a, T b) { return a + b; }
    T subtract(T a, T b) { return a - b; }
    T multiply(T a, T b) { return a * b; }
    T divide(T a, T b) {
        if (b == 0) throw invalid_argument("Division by zero!");
        return a / b;
    }

    // Trigonometric Operations
    T sin_value(T angle) { return sin(angle); }
    T cos_value(T angle) { return cos(angle); }
    T tan_value(T angle) { return tan(angle); }

    // Power and Root
    T power(T base, T exponent) { return pow(base, exponent); }
    T root(T value, T degree) {
        if (degree == 0) throw invalid_argument("Root degree cannot be zero!");
        return pow(value, 1 / degree);
    }

    // Logarithmic Operations
    T log_value(T value) {
        if (value <= 0) throw invalid_argument("Logarithm of non-positive numbers is undefined!");
        return log(value);
    }

    T exp_value(T exponent) { return exp(exponent); }

    // Fraction
    T fraction(T value) {
        if (value == 0) throw invalid_argument("Fraction of zero is undefined!");
        return 1 / value;
    }
};

// Display Menu
void displayMenu() {
    cout << "\n=== Scientific Calculator Menu ===\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Sine (in radians)\n";
    cout << "6. Cosine (in radians)\n";
    cout << "7. Tangent (in radians)\n";
    cout << "8. Power\n";
    cout << "9. Root\n";
    cout << "10. Logarithm (ln)\n";
    cout << "11. Exponential (e^x)\n";
    cout << "12. Fraction (1/x)\n";
    cout << "0. Exit\n";
    cout << "===================================\n";
    cout << "Enter your choice: ";
}

// Main function to interact with the user
int main() {
    ScientificCalculator<double> calc;
    int choice;
    double num1, num2;

    do {
        displayMenu();
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.add(num1, num2) << endl;
                    break;

                case 2:
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.subtract(num1, num2) << endl;
                    break;

                case 3:
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.multiply(num1, num2) << endl;
                    break;

                case 4:
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.divide(num1, num2) << endl;
                    break;

                case 5:
                    cout << "Enter angle in radians: ";
                    cin >> num1;
                    cout << "Result: " << calc.sin_value(num1) << endl;
                    break;

                case 6:
                    cout << "Enter angle in radians: ";
                    cin >> num1;
                    cout << "Result: " << calc.cos_value(num1) << endl;
                    break;

                case 7:
                    cout << "Enter angle in radians: ";
                    cin >> num1;
                    cout << "Result: " << calc.tan_value(num1) << endl;
                    break;

                case 8:
                    cout << "Enter base and exponent: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.power(num1, num2) << endl;
                    break;

                case 9:
                    cout << "Enter number and root degree: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.root(num1, num2) << endl;
                    break;

                case 10:
                    cout << "Enter a number: ";
                    cin >> num1;
                    cout << "Result: " << calc.log_value(num1) << endl;
                    break;

                case 11:
                    cout << "Enter exponent: ";
                    cin >> num1;
                    cout << "Result: " << calc.exp_value(num1) << endl;
                    break;

                case 12:
                    cout << "Enter a number: ";
                    cin >> num1;
                    cout << "Result: " << calc.fraction(num1) << endl;
                    break;

                case 0:
                    cout << "Exiting the calculator. Goodbye!" << endl;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const std::exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != 0);

    return 0;
}
