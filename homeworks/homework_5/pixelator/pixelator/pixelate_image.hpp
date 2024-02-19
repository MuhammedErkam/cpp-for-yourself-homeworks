#pragma once

#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/image.hpp"

namespace pixelator {
// Function to scale coordinates
int Scale(int number, float factor) {
    return static_cast<int>(number * factor);
}

Image PixelateImage(const StbImageDataView& original_image, const Size& new_size) {
    int new_row = 0;
    int new_col = 0;

    if(new_size.row >= original_image.rows() && new_size.col >= original_image.cols()){
        new_row = original_image.rows();
        new_col = original_image.cols();
    }
    else{
        new_row = new_size.row;
        new_col = new_size.col;
    }
    // Calculate scaling factors for rows and columns
    const float factor_rows = new_row / static_cast<float>(original_image.rows());
    const float factor_cols = new_col / static_cast<float>(original_image.cols());
    const float smallest_factor = std::min(factor_cols, factor_rows);
    // Calculate new dimensions for the pixelated image
    const int new_image_rows = Scale(original_image.rows(), smallest_factor);
    const int new_image_cols = Scale(original_image.cols(), smallest_factor);

    // Create a new Image object with the pixelated dimensions
    Image pixelated_image(new_image_rows, new_image_cols);
    ftxui::Color color;

    for (int i = 0; i < new_image_rows; i++) {
        for (int j = 0; j < new_image_cols; j++) {
            // Calculate the corresponding coordinates in the original image
            const int original_row = static_cast<int>(i / smallest_factor);
            const int original_col = static_cast<int>(j / smallest_factor);

            // Set the color of the pixel in the pixelated image
            pixelated_image.at(i, j) = original_image.at(original_row, original_col);
        }
    }

    return pixelated_image;
}

/* Image PixelateImage(const StbImageDataView& original_image, const Size& new_size) {
    // Calculate scaling factors for rows and columns
    const float factor_rows = original_image.rows() / static_cast<float>(new_size.row);
    const float factor_cols = original_image.cols() / static_cast<float>(new_size.col);

    // Create a new Image object with the pixelated dimensions
    Image pixelated_image(new_size.row, new_size.col);

    for (int i = 0; i < new_size.row; i++) {
        for (int j = 0; j < new_size.col; j++) {
            // Calculate the corresponding coordinates in the original image
            const int original_row = static_cast<int>(i * factor_rows);
            const int original_col = static_cast<int>(j * factor_cols);

            // Set the color of the pixel in the pixelated image
            pixelated_image.at(i, j) = original_image.at(original_row, original_col);
        }
    }

    return pixelated_image;
} */

} // namespace pixelator
