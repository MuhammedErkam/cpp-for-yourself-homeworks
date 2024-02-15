#include <iostream>
#include <map>
#include <random>
#include <vector>

int main(int argc, char const *argv[]) {
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};
  int smallest{0};
  int largest{0};
  int random_variable{0};
  int guess{0};
  int counter{1};

  std::cout << "Welcome to the GUESSING GAME!\n"
            << "I will generate a number and you will guess it!" << std::endl;

  std::cout << "Please provide the smallest number:" << std::endl;
  std::cin >> smallest;
  std::cout << "Please provide the largest number:" << std::endl;
  std::cin >> largest;
  std::uniform_int_distribution distrubution{smallest, largest};

  random_variable = distrubution(random_engine);
  std::cout << "I've generated a number. Try to guess it!" << std::endl;

  while (true) {
    std::cout << "Please provide the next guess:";
    std::cin >> guess;
    if (guess < random_variable) {
      std::cout << "Your number is too small. Try again!" << std::endl;
      counter++;
    }
    else if (guess > random_variable) {
      std::cout << "Your number is too big. Try again!" << std::endl;
      counter++;
    } else {
      std::cout << "You've done it! You guessed the number " << random_variable
                << " in " << counter << " guesses!" << std::endl;
      break;
    }
  }

  return 0;
}
