#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> text_wrap(const string& text, int line_width) {
    vector<string> words;
    stringstream ss(text);
    string word;

    // Split the text into words
    while (ss >> word) {
        words.push_back(word);
    }

    vector<string> wrapped_lines;
    string current_line = "";

    // Process each word
    for (const string& word : words) {
        // Check if adding this word to the current line would exceed the line width
        if (current_line.empty()) {
            current_line = word; // First word in the line
        }
        else if (current_line.length() + 1 + word.length() <= line_width) {
            // If it fits add the word with a space
            current_line += " " + word;
        }
        else {
            // If it doesn't fit push the current line to wrapped_lines and start a new line
            wrapped_lines.push_back(current_line);
            current_line = word;
        }
    }

    // Add the last line if it has any content
    if (!current_line.empty()) {
        wrapped_lines.push_back(current_line);
    }

    return wrapped_lines;

}
int main() {
    string text = "Mary loves to sing and perform tapdancing";
    int line_width = 15;

    vector<string> wrapped_text = text_wrap(text, line_width);

    // Print the wrapped text
    for (int i = 0; i < wrapped_text.size(); ++i) {
        cout << "line " << i + 1 << ": " << wrapped_text[i] << endl;
    }

    return 0;
}
