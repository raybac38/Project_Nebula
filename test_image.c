
#include <stdio.h>
#include <stdlib.h>
#include "picture.h"

int main(int argc, char * argv[])
{

    if(argc != 4)
    {
        printf("invalid argument \n ./test_image width hight filename\n");
        exit(EXIT_FAILURE);
    }

    unsigned width = atoi(argv[1]);
    unsigned hight = atoi(argv[2]);

    Picture * picture = InitPicture(width, hight);

    for (unsigned j = 0; j < hight; j++)
    {
        for (unsigned i = 0; i < width; i++)
        {
            SetPicturePixelValue(picture, i,j,'r', (char)((i + j) % 255));
            SetPicturePixelValue(picture, i,j,'g', (char)((i) % 255));
            SetPicturePixelValue(picture, i,j,'b', (char)((j) % 255));
        }
        
    }
    WritePicture(picture, &argv[3]);

    FreePicture(&picture);
    
}