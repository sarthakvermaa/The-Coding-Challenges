#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 3 && string(argv[1]) == "-c") {
        string filename = argv[2];

        // Open the file in binary mode and place the cursor at the end
        ifstream file(filename, ios::binary | ios::ate);

        if (file.is_open()) {
            streamsize size = file.tellg();
            cout << size << " " << filename << endl;

            file.close();
        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1;
        }
    }

    else if (argc == 3 && string(argv[1]) == "-l"){
        string filename = argv[2];

        // Open the file in text mode
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            int line_count = 0;

            // Read the file line by line
            while (getline(file, line)) {
                line_count++;
            }

            cout << line_count << " " << filename << endl;
            file.close();
        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1;
        }
    }

    else if (argc == 3 && string(argv[1]) == "-w"){
        string filename = argv[2];

        // Open the file in text mode
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            int wordCount = 0;

            while (getline(file, line)) {
                stringstream ss(line);  // Create a stringstream object with the current line content
                string word;

                while (ss >> word) {  // Extract words from the stringstream
                    wordCount++;  // Increment word count for each word extracted
                }
            }

            cout << wordCount << " " << filename << endl;
            file.close();
        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1;
        }
    }

    else if (argc == 3 && string(argv[1]) == "-m"){
        string filename = argv[2];

        ifstream file(filename, ios::binary);
        
        if (file.is_open()) {
            // Seek to the end of the file to find its size
            file.seekg(0, ios::end);

            // Get the current position (which is the size of the file in bytes)
            streampos size = file.tellg();
            
            cout << size << " " << filename << endl;
            file.close();

        } else {
            cout << "Unable to open the file: " << filename << endl;
            return 1;
        }
    }

    else if (argc == 2){
        if(access(argv[1], F_OK) == -1){
            printf("Error: file does not exist\n");
            return 2;
        }
        else {
            string filename = argv[1];

            ifstream file(filename);

            if (file.is_open()) {
                // Initialize counters
                int line_count = 0;
                int word_count = 0;
                streamsize byte_count = 0;
                string line;

                while (getline(file, line)) {
                    line_count++; 
                    byte_count += line.size() + 1; 

                    // Count words in the current line
                    stringstream ss(line);
                    string word;
                    while (ss >> word) {
                        word_count++; 
                    }
                }

                cout << line_count << " " << word_count << " " << byte_count << " " << filename << endl;
                file.close();
            }   
        }
    }

    else {
        cout << "Use the correct commands" << endl;
        return 1;
    }

    return 0;
}

/*
    cp ccmc ~/bin
    sudo cp ccmc /bin
*/