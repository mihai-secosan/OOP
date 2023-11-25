#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <exception>
#include <string>

class ItemAlreadyExists : public std::exception {
public:
    ItemAlreadyExists(const std::string& message) : message_(message) {}
    const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    std::string message_;
};

class DontWorryItIsJustAnExeption : public std::exception {
public:
    DontWorryItIsJustAnExeption(const std::string& message) : message_(message) {}
    const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    std::string message_;
};

class SpaceLimitReached : public std::exception {
public:
    SpaceLimitReached(const std::string& message) : message_(message) {}
    const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    std::string message_;
};

void test_exeptions();

#endif
