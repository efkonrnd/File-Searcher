#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\imgcodecs\imgcodecs.hpp>
#include <iostream>
#include <fstream>
#include <direct.h>



using namespace cv;
using namespace std;

int main()
{
	string STRING;
	string str1;
	cout << "enter the path";
	getline(cin, str1);
	string in = str1 + "\/" + "text.txt";
	cout << endl;
	string str2;

	ifstream infile;
	
	
	str2 = str1 + "\/" + "txn";
	
	cout << endl;
	const char * c1 = str2.c_str();
	_mkdir(c1);
	
	infile.open(in);               //("F:/CAM3 22 APR 2016/ROI/NONSTANDARD/traindata.txt"); 
	int b = 0;
	string previousline = "";
	double a = 0;
	while (b<1)
	{

		getline(infile, STRING);
		if (STRING != previousline)
		{
			previousline = STRING;
			string fullstr = str1 + "\/" + STRING;
			Mat frame;
			frame = imread(fullstr);
			//waitKey(500);
			//	imshow("input",frame);
			cout << STRING << endl;
			
			int p = STRING.length();
			string swri = STRING.substr(0, p - 4);
			string str3 = str2 + "\/" + swri;
			_mkdir(str3.c_str());
			imwrite(str3 + "\/" + swri+".jpg", frame);

		//	destroyWindow("input");
		}
	
	}
}
