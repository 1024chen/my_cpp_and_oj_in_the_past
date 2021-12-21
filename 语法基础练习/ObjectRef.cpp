#include <iostream>

class SimpleCat {
public:
  SimpleCat();            //默认构造函数
  SimpleCat(SimpleCat &); //拷贝构造函数
  ~SimpleCat();
};

SimpleCat::SimpleCat() {
  std::cout << "Simple Cat Constructor ..." << std::endl;
}

SimpleCat::SimpleCat(SimpleCat &) {
  std::cout << "Simple Cat Copy Constructor ..." << std::endl;
}

SimpleCat::~SimpleCat() {
  std::cout << "Simple Cat Destructor ..." << std::endl;
}

SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat *FunctionTwo(SimpleCat *theCat);

int main() {
  std::cout << "Making a Cat ..." << std::endl;
  SimpleCat simpleCat;
  std::cout << "Calling FunctionOne..." << std::endl;
  FunctionOne(simpleCat);
  std::cout << "Calling FunctionTwo..." << std::endl;
  FunctionTwo(&simpleCat);
  return 0;
}

SimpleCat FunctionOne(SimpleCat theCat) {
  std::cout << "Function One. Returning ..." << std::endl;
  return theCat;
}
SimpleCat *FunctionTwo(SimpleCat *theCat) {
  std::cout << "Function Two. Returning ..." << std::endl;
  return theCat;
}