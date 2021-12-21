#include <iostream>

class SimpleCat {
private:
  int itsAge;

public:
  SimpleCat();
  SimpleCat(SimpleCat &);
  ~SimpleCat();

  int getAge() const { return itsAge; }
  void setAge(int age) { itsAge = age; }
};

SimpleCat::SimpleCat() {
  std::cout << "Simple Cat Constructor ..." << std::endl;
  itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat &) {
  std::cout << "Simple Cat Copy Constructor ..." << std::endl;
}

SimpleCat::~SimpleCat() {
  std::cout << "Simple Cat Destructor ..." << std::endl;
}

const SimpleCat &FunctionTwo(const SimpleCat &simpleCat); //指向常量的常量指针

int main() {
  std::cout << "Making a cat ..." << std::endl;
  SimpleCat simpleCat;
  std::cout << "simpleCat is now " << simpleCat.getAge() << " years old"
            << std::endl;
  int age = 5;
  simpleCat.setAge(age);
  std::cout << "simpleCat is now " << simpleCat.getAge() << " years old"
            << std::endl;
  std::cout << "Calling FunctionTwo..." << std::endl;
  FunctionTwo(simpleCat);
  std::cout << "simpleCat is now " << simpleCat.getAge() << " years old"
            << std::endl;
  return 0;
}

const SimpleCat &FunctionTwo(const SimpleCat &simpleCat) {
  std::cout << "Function Two. Returning ..." << std::endl;
  std::cout << "simpleCat is now " << simpleCat.getAge() << " years old"
            << std::endl;
  // simpleCat->setAge(9);//报错，无法对const类型对象进行修改
  return simpleCat;
}