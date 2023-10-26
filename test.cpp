#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;



void main() {
	VideoCapture video(0);
	CascadeClassifier facedetect;
	facedetect.load("haarcascade_frontalface_default.xml");
	Mat img;
	while (true) {

		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.3, 5);
		cout << faces.size() << endl;
		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 200), 3);
			putText(img, to_string(faces.size()), Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(225, 255, 255), 1);

		}
		imshow("Frame", img);
		waitKey(1);
	 
	}
}
