
#ifndef _IMAGEPRE_FILE_H_
#define _IMAGEPRE_FILE_H_

#include "Public.h"

/*****************************************
   ImagePre对应的接口函数
*****************************************/
DLLAPI void STDCALL CvAdaptiveStretchImage(CvImage* srcImage, CvRect rect, float lowValue,
	float highValue, CvImage* dstImage);

/*****************************************
      ThresholdPre对应的接口函数
*****************************************/
DLLAPI void STDCALL CvAdaptiveDevision(CvImage* srcImage, int hModel, int wModel, int DiffValue, CvImage* dstImage);

DLLAPI void STDCALL CvFixThreshold(IplImage* srcImage, int threshold, IplImage* dstImage);
DLLAPI void STDCALL CvFixThreshold_Inverse(IplImage* srcImage, int threshold, IplImage* dstImage);

DLLAPI void STDCALL CvAdaptiveDevisionImageByProb(CvImage* srcImage, float MinValue, float MaxValue, CvImage* dstImage);

DLLAPI int STDCALL CvOstuThreshold(CvImage* srcImage, CvImage* dstImage);
DLLAPI int STDCALL OstuThresholdWhite(CvImage* srcImage, int MinThreshold, int MaxThreshold, CvImage* dstImage);
DLLAPI int STDCALL OstuThresholdBlack(CvImage* srcImage, int MinThreshold, int MaxThreshold, CvImage* dstImage);

DLLAPI int STDCALL CvPathContrastForRectImage(CvImage* srcImage, CvRect rect, int PathValue, CvImage* dstImage);

DLLAPI void STDCALL CvPathContrastForMarkImage(CvImage* srcImage, CvImage* markImage, int ObjectGray, int PathValue, CvImage* dstImage);

DLLAPI void STDCALL CvProbDevisionImageByLow(CvImage* srcImage, float MinValue, int deltaValue, CvImage* dstImage);
DLLAPI void STDCALL CvProbDevisionImageByHigh(CvImage* srcImage, float MaxValue, int deltaValue, CvImage* dstImage);

DLLAPI void STDCALL CalculateHistThreshold(int* hist, int Percent, int* Gmin, int* Gmax);
DLLAPI void STDCALL HistThreshold(CvImage* srcImage, int Percent, int hModelNum, int wModelNum, CvImage* dstImage);

/*****************************************
      ImagePre对应的接口函数
*****************************************/
DLLAPI void STDCALL MarkEdgeIplImageForRectBorder(CvImage* srcImage, CvRect rect, int ObjectGray, CvImage* EdgeImage);
DLLAPI void STDCALL MarkEdgeIplImageForRodNum(CvImage* srcImage, CvRect rect, int ObjectGray, CvImage* EdgeImage);

DLLAPI void STDCALL TraceEdgeForIplImageModel(CvImage* srcImage, CvImage* MarkImage, CvRect rect, int MarkValue,
	int hIndex, int wIndex, ListPoint* EdgePoint);

DLLAPI void STDCALL TraceEdgeForIplImageModel2(IplImage* srcImage, IplImage* MarkImage, CvRect rect,
	int MarkValue, int hIndex, int wIndex, ListPoint* EdgePoint);

//提取所有边缘中像素点最多的目标边缘，添加到像素点集合中
DLLAPI int STDCALL ExtractMaxEdgePointNumForItem(CvImage* EdgeImage, CvImage* MarkImage, CvRect rect,
	int ObjectGray, ListPoint* PointList);

DLLAPI void STDCALL ExtractAllLineNumForItem(CvImage* EdgeImage, CvImage* MarkImage, CvRect rect,
	int ObjectGray, ListLineObj* LineList);

//提取所有边缘点，添加到像素点集合中
DLLAPI int STDCALL ExtractAllEdgePointNumForItem(CvImage* EdgeImage, CvImage* MarkImage, CvRect rect,
	int ObjectGray, ListPoint* PointList);

DLLAPI bool STDCALL FilterMaxEdgePointNum(CvImage* EdgeImage, CvImage* MarkImage, 
	CvRect rect, int EdgePointNum, int ObjectGray);

//滤除所有边缘和面积范围外的目标物
DLLAPI void STDCALL FilterEdgeRegionForRect(IplImage* srcImage, IplImage* MarkImage, CvRect rect, int Objectgray,
	int MinMarkNum, int MaxMarkNum, IplImage* dstImage);

//滤除宽度最大值外的所有目标物
DLLAPI void STDCALL FilterHeightWidthRegionForRect(CvImage* srcImage, CvImage* MarkImage, CvRect rect, 
	float MinHeightWidthRatio, int MinMarkNum, int MaxMarkNum, int Objectgray, CvImage* dstImage);

//滤除在设置面积范围之外的所有目标物
DLLAPI void STDCALL FilterBlobNoiseForRect(IplImage* srcImage, IplImage* MarkImage, CvRect rect,
	int Objectgray, int MinMarkNum, int MaxMarkNum, IplImage* dstImage);

DLLAPI void STDCALL FilterMaxBlobNoiseForUpRect(CvImage* srcImage, CvImage* MarkImage, 
	CvRect rect, int Objectgray, int MinMarkNum, int MaxMarkNum, CvImage* dstImage);

//滤除在设置范围之外的所有目标物，将剩余部分添加到ListRect中
DLLAPI void STDCALL FilterRegionListForRect(IplImage* srcImage, IplImage* MarkImage, CvRect rect, int Objectgray,
	int MinMarkNum, int MaxMarkNum, IplImage* dstImage, ListRect* rectList, ListInt* intList);

DLLAPI void STDCALL FilterRegionListForListPoint(CvImage* srcImage, CvImage* MarkImage, CvRect rect, int Objectgray,
	int MinMarkNum, int MaxMarkNum, CvImage* dstImage, ListPoint* PointList);

DLLAPI int STDCALL FilterMaxAreaBlobForRect(CvImage* srcImage, CvImage* MarkImage,
	CvRect rect, int IsFilterEdgeBlob, int MinBlobNum, int MaxBlobNum, int Objectgray,
	CvImage* dstImage, CvPoint* MaxAreaPoint);

DLLAPI bool STDCALL FilterMaxRegionForImage(IplImage* srcImage, IplImage* MarkImage, CvRect rect,
	int Objectgray, IplImage* dstImage, CvRect* ImageRect);

DLLAPI int STDCALL FilterMaxRectRegionForImage(CvImage* srcImage, CvImage* MarkImage, CvRect rect,
	int Objectgray, CvImage* dstImage, int& AllYValue, int& MaxHeight, int& AllXValue, int& MaxWidth);

DLLAPI void STDCALL FilterMaxRegionForRectImage(CvImage* srcImage, CvImage* MarkImage, CvRect rect, 
	int Objectgray, CvImage* dstImage);

DLLAPI int STDCALL FilterEdgeRegionForMaxRect(CvImage* srcImage, CvImage* MarkImage, CvRect rect,
	int Objectgray, CvImage* dstImage);

DLLAPI void STDCALL FilterLaserNoiseForRect(CvImage* srcImage, CvImage* MarkImage, CvRect rect, int Objectgray,
	int MinMarkNum, int AllYValue, int AllHeight, int AllXValue, int AllWidth, CvImage* dstImage);

DLLAPI void STDCALL FilterEdgeRegionRectList(CvImage* srcImage, CvImage* MarkImage, 
	int Objectgray, CvRect rect, int MinMarkNum, int MaxMarkNum, int MinHeightValue, 
	int MaxHeightValue, int MinWidthValue, int MaxWidthValue, CvImage* dstImage,
	ListRect* RectList, ListInt* IntList, ListPoint* PointList, ListRectObj* RectObjList);

DLLAPI void STDCALL FilterBlobNoiseForRatio(CvImage* srcImage, CvImage* MarkImage, 
	CvRect rect, int Objectgray, int MinMarkNum, int MaxMarkNum, CvImage* dstImage);

DLLAPI void STDCALL FilterRectImageForUsualImage(CvImage* currImage, CvImage* adaptImage, 
	CvImage* markImage, CvRect rect, int Objectgray, int deltaValue, int MinMarkNum,
	int MaxMarkNum, CvImage* dstImage);

DLLAPI void STDCALL FilterRectImageForBackImage(CvImage* currImage, CvImage* adaptImage, CvRect rect, int Objectgray);

DLLAPI void STDCALL MarkMaxRegionForImage(CvImage* srcImage, CvImage* MarkImage, CvRect rect, int Objectgray, CvImage* dstImage);

DLLAPI void STDCALL MarkEdgeIplImageForDuanKou(IplImage* srcImage, CvRect rect, int ObjectGray, IplImage* EdgeImage);

DLLAPI int STDCALL ExtractMaxAreaEdgePointForItem(IplImage* EdgeImage,
	IplImage* MarkImage, CvRect rect, int ObjectGray, ListPoint* PointList);

/****************************************************
   Morph  对应接口函数
*****************************************************/
DLLAPI void STDCALL CvDilationImage(IplImage* srcImage, CvRect rect, 
	int hModel, int wModel, int Objectgray, IplImage* dstImage);

DLLAPI void STDCALL CvDilationImage_cvImage(CvImage* srcImage, CvRect rect,
	int hModel, int wModel, int Objectgray, CvImage* dstImage);

DLLAPI void STDCALL CvErosionImage(IplImage* srcImage, CvRect rect, 
	int hModel, int wModel, int Objectgray, IplImage* dstImage);

DLLAPI void STDCALL MorphDilationImage(IplImage* srcImage, CvRect rect, 
	int hModel, int wModel, int Objectgray, IplImage* dstImage);
DLLAPI void STDCALL MorphErosionImage(IplImage* srcImage, CvRect rect, 
	int hModel, int wModel, int Objectgray, IplImage* dstImage);

DLLAPI void STDCALL CvMorphImage_Warp(IplImage* srcImage, CvRect rect,
	int hModel, int wModel, int Objectgray, IplImage* dstImage);

#ifdef UPPROCESS
#ifndef IMAGEPRE_IMPLEMENT
#pragma comment(lib, "ImagePre.lib")
#endif
#endif

#endif  //_IMAGEPRE_FILE_H_
