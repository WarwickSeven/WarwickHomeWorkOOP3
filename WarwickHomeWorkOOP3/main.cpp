#include <iostream>

class DivByZero {
    std::string m_error;
public:
    DivByZero(std::string error) : m_error(error) { }
    const char* getError() {
        return m_error.c_str();
    }
};

class Fraction {
    int m_a;
    int m_b;
public:
    Fraction(const int a, const int b) : m_a(a), m_b(b) {
        if (m_b==0) {
            throw DivByZero("Division by zero!");
        }
    }
    virtual ~Fraction() { }
        
    void printFr() {
        if (m_a%m_b==0) {
            m_a = m_a/m_b;
            std::cout <<"It's int: "<< m_a << std::endl;
        } else {
            std::cout << "Fraction: " << m_a << "/" << m_b << std::endl;
        }
    };
    
    Fraction reduction() { //сокращатор некорректно отрабатывает отрицательные дроби
        int a = m_a;
        int b = m_b;
        if (a < b) {
            for (int i = a; i > 0; i--) {
                if ((a%i==0)&&(b%i==0)) {
                    a = a/i;
                    b = b/i;
                }
            }
        } else if (a > b) {
            for (int i = b; i > 0; i--) {
                if ((a%i==0)&&(b%i==0)) {
                    a = a/i;
                    b = b/i;
                }
            }
        } else {
            a = 1;
            b = 1;
        }
        return Fraction(a, b);
    }
    friend Fraction operator+(const Fraction &f1, const Fraction&f2);
    friend Fraction operator-(const Fraction &f1, const Fraction&f2);
    friend Fraction operator*(const Fraction &f1, const Fraction&f2);
    friend Fraction operator/(const Fraction &f1, const Fraction&f2);
    friend Fraction operator-(const Fraction &f1);
    friend bool operator==(Fraction &f1, Fraction&f2);
    friend bool operator!=(Fraction &f1, Fraction&f2);
    friend bool operator<(const Fraction &f1, const Fraction&f2);
    friend bool operator>(const Fraction &f1, const Fraction&f2);
    friend bool operator<=(const Fraction &f1, const Fraction&f2);
    friend bool operator>=(const Fraction &f1, const Fraction&f2);
};

Fraction operator+(const Fraction &f1, const Fraction&f2) {
    int a;
    int b;
    if (f1.m_b == f2.m_b) {
        a = f1.m_a + f2.m_a;
        b = f1.m_b;
    } else {
        a = (f1.m_a*f2.m_b)+(f2.m_a*f1.m_b);
        b = f1.m_b * f2.m_b;
    }
    return Fraction(a,b).reduction();
};

Fraction operator-(const Fraction &f1, const Fraction&f2) {
    int a;
    int b;
    if (f1.m_b == f2.m_b) {
        a = f1.m_a - f2.m_a;
        b = f1.m_b;
    } else {
        a = (f1.m_a*f2.m_b)-(f2.m_a*f1.m_b);
        b = f1.m_b * f2.m_b;
    }
    return Fraction(a,b).reduction();
};

Fraction operator*(const Fraction &f1, const Fraction&f2) {
    int a = f1.m_a*f2.m_a;
    int b = f1.m_b*f2.m_b;
    return Fraction(a, b).reduction();
};

Fraction operator/(const Fraction &f1, const Fraction&f2) {
    int a = f1.m_a*f2.m_b;
    int b = f1.m_b*f2.m_a;
    return Fraction(a, b).reduction();
};

Fraction operator-(const Fraction &f1) {
    int a = -f1.m_a;
    int b = f1.m_b;
    return Fraction(a,b).reduction();
};

bool operator==(Fraction &f1, Fraction&f2) {
    f1 = f1.reduction();
    f2 = f2.reduction();
    return ((f1.m_a==f2.m_a)&&(f1.m_b==f2.m_b));
};

bool operator!=(Fraction &f1, Fraction&f2) {
    f1 = f1.reduction();
    f2 = f2.reduction();
    return ((f1.m_a!=f2.m_a)||(f1.m_b!=f2.m_b));
};

bool operator<(const Fraction &f1, const Fraction&f2) {
    int a = f1.m_a*f2.m_b;
    int b = f2.m_a*f1.m_b;
    return (a < b);
}

bool operator>(const Fraction &f1, const Fraction&f2) {
    int a = f1.m_a*f2.m_b;
    int b = f2.m_a*f1.m_b;
    return (a > b);
}

bool operator<=(const Fraction &f1, const Fraction&f2) {
    int a = f1.m_a*f2.m_b;
    int b = f2.m_a*f1.m_b;
    return (a < b);
}

bool operator>=(const Fraction &f1, const Fraction&f2) {
    int a = f1.m_a*f2.m_b;
    int b = f2.m_a*f1.m_b;
    return (a > b);
}

int main() {
    try {
    Fraction fr1(2, 3);
    Fraction fr2(3, 4);
    fr1.printFr();
    fr2.printFr();
    Fraction frSum = fr1 + fr2;
    frSum.printFr();
    Fraction frSub = fr1 - fr2;
    frSub.printFr();
    Fraction frMult = fr1 * fr2;
    frMult.printFr();
    Fraction frDiv = fr1 / fr2;
    frDiv.printFr();
    Fraction frUno = -fr1;
    frUno.printFr();
    if (fr1<=fr2) {
    std::cout << "Meow!" << std::endl;
    }
    } catch(DivByZero &exception) {
        std::cout << exception.getError() << std::endl;
    }
    return 0;
}

