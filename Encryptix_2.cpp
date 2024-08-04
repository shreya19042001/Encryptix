#include <bits/stdc++.h>

using namespace std;

void displayMenu() {
    cout << "CALCULATOR\n";
    cout << "Select operation:\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Sine (sin)\n";
    cout << "6. Cosine (cos)\n";
    cout << "7. Tangent (tan)\n";
    cout << "8. Exponential (exp)\n";
    cout << "9. Logarithm (log)\n";
    cout << "10. Power (^)\n";
    cout << "11. Square Root (sqrt)\n";
    cout << "0. Exit\n";
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        cout << "Enter your choice (0 to exit): ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting the calculator. Goodbye!\n";
                break;
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 + num2;
                cout << "Result: " << result << "\n";
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 - num2;
                cout << "Result: " << result << "\n";
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 * num2;
                cout << "Result: " << result << "\n";
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    result = num1 / num2;
                    if (result == numeric_limits<double>::infinity()) {
                        cout << "Result: Infinity\n";
                    } else {
                        cout << "Result: " << result << "\n";
                    }
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            case 5:
                cout << "Enter a number: ";
                cin >> num1;
                result = sin(num1);
                cout << "Result: " << result << "\n";
                break;
            case 6:
                cout << "Enter a number: ";
                cin >> num1;
                result = cos(num1);
                cout << "Result: " << result << "\n";
                break;
            case 7:
                cout << "Enter a number: ";
                cin >> num1;
                result = tan(num1);
                if (result == numeric_limits<double>::infinity()) {
                    cout << "Result: Infinity\n";
                } else {
                    cout << "Result: " << result << "\n";
                }
                break;
            case 8:
                cout << "Enter a number: ";
                cin >> num1;
                result = exp(num1);
                if (result == numeric_limits<double>::infinity()) {
                    cout << "Result: Infinity\n";
                } else {
                    cout << "Result: " << result << "\n";
                }
                break;
            case 9:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 > 0) {
                    result = log(num1);
                    cout << "Result: " << result << "\n";
                } else {
                    cout << "Error: Logarithm of non-positive numbers is not defined.\n";
                }
                break;
            case 10:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                result = pow(num1, num2);
                if (result == numeric_limits<double>::infinity()) {
                    cout << "Result: Infinity\n";
                } else {
                    cout << "Result: " << result << "\n";
                }
                break;
            case 11:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 >= 0) {
                    result = sqrt(num1);
                    cout << "Result: " << result << "\n";
                } else {
                    cout << "Error: Square root of negative numbers is not defined.\n";
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << "\n";
    } while (choice != 0);

    return 0;
}
