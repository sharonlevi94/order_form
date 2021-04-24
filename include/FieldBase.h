#pragma once


class FieldBase {
public:
    virtual void setAnswer() = 0;
    virtual void printField()const = 0;
    virtual bool getIsCorrect()const = 0;
    virtual void setIsCorrect(bool) = 0;
};
