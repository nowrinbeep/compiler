#include <iostream>
#include <string>
using namespace std;
void identifyTokens(string input)
{
    string identifiers[20];
    string numbers[20];
    string operators[20];
    int idCount = 0, numCount = 0, opCount = 0;
    int i = 0;
    while (i < input.length())
    {
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z'))
        {
            string token = "";
            while ((input[i] >= 'A' && input[i] <= 'Z') ||
                   (input[i] >= 'a' && input[i] <= 'z') ||
                   (input[i] >= '0' && input[i] <= '9'))
            {
                token += input[i];
                i++;
            }
            identifiers[idCount++] = token;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            string token = "";
            while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
            {
                token += input[i];
                i++;
            }
            numbers[numCount++] = token;
        }
        else if (input[i] == '<' && input[i + 1] == '<')
        {
            operators[opCount++] = "<<";
            i += 2;
        }
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '%')
        {
            string op = "";
            op += input[i];
            operators[opCount++] = op;
            i++;
        }

        else
        {
            i++;
        }
    }
    cout << " Identifiers / Keywords: "<<endl;
    for (int j = 0; j < idCount; j++)
        cout << identifiers[j] << endl;
    cout << "Numbers: "<<endl;
    for (int j = 0; j < numCount; j++)
        cout << numbers[j] << endl;
    cout << " Operators: "<<endl;
    for (int j = 0; j < opCount; j++)
        cout << operators[j] << endl;
}
int main()
{
    string input;
    cout << "Enter statement: ";
    getline(cin, input);
    identifyTokens(input);
    return 0;
}
