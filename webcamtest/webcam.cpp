#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Open the default camera (usually 0)
    VideoCapture cap(0);
    
    // Check if camera opened successfully
    if (!cap.isOpened()) {
        cout << "Error: Could not open camera." << endl;
        return -1;
    }
    
    // Load the cascade classifier
    CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_default.xml")) {
        cout << "Error: Could not load face cascade classifier." << endl;
        return -1;
    }
    
    Mat frame;
    
    while (true) {
        // Capture frame from camera
        cap >> frame;
        
        // Check if frame is empty
        if (frame.empty()) {
            cout << "Error: Could not capture frame." << endl;
            break;
        }

        // Flip the frame vertically (mirror effect)
        flip(frame, frame, 1);  // 1 for horizontal flip (mirror), 0 for vertical, -1 for both
        
        // Convert frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        
        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale(
            gray,
            faces,
            1.1,     // Scale factor
            6,       // Minimum neighbors
            0,       // Flags
            Size(60, 60) // Minimum face size
        );
        
        // Draw rectangles around detected faces
        for (const auto& face : faces) {
            rectangle(frame, 
                     face, 
                     Scalar(0, 255, 0), // Green color in BGR
                     2);                // Line thickness
        }
        
        // Display the frame
        imshow("Face Detection", frame);
        
        // Break the loop if 'q' is pressed
        if (waitKey(1) == 'q') {
            break;
        }
    }
    
    // Release the camera and destroy windows
    cap.release();
    destroyAllWindows();
    
    return 0;
}