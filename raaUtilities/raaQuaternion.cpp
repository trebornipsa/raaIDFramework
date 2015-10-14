#include <math.h>

#include "raaQuaternion.h"

raaQuaternion::raaQuaternion(float fW, raaVector vV)
{
	set(fW, vV);
}

raaQuaternion::raaQuaternion(void)
{
	m_fW=0.0f;
}

raaQuaternion::~raaQuaternion(void)
{
}

raaQuaternion& raaQuaternion::operator=(raaQuaternion &r)
{
	m_vV=r.v();
	m_fW=r.w();

	return r;
}

float& raaQuaternion::w()
{
	return m_fW;
}

raaVector& raaQuaternion::v()
{
	return m_vV;
}

void raaQuaternion::set(float fW, raaVector vV)
{
	m_fW=fW;
	m_vV=vV;

}

raaQuaternion raaQuaternion::add(raaQuaternion &q)
{
	return raaQuaternion(m_fW+q.w(), m_vV+q.v());
}

raaQuaternion raaQuaternion::operator+(raaQuaternion &q)
{
	return raaQuaternion(m_fW+q.w(), m_vV+q.v());
}

raaQuaternion raaQuaternion::mult(raaQuaternion &q)
{
	return raaQuaternion(m_fW*q.w()-(m_vV|q.v()), m_vV^q.v()+m_vV*q.w()+q.v()*m_fW);
}

raaQuaternion raaQuaternion::operator*(raaQuaternion &q)
{
	return raaQuaternion(m_fW*q.w()-(m_vV|q.v()), m_vV^q.v()+m_vV*q.w()+q.v()*m_fW);
}

raaQuaternion raaQuaternion::normalise()
{
	float f=m_fW*m_fW+!m_vV;

	return raaQuaternion(m_fW/f, m_vV/f);
}

raaQuaternion raaQuaternion::operator!()
{
	float f=m_fW*m_fW+!m_vV;

	return raaQuaternion(m_fW/f, m_vV/f);
}

void raaQuaternion::fromAngleAxis(float fAngle, raaVector &vAxis)
{
	m_fW=cos(fAngle/2.0f);
	m_vV=vAxis*sin(fAngle/2.0f);
}

void raaQuaternion::fromMatrix(raaMatrix &m)
{
	float  tr, s, q[4];
	int    i, j, k;


	int nxt[3] = {1, 2, 0};


	tr = m[raaMatrix::index(0,0)] + m[raaMatrix::index(1,1)] + m[raaMatrix::index(2,2)];


	// check the diagonal
	if (tr > 0.0) {
		s = sqrt (tr + 1.0);
		m_fW = s / 2.0;
		s = 0.5 / s;

		m_vV.set((m[raaMatrix::index(2,1)] - m[raaMatrix::index(1,2)]) * s, (m[raaMatrix::index(0,2)] - m[raaMatrix::index(2,0)]) * s, (m[raaMatrix::index(1,0)] - m[raaMatrix::index(0,1)]) * s);
	} else {		
		// diagonal is negative
		i = 0;
		if (m[raaMatrix::index(1,1)] > m[raaMatrix::index(0,0)]) i = 1;
		if (m[raaMatrix::index(2,2)] > m[raaMatrix::index(i,i)]) i = 2;
		j = nxt[i];
		k = nxt[j];


		s = sqrt ((m[raaMatrix::index(i,i)] - (m[raaMatrix::index(j,j)] + m[raaMatrix::index(k,k)])) + 1.0);

		q[i] = s * 0.5;

		if (s != 0.0) s = 0.5 / s;


		q[3] = (m[raaMatrix::index(k,j)] - m[raaMatrix::index(j,k)]) * s;
		q[j] = (m[raaMatrix::index(j,i)] + m[raaMatrix::index(i,j)]) * s;
		q[k] = (m[raaMatrix::index(k,i)] + m[raaMatrix::index(i,k)]) * s;


		m_vV.set(q[0], q[1], q[2]);
		m_fW=q[3];
	}
}

raaMatrix raaQuaternion::toMatrix()
{
	raaMatrix m;


	float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;


	// calculate coefficients
	x2 = m_vV[0] + m_vV[0];
	y2 = m_vV[1] + m_vV[1];
	z2 = m_vV[2] + m_vV[2];
	xx = m_vV[0] * x2; 
	xy = m_vV[0] * y2; 
	xz = m_vV[0] * z2;
	yy = m_vV[1] * y2; 
	yz = m_vV[1] * z2;
	zz = m_vV[2] * z2;
	wx = m_fW * x2; 
	wy = m_fW * y2;
	wz = m_fW * z2;

	m[raaMatrix::index(0,0)] = 1.0f - (yy + zz); m[raaMatrix::index(0,1)] = xy - wz;
	m[raaMatrix::index(0,2)] = xz + wy; m[raaMatrix::index(0,3)] = 0.0f;

	m[raaMatrix::index(1,0)] = xy + wz; 
	m[raaMatrix::index(1,1)] = 1.0f - (xx + zz);
	m[raaMatrix::index(1,2)] = yz - wx; 
	m[raaMatrix::index(1,3)] = 0.0f;

	m[raaMatrix::index(2,0)] = xz - wy; 
	m[raaMatrix::index(2,1)] = yz + wx;
	m[raaMatrix::index(2,2)] = 1.0f - (xx + yy); 
	m[raaMatrix::index(2,3)] = 0.0f;

	m[raaMatrix::index(3,0)] = 0.0f; 
	m[raaMatrix::index(3,1)] = 0.0f;
	m[raaMatrix::index(3,2)] = 0.0f; 
	m[raaMatrix::index(3,3)] = 1.0f;

	return m;
}

