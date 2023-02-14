#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Bad_Range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ОШИБКА: Вне диапазона контейнера.";
    }
};
class Bad_Length : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ОШИБКА: Неправильная длина масива.";
    }
};
