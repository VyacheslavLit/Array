#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Bad_Range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "������: ��� ��������� ����������.";
    }
};
class Bad_Length : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "������: ������������ ����� ������.";
    }
};
