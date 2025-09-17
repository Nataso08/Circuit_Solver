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



void find_brackets (vector<string>& tokens) {
    vector<string>::iterator open_bracket, 
        close_bracket = find(tokens.begin(), tokens.end(), ")");

    if (close_bracket != tokens.end()) {
        for (open_bracket=close_bracket; open_bracket >= tokens.begin(); open_bracket--) {
            if (*open_bracket == "(") {
                break;
            }
        }
    }
}

void solve_section () {

}


void solve () {

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

    while (tokens.size() > 1) {

    }

    cout << "R_eq = " << tokens[0] << " ohm";

    return 0;
}