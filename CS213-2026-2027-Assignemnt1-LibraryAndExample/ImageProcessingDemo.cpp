#include <iostream>
#include "Image_Class.h"

using namespace std;

void blackwhite(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            
            int gray = (red + green + blue) / 3;
            
            int finalColor;
            if (gray > 127) {
                finalColor = 255; 
            } else {
                finalColor = 0;   
            }
            
            image(i, j, 0) = finalColor;
            image(i, j, 1) = finalColor;
            image(i, j, 2) = finalColor;
        }
    }
}

int main() {
    string inputFileName = "luffy.jpg"; 
    string outputFileName = "luffy_out.jpg";

    cout << "Loading image..." << endl;
    
    Image myImage(inputFileName);
    
    blackwhite(myImage);
    
    myImage.saveImage(outputFileName);
    
    cout << "Filter applied successfully! Output saved as: " << outputFileName << endl;
    
    return 0;
}