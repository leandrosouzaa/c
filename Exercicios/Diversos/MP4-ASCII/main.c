#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define W 72
#define H 54

char grayScale(unsigned char red, unsigned char green, unsigned char blue) {
   return ((0.3 * red) + (0.59 * green) + (0.11 * blue));
}

int main() {
   unsigned char frame[H][W][3] = {0};

   int x, y, count;
   char gray;
   FILE *pipein = popen("ffmpeg -i bad-apple.mp4 -f image2pipe -vcodec rawvideo -pix_fmt rgb24 -hide_banner -loglevel error -", "r");
   FILE *pipeout = popen("ffmpeg -y -f rawvideo -vcodec rawvideo -pix_fmt rgb24 -s 72x54 -r 25 -i - -f mp4 -q:v 5 -an -vcodec mpeg4 output.mp4", "w");

   int textPixel[] = {64, 35, 37,32};
   int i = 0;

   while(1) {
      count = fread(frame, 1, H*W*3, pipein);
      if (count != H*W*3) break;
      printf("\n");
      for (y=0 ; y<H ; ++y) {
         for (x=0 ; x<W ; ++x) {
            gray = grayScale(frame[y][x][0], frame[y][x][1], frame[y][x][2]);
            // printf("%c",textPixel[3-gray/32]);
            printf("%d", gray);
         }
         printf("\n");
      }
      sleep(1);

      // fwrite(frame, 1, H*W*3, pipeout);
   }

   fflush(pipein);
   pclose(pipein);
   fflush(pipeout);
   pclose(pipeout);
   return 0;
}