#pragma once

#include "size.hpp"
#include <ftxui/screen/color.hpp>

#include <vector>

namespace pixelator
{
    class Image
    {
    private:
        int cols_{0};
        int rows_{0};
        std::vector<ftxui::Color> pixels_;
    public:
        Image(/* args */) = default;

        Image(const int row, const int col): cols_{col}, rows_{row}, pixels_(row*col) {
        }

        Image(const Size size): cols_{size.cols}, rows_{size.rows}, pixels_(size.rows*size.cols) {
        }

        Image(const Image& ref_object) : cols_{ref_object.cols_}, rows_{ref_object.rows_}, pixels_{ref_object.pixels_} {}
        
        Image(Image&& move_object) : cols_{move_object.cols_}, rows_{move_object.rows_}, pixels_{move_object.pixels_} {
            move_object.cols_ = 0;
            move_object.rows_ = 0;
            move_object.pixels_.clear();
        }

        bool empty() const {
            return pixels_.empty();
        }
        int rows() const {
            return rows_;
        }

        int cols() const {
            return cols_;
        }
        
        const ftxui::Color& at(int row, int col) const {
            return pixels_[cols_*row + col];
        }

        ftxui::Color& at(int row, int col) {
            return pixels_[cols_*row + col];
        }

        Size size() {
            return Size{rows_,cols_};
        }

        const Size size() const{
            return Size{rows_,cols_};
        }

        ~Image(){}
    };

    
} // namespace pixelator
