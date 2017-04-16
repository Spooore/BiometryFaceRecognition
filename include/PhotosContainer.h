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
public:
  PhotosContainer(char imagePath[]);
  void medianFilter(void);
};

#endif
