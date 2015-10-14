#pragma once

#include <ostream>
#include "raaUtilitiesDefs.h"

class raaVector;

class RAAUTILITIES_DLL_DEF raaMatrix
{
public:
	raaMatrix(void);
	raaMatrix(raaMatrix &r);
	raaMatrix(float *f);
	virtual ~raaMatrix(void);

	void set(float *f);
	void set(raaMatrix &r);

	float* get();
	float* row(unsigned int i);

	float& operator[](unsigned int i);
	raaMatrix& operator=(raaMatrix &r);
	
	void identify();
	
	void invert();
	raaMatrix operator!();

	raaMatrix mult(raaMatrix &r, bool bPost=true);
	raaMatrix operator*(raaMatrix &r);

	static unsigned int index(unsigned int uiRow, unsigned int uiCol);
	static void pos(unsigned int uiIndex, unsigned int &uiRow, unsigned int &uiCol);

	void print();
	RAAUTILITIES_DLL_DEF friend std::ostream& operator<<(std::ostream &out, class raaMatrix &v);

	void setRotation(raaVector &vAxis, float fRad);
	void setRotation(raaVector &vRads);
	void rotate(raaVector &vAxis, float fRad, bool bPost=true);
	void rotate(raaVector &vRads);
	void revRotate(raaVector &vRads);
	

	void setTranslation(raaVector &v);
	void translate(raaVector &v, bool bPost=true);

	void setScale(raaVector &v);
	void scale(raaVector &v, bool bPost=true);

	void setFrustrum(float fLeft, float fRight, float fBottom, float fTop, float fNear, float fFar);

	void transpose();

protected:
	float m_afMatrix[16];
	float m_fDef;
};
