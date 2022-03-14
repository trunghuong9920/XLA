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
			image.at<uchar>(x, y) = abs(totalG1) +abs(totalG2);
		}
	}
	imshow("After Fillter", image);
}
int main() {
	Mat img = imread("D://Documents//XLA//TH//new6.png", 0);
	//imshow("Show IMG", img);
	//nhapmatran();
	nhapmatranimg();
	//nhanchap_2();
	dobien(img);
	waitKey();
	return 0;
}