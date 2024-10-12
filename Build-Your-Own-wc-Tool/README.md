# Character, Word, and Line Counter (ccwc)

## Overview

The **ccwc** program is a command-line utility written in C++ that counts characters, words, lines, and bytes in a given text file. It can also read from standard input, allowing for flexible use in various scenarios. The program supports several command-line options to specify the type of count to perform.

## Features

- Count **lines** in a file.
- Count **words** in a file.
- Count **bytes** (size of the file) in a file.
- Count **characters** (including printable and whitespace characters) in a file.
- Read input from standard input for line, word, and byte counts.

## Usage

### Command-Line Options

- `-l <filename>`: Count the number of lines in the specified file.
- `-w <filename>`: Count the number of words in the specified file.
- `-c <filename>`: Count the number of bytes in the specified file.
- `-m <filename>`: Count the number of characters in the specified file.
- `<filename>`: Count lines, words, and bytes in the specified file.

### Reading from Standard Input

You can also use the following options to count from standard input:

- `ccwc -l`: Count lines from standard input.
- `ccwc -w`: Count words from standard input.
- `ccwc -c`: Count bytes from standard input.

### Example

To count lines, words, and bytes in a file named `example.txt`, you would use:

```bash
ccwc example.txt
```

To read from standard input, you can use:

```bash
echo "Hello World" | ccwc -w
```

### Installation

To install the ccwc command for system-wide use, you can copy the executable to your local bin directory:

```bash
cp ccwc ~/bin
```

For system-wide access, you can copy it to /usr/bin (requires superuser privileges):

```bash
sudo cp ccwc /usr/bin
```

### Acknowledgements
This utility is inspired by the Unix wc (word count) command and serves to provide a similar functionality in a simple C++ program.

For more details you can refer: <a href="https://codingchallenges.fyi/challenges/challenge-wc/">Build Your Own wc Tool</a>

### Contributing
Feel free to contribute by forking the repository and submitting pull requests. For significant changes, please open an issue first to discuss what you would like to change.
