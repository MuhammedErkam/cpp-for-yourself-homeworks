#pragma once

#include <external/ftxui/include/ftxui/screen/screen.hpp>
#include "image.hpp"
#include <iostream>
namespace pixelator {

class Drawer {
private:
    ftxui::Screen screen_{0,0};

public:
    Drawer() = default;
    // Constructor to create a drawer with full screen size
    Drawer(ftxui::Dimensions dimension) {
        dimension.dimx = dimension.dimy * 2;
        screen_ = ftxui::Screen::Create(dimension) ;
    }

    // Get the number of rows
    int rows() const {
        return screen_.dimy();
    }

    // Get the number of columns
    int cols() const {
        return screen_.dimx();
    }

    // Get the size of the drawer
    Size size() const {
        return {rows(), cols()};
    }

    // Set a pixelated image to the drawer
    void Set(const Image& image) {
        int a = 3;
        for (int i = 0; i < image.cols(); i=i+a) {
            for (int j = 0; j < image.rows(); j++) {
                for (int k = 0; k < a; k++)
                {
                    for (int t = 0; t < a; t++)
                    {
                        screen_.PixelAt(i+t,j+k).background_color = image.at(j,i);
                        screen_.PixelAt(i+t,j+k).character = ' ';
                    }
                }
            }
        }
    }

    // Draw the drawer to the terminal
    void Draw() {
        screen_.Print();
    }

    // Print the drawer content to a string (used for testing)
    std::string ToString() const {
        return screen_.ToString();
    }
};

} // namespace pixelator
