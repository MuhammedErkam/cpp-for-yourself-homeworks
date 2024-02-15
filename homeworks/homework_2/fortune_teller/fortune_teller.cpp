#include <array>
#include <iostream>
#include <map> //needed for std::map --> implemented as tree

int main(int argc, char const *argv[]) {
  const std::map<std::string, std::string> noun_map{
      {"spring", "STL guru"},
      {"summer", "C++ expert"},
      {"autumn", "coding beast"},
      {"winter", "software design hero"}};

  const std::array<std::string, 3UL> ending{
      "eats UB for breakfast", "finds errors quicker than the compiler",
      "is not afraid of C++ error messages"};

  std::array<std::string, 2UL> adjectives{};

  std::string name{}, born{}, adj1{}, adj2{};
  std::cout << "Welcome to the fortune teller program!" << std::endl;
  std::cout << "Please enter your name:" << std::endl;
  std::cin >> name;
  std::cout << "Please enter the time of year when you were born:\n"
            << "(pick from 'spring', 'summer', 'autumn', 'winter')"
            << std::endl;
  std::cin >> born;
  std::cout << "Please enter an adjective:" << std::endl;
  std::cin >> adj1;
  adjectives[0] = adj1;
  std::cout << "Please enter another adjective:" << std::endl;
  std::cin >> adj2;
  adjectives[1] = adj2;
  std::string message{};
  message = name + ", the " + adjectives[name.size() % adjectives.size()] +
            +" " + noun_map.at(born) + " that " +
            ending[name.size() % ending.size()];
  std::cout << message << std::endl;
  return 0;
}
