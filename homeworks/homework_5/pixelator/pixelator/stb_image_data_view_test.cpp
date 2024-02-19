#include "pixelator/stb_image_data_view.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

const std::filesystem::path image_path{"/home/erkam/Desktop/CppTuts/CodeForYourself/homeworks/homework5/pixelator/pixelator/test_data/test.png"};

TEST(StbImage_test, test1) {
    pixelator::StbImageDataView empty_image{};
    bool empty = true;
    int row = 0;
    int col = 0;
    pixelator::Size s{row,col};  
    EXPECT_EQ(empty, empty_image.empty());
    EXPECT_EQ(row, empty_image.rows());
    EXPECT_EQ(col, empty_image.cols());
    EXPECT_EQ(s.row, empty_image.size().row);
    EXPECT_EQ(s.col, empty_image.size().col);
}

TEST(StbImage_test, test2) {

    pixelator::StbImageDataView image(image_path);
    bool empty = false;
    int row = 6;
    int col = 4;
    pixelator::Size s{row,col};    
    EXPECT_EQ(empty, image.empty());
    EXPECT_EQ(row, image.rows());
    EXPECT_EQ(col, image.cols());
    EXPECT_EQ(s.row, image.size().row);
    EXPECT_EQ(s.col, image.size().col);
}

TEST(StbImage_test, test3) {

    pixelator::StbImageDataView image(image_path);
    const ftxui::Color yellowish{ftxui::Color::RGB(255, 255, 255)};
    ftxui::Color color;

    color = image.at(4,2);

    EXPECT_EQ(yellowish, color);

}

TEST(StbImage_test, test4) {
    pixelator::StbImageDataView image(image_path);
    const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};
    ftxui::Color color;
    color = image.at(4,2);
    const pixelator::StbImageDataView image_copy{std::move(image)};

    EXPECT_EQ(color, image_copy.at(4,2));

}    