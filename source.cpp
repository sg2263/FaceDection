cv2.destroyAllWindows()


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//download harcascade functions, here we use the frontal_face function
	CascadeClassifier faceCascade;
	faceCascade.load('haarcascade_frontalface_default.xml');

	//capture video from default source
	VideoCapture cap(0);

	while (true)
	{
		//capture frame from the video
		Mat frame;
		bool flag = cap.read(frame);

		//show the frame
		imshow('frame', frame);
		Mat gray;
		cvtColor(frame, gray, COLOR_BGR2GRAY);

		//detect faces
		vector<Rect> faces;
		faceCascade.detectMultiScale(gray, faces, 1.1, 5);

		//draw rectangles on the detected faces
		for (int i = 0; i < faces.size(); i++)
		{
			Rect face = faces[i];
			rectangle(frame, Point(face.x, face.y),
				Point(face.x + face.width, face.y + face.height),
				Scalar(255, 0, 0), 2);
		}

		//wait for 30 milisecond
		int k = waitKey(30) & 0xff;

		//break loop
		if (k == ord('q'))
			break;
	}

	//release capture and destroy all windows
	cap.release();
	destroyAllWindows();
	return 0;
}
