// raaVector.h: interface for the raaVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAAVECTOR_H__55B3E555_FDA9_4CCA_AD89_72D28EE612D6__INCLUDED_)
#define AFX_RAAVECTOR_H__55B3E555_FDA9_4CCA_AD89_72D28EE612D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "raaUtilitiesDefs.h"

#include "raaMatrix.h"

class RAAUTILITIES_DLL_DEF raaVector
{
public:
	raaVector(unsigned int uiDim=4);
	raaVector(float fX, float fY, float fZ);
	raaVector(float fX, float fY, float fZ, float fA);
	raaVector(float* pVector, unsigned int uiContainedVector=0);
	raaVector(raaVector &v, unsigned int uiContainedVector=0);
	//	raaVector(raaVector &v);
	virtual ~raaVector(void);

	void print();

	void set(float fX, float fY, float fZ, float fA=1.0);
	void set(float* pVector, unsigned int uiSize);
	void set(const float* pVector, unsigned int uiSize);
	float* get();

	unsigned int getDim();

	bool isContained();

	float& operator[](unsigned int uiIndex);
	raaVector& operator=(raaVector &v);
	bool operator==(raaVector &v);

	raaVector mult(raaMatrix &r);
	raaVector operator*(raaMatrix &r);


	raaVector operator+(raaVector &v);
	raaVector operator-(raaVector &v);
	raaVector& operator+=(raaVector &v);
	raaVector& operator-=(raaVector &v);
	raaVector operator+(float f);
	raaVector operator-(float f);
	raaVector& operator+=(float f);
	raaVector& operator-=(float f);
	raaVector operator*(raaVector &v);
	raaVector operator*(float f);
	raaVector& operator*=(raaVector &v);
	raaVector& operator*=(float f);
	raaVector operator/(raaVector &v);
	raaVector operator/(float f);
	raaVector& operator/=(raaVector &v);
	raaVector& operator/=(float f);

	float dot(raaVector &v);
	float operator|(raaVector &v);

	raaVector cross(raaVector &v);
	raaVector operator^(raaVector &v);

	float normalise();
	float operator!();

	float length();
	float operator~();

	raaVector slerp(raaVector v, float fStep);

	static raaVector normal(raaVector &v0, raaVector &v1, raaVector &v2);
	static float planeRayIntersection(raaVector vRayStart, raaVector vRayEnd, raaVector vPlaneNormal, float fPlaneDist);
	static int planeBoxIntersection(raaVector *pvBoxArray, unsigned int *auiBoxIndexArray, raaVector vPlaneNormal, float fPlaneDist, float *adHits);

	raaVector project(raaVector vDir, float fLen);
protected:
	float *m_afVector;
	float m_f;
	bool m_bContainedVector;
	unsigned int m_uiDim;
};
#endif // !defined(AFX_RAAVECTOR_H__55B3E555_FDA9_4CCA_AD89_72D28EE612D6__INCLUDED_)


/*// raaVector.h: interface for the raaVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAAVECTOR_H__55B3E555_FDA9_4CCA_AD89_72D28EE612D6__INCLUDED_)
#define AFX_RAAVECTOR_H__55B3E555_FDA9_4CCA_AD89_72D28EE612D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "raaUtilitiesDefs.h"

#include "raaMatrix.h"

class RAAUTILITIES_DLL_DEF raaVector
{
public:
	raaVector(unsigned int uiDim=4);
	raaVector(float fX, float fY, float fZ);
	raaVector(float fX, float fY, float fZ, float fA);
	raaVector(float* pVector, unsigned int uiContainedVector=0);
	raaVector(raaVector &v, unsigned int uiContainedVector=0);
//	raaVector(raaVector &v);
	virtual ~raaVector(void);

	void print();

	void set(float fX, float fY, float fZ, float fA=1.0);
	void set(unsigned int uiIndex, float f);
	float* get();

	unsigned int getDim();

	bool isContained();

	float& operator[](unsigned int uiIndex);
	raaVector& operator=(raaVector &v);
	bool operator==(raaVector &v);

	raaVector mult(raaMatrix &r);
	raaVector operator*(raaMatrix &r);


	raaVector operator+(raaVector &v);
	raaVector operator-(raaVector &v);
	raaVector& operator+=(raaVector &v);
	raaVector& operator-=(raaVector &v);
	raaVector operator+(float f);
	raaVector operator-(float f);
	raaVector& operator+=(float f);
	raaVector& operator-=(float f);
	raaVector operator*(raaVector &v);
	raaVector operator*(float f);
	raaVector& operator*=(raaVector &v);
	raaVector& operator*=(float f);
	raaVector operator/(raaVector &v);
	raaVector operator/(float f);
	raaVector& operator/=(raaVector &v);
	raaVector& operator/=(float f);

	float dot(raaVector &v);
	float operator|(raaVector &v);

	raaVector cross(raaVector &v);
	raaVector operator^(raaVector &v);

	float normalise();
	float operator!();

	float length();
	float operator~();

	raaVector slerp(raaVector v, float fStep);
	raaVector slerpByDir(raaVector v, float fStep);

	static raaVector normal(raaVector &v0, raaVector &v1, raaVector &v2);
	static float planeRayIntersection(raaVector vRayStart, raaVector vRayEnd, raaVector vPlaneNormal, float fPlaneDist);
	static int planeBoxIntersection(raaVector *pvBoxArray, unsigned int *auiBoxIndexArray, raaVector vPlaneNormal, float fPlaneDist, float *adHits);

	raaVector project(raaVector vDir, float fLen);
	void proj(raaVector &vStart, raaVector &vDir, float fLen);
protected:
	float *m_afVector;
	float m_f;
	bool m_bContainedVector;
	unsigned int m_uiDim;
};
#endif // !defined(AFX_RAAVECTOR_H__55B3E555_FDA9_4CCA_AD89_72D28EE612D6__INCLUDED_)
*/