#include <ftxui/screen/color.hpp>
#include "ftxui/screen/screen.hpp"
#include <iostream>
namespace {
const ftxui::Color kYellowishColor = ftxui::Color::RGB(255, 200, 100);
}

int main() {
  ftxui::Dimensions dimensions{ftxui::Dimension::Full()};
  dimensions.dimy = dimensions.dimx *2;
  std::cout << dimensions.dimx << " " << dimensions.dimy << std::endl; 
  ftxui::Screen screen{ftxui::Screen::Create(dimensions)};
  auto &pixel_left = screen.PixelAt(10, 10);
  pixel_left.background_color = kYellowishColor;
  pixel_left.character = ' ';
  auto &pixel_right = screen.PixelAt(10, 1);
  pixel_right.background_color = kYellowishColor;
  pixel_right.character = ' ';
  screen.Print();
  return 0;
}