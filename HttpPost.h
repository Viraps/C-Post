#ifndef HTTPPOST_H
#define HTTPPOST_H

#include <windows.h>
#include <wininet.h>
#include <string>

#pragma comment(lib, "wininet.lib")

class HttpPost {
public:
    HttpPost(const std::string& url);
    ~HttpPost();

    bool sendRequest(const std::string& postData);

private:
    HINTERNET hSession;
    HINTERNET hConnect;
    HINTERNET hRequest;
    std::string host;
    std::string path;
};

#endif // HTTPPOST_H
