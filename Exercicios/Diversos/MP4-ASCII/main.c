#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define W 72
#define H 54

unsigned char grayScale(unsigned char red, unsigned char green, unsigned char blue) {
   return ((0.3 * red) + (0.59 * green) + (0.11 * blue));
}

int main(int argc, char* argv[]) {
   printf("Conversor de MP4 para ASCII - Leandro Ribeiro de Souza \n\n");
   if(argc < 3) {
      printf("Missing Param.\n");
      printf("%s <fileName> <frameTime>.\n", argv[0]);
   };

   unsigned char frame[H][W][3] = {0};

   int x, y, count, gray;
   char open[400] = "ffmpeg -i ", frameTime[100] = "sleep ";

   strcat(open ,argv[1]);
   strcat(open ," -f image2pipe -vcodec rawvideo -pix_fmt rgb24 -hide_banner -");
   
   strcat(frameTime ,argv[2]);

   // FILE *pipein = popen(open, "r");
   FILE *pipein = popen(open, "r");
   FILE *fileout = fopen("output.txt", "w");

   if(fileout == NULL) {
      printf("Erro na abertura do arquivo.");
      return 1;
   }

   int textPixel[] = {64, 35, 37, 79, 97, 45, 46, 32};
   int i = 0;

   while(1) {
      count = fread(frame, 1, H*W*3, pipein);
      if (count != H*W*3) break;
      for (y=0 ; y<H ; ++y) {
         for (x=0 ; x<W ; ++x) {
            gray = grayScale(frame[y][x][0], frame[y][x][1], frame[y][x][2]);
            fputc(textPixel[7-gray/32], fileout);
         }
         fputc(10, fileout);
      }
      fputc('f', fileout);
   }

   fclose(fileout);

   fileout = fopen("output.txt", "r");
   char temp = fgetc(fileout);
   while(temp != EOF) {
      if(temp == 'f') {
         system(frameTime);
         system("clear");
      } else {
         printf("%c", temp);
      }
      temp = fgetc(fileout);
   }


   fflush(pipein);
   pclose(pipein);
   fflush(fileout);
   fclose(fileout);
   return 0;
}