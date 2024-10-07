#include "HttpPost.h"
#include <iostream>

HttpPost::HttpPost(const std::string& url) {
    // Parse the URL
    size_t pos = url.find("://");
    size_t start = pos != std::string::npos ? pos + 3 : 0;
    size_t end = url.find('/', start);
    host = end != std::string::npos ? url.substr(start, end - start) : url.substr(start);
    path = end != std::string::npos ? url.substr(end) : "/";

    // Initialize WinINet
    hSession = InternetOpen("HttpPost", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    hConnect = InternetConnect(hSession, host.c_str(), INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
}

HttpPost::~HttpPost() {
    // Clean up handles
    if (hRequest) {
        InternetCloseHandle(hRequest);
    }
    if (hConnect) {
        InternetCloseHandle(hConnect);
    }
    if (hSession) {
        InternetCloseHandle(hSession);
    }
}

bool HttpPost::sendRequest(const std::string& postData) {
    // Create a request
    hRequest = HttpOpenRequest(hConnect, "POST", path.c_str(), NULL, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE, 0);
    
    // Set the content type to application/json
    const char* headers = "Content-Type: application/json";
    BOOL result = HttpSendRequest(hRequest, headers, strlen(headers), (LPVOID)postData.c_str(), postData.length());

    if (!result) {
        std::cerr << "Error in HttpSendRequest: " << GetLastError() << std::endl;
        return false;
    }

    // Optional: Read the response if needed
    DWORD bytesRead;
    char buffer[4096];
    while (InternetReadFile(hRequest, buffer, sizeof(buffer) - 1, &bytesRead) && bytesRead != 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the buffer
        std::cout << "Response: " << buffer << std::endl; // Print the response
    }

    return true;
}
