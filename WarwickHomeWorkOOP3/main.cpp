#include <iostream>

class Car {
protected:
    std::string m_company;
    std::string m_model;
public:
    Car(std::string company, std::string model) : m_company(company), m_model(model) {
        std::cout << "Car - Company: " << company << ", model: " << model << std::endl;
    }
};

class PassengerCar : public Car {
public:
    PassengerCar(std::string company, std::string model) : Car(company, model) {
        std::cout << "PassengerCar - Company: " << company << ", model: " << model << std::endl;
    }
    
};
class Bus : public Car {
public:
    Bus(std::string company, std::string model) : Car(company, model) {
        std::cout << "Bus - Company: " << company << ", model: " << model << std::endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(std::string company, std::string model) : PassengerCar(company, model), Bus(company, model) {
        std::cout << "Minivan - Company: " << company << ", model: " << model << std::endl;
    }
};

int main()
{
    Car Car1("Nissan", "Skyline");
    PassengerCar pc1("Audi", "Q7");
    Bus bus1("ПАЗ", "3205");
    Minivan mv1("Mercedes", "Vito");
    return 0;
}
