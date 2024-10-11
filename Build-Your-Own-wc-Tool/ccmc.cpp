#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3 || string(argv[1]) != "-c") {
        cout << "Usage: " << argv[0] << " -c <filename>" << endl;
        return 1;
    }

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

    return 0;
}
