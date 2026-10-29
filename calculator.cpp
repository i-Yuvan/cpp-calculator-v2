
#include <bits/stdc++.h>
using namespace std;

double getNumber(string message) {
    double number;

    while (true) {
        cout << message;

        if (cin >> number) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int getChoice() {
    int choice;

    while (true) {
        cout << "Enter your choice: ";

        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid choice! Enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool calculate(double a, double b, int choice, double &result) {
    switch (choice) {
        case 1:
            result = a + b;
            return true;

        case 2:
            result = a - b;
            return true;

        case 3:
            result = a * b;
            return true;

        case 4:
            if (b == 0) {
                cout << "Error: Cannot divide by zero.\n";
                return false;
            }
            result = a / b;
            return true;

        default:
            cout << "Invalid operation!\n";
            return false;
    }
}

void showHistory(const vector<string>& history) {
    cout << "\n===== CALCULATION HISTORY =====\n";

    if (history.empty()) {
        cout << "No calculations yet.\n";
    } else {
        for (int i = 0; i < static_cast<int>(history.size()); i++) {
            cout << i + 1 << ". " << history[i] << '\n';
        }
    }

    cout << "===============================\n";
}

int main() {
    vector<string> history;
    int choice;

    cout << "================================\n";
    cout << "       UPDATED C++ CALCULATOR\n";
    cout << "================================\n";

    do {
        cout << "\n1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. View History\n";
        cout << "0. Exit\n";

        choice = getChoice();

        if (choice >= 1 && choice <= 4) {
            double a = getNumber("Enter first number: ");
            double b = getNumber("Enter second number: ");
            double result = 0;

            if (calculate(a, b, choice, result)) {
                char op;

                switch (choice) {
                    case 1: op = '+'; break;
                    case 2: op = '-'; break;
                    case 3: op = '*'; break;
                    default: op = '/';
                }

                cout << fixed << setprecision(2);
                cout << "Result: " << a << " " << op
                     << " " << b << " = " << result << '\n';

                ostringstream record;
                record << a << " " << op << " "
                       << b << " = " << result;

                history.push_back(record.str());
            }
        } else if (choice == 5) {
            showHistory(history);
        } else if (choice != 0) {
            cout << "Please select a valid menu option.\n";
        }

    } while (choice != 0);

    cout << "\nThank you for using C++ Smart Calculator!\n";
    cout << "Goodbye!\n";

    return 0;
}
