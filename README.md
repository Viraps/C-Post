# C++ POST Request Sender

This project is a C++ application that allows sending multiple HTTP POST requests to a specified URL with a custom message. It is useful for network testing, API integration, or stress testing purposes.

## Features

- **Custom URL and Message**: Specify the URL and the message content for the POST request.
- **Multiple Requests**: Send the message a specified number of times.
- **Simple API**: Easily send HTTP POST requests with minimal setup.
- **Error Handling**: Provides feedback on whether each request was successful or failed.

## Installation

### Prerequisites

- **C++17** or later
- A C++ compiler (e.g., GCC, Clang, MSVC)
- **lwininet** (for making HTTP POST requests)
- *using g++*
- ```g++ -o main main.cpp HttpPost.cpp -lwininet```
  - Install on Ubuntu:  
    ```bash
    sudo apt-get install lwininet
    ```
  - Install on macOS using Homebrew:  
    ```bash
    brew install curl
    ```

### Clone the repository

```bash
git clone https://github.com/viraps/C-Post.git
cd C-Post
g++ -o main main.cpp HttpPost.cpp -lwininet

```

# Contribution
Contributions are welcome! Feel free to submit a pull request or open an issue if you have suggestions for improvements or new features.

To contribute:
Fork the repository.
Create a new branch (git checkout -b feature-branch).
Commit your changes (git commit -am 'Add some feature').
Push to the branch (git push origin feature-branch).
Create a new pull request.
