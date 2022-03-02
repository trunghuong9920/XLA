#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
using namespace std;
using namespace cv;

int a[50][50], n, m;

void tangsang(Mat img, int c) {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			for (int k = 0; k < 3; k++) {
				img.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[k] + c > 255 ? 255 : img.at<Vec3b>(i, j)[k] + c;

				img.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[k] + c < 0 ? 0 : img.at<Vec3b>(i, j)[k] + c;
			}
		}
	}

	imshow("Tang sang", img);

}

void tuongphan(Mat img, int contrast, int c) {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			for (int k = 0; k < 3; k++) {
				img.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(contrast * (img.at<Vec3b>(i, j)[k]) + c);
			}
		}
	}

	imshow("Tuong phan", img);
	
}
void amban(Mat img) {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			img.at<uchar>(i, j) = 255 - img.at<uchar>(i, j);
		}
	}
}

void dosang(Mat img) {
	float sum = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			for (int k = 0; k < 3; k++) {
				sum += img.at<Vec3b>(i, j)[k] / 255;
			}
		}
	}
	float tb = (sum / img.rows * img.cols);
	cout << "\nDo sang= " << sum;
}
void dotuongphan(Mat img) {
	float sum = 0;
	float sum2 = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			for (int k = 0; k < 3; k++) {
				sum += pow((img.at<Vec3b>(i, j)[k] / 255),2);
				sum2 += img.at<Vec3b>(i, j)[k] / 255;

			}
		}
	}
	float tb = (sum / img.rows * img.cols) - pow((sum2 / img.rows * img.cols), 2);
	cout << "\nTuong phan= " << tb;
}

vector <int>cal_histogram(Mat img) {			//Hàm tính histogarm
	vector <int> h;
	for (int i = 0; i <= 255; i++) h.push_back(0);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			h[img.at<uchar>(i, j)] ++;
		}
	}
	return h;
}

vector <int>eq_histogram(vector<int> h, int L) {			//Hàm cân bằng
	vector <int> eh;
	int tong = 0;
	vector<int> s;

	for (int i = 0; i <= 255; i++) tong+=h[i];
	eh.push_back(h[0]);
	for (int i = 0; i < 256; i++) {
		eh.push_back(eh[i - 1] + h[i]);
		s[i] = (int)eh[i] / tong;
	}
	return eh;
}

int main() {
	Mat img = imread("D:\\Documents\\XLA\\TH\\VD1\\new.jpg", 1);
	//imshow("Demo", img);
	int contrast = 2;
	int c = 10;

	vector<int> h = cal_histogram(img);

	Mat his(300, 300, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 256; i++) {
		line(his, Point(i, 0), Point(i, 300 - h[i] * 0.1), Scalar(255, 255, 255), 1, 8, 0);
	}
	imshow("Histogram", his);
	
	//dosang(img);
	//dotuongphan(img);
	//tangsang(img, c);
	//tuongphan(img, contrast,c);
	//dosang(img);
	//dotuongphan(img);



	//tuongphan(img, contrast, c);

	//am ban


	/*
		imshow("red", kenh[2])
		imshow("green", kenh[0])
		imshow("blue", kenh[0])

	*/
	waitKey();
	return 0;
}
