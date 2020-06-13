
#pragma once
#ifdef FaceLIBDLL
#define FACEAPI _declspec(dllexport)
#else
#define FACEAPI  _declspec(dllimport)
#endif
//可以include需要用到的头文件
class FACEAPI FaceRecognizer
{
public:
	FaceRecognizer();
	~FaceRecognizer();
	void ConfirmTest();
};