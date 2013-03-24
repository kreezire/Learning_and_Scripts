#include <highgui.h>
#include<cv.h>

IplImage* doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5)
{
    assert(in->width%2==0&& in->height%2==0);
    IplImage* out = cvCreateImage(cvSize(in->width/2,in->height/2),in->depth,in->nChannels);
    cvPyrDown(in,out);
    return out;

}

int main()
{
    char ch[] ="C:\\Users\\Administrator\\Pictures\\2011-07-30\\001.jpg";
    cvNamedWindow("input", CV_WINDOW_AUTOSIZE );
    cvNamedWindow("output",CV_WINDOW_AUTOSIZE);
    IplImage *image = cvLoadImage(ch);
     cvShowImage("input",image);

    IplImage *imageout= doPyrDown(image);
    cvSmooth(imageout, imageout, CV_GAUSSIAN, 3, 3);

    cvShowImage("output",imageout);
    cvWaitKey(0);
    cvReleaseImage(&imageout);
    cvReleaseImage(&image);
    cvDestroyWindow("input");
    cvDestroyWindow("output");

}
