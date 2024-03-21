#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include "size.hpp"
#include "stb/stb_image.h"
#include <ftxui/screen/color.hpp>

#include <iostream>
#include <string>
#include <filesystem>

// Some path to an image on disk.
// const std::filesystem::path image_path{"../../pixelator/test_data/test.png"};

namespace pixelator
{
    class StbImageDataView
    {
    private:
        int cols_;
        int rows_;
        int channels_;
        unsigned char * image_data{nullptr};
    public:
        StbImageDataView() : cols_{0}, rows_{0}, channels_{0}, image_data{nullptr} {};
        StbImageDataView(const std::string& image_path){
            image_data = stbi_load(image_path.c_str(), &cols_, &rows_, &channels_, 0);
            if (!image_data) {
                std::cerr << "Failed to load image data from file: " << image_path << std::endl;
                rows_ = 0;
                cols_ = 0;
                channels_ = 0;
            }
        };
        StbImageDataView(StbImageDataView&& other_image): 
        rows_{other_image.rows_}, cols_{other_image.cols_}, channels_{other_image.channels_},
        image_data{other_image.image_data}
        {            
            other_image.image_data = nullptr;
            other_image.rows_ = 0;
            other_image.cols_ = 0;
            other_image.channels_ = 0;
        };

        StbImageDataView &operator=(StbImageDataView &&other_image){
            if (this == &other_image) { return *this; }  // Do not self-assign.
            if (image_data) stbi_image_free(image_data);

            image_data = other_image.image_data;

            rows_ = other_image.rows_;
            cols_ = other_image.cols_; 
            channels_ = other_image.channels_;   

            other_image.image_data = nullptr;
            other_image.rows_ = 0;
            other_image.cols_ = 0;
            other_image.channels_ = 0;

            return *this;
        };

        bool empty() const {
            if(rows_ == 0 && cols_ == 0){
                return true;
            }
            return false;
        }
        int rows() const {
            return rows_;
        }

        int cols() const {
            return cols_;
        }
        
        const ftxui::Color at(int row, int col) const {
            const auto index{channels_ * (row * cols_ + col)};
            const ftxui::Color color{image_data[index], image_data[index + 1], image_data[index + 2]};
            return color;
        }

        Size size() const {
            return Size{rows_,cols_};
        }

        ~StbImageDataView() {
            if (image_data != nullptr)
            {
                stbi_image_free(image_data);
            }
        }
    };
    
} // namespace pixelator

