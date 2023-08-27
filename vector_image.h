#pragma once

#include "primitive.h"

#include <iostream>
#include <vector>


class VectorImage {
public:
    VectorImage() = default;

    VectorImage(char* data) {
        std::cout << "VectorImage init" << std::endl;
        Data_ = data;
    }

    size_t AddPrimitive(const Primitive& primitive) {
        std::cout << "AddPrimitive" << std::endl;
        Primitives_.push_back(primitive);
        // Do something with Data_
        return Primitives_.size() - 1;
    }

    size_t AddPrimitive(Primitive&& primitive) {
        std::cout << "AddPrimitive" << std::endl;
        Primitives_.push_back(std::move(primitive));
        // Do something with Data_
        return Primitives_.size() - 1;
    }

    void DeletePrimitive(size_t id) {
        std::cout << "DeletePrimitive" << std::endl;
        Primitives_.erase(Primitives_.begin() + id);
        // Do something with Data_
    }

private:
    std::vector<Primitive> Primitives_;
    char* Data_ = nullptr;
};
