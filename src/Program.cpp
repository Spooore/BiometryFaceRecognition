#include <algorithm>
#include <cstdio>
#include <iostream>
#include "/root/Documents/Biometria/FaRe/include/PhotosContainer.h"

using namespace std;

void usage(void)
{
    fprintf(stderr,"USAGE\n");
    fprintf(stderr,"Wrong number of arguments\n");
    exit(EXIT_FAILURE);
}


int main(int argc, char** argv)
{
  if(argc!=3) usage();
  PhotosContainer photo(argv[1],1920,1080);
  photo.medianFilter(13);
  waitKey(0);
  return 0;
}
