/*********************************************
所有的内存管理的封装函数---vector
***********************************************/

#ifndef _LISTARRAY_LIB_H_
#define _LISTARRAY_LIB_H_

#include "CSIItemStruct.h"

/*****************ListInt*********************************/
DLLAPI void* STDCALL MallocArrayInt();
DLLAPI void  STDCALL AddArrayInt(ArrayInt* IntArray, int IntValue);
DLLAPI void  STDCALL InsertArrayInt(ArrayInt* IntArray, int InsertIndex, int IntValue);
DLLAPI void  STDCALL EraseArrayInt(ArrayInt* IntArray, int Index);
DLLAPI void  STDCALL ClearArrayInt(ArrayInt* IntArray);
DLLAPI void  STDCALL FreeArrayInt(ArrayInt* IntArray);
DLLAPI void  STDCALL CopyArrayInt(ArrayInt* dstArray, ArrayInt* srcArray);

/****************Char*结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayChar();
DLLAPI void  STDCALL AddArrayChar(ArrayChar* charArray, char* charValue);
DLLAPI void  STDCALL InsertArrayChar(ArrayChar* charArray, int InsertIndex, char* charValue);
DLLAPI void  STDCALL EraseArrayChar(ArrayChar* charArray, int Index);
DLLAPI void  STDCALL ClearArrayChar(ArrayChar* charArray);
DLLAPI void  STDCALL FreeArrayChar(ArrayChar* charArray);
DLLAPI void  STDCALL CopyArrayChar(ArrayChar* dstArray, ArrayChar* srcArray);

/****************Float结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayFloat();
DLLAPI void  STDCALL AddArrayFloat(ArrayFloat* FloatArray, float FloatValue);
DLLAPI void  STDCALL InsertArrayFloat(ArrayFloat* FloatArray, int InsertIndex, float FloatValue);
DLLAPI void  STDCALL EraseArrayFloat(ArrayFloat* FloatArray, int Index);
DLLAPI void  STDCALL ClearArrayFloat(ArrayFloat* FloatArray);
DLLAPI void  STDCALL FreeArrayFloat(ArrayFloat* FloatArray);
DLLAPI void  STDCALL CopyArrayFloat(ArrayFloat* dstArray, ArrayFloat* srcArray);

/****************Point结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayPoint();
DLLAPI void  STDCALL AddArrayPoint(ArrayPoint* PointArray, CvPoint Point);
DLLAPI void  STDCALL InsertArrayPoint(ArrayPoint* PointArray, int InsertIndex, CvPoint Point);
DLLAPI void  STDCALL EraseArrayPoint(ArrayPoint* PointArray, int Index);
DLLAPI void  STDCALL ClearArrayPoint(ArrayPoint* PointArray);
DLLAPI void  STDCALL FreeArrayPoint(ArrayPoint* PointArray);
DLLAPI void  STDCALL CopyArrayPoint(ArrayPoint* dstArray, ArrayPoint* srcArray);
DLLAPI void  STDCALL CopyArrayPointForNotFreeSrc(ArrayPoint* dstArray, ArrayPoint* srcArray);

/****************Rect结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayRect();
DLLAPI void  STDCALL AddArrayRect(ArrayRect* RectArray, CvRect Rect);
DLLAPI void  STDCALL InsertArrayRect(ArrayRect* RectArray, int InsertIndex, CvRect Rect);
DLLAPI void  STDCALL EraseArrayRect(ArrayRect* RectArray, int Index);
DLLAPI void  STDCALL ClearArrayRect(ArrayRect* RectArray);
DLLAPI void  STDCALL FreeArrayRect(ArrayRect* RectArray);
DLLAPI void  STDCALL CopyArrayRect(ArrayRect* dstArray, ArrayRect* srcArray);

/****************PointF结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayPointF();
DLLAPI void  STDCALL AddArrayPointF(ArrayPointF* PointArray, CvPointF Point);
DLLAPI void  STDCALL InsertArrayPointF(ArrayPointF* PointArray, int InsertIndex, CvPointF Point);
DLLAPI void  STDCALL EraseArrayPointF(ArrayPointF* PointArray, int Index);
DLLAPI void  STDCALL ClearArrayPointF(ArrayPointF* PointArray);
DLLAPI void  STDCALL FreeArrayPointF(ArrayPointF* PointArray);
DLLAPI void  STDCALL CopyArrayPointF(ArrayPointF* dstArray, ArrayPointF* srcArray);

/****************VectorD结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayVectorD();
DLLAPI void  STDCALL AddArrayVectorD(ArrayVectorD* VectorArray, VectorD Vector);
DLLAPI void  STDCALL InsertArrayVectorD(ArrayVectorD* VectorArray, int InsertIndex, VectorD Vector);
DLLAPI void  STDCALL EraseArrayVectorD(ArrayVectorD* VectorArray, int Index);
DLLAPI void  STDCALL ClearArrayVectorD(ArrayVectorD* VectorArray);
DLLAPI void  STDCALL FreeArrayVectorD(ArrayVectorD* VectorArray);
DLLAPI void  STDCALL CopyArrayVectorD(ArrayVectorD* dstVectorArray, ArrayVectorD* srcVectorArray);

/****************RectObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayRectObj();
DLLAPI void  STDCALL AddArrayRectObj(ArrayRectObj* RectArray, CvRectObj RectObj);
DLLAPI void  STDCALL InsertArrayRectObj(ArrayRectObj* RectArray, int InsertIndex, CvRectObj RectObj);
DLLAPI void  STDCALL EraseArrayRectObj(ArrayRectObj* RectArray, int Index);
DLLAPI void  STDCALL ClearArrayRectObj(ArrayRectObj* RectArray);
DLLAPI void  STDCALL FreeArrayRectObj(ArrayRectObj* RectArray);
DLLAPI void  STDCALL CopyArrayRectObj(ArrayRectObj* dstArray, ArrayRectObj* srcArray);

/****************LineObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayLineObj();
DLLAPI void  STDCALL AddArrayLineObj(ArrayLineObj* LineObjArray, CvLineObj LineObj);
DLLAPI void  STDCALL InsertArrayLineObj(ArrayLineObj* LineObjArray, int InsertIndex, CvLineObj LineObj);
DLLAPI void  STDCALL EraseArrayLineObj(ArrayLineObj* LineObjArray, int Index);
DLLAPI void  STDCALL ClearArrayLineObj(ArrayLineObj* LineObjArray);
DLLAPI void  STDCALL FreeArrayLineObj(ArrayLineObj* LineObjArray);
DLLAPI void  STDCALL CopyArrayLineObj(ArrayLineObj* dstArray, ArrayLineObj* srcArray);

/****************StreakObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayStreakObj();
DLLAPI void  STDCALL AddArrayStreakObj(ArrayStreakObj* StreakObjArray, CvStreakObj StreakObj);
DLLAPI void  STDCALL InsertArrayStreakObj(ArrayStreakObj* StreakObjArray, int InsertIndex, CvStreakObj StreakObj);
DLLAPI void  STDCALL EraseArrayStreakObj(ArrayStreakObj* StreakObjArray, int Index);
DLLAPI void  STDCALL ClearArrayStreakObj(ArrayStreakObj* StreakObjArray);
DLLAPI void  STDCALL FreeArrayStreakObj(ArrayStreakObj* StreakObjArray);
DLLAPI void  STDCALL CopyArrayStreakObj(ArrayStreakObj* dstArray, ArrayStreakObj* srcArray);

/****************CircleObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayCircleObj();
DLLAPI void  STDCALL AddArrayCircleObj(ArrayCircleObj* CircleArray, CvCircleObj Circle);
DLLAPI void  STDCALL InsertArrayCircleObj(ArrayCircleObj* CircleArray, int InsertIndex, CvCircleObj Circle);
DLLAPI void  STDCALL EraseArrayCircleObj(ArrayCircleObj* CircleArray, int Index);
DLLAPI void  STDCALL ClearArrayCircleObj(ArrayCircleObj* CircleArray);
DLLAPI void  STDCALL FreeArrayCircleObj(ArrayCircleObj* CircleArray);
DLLAPI void  STDCALL CopyArrayCircleObj(ArrayCircleObj* dstArray, ArrayCircleObj* srcArray);

/****************CircleLoopObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayCircleLoopObj();
DLLAPI void  STDCALL AddArrayCircleLoopObj(ArrayCircleLoopObj* CircleLoopArray, CvCircleLoopObj CircleLoop);
DLLAPI void  STDCALL InsertArrayCircleLoopObj(ArrayCircleLoopObj* CircleLoopArray, int InsertIndex, CvCircleLoopObj CircleLoop);
DLLAPI void  STDCALL EraseArrayCircleLoopObj(ArrayCircleLoopObj* CircleLoopArray, int Index);
DLLAPI void  STDCALL ClearArrayCircleLoopObj(ArrayCircleLoopObj* CircleLoopArray);
DLLAPI void  STDCALL FreeArrayCircleLoopObj(ArrayCircleLoopObj* CircleLoopArray);
DLLAPI void  STDCALL CopyArrayCircleLoopObj(ArrayCircleLoopObj* dstLoopArray, ArrayCircleLoopObj* srcLoopArray);

/****************ArcObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayArcObj();
DLLAPI void  STDCALL AddArrayArcObj(ArrayArcObj* ArcArray, CvArcObj Arc);
DLLAPI void  STDCALL InsertArrayArcObj(ArrayArcObj* ArcArray, int InsertIndex, CvArcObj Circle);
DLLAPI void  STDCALL EraseArrayArcObj(ArrayArcObj* ArcArray, int Index);
DLLAPI void  STDCALL ClearArrayArcObj(ArrayArcObj* ArcArray);
DLLAPI void  STDCALL FreeArrayArcObj(ArrayArcObj* ArcArray);
DLLAPI void  STDCALL CopyArrayArcObj(ArrayArcObj* dstArray, ArrayArcObj* srcArray);

/****************ArcLoopObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayArcLoopObj();
DLLAPI void  STDCALL AddArrayArcLoopObj(ArrayArcLoopObj* ArcArray, CvArcLoopObj ArcLoop);
DLLAPI void  STDCALL InsertArrayArcLoopObj(ArrayArcLoopObj* ArcLoopArray, int InsertIndex, CvArcLoopObj ArcLoop);
DLLAPI void  STDCALL EraseArrayArcLoopObj(ArrayArcLoopObj* ArcArray, int Index);
DLLAPI void  STDCALL ClearArrayArcLoopObj(ArrayArcLoopObj* ArcArray);
DLLAPI void  STDCALL FreeArrayArcLoopObj(ArrayArcLoopObj* ArcArray);
DLLAPI void  STDCALL CopyArrayArcLoopObj(ArrayArcLoopObj* dstArray, ArrayArcLoopObj* srcArray);

/****************CvEllipseObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayEllipseObj();
DLLAPI void  STDCALL AddArrayEllipseObj(ArrayEllipseObj* EllipseArray, CvEllipseObj EllipseObj);
DLLAPI void  STDCALL InsertArrayEllipseObj(ArrayEllipseObj* EllipseArray, int InsertIndex, CvEllipseObj EllipseObj);
DLLAPI void  STDCALL EraseArrayEllipseObj(ArrayEllipseObj* EllipseArray, int Index);
DLLAPI void  STDCALL ClearArrayEllipseObj(ArrayEllipseObj* EllipseArray);
DLLAPI void  STDCALL FreeArrayEllipseObj(ArrayEllipseObj* EllipseArray);
DLLAPI void  STDCALL CopyArrayEllipseObj(ArrayEllipseObj* dstArray, ArrayEllipseObj* srcArray);

/****************CvBlobInfo结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayBlobInfo();
DLLAPI void  STDCALL AddArrayBlobInfo(ArrayBlobInfo* BlobInfoArray, CvBlobInfo BlobInfoValue);
DLLAPI void  STDCALL InsertArrayBlobInfo(ArrayBlobInfo* BlobInfoArray, int InsertIndex, CvBlobInfo BlobInfoValue);
DLLAPI void  STDCALL EraseArrayBlobInfo(ArrayBlobInfo* BlobInfoArray, int Index);
DLLAPI void  STDCALL ClearArrayBlobInfo(ArrayBlobInfo* BlobInfoArray);
DLLAPI void  STDCALL FreeArrayBlobInfo(ArrayBlobInfo* BlobInfoArray);
DLLAPI void  STDCALL CopyArrayBlobInfo(ArrayBlobInfo* dstArray, ArrayBlobInfo* srcArray);

/****************CvMarkPara结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayMarkPara();
DLLAPI void  STDCALL AddArrayMarkPara(ArrayMarkPara* MarkParaArray, CvMarkPara MarkParaValue);
DLLAPI void  STDCALL InsertArrayMarkPara(ArrayMarkPara* MarkParaArray, int InsertIndex, CvMarkPara MarkParaValue);
DLLAPI void  STDCALL EraseArrayMarkPara(ArrayMarkPara* MarkParaArray, int Index);
DLLAPI void  STDCALL ClearArrayMarkPara(ArrayMarkPara* MarkParaArray);
DLLAPI void  STDCALL FreeArrayMarkPara(ArrayMarkPara* MarkParaArray);
DLLAPI void  STDCALL CopyArrayMarkPara(ArrayMarkPara* dstArray, ArrayMarkPara* srcArray);

/****************CvEdgePara结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayEdgePara();
DLLAPI void  STDCALL AddArrayEdgePara(ArrayEdgePara* EdgeParaArray, CvEdgePara EdgeParaValue);
DLLAPI void  STDCALL InsertArrayEdgePara(ArrayEdgePara* EdgeParaArray, int InsertIndex, CvEdgePara EdgeParaValue);
DLLAPI void  STDCALL EraseArrayEdgePara(ArrayEdgePara* EdgeParaArray, int Index);
DLLAPI void  STDCALL ClearArrayEdgePara(ArrayEdgePara* EdgeParaArray);
DLLAPI void  STDCALL FreeArrayEdgePara(ArrayEdgePara* EdgeParaArray);
DLLAPI void  STDCALL CopyArrayEdgePara(ArrayEdgePara* dstArray, ArrayEdgePara* srcArray);

/****************BlobObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayBlobObj();
DLLAPI void  STDCALL AddArrayBlobObj(ArrayBlobObj* BlobObjArray, CvBlobObj BlobObj);
DLLAPI void  STDCALL InsertArrayBlobObj(ArrayBlobObj* BlobObjArray, int InsertIndex, CvBlobObj BlobObj);
DLLAPI void  STDCALL EraseArrayBlobObj(ArrayBlobObj* BlobObjArray, int Index);
DLLAPI void  STDCALL ClearArrayBlobObj(ArrayBlobObj* BlobObjArray);
DLLAPI void  STDCALL FreeArrayBlobObj(ArrayBlobObj* BlobObjArray);
DLLAPI void  STDCALL CopyArrayBlobObj(ArrayBlobObj* dstArray, ArrayBlobObj* srcArray);

/****************TargetObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayTargetObj();
DLLAPI void  STDCALL AddArrayTargetObj(ArrayTargetObj* TargetObjArray, CvTargetObj TargetObj);
DLLAPI void  STDCALL InsertArrayTargetObj(ArrayTargetObj* TargetObjArray, int InsertIndex, CvTargetObj TargetObj);
DLLAPI void  STDCALL EraseArrayTargetObj(ArrayTargetObj* TargetObjArray, int Index);
DLLAPI void  STDCALL ClearArrayTargetObj(ArrayTargetObj* TargetObjArray);
DLLAPI void  STDCALL FreeArrayTargetObj(ArrayTargetObj* TargetObjArray);
DLLAPI void  STDCALL CopyArrayTargetObj(ArrayTargetObj* dstArray, ArrayTargetObj* srcArray);

/****************TargetGroupObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayTargetGroupObj();
DLLAPI void  STDCALL AddArrayTargetGroupObj(ArrayTargetGroupObj* TargetGroupObjArray, CvTargetGroupObj TargetGroupObj);
DLLAPI void  STDCALL InsertArrayTargetGroupObj(ArrayTargetGroupObj* TargetGroupObjArray, int InsertIndex, CvTargetGroupObj TargetGroupObj);
DLLAPI void  STDCALL EraseArrayTargetGroupObj(ArrayTargetGroupObj* TargetGroupObjArray, int Index);
DLLAPI void  STDCALL ClearArrayTargetGroupObj(ArrayTargetGroupObj* TargetGroupObjArray);
DLLAPI void  STDCALL FreeArrayTargetGroupObj(ArrayTargetGroupObj* TargetGroupObjArray);
DLLAPI void  STDCALL CopyArrayTargetGroupObj(ArrayTargetGroupObj* dstArray, ArrayTargetGroupObj* srcArray);

/****************OCRObj结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayOCRObj();
DLLAPI void  STDCALL AddArrayOCRObj(ArrayOCRObj* OCRObjArray, CvOCRObj OCRObj);
DLLAPI void  STDCALL InsertArrayOCRObj(ArrayOCRObj* OCRObjArray, int InsertIndex, CvOCRObj OCRObj);
DLLAPI void  STDCALL EraseArrayOCRObj(ArrayOCRObj* OCRObjArray, int Index);
DLLAPI void  STDCALL ClearArrayOCRObj(ArrayOCRObj* OCRObjArray);
DLLAPI void  STDCALL FreeArrayOCRObj(ArrayOCRObj* OCRObjArray);
DLLAPI void  STDCALL CopyArrayOCRObj(ArrayOCRObj* dstArray, ArrayOCRObj* srcArray);

/****************PointPair结构的遍历函数*******************/
DLLAPI void* STDCALL MallocArrayPointPair();

DLLAPI void STDCALL AddArrayPointPair(ArrayPointPair* PointArray, PointPair Point);

DLLAPI void STDCALL InsertArrayPointPair(ArrayPointPair* PointArray, int InsertIndex, PointPair Point);

DLLAPI void STDCALL EraseArrayPointPair(ArrayPointPair* PointArray, int Index);

DLLAPI void STDCALL ClearArrayPointPair(ArrayPointPair* PointArray);

DLLAPI void STDCALL FreeArrayPointPair(ArrayPointPair* PointArray);

DLLAPI void STDCALL CopyArrayPointPair(ArrayPointPair* dstArray, ArrayPointPair* srcArray);


#ifdef UPPROCESS
#ifndef LISTARRAYLIB_IMPLEMENT
#pragma comment(lib, "ListArrayLib.lib")
#endif
#endif

#endif //_LISTARRAY_LIB_H_