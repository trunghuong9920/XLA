#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
#include <algorithm>
using namespace std;
using namespace cv;

const int Max = 50;
int a[Max][Max], K1[Max][Max], K2[Max][Max], b[Max][Max], matrix[Max],G1[Max][Max],G2[Max][Max];
int n, m;

void nhapmatran() {
	cout << "Nhap ma tran anh: ";
	cout << "\nSo hang: ";
	cin >> m;
	cout << "So cot: ";
	cin >> n;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			a[i][j] = 0;
		}
	}
	cout << "Nhap ma tran anh: \n";
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
		}
	}
	cout << "Nhap ma tran mat na 1: \n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << "K[" << i << "][" << j << "] = "; cin >> K1[i][j];
		}
	}
	cout << "Nhap ma tran mat na 2: \n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << "K[" << i << "][" << j << "] = "; cin >> K2[i][j];
		}
	}
	cout << "\nMa tran anh la: \n";
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nMa tran mat na 1:\n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << K1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nMa tran mat na 2:\n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << K2[i][j] << "\t";
		}
		cout << endl;
	}

}

void nhanchap_2() {
	cout << "\nG1 = : \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {
			int tong = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x + i][y + j] * K1[i][j];
				}
			}
			G1[x][y] = abs(tong);
			cout << abs(tong) << "\t";
		}
		cout << endl;
	}
	cout << "\nG2 = : \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {
			int tong = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x + i][y + j] * K2[i][j];
				}
			}
			cout << abs(tong) << "\t";
			G2[x][y] = abs(tong);
		}
		cout << endl;
	}
	cout << "\nKet Qua bien Robert: \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {
			cout << G1[x][y] + G2[x][y] << " ";
		}
		cout << endl;
	}
}
void nhapmatranimg() {
	cout << "Nhap ma tran mat na 1: \n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << "K[" << i << "][" << j << "] = "; cin >> K1[i][j];
		}
	}
	cout << "Nhap ma tran mat na 2: \n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << "K[" << i << "][" << j << "] = "; cin >> K2[i][j];
		}
	}
	cout << "\nMa tran anh la: \n";
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nMa tran mat na 1:\n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << K1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nMa tran mat na 2:\n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << K2[i][j] << "\t";
		}
		cout << endl;
	}

}
void dobien(Mat img) {
	Mat image = img.clone();

	for (int x = 1; x < img.rows - 1; x++) {
		for (int y = 1; y < img.cols - 1; y++) {
			int totalG1 = 0;
			int totalG2 = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					totalG1 = totalG1 + img.at<uchar>(x + i, y + j) * K1[i][j];
				}
			}
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					totalG2 = totalG2 + img.at<uchar>(x + i, y + j) * K2[i][j];
				}
			}
			image.at<uchar>(x, y) = abs(totalG1) + abs(totalG2);

		}
	}
	imshow("After Fillter", image);
}
void Laplace(string name, Mat img) {

	Mat image = img.clone();
	cout << "Nhap ma tran mat na 1: \n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << "K[" << i << "][" << j << "] = "; cin >> K1[i][j];
		}
	}
	for (int x = 1; x < img.rows - 1; x++) {
		for (int y = 1; y < img.cols - 1; y++) {
			int totalG1 = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					totalG1 = totalG1 + img.at<uchar>(x + i, y + j) * K1[i][j];
				}
			}
			
			image.at<uchar>(x, y) = abs(totalG1);

		}
	}
	imshow(name, image);
}
int main() {
	Mat img = imread("D://Documents//XLA//TH//Dobien//bs2.jpg", 1);
	//imshow("Show IMG", img);
	nhapmatran();
	//nhapmatranimg();
	nhanchap_2();
	//dobien(img);
	// 
	/*Mat dst, dst1, dst2;

	Mat h1(3, 3, CV_8S, Scalar(0));
	Mat h2(3, 3, CV_8S, Scalar(0));
	h1.at<schar>(1, 1) = h2.at<schar>(1, 2) = -1;
	h1.at<schar>(2, 2) = h2.at<schar>(2, 1) = 1;
	filter2D(img, dst1, -1, h1, Point(-1, -1), 0, 4);
	filter2D(img, dst2, -1, h2, Point(-1, -1), 0, 4);
	dst = dst1 + dst2;
	imshow("filter", dst);*/

	
	//Mat dst1,dst2;
	//Sobel(img, dst1, -1, 1, 0, 3, 1, 0, 4);
	//imshow("Sobe x", dst1);
	//Sobel(img, dst2, -1, 0, 1, 3, 1, 0, 4);
	//imshow("Sobe y", dst2);

	//Mat dstOutput;
	//Canny(img, dst1, 20, 70, 3);
	//imshow("canny", dst1);
	//medianBlur(img, dstOutput, (3,3));						//loc trung vi
	//Laplace("img 1", img);
	//Laplace("Ảnh 2", dst);

	/*img = dstOutput;
	cvtColor(img, img, CV_BGR2GRAY);
	threshold(img, img, 177, 200, THRESH_BINARY);

	vector<vector<Point>> contours;
	Mat contoursImg = img.clone();

	findContours(contoursImg, contours, CV_RETR_LIST, CHAIN_APPROX_SIMPLE);

	Mat dst(img.size(), CV_8UC3, Scalar(0,0,0));
	Scalar colors[3];
	colors[0] = Scalar(255, 0, 0);
	colors[1] = Scalar(0, 255, 0);
	colors[2] = Scalar(0, 0, 255);

	for (size_t i = 0; i < contours.size(); i++)
	{
		drawContours(dst, contours, i, colors[i % 3]);
	}
	imshow("newimg", dst);*/

	waitKey();
	return 0;
}