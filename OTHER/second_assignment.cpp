#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to perform operation on two operands
// Function to perform operation on two operands
int performOperation(std::stack<int>& s, char op) {
    if (s.size() < 2) {
        throw std::invalid_argument("Not enough operands on the stack");
    }

    int b = s.top();
    s.pop();
    int a = s.top();
    s.pop();

    switch (op) {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/':
            return b / a;
        case '^':
            return static_cast<int>(pow(b, a));
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

// Function to convert infix notation to postfix notation
std::vector<std::string> infixToPostfix(const std::string& infix) {
    std::stack<int> s;
    std::vector<std::string> postfix;

    for (char c : infix) {
        if (std::isalnum(c)) {
            // If the character is an alphanumeric character, add it to the postfix vector
            postfix.push_back(std::string(1, c));
        } else if (isOperator(c)) {
            // If the character is an operator, pop operands from the stack and push the result onto the postfix vector
            try {
                int result = performOperation(s, c);
                s.push(result);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << "\n";
                exit(EXIT_FAILURE);
            }

            // Add the operator to the postfix vector
            postfix.push_back(std::string(1, c));
        } else if (c == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            s.push(-1);
        } else if (c == ')') {
            // If the character is a closing parenthesis, pop operands from the stack and add them to the postfix vector until an opening parenthesis is encountered
            while (s.top() != -1) {
                try {
                    int result = performOperation(s, '+');
                    s.push(result);
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                    exit(EXIT_FAILURE);
                }
            }
            s.pop(); // Remove the opening parenthesis from the stack
        }
    }

    // Add remaining operands to the postfix vector
    while (!s.empty()) {
        try {
            int result = performOperation(s, '+');
            s.push(result);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\n";
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    std::string infix = "3 + 5 * ( 10 - 4 ) ^ 2 / ( 1 + 2 )";
    std::vector<std::string> postfix = infixToPostfix(infix);

    for (const std::string& token : postfix) {
        std::cout << token << " ";
    }

    return 0;
}