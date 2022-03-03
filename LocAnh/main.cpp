#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
using namespace std;
using namespace cv;

const int Max = 50;
int a[Max][Max], K[Max][Max], b[Max][Max];
int n, m;

void nhapmatran() {
	cout << "Nhap ma tran anh: ";
	cout << "\nSo hang: ";
	cin >> m;
	cout << "So cot: ";
	cin >> n;
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++) {
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
			cout <<a[i][j]<<"\t";
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
			cout << (double)tong/(sqrt(9) * sqrt(sg)) << "\t";
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
void Loctrungbinh_1(Mat img) {
	cout << "Loc trung binh:\n";

	int tong = 0;
	for (int x = 1; x <= 8; x++) {
		for (int y = 1; y < 8; y++) {
			int tg = 0;
			int sg = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + img.at<uchar>(x + i, y + j);
				}
			}
			cout << (double)tong / 9 << "\t";
			tong = 0;
		}
		cout << "\n";
	}
}

void tuongquan_2() {
	int tong = 0;
	cout << "\nMa tran phep tuong quan: \n";
	for (int x = 1; x < n + 1; x++) {
		for (int y = 1; y < m + 1; y++) {
			
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x + i][y + j]*K[i][j];
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
			cout << fixed<<chuanhoa << "\t";
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

			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					tong = tong + a[x + i][y + j] * K[i][j];
				}
			}
			cout << round((double)tong/9) << "\t";
			tong = 0;
		}
		cout << endl;
	}
}

int main() {
	Mat img = imread("D://Documents//XLA//TH//Loc_anh//new.jpg", 1);
	//imshow("Show IMG", img);
	/*
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << (int)img.at<uchar>(i, j) << " ";
		}
		cout << endl;
	}
	*/
	//tuongquan_1(img);

	nhapmatran();
	//tuongquan_2();
	//nhanchap_2();
	loctrungbinh_2();
	//Loctrungbinh_1(img);
	waitKey();
	return 0;
}