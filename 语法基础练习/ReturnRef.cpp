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
  return 0;
}

SimpleCat &TheFunction() {
  SimpleCat simpleCat(5, 9);
  return simpleCat;
}
