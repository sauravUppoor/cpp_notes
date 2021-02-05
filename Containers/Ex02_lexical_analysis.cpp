#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<numeric>
// #include<boost/graph/bandwidth.hpp>

// Constants
const std::vector<std::string> operators = {",", "<", ">", ".", "_", ")", "(", ";", "$",
    ":", "%", "[", "]", "#", "?", "'", "&", "{", "}", "\"", "^", "!", "*", "/", "|",
    "-", "\\", "~", "+", "=", "==", ">=", "<=", "++", "--"};

const std::vector<std::string> keywords = {"auto", "break", "case", "char", "continue"
    "default", "const", "double", "else", "enum", "extern", "for", "if", "goto", "float",
    "int", "long", "register", "return", "signed", "static", "sizeof", "short", "struct",
    "switch", "typedef", "union", "void", "while", "volatile", "unsigned"};

// Function prototypes
std::vector<std::string> string_to_vector(std::string, char);

int main()
{
    std::string text;
    std::vector<std::string> tokens;
    std::string trail;

    std::cout << "Enter the c statement: ";
    std::getline(std::cin, text);
    std::cout << '\n';

    trail = text[text.length()-1];
    if(trail != ";" && trail != "}")
    {
        std::cout << "Invalid statement\n";
        return 0;
    }

    if(trail == ";") 
        text = text.substr(0,text.length()-1);
    tokens = string_to_vector(text, ' ');

    for(auto token: tokens)
    {
        std::cout << token << " - ";
        auto it = std::find(operators.begin(), operators.end(), token);
        if(it != operators.end())
        {
            std::cout << "Operator\n";
            continue;
        }
        it = std::find(keywords.begin(), keywords.end(), token);
        if(it != keywords.end())
        {
            std::cout << "Keyword\n";
            continue;
        }
        if(isdigit(token[0]))
            std::cout << "Constant\n";
        else 
        std::cout << "Identifier\n";
    }
        
}

std::vector<std::string> string_to_vector(std::string theString, char del)
{
    std::stringstream ss(theString);
    std::string indv_string;

    std::vector<std::string> tokens;
    while(getline(ss, indv_string, del))
    {
        tokens.push_back(indv_string);
    }
    
    return tokens;
}