#include<cv.h>
#include<highgui.h>

int main()
{
    char ch[] ="a.jpg";
    cvNamedWindow("input", CV_WINDOW_AUTOSIZE );
    cvNamedWindow("output",CV_WINDOW_AUTOSIZE);
    IplImage *image = cvLoadImage(ch);
     cvShowImage("input",image);

    IplImage *imageout= cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);
    cvSmooth(image, imageout, CV_GAUSSIAN, 3, 3);

    cvShowImage("output",imageout);
    cvWaitKey(0);
    cvReleaseImage(&imageout);
    cvReleaseImage(&image);
    cvDestroyWindow("input");
    cvDestroyWindow("output");

}
