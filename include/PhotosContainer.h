// PhotosContainer.h
#ifndef PhotosContainer_H
#define PhotosContainer_H

#include <cstdio>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

class PhotosContainer
{
private:
  Mat image;
  int width;
  int height;
public:
  PhotosContainer(char imagePath[]);
  PhotosContainer(char imagePath[],int width ,int height);
  Mat getImage();
  void medianFilter(int ksize);
};

#endif
