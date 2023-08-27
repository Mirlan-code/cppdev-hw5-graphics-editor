#pragma once

#include "vector_image.h"
#include <vector>

class VectorGraphicsEditor {
public:
    VectorImage& CreateNewImage() {
        std::cout << "CreateNewImage" << std::endl;
        VectorImages_.push_back({});
        return VectorImages_.back();
    }

    VectorImage& ImportImageFromFile(const std::string_view /* path */) {
        std::cout << "ImportImageFromFile" << std::endl;
        VectorImages_.push_back({});
        return VectorImages_.back();
    }

    void ExportImageToFile(const std::string_view /* path */) {
        std::cout << "ExportImageToFile" << std::endl;
    }

    std::vector<VectorImage> VectorImages_;
};