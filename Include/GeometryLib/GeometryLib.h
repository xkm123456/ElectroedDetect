#ifndef _GEOMETRYLIB_H_
#define _GEOMETRYLIB_H_

#include "Public.h"

/*********************************************************
              所有几何类的接口函数
**********************************************************/
DLLAPI float     STDCALL DotDotDis(CvPoint Point1, CvPoint Point2);
DLLAPI CvLineObj STDCALL DotDotLine(CvPoint Point1, CvPoint Point2);
DLLAPI bool      STDCALL DotDotToLine(CvPoint Point1, CvPoint Point2, CvLineObj& outLine);
DLLAPI double    STDCALL DotDotAngle(CvPoint Point1, CvPoint Point2, int AngleRange);
DLLAPI bool      STDCALL DotDotToAngle(CvPoint Point1, CvPoint Point2, double& Angle);

DLLAPI float     STDCALL DotLineDis(CvPoint Point, CvLineObj InLine);
DLLAPI float     STDCALL LineLineDis(CvLineObj InLine1, CvLineObj InLine2);
DLLAPI float     STDCALL DotLineDisAbs(CvPoint Point, CvLineObj InLine);
DLLAPI float     STDCALL LineLineDotDis(CvLineObj InLine1, CvLineObj InLine2);
DLLAPI CvPoint   STDCALL LineLineIntersection(CvLineObj InLine1, CvLineObj InLine2);
DLLAPI CvPointF  STDCALL LineLineIntersectionF(CvLineObj InLine1, CvLineObj InLine2);
DLLAPI float     STDCALL LineLineIncludeAngle(CvLineObj InLine1, CvLineObj InLine2, int AngleRangle);

DLLAPI CvPoint   STDCALL DotLineInterPoint(CvPoint Point, CvLineObj InLine);

DLLAPI CvLineObj STDCALL DotLineVertLine(CvPoint Point, CvLineObj InLine);
DLLAPI CvLineObj STDCALL DotLineHoriLine(CvPoint Point, CvLineObj InLine);
DLLAPI CvPoint   STDCALL GetThirdCvLinePoint(CvPoint FirstPoint, CvPoint SecondPoint, CvPoint ThirdPoint);

DLLAPI double STDCALL  LineAngleByLinePara(double sinAValue, double cosBValue, int AngleRangle);
DLLAPI CvPoint STDCALL CalculateLinePoint(CvLineObj h1, int TempValue, bool IsYValue);

DLLAPI float STDCALL MaxPoint2Line(CvLineObj h1, CvLineObj h2);
DLLAPI float STDCALL MinPoint2Line(CvLineObj h1, CvLineObj h2);
DLLAPI float STDCALL MinPoint2Point(CvLineObj h1, CvLineObj h2);

DLLAPI void STDCALL CalculateRectToNorm_Aotu(int RectHeight, int RectWidth, int NormHeight, int NormWidth);
DLLAPI void STDCALL CalculateNormToRect_Aotu(int NormHeight, int NormWidth, int RectHeight, int RectWidth);

DLLAPI void STDCALL Resize_Interpolate_RectToNorm(IplImage* src, IplImage* mask);
DLLAPI void STDCALL Resize_Interpolate_NormToRect(IplImage* src, IplImage* mask);

#ifdef UPPROCESS
   #ifndef GEOMETRYLIB_IMPLEMENT
      #pragma comment(lib, "GeometryLib.lib")
   #endif
#endif

#endif  //_GEOMETRYLIB_H_