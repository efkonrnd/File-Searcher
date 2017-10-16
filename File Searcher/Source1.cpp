#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\imgcodecs\imgcodecs.hpp>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <Windows.h>
#include <regex>



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
	string fo;
	cout << "give the name of folder";
	cin >> fo;
	str2 = str1 + "\/" + fo;

	cout << endl;
	const char * c1 = str2.c_str();
	_mkdir(c1);

	infile.open(in);               //("F:/CAM3 22 APR 2016/ROI/NONSTANDARD/traindata.txt"); 
	int b = 0;
	string previousline = "";
	double a = 0;
//	namedWindow("input", CV_WINDOW_AUTOSIZE);
	string fext;
	cout << "whats the extension for files\[txt/jpg/png]";
	cin >> fext;
	while (b<1)
	{

		getline(infile, STRING);
		if (STRING != previousline)
		{
			previousline = STRING;
			if (fext == "jpg" || fext == "png")
			{
				
				string fullstr = str1 + "\/" + STRING;
				Mat frame;
				frame = imread(fullstr);
				if (frame.data == 0)
				{
					system("pause");
					continue;
				}
				//waitKey(500);
				//imshow("input",frame);
				cout << STRING << endl;

				int p = STRING.length();
				string swri = STRING.substr(0, p - 4);
				imwrite(str2 + "\/" + swri + "."+fext, frame);

				//	destroyWindow("input");
			}
			if (fext == "txt")
			{
				
				cout << STRING << endl;

				int p = STRING.length();
				
				ifstream ifile;
				string filecontent;
				ifile.open(str1 + "\/" + STRING);
				if (!ifile)
				{
					system("pause");
					continue;
				}
				std::getline(ifile, filecontent);
				ifile.close();
				
				ofstream ofile;
				ofile.open(str2 + "\/" + STRING);
				ofile << filecontent;
				ofile.close();

			//	cout << filecontent;
				//	destroyWindow("input");
			}
			
		}

	}
}