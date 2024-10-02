#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to convert a number from one base to another
string convertNumber(string number, int fromBase, int toBase) {
    // Handle invalid input bases
    if (fromBase < 2 || fromBase > 36 || toBase < 2 || toBase > 36) {
        cout << "Invalid input bases. Please enter bases between 2 and 36." << endl;
        return "";
    }

    // Convert the number from the given base to decimal
    int decimalValue = 0;
    for (int i = 0; i < number.length(); i++) {
        int digitValue;
        if (isdigit(number[i])) {
            digitValue = number[i] - '0';
        } else {
            digitValue = number[i] - 'A' + 10;
        }
        decimalValue += digitValue * pow(fromBase, number.length() - i - 1);
    }

    // Convert the decimal value to the desired base
    string result = "";
    while (decimalValue > 0) {
        int remainder = decimalValue % toBase;
        if (remainder < 10) {
            result = static_cast<char>(remainder + '0') + result;
        } else {
            result = static_cast<char>(remainder - 10 + 'A') + result;
        }
        decimalValue /= toBase;
    }

    return result;
}

int main() {
    while (true) {
        cout << "Enter the number to convert: ";
        string number;
        cin >> number;

        cout << "Enter the base of the input number: ";
        int fromBase;
        cin >> fromBase;

        cout << "Enter the desired base for the output: ";
        int toBase;
        cin >> toBase;

        string convertedNumber = convertNumber(number, fromBase, toBase);
        if (!convertedNumber.empty()) {
            cout << "The converted number is: " << convertedNumber << endl;
        }

        cout << "Do you want to convert another number? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}
