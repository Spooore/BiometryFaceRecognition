#include "/root/Documents/Biometria/FaRe/include/PhotosContainer.h"

PhotosContainer::PhotosContainer(char imagePath[])
{
    this->image=imread(imagePath,1);
}

void PhotosContainer::medianFilter(void)
{

}
