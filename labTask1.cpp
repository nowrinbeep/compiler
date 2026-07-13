#include <iostream>
#include <string>
using namespace std;

bool isNumericConstant(const string &input) {
    if (input.empty())
        return false;

    int start = 0;
    int firstAscii = (int)input[0];

    if (firstAscii == 43 || firstAscii == 45) // optional leading sign
        start = 1;

    if (start == (int)input.length()) // string was only "+" or "-"
        return false;

    bool dotSeen = false;

    for (int i = start; i < (int)input.length(); i++) {
        int ascii = (int)input[i];

        if (ascii == 46) {
            if (dotSeen)
                return false;
            dotSeen = true;
        }
        else if (ascii >= 48 && ascii <= 57) {

        }
        else {
            return false;
        }
    }
    return true;
}

void task1() {
    string input;
    cout << "\nEnter an input: ";
    cin >> input;

    if (isNumericConstant(input))
        cout << "\"" << input << "\" is a numeric constant." << endl;
    else
        cout << "\"" << input << "\" is not numeric." << endl;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '=');
}

void findOperators(const string &input) {
    int count = 0;
    for (int i = 0; i < (int)input.length(); i++) {
        if (isOperator(input[i])) {
            count++;
            cout << "operator" << count << ": " << input[i] << endl;
        }
    }
    if (count == 0)
        cout << "No operator found in the input." << endl;
}

void task2() {
    string input;
    cout << "\nEnter an expression (e.g. 2+3=5): ";
    cin >> input;
    findOperators(input);
}

bool isSingleLineComment(const string &line) {
    return (line.length() >= 2 && line[0] == '/' && line[1] == '/');
}

bool startsMultiLineComment(const string &line) {
    return (line.length() >= 2 && line[0] == '/' && line[1] == '*');
}

bool endsMultiLineComment(const string &line) {
    int len = (int)line.length();
    return (len >= 2 && line[len - 2] == '*' && line[len - 1] == '/');
}

void task3() {
    string line;
    cin.ignore();
    cout << "\nEnter a line: ";
    getline(cin, line);

    if (isSingleLineComment(line)) {
        cout << "This is a single line comment." << endl;
    }
    else if (startsMultiLineComment(line)) {
        if (endsMultiLineComment(line)) {
            cout << "This is a complete multiple line comment." << endl;
        }
        else {
            cout << "This is the start of a multiple line comment." << endl;
            cout << "Keep entering lines until you close it with */" << endl;

            string nextLine;
            bool closed = false;
            while (getline(cin, nextLine)) {
                if (endsMultiLineComment(nextLine)) {
                    closed = true;
                    break;
                }
            }
            if (closed)
                cout << "Comment closed. This was a complete multiple line comment." << endl;
            else
                cout << "Comment was never closed." << endl;
        }
    }
    else {
        cout << "This is not a comment." << endl;
    }
}


bool isAlphabetOrUnderscore(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_');
}

bool isAlphaNumericOrUnderscore(char ch) {
    return (isAlphabetOrUnderscore(ch) || (ch >= '0' && ch <= '9'));
}

bool isIdentifier(const string &input) {
    if (input.empty())
        return false;

    if (!isAlphabetOrUnderscore(input[0]))
        return false;

    for (int i = 1; i < (int)input.length(); i++) {
        if (!isAlphaNumericOrUnderscore(input[i]))
            return false;
    }
    return true;
}

void task4() {
    string input;
    cout << "\nEnter an input: ";
    cin >> input;

    if (isIdentifier(input))
        cout << "\"" << input << "\" is a valid identifier." << endl;
    else
        cout << "\"" << input << "\" is not a valid identifier." << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== Lab Task-1 Menu =====" << endl;
        cout << "1. Check Numeric Constant" << endl;
        cout << "2. Check Operators" << endl;
        cout << "3. Check Comment Line(s)" << endl;
        cout << "4. Check Identifier" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
