//
// Created by wexshuq on 20.09.2026.
//

#pragma once
#include <exception>
#include <string>


class RenderException : public std::exception {
    std::string message;
public:
    explicit RenderException(std::string msg) : message(std::move(msg)) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};
