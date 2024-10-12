#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    // Check for -c (count bytes) option
    if (argc == 3 && string(argv[1]) == "-c") {
        string filename = argv[2];

        // Open the file in binary mode and place the cursor at the end
        ifstream file(filename, ios::binary | ios::ate);

        if (file.is_open()) {
            streamsize size = file.tellg(); // Get the size of the file
            cout << size << " " << filename << endl; // Output size (in bytes) and filename

            file.close();
        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1; // Return error code if file can't be opened
        }
    }
    // Check for -l (count lines) option
    else if (argc == 3 && string(argv[1]) == "-l") {
        string filename = argv[2];

        // Open the file in text mode
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            int line_count = 0;

            // Read the file line by line
            while (getline(file, line)) {
                line_count++; // Increment line count for each line read
            }

            cout << line_count << " " << filename << endl; // Output line count and filename
            file.close();
        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1; // Return error code if file can't be opened
        }
    }
    // Check for -w (count words) option
    else if (argc == 3 && string(argv[1]) == "-w") {
        string filename = argv[2];

        // Open the file in text mode
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            int wordCount = 0;

            // Count words in the file
            while (getline(file, line)) {
                stringstream ss(line);  // Create a stringstream object with the current line content
                string word;

                while (ss >> word) {  // Extract words from the stringstream
                    wordCount++;  // Increment word count for each word extracted
                }
            }

            cout << wordCount << " " << filename << endl; // Output word count and filename
            file.close();
        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1; // Return error code if file can't be opened
        }
    }
    // Check for -m (count characters) option
    else if (argc == 3 && string(argv[1]) == "-m") {
        string filename = argv[2];

        ifstream file(filename); // Open the file in text mode
        
        if (file.is_open()) {
            // Initialize character count
            int charCount = 0;
            char c;

            // Count characters until EOF
            while (file.get(c)) {
                // Check if the character is printable
                if (isprint(c) || isspace(c)) {
                    charCount++; // Increment character count for each printable or whitespace character
                }
            }

            // Output character count
            cout << charCount << " " << filename << endl; // Output character count and filename
            file.close();
        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1; // Return error code if file can't be opened
        }
    }
    // Check for invalid options and handle file access
    else if (argc == 2 && string(argv[1]) != "-l" && string(argv[1]) != "-c" && string(argv[1]) != "-w") {
        if (access(argv[1], F_OK) == -1) {
            printf("Error: file does not exist\n");
            return 2; // Return error code if file doesn't exist
        } else {
            string filename = argv[1];

            ifstream file(filename);

            if (file.is_open()) {
                // Initialize counters
                int line_count = 0;
                int word_count = 0;
                streamsize byte_count = 0;
                string line;

                // Read the file line by line
                while (getline(file, line)) {
                    line_count++; 
                    byte_count += line.size() + 1; // Count bytes (including newline)

                    // Count words in the current line
                    stringstream ss(line);
                    string word;
                    while (ss >> word) {
                        word_count++; // Increment word count for each word extracted
                    }
                }

                cout << line_count << " " << word_count << " " << byte_count << " " << filename << endl; // Output counts
                file.close();
            }   
        }
    }
    // Check for -l, -c, -w without a filename
    else if (argc == 2 && (string(argv[1]) == "-l" || string(argv[1]) == "-c" || string(argv[1]) == "-w")) {
        bool countLines = false;
        bool countWords = false;
        bool countChars = false;

        // Parse command line arguments
        for (int i = 1; i < argc; i++) {
            if (string(argv[i]) == "-l") {
                countLines = true;
            } else if (string(argv[i]) == "-w") {
                countWords = true;
            } else if (string(argv[i]) == "-c") {
                countChars = true;
            }
        }

        string line;
        int lineCount = 0;
        int wordCount = 0;
        int charCount = 0;

        // Read from standard input
        while (getline(cin, line)) {
            if (countLines) {
                lineCount++; // Increment line count
            }
            
            if (countWords) {
                stringstream ss(line);
                string word;
                while (ss >> word) {
                    wordCount++; // Increment word count
                }
            }
            
            if (countChars) {
                charCount += (line.size() + 1); // Count characters (including newline)
            }
        }

        // Output the results based on the flags
        if (countLines) {
            cout << lineCount << endl; // Output line count
        }
        if (countWords) {
            cout << wordCount << endl; // Output word count
        }
        if (countChars) {
            cout << charCount << endl; // Output character count
        }
    }
    // Handle invalid command usage
    else {
        cout << "Invalid command usage." << endl;
        cout << "Usage:" << endl;
        cout << "  ccwc -l <filename>   Count lines in a file" << endl;
        cout << "  ccwc -w <filename>   Count words in a file" << endl;
        cout << "  ccwc -c <filename>   Count bytes in a file" << endl;
        cout << "  ccwc -m <filename>   Count characters in a file" << endl;
        cout << "  ccwc <filename>      Count lines, words, and bytes in a file" << endl;
        cout << "  ccwc -l              Count lines from standard input" << endl;
        cout << "  ccwc -w              Count words from standard input" << endl;
        cout << "  ccwc -c              Count bytes from standard input" << endl;
        return 1; // Return error code for invalid command usage
    }

    return 0; // Return success
}

/*
    terminal cmds:
        cp ccwc ~/bin
        sudo cp ccwc /bin
*/