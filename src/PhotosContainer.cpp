#include "/root/Documents/Biometria/FaRe/include/PhotosContainer.h"

PhotosContainer::PhotosContainer(char imagePath[])
{
    this->image=imread(imagePath,1);
    if (!this->image.data){cout <<"No image data"<<endl;exit(EXIT_FAILURE);}
}


PhotosContainer::PhotosContainer(char imagePath[],int width,int height)
{
    this->image=imread(imagePath,1);
    this->width=width;
    this->height=height;
    if (!this->image.data){cout <<"No image data"<<endl;exit(EXIT_FAILURE);}
    resize(image,image,Size(width,height));
}

void PhotosContainer::medianFilter(int ksize)
{
  medianBlur(image, image, ksize);
  imshow("Median Filter", image);
}

Mat PhotosContainer::getImage()
{
  return this->image;
}
