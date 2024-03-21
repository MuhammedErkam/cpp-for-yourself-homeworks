#pragma once

#include "stb_image_data_view.hpp"
#include "image.hpp"

namespace pixelator
{
    int Scale(int number, float factor) {
        return static_cast<int>(number * factor);
    }

    Image PixelateImage(const StbImageDataView& image, Size size){
        // static_cast<float>(number) converts (aka "casts") a number to float.
        float factor_cols = 0.0f;
        float factor_rows = 0.0f;
        float smallest_factor = 0;
        
        if(size.cols >= image.cols() && size.rows >= image.rows()){
            factor_cols = image.cols();
            factor_rows = image.rows();
            smallest_factor = 1.0f;
        }
        else{
            factor_cols = size.cols / static_cast<float>(image.cols());
            factor_rows = size.rows / static_cast<float>(image.rows());            
            smallest_factor = std::min(factor_cols, factor_rows);
        }
        

        const int new_image_rows = Scale(image.rows(), smallest_factor);
        const int new_image_cols = Scale(image.cols(), smallest_factor);

        Image pixelatedImage(new_image_rows, new_image_cols);

        for (int i = 0; i < new_image_rows; i++)
        {
            for (int j = 0; j < new_image_cols; j++)
            {
                // Calculate the corresponding coordinates in the original image
                const int original_row = static_cast<int>(i / smallest_factor);
                const int original_col = static_cast<int>(j / smallest_factor);

                // Set the color of the pixel in the pixelated image
                pixelatedImage.at(i, j) = image.at(original_row, original_col);
            }
        }
        
        return pixelatedImage;
    }
} // namespace pixelator
