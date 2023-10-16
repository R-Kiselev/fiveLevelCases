#include <iostream>
#include <string>

std::string func(const std::string &identifier, const std::string &targetCase)
{
    std::string result = "";
    if (identifier == "") {
        return "";
    }

    bool camelCase = false, snake_case = false, kebab_case = false;
    for (char c : identifier) {
        if (c == toupper(c) && c != '-' && c != '_') {
            camelCase = true;
        }
        if (c == '_') {
            snake_case = true;
        }
        if (c == '-') {
            kebab_case = true;
        }
    }
    // 1 xor 1 xor 1 = 0 xor 1 = 1   0
    if ( (!camelCase ^ snake_case ^ kebab_case) || (camelCase == 1 && snake_case == 1 && kebab_case == 1 ) ){
        return "";
    }

    if (targetCase == "snake") {
        if (snake_case) {
            return identifier;
        }
        if (kebab_case) {
            for (size_t i = 0; i < identifier.size(); i++) {
                if (identifier[i] == '-') {
                    result += '_';
                }
                else {
                    result += identifier[i];
                }
            }
            return result;
        }
        if (camelCase) {
            for (size_t i = 0; i < identifier.size(); i++) {
                if (identifier[i] == toupper(identifier[i])) {
                    result += '_';
                }
                result += (char)tolower(identifier[i]);
            }
            return result;
        }
    }
    else if (targetCase == "camel") {
        if (camelCase) {
            return identifier;
        }
        if (snake_case) {
            for (size_t i = 0; i < identifier.size(); i++) {
                if (identifier[i] == '_') {
                    result += (char)toupper(identifier[i + 1]);
                    i++;
                }
                else {
                    result += identifier[i];
                }
            }
            return result;
        }
        if (kebab_case) {
            for (size_t i = 0; i < identifier.size(); i++) {
                if (identifier[i] == '-') {
                    result += (char)toupper(identifier[i + 1]);
                    i++;
                }
                else {
                    result += identifier[i];
                }
            }
            return result;
        }
    }
    else if (targetCase == "kebab") {
        if (kebab_case) {
            return identifier;
        }
        if (snake_case) {
            for (size_t i = 0; i < identifier.size(); i++) {
                if (identifier[i] == '_') {
                    result += '-';
                }
                else {
                    result += identifier[i];
                }
            }
            return result;
        }
        if (camelCase) {
            for (size_t i = 0; i < identifier.size(); i++) {
                if (identifier[i] == toupper(identifier[i])) {
                    result += '-';
                }
                result += (char)tolower(identifier[i]);
            }
            return result;
        }
    }

}

int main() {
    std::cout << func("invalid-inPut_bad", "kebab");
}
