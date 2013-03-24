#include <highgui.h>

using namespace std;

int main()
{
    char ch[] = "a.jpg";
    IplImage *image = cvLoadImage(ch);
    cvNamedWindow("qwerty", CV_WINDOW_FULLSCREEN);
    cvShowImage("qwerty", image);
    cvWaitKey(1000);
    cvReleaseImage(&image);
    cvDestroyWindow("qwerty");
    return 0;
}
