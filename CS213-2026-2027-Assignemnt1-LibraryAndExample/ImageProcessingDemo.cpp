#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

void rotateImage(Image& image) {
    int choice;
    cout << "Enter rotation degree (90, 180, 270): ";
    cin >> choice;

    if (choice == 90) {
        Image rotated(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    rotated(j, image.width - 1 - i, k) = image(i, j, k);
                }
            }
        }
        image = rotated; 
    } 
    else if (choice == 180) {
        Image rotated(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    rotated(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
                }
            }
        }
        image = rotated;
    } 
    else if (choice == 270) {
        Image rotated(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    rotated(image.height - 1 - j, i, k) = image(i, j, k);
                }
            }
        }
        image = rotated;
    } 
    else {
        cout << "Invalid choice! No rotation applied." << endl;
    }
}

int main() {
    string inputFilename = "luffy.jpg";
    string outputFilename = "luffy_out.jpg";

    Image myImage(inputFilename);

    rotateImage(myImage);

    myImage.saveImage(outputFilename);

    cout << "Image rotated and saved successfully!" << endl;
    return 0;
}