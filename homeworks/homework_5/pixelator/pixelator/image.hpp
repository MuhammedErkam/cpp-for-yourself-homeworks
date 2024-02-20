#pragma once

#include <external/ftxui/include/ftxui/screen/color.hpp>
#include "size.hpp"

#include <cstdint>  // for uint8_t
#include <vector>

namespace pixelator {

class Image {
   private:
    /* data */

    int rows_{};
    int cols_{};
    Size *s_{nullptr};
    std::vector<std::vector<ftxui::Color>> *pixel_vec{nullptr};
   public:
    Image() {
        s_ = new Size{0, 0};
    };
    Image(const int rows, const int cols) : rows_{rows}, cols_{cols} {
        pixel_vec = new std::vector<std::vector<ftxui::Color>>(rows, std::vector<ftxui::Color>(cols)); 
        s_ = new Size{rows, cols};
    };

    // Copy constructor
    Image(const Image& image) : rows_{image.rows_}, cols_{image.cols_} {
        s_ = new Size{image.rows_, image.cols_};
        pixel_vec = new std::vector<std::vector<ftxui::Color>>(image.rows_, std::vector<ftxui::Color>(image.cols_));
        for (int i = 0; i < image.rows_; ++i) {
            std::copy(image.pixel_vec->at(i).begin(), image.pixel_vec->at(i).end(), pixel_vec->at(i).begin());
        }
    }

    // Move constructor
    Image(Image&& image) noexcept : rows_(image.rows_), cols_(image.cols_){
        pixel_vec = nullptr;
        pixel_vec = new std::vector<std::vector<ftxui::Color>>(image.rows_, std::vector<ftxui::Color>(image.cols_));
        image.pixel_vec = nullptr;
        
        s_ = nullptr;
        s_ = new Size{image.rows_, image.cols_};
        image.s_ = nullptr;
        
        image.rows_ = 0;
        image.cols_ = 0;
    }

    // Function to check if the pixel_vec is empty
    bool empty() const {
        return (rows_ == 0 || cols_ == 0);
    }

    auto rows() const { return rows_; }
    auto cols() const { return cols_; }


    ftxui::Color& at(const int row, const int col) const {
        return (pixel_vec->at(row).at(col));
    }

    Size& size() const {
        return *s_;
    }

    ~Image() {
        delete pixel_vec;
        delete s_;
    }
};

}  // namespace pixelator
