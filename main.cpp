#include "primitive.h"
#include "vector_graphics_editor.h"

#include <iostream>

int main (int, char **) {
    VectorGraphicsEditor vectorGraphicsEditor;
    auto& vectorImage = vectorGraphicsEditor.CreateNewImage();
    vectorImage.AddPrimitive({});
    vectorImage.AddPrimitive(Point(1, 2, Color(1)));
    return 0;
}
