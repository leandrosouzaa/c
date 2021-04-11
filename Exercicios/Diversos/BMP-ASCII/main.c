#include <stdio.h>
#include <stdlib.h>

typedef struct BmpFileHeader {
   char bfType[2];
   unsigned int bfSize;
   unsigned short int __bfReserved1;
   unsigned short int __bfReserved2;
   unsigned int bfOffBits;
} __attribute__ ((packed)) BMPFILEHEADER; 

typedef struct BmpImageHeader {
   unsigned int biSize;
   int biWidth;
   int biHeight;
   unsigned short int biPlanes;
   unsigned short int biBitCount;
   unsigned int biCompression;
   unsigned int biSizeImage;
   int biXPelsPerMeter;
   int biYPelPerMeter;
   unsigned int biClrUsed;
   unsigned int biClrImportant;  
} __attribute__ ((packed)) BMPIMAGEHEADER;

typedef struct Rgb {
   unsigned char blue;
   unsigned char green;
   unsigned char red;
} __attribute__ ((packed)) RGB;

typedef struct Image {
   int height;
   int width;
   RGB **rgb;
} IMAGE;

IMAGE readImage(FILE *file,int height, int width) {
   IMAGE picture;
   picture.rgb = (RGB**) malloc(height*sizeof(void*));
   
   picture.height = height;
   picture.width = width;

   int bytestoraged = ((24*width+31)/32)*4;
   int numberOfRGB = bytestoraged/sizeof(RGB) + 1;

   for(int i=height-1; i>=0; i--) {
      picture.rgb[i] = (RGB*) malloc(numberOfRGB*sizeof(RGB));
      fread(picture.rgb[i],1, bytestoraged, file);
   }

   return picture;
}

void freeImage(IMAGE picture) {
   for(int i=picture.height-1; i>=0; i--) {
      free(picture.rgb[i]);
   }
   free(picture.rgb);

}

void printFileHeader(BMPFILEHEADER fileHeader) {
   printf("\nType: %c%c.\n", fileHeader.bfType[0],fileHeader.bfType[1]);
   printf("Size: %d.\n", fileHeader.bfSize);
};

void printImageHeader(BMPIMAGEHEADER imageHeader) {
   printf("\nSize of header: %d.\n", imageHeader.biSize);
   printf("Width: %d.\n", imageHeader.biWidth);
   printf("Height: %d.\n", imageHeader.biHeight);
   printf("Color Planes: %d.\n", imageHeader.biPlanes);
   printf("Bits per Pixel: %d.\n", imageHeader.biBitCount);
   printf("Compression: %d.\n", imageHeader.biCompression);
   printf("Image size: %d.\n", imageHeader.biSizeImage);
   printf("Number color map: %d.\n", imageHeader.biClrUsed);
   printf("Number of significant colors: %d.\n", imageHeader.biClrImportant);
}

char grayScale(RGB rgb) {
   return ((0.3 * rgb.red) + (0.59 * rgb.green) + (0.11 * rgb.blue));
}

void RGBImageToGrayscale(IMAGE picture) {
   int i, j;
   for(i=0; i<picture.height;i++) {
      for(j=0;j<picture.width; j++) {
         picture.rgb[i][j].red = picture.rgb[i][j].green = picture.rgb[i][j].blue = grayScale(picture.rgb[i][j]);
      }
   }
}

void imageToText(IMAGE img) {
   unsigned char gs;

   int textPixel[] = {64, 35, 37, 79, 97, 45, 46, 32};

   FILE *destiny = fopen("test.txt", "w");

   if(!destiny) {
      printf("deu pau");
   }

   for(int i=0; i <img.height; i++) {
      for(int j=0; j<img.width; j++) {
         gs = grayScale(img.rgb[i][j]);
         fputc(textPixel[7-gs/32], destiny);
      }
      fputc(10, destiny);
   }
   fclose(destiny);

}

int createBWImage(BMPFILEHEADER header, BMPIMAGEHEADER imageHeader, IMAGE picture) {
   FILE *fp = fopen("new.bmp", "w");
   if(!fp) {
      printf("Erro na conversão para preto e branco. \n");
      return 1;
   }
   fwrite(header.bfType, 2, 1, fp);
   fwrite(&header.bfSize, 3*sizeof(int), 1, fp);
   fwrite(&imageHeader, sizeof(imageHeader), 1, fp);

   RGBImageToGrayscale(picture);

   for(int i=picture.height-1;i>=0;i--) {
      fwrite(picture.rgb[i],((24*picture.width+31)/32)*4, 1, fp);
   }

   fclose(fp);

   return 0;
}


int main(int argc, char* argv[]) {
   printf("Conversor de BMP para ASCII - Leandro Ribeiro de Souza \n\n");

   FILE *fp;
   BMPFILEHEADER header;
   BMPIMAGEHEADER imageHeader;
   RGB pixel;

   fp = fopen(argv[1], "rb");

   if(!fp) {
      printf("Não foi possível abrir o arquivo %s.", "quadrado.bmp");
      fclose(fp);
      return 1;
   }

   fread(&header, sizeof(BMPFILEHEADER), 1, fp);

   printf("File header information:");
   printFileHeader(header);

   if(header.bfType[0] != 'B' || header.bfType[1] != 'M') {
      printf("O arquivo %s não é um BMP válido.", "quadrado.bmp");
      return 1;
   }

   fread(&imageHeader, sizeof(BMPIMAGEHEADER), 1, fp);
   
   printf("\nImage header information:");
   printImageHeader(imageHeader);

   if(imageHeader.biCompression != 0 || imageHeader.biBitCount != 24) {
      printf("O arquivo %s não é um BMP válido.", "quadrado.bmp");
      fclose(fp);
      return 1;
   }

   fseek(fp, header.bfOffBits, SEEK_SET);
   IMAGE image = readImage(fp, imageHeader.biHeight, imageHeader.biWidth);

   createBWImage(header, imageHeader, image);
   imageToText(image);

   fclose(fp);
   freeImage(image);
   return 0;
}