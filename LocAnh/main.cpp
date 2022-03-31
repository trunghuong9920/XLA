#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
#include <algorithm>
using namespace std;
using namespace cv;

const int Max = 50;
int a[Max][Max], K[Max][Max], b[Max][Max], matrix[Max];
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
	cout << "Nhap ma tran mat na: \n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << "K[" << i << "][" << j << "] = "; cin >> K[i][j];
		}
	}
	cout << "\nMa tran anh la: \n";
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nMa tran mat na:\n";
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			cout << K[i][j] << "\t";
		}
		cout << endl;
	}

}

void tuongquan_1(Mat img) {
	cout << "Nhan Chap:\n";

	int tong = 0;
	for (int x = 1; x <= 8; x++) {
		for (int y = 1; y < 8; y++) {
			int tg = 0;
			int sg = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + img.at<uchar>(x + i, y + j);
					sg += img.at<uchar>(x + i, y + j);
				}
			}
			cout << (double)tong / (sqrt(9) * sqrt(sg)) << "\t";
			tong = 0;
		}
		cout << "\n";
	}
}
void nhanchap_1(Mat img) {
	cout << "Nhan Chap:\n";

	int tong = 0;
	for (int x = 1; x <= 8; x++) {
		for (int y = 1; y < 8; y++) {
			int tg = 0;
			int sg = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + img.at<uchar>(x - i, y - j);
					sg += img.at<uchar>(x - i, y - j);
				}
			}
			cout << (double)tong / (sqrt(9) * sqrt(sg)) << "\t";
			tong = 0;
		}
		cout << "\n";
	}
}

void Fillter(Mat img) {
	Mat image = img.clone();
	int n, m;
	cout << "Nhap kich thuoc bo loc: ";
	cout << "\nChieu rong = "; cin >> n;
	cout << "Chieu cao = "; cin >> m;
	int temp = n / 2;
	for (int x = temp; x < img.rows - temp; x++) {
		for (int y = temp; y < img.cols - temp; y++) {
			int tong = 0;
			for (int i = -temp; i < n - temp; i++) {
				for (int j = -temp; j < m - temp; j++) {
					tong = tong + img.at<uchar>(x + i, y + j);
				}
			}
			image.at<uchar>(x, y) = tong / (n * m);
		}
	}
	imshow("After Fillter", image);

}

void MedFillter(Mat img) {
	Mat image = img.clone();
	int n, m;
	cout << "Nhap kich thuoc bo loc: ";
	cout << "\nChieu rong = "; cin >> n;
	cout << "Chieu cao = "; cin >> m;
	int temp = n / 2;
	int centrel = n * m / 2;
	for (int x = temp; x < img.rows - temp; x++) {
		for (int y = temp; y < img.cols - temp; y++) {
			vector<int> matrix;

			for (int i = -temp; i < n - temp; i++) {
				for (int j = -temp; j < m - temp; j++) {
					matrix.push_back(img.at<uchar>(x + i, y + j));
				}
			}
			sort(matrix.begin(), matrix.end());

			image.at<uchar>(x, y) = matrix.at(centrel);
		}
	}
	imshow("After Fillter", image);

}

void tuongquan_2() {
	int tong = 0;
	cout << "\nMa tran phep tuong quan: \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {

			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x + i][y + j] * K[i][j];
				}
			}
			cout << tong << "\t";
			tong = 0;
		}
		cout << endl;
	}

	cout << "\nChua hoa Ma tran phep tuong quan: \n";
	float temp1 = 0;
	float temp2 = 0;
	float chuanhoa = 0;
	float max = 0;

	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x + i][y + j] * K[i][j];
					temp1 = temp1 + pow(K[i][j], 2);
					temp2 = temp2 + pow(a[x + i][y + j], 2);
				}
			}
			chuanhoa = (tong * 1.0) / (sqrt(temp1) * sqrt(temp2));
			cout << fixed << chuanhoa << "\t";
			if (max < chuanhoa) {
				max = chuanhoa;
			}
			tong = 0;
			chuanhoa = 0;
			temp1 = 0;
			temp2 = 0;
		}
		cout << endl;
	}
	cout << "Vung anh khop voi mau nhat: " << max;

}
void nhanchap_2() {
	int tong = 0;
	cout << "\nMa tran phep nhan chap: \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {

			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x - i][y - j] * K[i][j];
				}
			}
			cout << tong << "\t";
			tong = 0;
		}
		cout << endl;
	}

	cout << "\nChua hoa Ma tran phep nhan chap: \n";
	float temp1 = 0;
	float temp2 = 0;
	float chuanhoa = 0;
	float max = 0;

	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x - i][y - j] * K[i][j];
					temp1 = temp1 + pow(K[i][j], 2);
					temp2 = temp2 + pow(a[x - i][y - j], 2);
				}
			}
			chuanhoa = (tong * 1.0) / (sqrt(temp1) * sqrt(temp2));
			cout << fixed << chuanhoa << "\t";
			if (max < chuanhoa) {
				max = chuanhoa;
			}
			tong = 0;
			chuanhoa = 0;
			temp1 = 0;
			temp2 = 0;
		}
		cout << endl;
	}
	cout << "Vung anh khop voi mau nhat: " << max;

}
void loctrungbinh_2() {
	int tong = 0;
	cout << "\nMa tran loc trung binh: \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {
			int temp= 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x + i][y + j] * K[i][j];
					temp += K[i][j];
				}
			}
			cout << round((double)tong / temp) << "\t";
			tong = 0;
		}
		cout << endl;
	}
}

bool comp(const int a, const int b) {
	return a < b;
}

void loctrungvi_2() {
	vector<int> matrix;
	cout << "\nMa tran loc trung vi: \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {

			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					matrix.push_back(a[x + i][y + j] * K[i][j]);
				}
			}
			sort(matrix.begin(), matrix.end());
			cout << matrix.at(4) << " ";
			matrix.clear();
		}
		cout << endl;

	}
	
}

int main() {
	Mat img = imread("D://Documents//XLA//TH//Loc_anh//new4.png", 0);
	//imshow("Show IMG", img);

	/*for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << (int)img.at<uchar>(i, j) << " ";
		}
		cout << endl;
	}*/
	/*Mat dst;
	int h[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	Mat k(3, 3, CV_8UC1, h);
	filter2D(img, dst, -1, k, Point(-1,-1),0,4);		
	blur(img, dst, Size(3, 3), Point(-1, -1), 4);		//loc trung binh
	imshow("fillter", dst);


	medianBlur(img, dst, 5);						//loc trung vi
	imshow("Medianfillter", dst);

	GaussianBlur(img, dst, Size(3, 3), 1, 4);
	imshow("Gaussfillter", dst);*/

	//tuongquan_1(img);
	nhapmatran();
	//loctrungvi_2();
	tuongquan_2();
	//nhanchap_2();
	//loctrungbinh_2();
	//Fillter(img);
	//MedFillter(img);
	waitKey();
	return 0;
}