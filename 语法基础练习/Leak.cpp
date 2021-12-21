#include <iostream>

class SimpleCat {
private:
  int itsAge;
  int itsWeight;

public:
  SimpleCat(int age, int weight);
  ~SimpleCat(){};
  int getAge() { return itsAge; }
  int getWeight() { return itsWeight; }
};

SimpleCat::SimpleCat(int age, int weight) : itsAge(age), itsWeight(weight) {}

SimpleCat &TheFunction();

int main() {
  SimpleCat &rCat = TheFunction();
  int age = rCat.getAge();
  std::cout << "rCat is " << age << " years old!" << std::endl;
  std::cout << "&rCat is " << &rCat << std::endl;
  SimpleCat *pCat = &rCat;
  delete pCat; //原对象被释放了，这时候rCat不就成了空引用了吗？
  return 0;
}

SimpleCat &TheFunction() {
  SimpleCat *simpleCat = new SimpleCat(5, 9);
  std::cout << "SimpleCat: " << simpleCat << std::endl;
  return *simpleCat;
}
