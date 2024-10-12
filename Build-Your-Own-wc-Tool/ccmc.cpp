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

    else {
        cout << "Use the correct commands" << endl;
        return 1;
    }

    return 0;
}
