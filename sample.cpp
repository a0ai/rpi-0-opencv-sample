#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

#ifndef CV_FOURCC
#define CV_FOURCC(a,b,c,d) cv::VideoWriter::fourcc(a,b,c,d)
#endif
int main(){

  // Create a VideoCapture object and use camera to capture the video
  VideoCapture cap(0); 

  // Check if camera opened successfully
  if(!cap.isOpened())
  {
    cout << "Error opening video stream" << endl; 
    return -1; 
  } 

  // Default resolution of the frame is obtained.The default resolution is system dependent. 
  int frame_width = cap.get(CAP_PROP_FRAME_WIDTH); 
  int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT); 
  
  // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file. 
  VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height)); 
  auto frameCounter = 0u;
  while(1)
  { 
    Mat frame; 
    
    // Capture frame-by-frame 
    cap >> frame;

 
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
    
    // Write the frame into the file 'outcpp.avi'
    video.write(frame);
   
    // Display the resulting frame    
    //imshow( "Frame", frame );
 
    // Press  ESC on keyboard to  exit
    frameCounter++;
    if (frameCounter > 300) break;
  }

  // When everything done, release the video capture and write object
  cap.release();
  video.release();

  // Closes all the windows
  destroyAllWindows();
  return 0;
}
