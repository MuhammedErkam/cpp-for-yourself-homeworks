#pragma once 
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "size.hpp"

#include <ftxui/screen/color.hpp>
#include <filesystem>
#include <iostream>


namespace pixelator
{
class StbImageDataView
{
private:
    /* data */
    int rows_{};
    int cols_{};
    int channels_{};
    Size* s_{nullptr};
    ftxui::Color *color_{nullptr};
    unsigned char* image_data{nullptr};
    void loadImage(const std::filesystem::path& image_path){
        image_data = stbi_load(image_path.c_str(), &cols_, &rows_, &channels_, 0);
        if (!image_data) {
            std::cerr << "Failed to load image data from file: " << image_path
                    << std::endl;
            rows_ = 0;
            cols_ = 0;
            channels_ = 0;
        }
    }
public:
    StbImageDataView() {
        s_ = new Size{0, 0};
        color_ = new ftxui::Color();
        image_data = new unsigned char;
    };

    StbImageDataView(const std::filesystem::path& image_path) : image_data(nullptr), rows_(0), cols_(0), channels_(0){
        // This call also populates rows, cols, channels.
        loadImage(image_path);
        s_ = new Size{rows_, cols_};
        color_ = new ftxui::Color();
        
    }
    // Move constructor
    StbImageDataView(StbImageDataView&& object) noexcept 
    : s_{object.s_}, image_data{object.image_data}, color_(object.color_),rows_(object.rows_), cols_(object.cols_), channels_{object.channels_} {
        object.image_data = nullptr;
        object.s_ = nullptr;
        object.color_ = nullptr;
        object.rows_ = 0;
        object.cols_ = 0;
        object.channels_ = 0;
    }
    StbImageDataView &operator=(StbImageDataView &&object){
        if (this == &object) { return *this; }  // Do not self-assign.
        if (image_data) stbi_image_free(image_data);
        if (s_) delete s_;
        if (color_) delete color_;
        image_data = object.image_data;
        s_ = object.s_;
        color_ = object.color_;
        rows_ = object.rows_;
        cols_ = object.cols_;
        channels_ = object.channels_;
        object.image_data = nullptr;
        object.s_ = nullptr;
        object.color_ = nullptr;
        object.rows_ = 0;
        object.cols_ = 0;
        object.channels_ = 0;
        return *this;
    }
    // Function to check if the pixel_vec is empty
    bool empty() const {
        return (rows_ == 0 || cols_ == 0);
    }

    auto rows() const { return rows_; }
    auto cols() const { return cols_; }
    auto channels() const { return channels_; }


    ftxui::Color& at(const int row, const int col) const {
        // Bounds checking omitted for brevity
        int index = channels_ * (row * cols_ + col); //(row * cols_ + col) * channels_;
        *color_ = ftxui::Color{image_data[index], image_data[index + 1], image_data[index + 2]};
        return *color_;
    }   

    Size& size() const {
        return *s_;
    }
    ~StbImageDataView(){
        if (image_data) stbi_image_free(image_data);
        if(s_) delete s_;
        if(color_) delete color_;
    }
};
   
} // namespace pixelator

