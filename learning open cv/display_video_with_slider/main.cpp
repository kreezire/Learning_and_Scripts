#include <highgui.h>
//#include<cv.h>


int g_slider_position =0;
CvCapture *g_capture = NULL;

void onTrackbarSlide(int pos){
    cvSetCaptureProperty(
                         g_capture,
                         CV_CAP_PROP_POS_FRAMES,
                         pos
                         );

     }

int main()
{
    char ch[]= "//media//container//Videos you must watch//9990426835.mp4";
    cvNamedWindow("qwerty",CV_WINDOW_NORMAL);
    g_capture = cvCreateFileCapture(ch);
    int frames = (int) cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT);

    if(frames!=0)
    {

        cvCreateTrackbar(
                         "abc",
                         "qwerty",
                         &g_slider_position,
                         frames,
                         onTrackbarSlide);
    }

    IplImage *frame;
    while(1)
    {

        frame= cvQueryFrame(g_capture);
        if(!frame)
            break;
        cvShowImage("qwerty", frame);
        char c= cvWaitKey(33);
        if(c==27)
            break;
    }
    cvReleaseCapture(&g_capture);
    cvDestroyWindow("qwerty");
    return 0;
}
