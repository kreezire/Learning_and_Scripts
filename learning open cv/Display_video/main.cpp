#include <highgui.h>

using namespace std;

int main()
{
    char ch[]= "//media//container//Videos you must watch//9990426835.mp4";
    cvNamedWindow("qwerty",CV_WINDOW_NORMAL);
    CvCapture *capture = cvCreateFileCapture(ch);
    IplImage *frame;
    while(1)
    {

        frame= cvQueryFrame(capture);
        if(!frame)
            break;
        cvShowImage("qwerty", frame);
        char c= cvWaitKey(33);
        if(c==27)
            break;
    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("qwerty");
    return 0;
}
