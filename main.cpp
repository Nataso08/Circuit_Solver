#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

inline float serie (float a, float b) {
    return a + b;
}

inline float parallel (float a, float b) {
    return a*b / (a+b);
}


void solve_section (vector<string>& tokens, vector<string>::iterator start) {
    int n = find (start, tokens.end(), ")") - start;

    while (n > 1) {
        vector<string>::iterator O = find (start, start + n, "//");

        if (O != start + n) {
            *O = to_string(parallel (stof(*(O - 1)), stof(*(O + 1))));    
        } else {
            O = find (start, start + n, "+");

            *O = to_string(serie (stof(*(O - 1)), stof(*(O + 1))));
        }

        tokens.erase(O +1);
        tokens.erase(O -1);
        
        n -= 2;
    }
}

// individuo le parentesi più interne
pair<vector<string>::iterator, vector<string>::iterator> find_brackets (vector<string>& tokens) {
    pair<vector<string>::iterator, vector<string>::iterator> brackets;
    
    brackets.second = find(tokens.begin(), tokens.end(), ")");

    if (brackets.second != tokens.end()) {
        for (brackets.first=brackets.second; brackets.first >= tokens.begin(); brackets.first--) {
            if (*brackets.first == "(") {
                break;
            }
        }
    } else {
        brackets.first = tokens.end();
    }

    return brackets;
}

// risolvo brackets
void solve_brackets (vector<string>& tokens, vector<string>::iterator brackets) {
    solve_section (tokens, brackets + 1);

    tokens.erase(brackets + 2);
    tokens.erase(brackets);
}


void solve (vector<string>& tokens) {
    vector<string>::iterator brackets;

    while (tokens.size() > 1) {
        brackets = find_brackets (tokens).first;

        if (brackets != tokens.end()) {   // esistono parentesi
            solve_brackets (tokens, brackets);
        } else {
            solve_section (tokens, tokens.begin());
        }
    }
}

int main () {
    string input;

    cout << "Inserire la formula del circuito: \n>>> "; 
    getline(cin, input);

    vector<string> tokens;
    {
        string token;
        stringstream ss(input);

        while (ss >> token) tokens.push_back(token);
    }

    solve (tokens);

    cout << "R_eq = " << tokens[0] << " ohm";

    return 0;
}