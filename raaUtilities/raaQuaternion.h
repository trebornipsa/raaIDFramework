#pragma once

#include "raaUtilitiesDefs.h"

#include "raaMatrix.h"
#include "raaVector.h"

class RAAUTILITIES_DLL_DEF raaQuaternion
{
public:
	raaQuaternion(void);
	raaQuaternion(float fW, raaVector vV);
	virtual ~raaQuaternion(void);

	raaQuaternion& operator=(raaQuaternion &r);

	float& w();
	raaVector& v();

	void set(float fW, raaVector vV);

	raaQuaternion add(raaQuaternion &q);
	raaQuaternion operator+(raaQuaternion &q);

	raaQuaternion mult(raaQuaternion &q);
	raaQuaternion operator*(raaQuaternion &q);

	raaQuaternion normalise();
	raaQuaternion operator!();

	void fromAngleAxis(float fAngle, raaVector &vAxis);
	void fromMatrix(raaMatrix &m);
	raaMatrix toMatrix();

protected:
	float m_fW;
	raaVector m_vV;

};
