#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool isPunctuation(char c)
{
    return c == '(' || c == ')' || c == '{' || c == '}' ||
           c == ';' || c == ',' || c == '"';
}

bool isKeyword(string token)
{
    string keywordList[] = {"int", "float", "double", "string", "char",
                             "if", "else", "while", "for", "return",
                             "void", "true", "false", "main"};
    int n = sizeof(keywordList) / sizeof(keywordList[0]);
    for (int i = 0; i < n; i++)
    {
        if (token == keywordList[i])
            return true;
    }
    return false;
}

void identifyTokens(string input)
{
    int i = 0;
    int len = input.length();

    while (i < len)
    {
        // Skip whitespace
        if (input[i] == ' ' || input[i] == '\t')
        {
            i++;
            continue;
        }

        // Identifier or Keyword
        if (isLetter(input[i]))
        {
            string token = "";
            while (i < len && (isLetter(input[i]) || isDigit(input[i])))
            {
                token += input[i];
                i++;
            }
            if (isKeyword(token))
                cout << token << " -> Keyword" << endl;
            else
                cout << token << " -> Identifier" << endl;
            continue;
        }

        // Number / Constant
        if (isDigit(input[i]))
        {
            string token = "";
            while (i < len && (isDigit(input[i]) || input[i] == '.'))
            {
                token += input[i];
                i++;
            }
            cout << token << " -> Constant" << endl;
            continue;
        }

        // Double-character operator <<
        if (input[i] == '<' && i + 1 < len && input[i + 1] == '<')
        {
            cout << "<< -> Operator" << endl;
            i += 2;
            continue;
        }

        // Double-character operator >>
        if (input[i] == '>' && i + 1 < len && input[i + 1] == '>')
        {
            cout << ">> -> Operator" << endl;
            i += 2;
            continue;
        }

        // Single-character operators
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
            input[i] == '/' || input[i] == '%' || input[i] == '=')
        {
            cout << input[i] << " -> Operator" << endl;
            i++;
            continue;
        }

        // Punctuation (includes quote marks)
        if (isPunctuation(input[i]))
        {
            cout << input[i] << " -> Punctuation" << endl;
            i++;
            continue;
        }

        // Anything unrecognized, skip it
        i++;
    }
}

int main()
{
    ifstream MyReadFile("LabAssingment.txt");

    if (!MyReadFile)
    {
        cout << "Error: could not open file." << endl;
        return 1;
    }

    string text;
    int line = 1;

    while (getline(MyReadFile, text))
    {
        cout << "Line-" << line << ":" << endl;
        identifyTokens(text);
        cout << endl;
        line++;
    }

    MyReadFile.close();
    return 0;
}
