#pragma once

#include "ftxui/screen/screen.hpp"
#include "image.hpp"
#include <iostream>
namespace pixelator {

class Drawer {
private:
    ftxui::Screen screen_{0,0};
    int rows_;
    int cols_;

public:
    Drawer() = default;
    // Constructor to create a drawer with full screen size
    Drawer(ftxui::Dimensions dimension) {
        if(dimension.dimx == ftxui::Dimension::Full().dimx && dimension.dimy == ftxui::Dimension::Full().dimy){
            rows_ = dimension.dimy;
            cols_ = dimension.dimx;
        }
        else{
            rows_ = dimension.dimy;
            cols_ = rows_ * 2;
        }
        screen_ = ftxui::Screen::Create(dimension) ;
    }

    // Get the number of rows
    int rows() const {
        return rows_;
    }

    // Get the number of columns
    int cols() const {
        return cols_;
    }

    // Get the size of the drawer
    Size size() const {
        return Size{rows(), cols()};
    }

    // Set a pixelated image to the drawer
    void Set(const Image& image) {
        int a = 2;
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