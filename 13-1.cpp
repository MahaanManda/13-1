#include <iostream>

class rectangleType {
protected:
    double length;
    double width;

public:
    rectangleType(double l = 0, double w = 0) : length(l), width(w) {}

    // Overloading pre-increment operator
    rectangleType& operator++() {
        ++length;
        ++width;
        return *this;
    }

    // Overloading post-increment operator
    rectangleType operator++(int) {
        rectangleType temp = *this;
        ++(*this);
        return temp;
    }

    // Overloading pre-decrement operator
    rectangleType& operator--() {
        if (length > 1)
            --length;
        if (width > 1)
            --width;
        return *this;
    }

    // Overloading post-decrement operator
    rectangleType operator--(int) {
        rectangleType temp = *this;
        --(*this);
        return temp;
    }

    // Overloading binary operator -
    rectangleType operator-(const rectangleType& other) const {
        rectangleType result(length - other.length, width - other.width);
        if (result.length <= 0 || result.width <= 0) {
            std::cout << "Resulting dimensions are not positive. Operation not performed.\n";
        }
        return result;
    }

    // Overloading relational operator ==
    bool operator==(const rectangleType& other) const {
        return (length * width == other.length * other.width);
    }

    // Overloading relational operator !=
    bool operator!=(const rectangleType& other) const {
        return !(*this == other);
    }

    // Overloading relational operator <
    bool operator<(const rectangleType& other) const {
        return (length * width < other.length * other.width);
    }

    // Overloading relational operator >
    bool operator>(const rectangleType& other) const {
        return (length * width > other.length * other.width);
    }

    // Overloading relational operator <=
    bool operator<=(const rectangleType& other) const {
        return !(*this > other);
    }

    // Overloading relational operator >=
    bool operator>=(const rectangleType& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const rectangleType& rect) {
        os << "Length: " << rect.length << ", Width: " << rect.width;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, rectangleType& rect) {
        is >> rect.length >> rect.width;
        return is;
    }
};

int main() {
    rectangleType rect1(5, 10);
    rectangleType rect2(3, 8);

    std::cout << "Rectangle 1: " << rect1 << std::endl;
    std::cout << "Rectangle 2: " << rect2 << std::endl;

    // Testing pre-increment operator
    ++rect1;
    std::cout << "After pre-incrementing Rectangle 1: " << rect1 << std::endl;

    // Testing post-increment operator
    rect2++;
    std::cout << "After post-incrementing Rectangle 2: " << rect2 << std::endl;

    // Testing pre-decrement operator
    --rect1;
    std::cout << "After pre-decrementing Rectangle 1: " << rect1 << std::endl;

    // Testing post-decrement operator
    rect2--;
    std::cout << "After post-decrementing Rectangle 2: " << rect2 << std::endl;

    // Testing subtraction operator
    rectangleType result = rect1 - rect2;
    std::cout << "Result of subtraction: " << result << std::endl;

    // Testing relational operators
    if (rect1 == rect2)
        std::cout << "Rectangle 1 is equal to Rectangle 2.\n";
    else
        std::cout << "Rectangle 1 is not equal to Rectangle 2.\n";

    if (rect1 != rect2)
        std::cout << "Rectangle 1 is not equal to Rectangle 2.\n";
    else
        std::cout << "Rectangle 1 is equal to Rectangle 2.\n";

    if (rect1 > rect2)
        std::cout << "Rectangle 1 is greater than Rectangle 2.\n";
    else
        std::cout << "Rectangle 1 is not greater than Rectangle 2.\n";

    if (rect1 < rect2)
        std::cout << "Rectangle 1 is less than Rectangle 2.\n";
    else
        std::cout << "Rectangle 1 is not less than Rectangle 2.\n";

    if (rect1 >= rect2)
        std::cout << "Rectangle 1 is greater than or equal to Rectangle 2.\n";
    else
        std::cout << "Rectangle 1 is not greater than or equal to Rectangle 2.\n";

    if (rect1 <= rect2)
        std::cout << "Rectangle 1 is less than or equal to Rectangle 2.\n";
    else
        std::cout << "Rectangle 1 is not less than or equal to Rectangle 2.\n";

    return 0;
}
