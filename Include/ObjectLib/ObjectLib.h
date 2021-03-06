#ifndef _OBJECTLIB_H_
#define _OBJECTLIB_H_

#include "Public.h"

/*********************************************************
              所有对象类的接口函数
**********************************************************/
DLLAPI int STDCALL FitCircleObj(ListPoint PointSet, CvCircleObj* OutCircle);
DLLAPI void STDCALL RansacCirclePoint(ListPoint PointSet, ListPoint* BestPoint, ListPoint* TempPoint);
DLLAPI void STDCALL RansacCirclePointForLess(ListPoint PointSet, ListPoint* BestPoint, ListPoint* TempPoint);
DLLAPI void STDCALL CalculateCirclePara(ListPoint PointSet, CvCircleObj* outCircle);

DLLAPI void STDCALL FitLineObj(ListPoint PointSet, CvLineObj* outLine);
DLLAPI void STDCALL RansacLinePoint(ListPoint PointSet, ListPoint* BestPoint, ListPoint* TempPoint);
DLLAPI void STDCALL RansacLinePointForLess(ListPoint PointSet, ListPoint* BestPoint, ListPoint* TempPoint);
DLLAPI void STDCALL RansacLinePointForEdge(ListPoint PointSet, ListPoint* BestPoint, ListPoint* TempPoint);
DLLAPI void STDCALL CalculateLinePara(ListPoint PointSet, CvLineObj* outLine, int AngleRangle);

DLLAPI void STDCALL GetConvexPointByListPoint(ListPoint* PointList, ListPoint* ConvexList);
DLLAPI void STDCALL GetMinimumEnclosedRectangle(ListPoint* PointList, CvRectObj* outRect);

DLLAPI void STDCALL QuickHullAlgorithmForListPoint(ListPoint* PointList, ListPoint* ConvexList);

DLLAPI void STDCALL MergeRectListForInt(ListRect* RectList, ListInt* IntList, int deltaValue);
DLLAPI void STDCALL MergeRectListForHeight(ListRect* RectList, ListInt* IntList, int deltaValue);


#ifdef UPPROCESS
#ifndef OBJECTLIB_IMPLEMENT
#pragma comment(lib, "ObjectLib.lib")
#endif
#endif

#endif