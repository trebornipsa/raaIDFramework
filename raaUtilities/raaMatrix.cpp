#include <iostream>
#include <math.h>

#include "raaVector.h"
#include "raaMatrix.h"

raaMatrix::raaMatrix(void)
{
	identify();
}

raaMatrix::raaMatrix(raaMatrix &r)
{
	for(int i=0;i<16;i++) m_afMatrix[i]=r[i];
}

raaMatrix::raaMatrix(float *f)
{
	for(int i=0;i<16;i++) m_afMatrix[i]=f[i];	
}


raaMatrix::~raaMatrix(void)
{
}

float& raaMatrix::operator[](unsigned int i)
{
	if(i<16)
		return m_afMatrix[i];
	else
		return m_fDef;
}

float* raaMatrix::get()
{
	return m_afMatrix;
}

void raaMatrix::identify()
{
	for(int i=0;i<16;i++) m_afMatrix[i]=0.0f;

	m_afMatrix[0]=1.0f;
	m_afMatrix[5]=1.0f;
	m_afMatrix[10]=1.0f;
	m_afMatrix[15]=1.0f;
}

float* raaMatrix::row(unsigned int i)
{
	if(i==0)
		return m_afMatrix;
	else if(i==1)
		return &m_afMatrix[4];
	else if(i==2)
		return &m_afMatrix[8];
	else if(i==3)
		return &m_afMatrix[12];
	else
		return &m_fDef;
}

raaMatrix raaMatrix::mult(raaMatrix &r, bool bPost)
{
	raaMatrix m;

	if(bPost)
	{	
		for(unsigned int uiRow=0;uiRow<4;uiRow++)
			for(unsigned int uiCol=0;uiCol<4;uiCol++)
			{
				m[index(uiRow, uiCol)]=m_afMatrix[index(uiRow, 0)]*r[index(0, uiCol)]+m_afMatrix[index(uiRow, 1)]*r[index(1, uiCol)]+m_afMatrix[index(uiRow, 2)]*r[index(2, uiCol)]+m_afMatrix[index(uiRow, 3)]*r[index(3, uiCol)];
			}
	}
	else
	{

		for(unsigned int uiRow=0;uiRow<4;uiRow++)
			for(unsigned int uiCol=0;uiCol<4;uiCol++)
			{
				m[index(uiRow, uiCol)]=r[index(uiRow, 0)]*m_afMatrix[index(0, uiCol)]+r[index(uiRow, 1)]*m_afMatrix[index(1, uiCol)]+r[index(uiRow, 2)]*m_afMatrix[index(2, uiCol)]+r[index(uiRow, 3)]*m_afMatrix[index(3, uiCol)];
			}

	}
	return m;
}

unsigned int raaMatrix::index(unsigned int uiRow, unsigned int uiCol)
{
	return uiRow*4+uiCol;
}

void raaMatrix::pos(unsigned int uiIndex, unsigned int &uiRow, unsigned int &uiCol)
{
	uiCol=uiIndex%4;
	unsigned int uiR=uiIndex-uiCol;

	if(uiR==0) uiRow=0;
	else if(uiR==4) uiRow=1;
	else if(uiR==8) uiRow=2;
	else if(uiR==12) uiRow=3;
	else uiRow=16;
}

raaMatrix& raaMatrix::operator=(raaMatrix &r)
{
	for(int i=0;i<16;i++) m_afMatrix[i]=r[i];

	return r;
}

std::ostream& operator<<(std::ostream &out, class raaMatrix &v)
{

	out<<v[0]<<" "
		<<v[1]<<" "
		<<v[2]<<" "
		<<v[3]<<std::endl
		<<v[4]<<" "
		<<v[5]<<" "
		<<v[6]<<" "
		<<v[7]<<std::endl
		<<v[8]<<" "
		<<v[9]<<" "
		<<v[10]<<" "
		<<v[11]<<std::endl
		<<v[12]<<" "
		<<v[13]<<" "
		<<v[14]<<" "
		<<v[15];

	return out;
}

void raaMatrix::print()
{
	std::cout<<"+++Matrix+++"<<std::endl;
	std::cout<<m_afMatrix[0]<<" "<<m_afMatrix[1]<<" "<<m_afMatrix[2]<<" "<<m_afMatrix[3]<<std::endl;
	std::cout<<m_afMatrix[4]<<" "<<m_afMatrix[5]<<" "<<m_afMatrix[6]<<" "<<m_afMatrix[7]<<std::endl;
	std::cout<<m_afMatrix[8]<<" "<<m_afMatrix[9]<<" "<<m_afMatrix[10]<<" "<<m_afMatrix[11]<<std::endl;
	std::cout<<m_afMatrix[12]<<" "<<m_afMatrix[13]<<" "<<m_afMatrix[14]<<" "<<m_afMatrix[15]<<std::endl;
	std::cout<<"+++Matrix+++"<<std::endl;
}

raaMatrix raaMatrix::operator*(raaMatrix &r)
{
	return mult(r);
}

void raaMatrix::invert()
{
	float a1, b1, c1;
	float a2, b2, c2;
	float a3, b3, c3;
	float i0, i1, i2;
	float t;
	float tx, ty, tz;

	a1 = m_afMatrix[0];
	b1 = m_afMatrix[1];
	c1 = m_afMatrix[2];

	a2 = m_afMatrix[4];
	b2 = m_afMatrix[5];
	c2 = m_afMatrix[6];

	a3 = m_afMatrix[8];
	b3 = m_afMatrix[9];
	c3 = m_afMatrix[10];

	tx = m_afMatrix[12];
	ty = m_afMatrix[13];
	tz = m_afMatrix[14];

	i0 =  ((b2 * c3) - (b3 * c2));
	i1 = -((a2 * c3) - (a3 * c2));
	i2 =  ((a2 * b3) - (a3 * b2));

	t = 1.0f/ ((a1 * i0) + (b1 * i1) + (c1 * i2));

	m_afMatrix[0] = i0 = i0 * t;
	m_afMatrix[4] = i1 = i1 * t;
	m_afMatrix[8] = i2 = i2 * t;
	m_afMatrix[12] = -((tx * i0) + (ty * i1) + (tz * i2));
	m_afMatrix[1] = i0 = -t * ((b1 * c3) - (b3 * c1));
	m_afMatrix[5] = i1 =  t * ((a1 * c3) - (a3 * c1));
	m_afMatrix[9] = i2 = -t * ((a1 * b3) - (a3 * b1));
	m_afMatrix[13] = -((tx * i0) + (ty * i1) + (tz * i2));
	m_afMatrix[2] = i0 =  t * ((b1 * c2) - (b2 * c1));
	m_afMatrix[6] = i1 = -t * ((a1 * c2) - (a2 * c1));
	m_afMatrix[10] = i2 =  t * ((a1 * b2) - (a2 * b1));
	m_afMatrix[14] = -((tx * i0) + (ty * i1) + (tz * i2));
	m_afMatrix[3] = 0.0f;
	m_afMatrix[7] = 0.0f;
	m_afMatrix[11] = 0.0f;
	m_afMatrix[15] = 1.0f;
}

void raaMatrix::setRotation(raaVector &vAxis, float dRad)
{
	float c=cos(dRad);
	float s=sin(dRad);
	float c1=1.0f-c;
	float x=vAxis[0];
	float y=vAxis[1];
	float z=vAxis[2];


	m_afMatrix[0]=c+c1*x*x;
	m_afMatrix[1]=c1*x*y-s*z;
	m_afMatrix[2]=c1*x*z+s*y;
	m_afMatrix[3]=0.0f;

	m_afMatrix[4]=c1*y*x+s*z;
	m_afMatrix[5]=c+c1*y*y;
	m_afMatrix[6]=c1*y*z-s*x;
	m_afMatrix[7]=0.0f;

	m_afMatrix[8]=c1*z*x-s*y;
	m_afMatrix[9]=c1*z*y+s*x;
	m_afMatrix[10]=c+c1*z*z;
	m_afMatrix[11]=0.0f;

	m_afMatrix[12] = 0.0f;
	m_afMatrix[13] = 0.0f;
	m_afMatrix[14] = 0.0f;
	m_afMatrix[15] = 1.0f;

}

void raaMatrix::setRotation(raaVector &vRads)
{
	float cx=cos(vRads[0]);
	float cy=cos(vRads[1]);
	float cz=cos(vRads[2]);
	float sx=sin(vRads[0]);
	float sy=sin(vRads[1]);
	float sz=sin(vRads[2]);

	m_afMatrix[0]=cy*cz;
	m_afMatrix[1]=-cx*sz+sx*sy*cz;
	m_afMatrix[2]=sx*sz+cx*sy*cz;
	m_afMatrix[3]=0.0f;

	m_afMatrix[4]=cy*sz;
	m_afMatrix[5]=cx*cz+sx*sy*sz;
	m_afMatrix[6]=-sx*cz+cx*sy*sz;
	m_afMatrix[7]=0.0f;

	m_afMatrix[8]=-sy;
	m_afMatrix[9]=sx*cy;
	m_afMatrix[10]=cx*cy;
	m_afMatrix[11]=0.0f;

	m_afMatrix[12]=0.0f;
	m_afMatrix[13]=0.0f;
	m_afMatrix[14]=0.0f;
	m_afMatrix[15]=1.0f;
}


void raaMatrix::transpose()
{
	float d1, d2, d3, d6, d7, d11;

	d1=m_afMatrix[1];
	d2=m_afMatrix[2];
	d3=m_afMatrix[3];
	d6=m_afMatrix[6];
	d7=m_afMatrix[7];
	d11=m_afMatrix[11];

	m_afMatrix[1]=m_afMatrix[4];
	m_afMatrix[2]=m_afMatrix[8];
	m_afMatrix[3]=m_afMatrix[12];
	m_afMatrix[6]=m_afMatrix[9];
	m_afMatrix[7]=m_afMatrix[13];
	m_afMatrix[11]=m_afMatrix[14];

	m_afMatrix[4]=d1;
	m_afMatrix[8]=d2;
	m_afMatrix[12]=d3;
	m_afMatrix[9]=d6;
	m_afMatrix[13]=d7;
	m_afMatrix[14]=d11;
}


raaMatrix raaMatrix::operator!()
{
	raaMatrix m(*this);
	m.invert();
	return m;
}

void raaMatrix::rotate(raaVector &vAxis, float dRad, bool bPost)
{
	raaMatrix m;
	m.setRotation(vAxis, dRad);

	*this=mult(m, bPost);
}

void raaMatrix::setTranslation(raaVector &v)
{
	identify();
	m_afMatrix[12]=v[0];
	m_afMatrix[13]=v[1];
	m_afMatrix[14]=v[2];
}

void raaMatrix::translate(raaVector &v, bool bPost)
{
	raaMatrix m;
	m.setTranslation(v);

	set(mult(m, bPost));
}

void raaMatrix::setScale(raaVector &v)
{
	identify();
	m_afMatrix[0]=v[0];
	m_afMatrix[5]=v[1];
	m_afMatrix[10]=v[2];
}

void raaMatrix::scale(raaVector &v, bool bPost)
{
	raaMatrix m;
	m.setScale(v);

	*this=mult(m, bPost);
}

void raaMatrix::setFrustrum(float dLeft, float dRight, float dBottom, float dTop, float dNear, float dFar)
{
	m_afMatrix[0]=(2.0f*dNear)/(dRight-dLeft);
	m_afMatrix[1]=0.0f;
	m_afMatrix[2]=(dRight+dLeft)/(dRight-dLeft);
	m_afMatrix[3]=0.0f;

	m_afMatrix[4]=0.0f;
	m_afMatrix[5]=(2.0f*dNear)/(dTop-dBottom);
	m_afMatrix[6]=(dTop+dBottom)/(dTop-dBottom);
	m_afMatrix[7]=0.0f;

	m_afMatrix[8]=0.0f;
	m_afMatrix[9]=0.0f;
	m_afMatrix[10]=-((dFar+dNear)/(dFar-dNear));
	m_afMatrix[11]=-1.0f;

	m_afMatrix[12]=0.0f;
	m_afMatrix[13]=0.0f;
	m_afMatrix[14]=-((2.0f*dFar*dNear)/(dFar-dNear));
	m_afMatrix[15]=0.0f;
}

void raaMatrix::set(float *d)
{
	for(int i=0;i<16;i++) m_afMatrix[i]=d[i];
}

void raaMatrix::set(raaMatrix &r)
{
	for(int i=0;i<16;i++) m_afMatrix[i]=r[i];	
}

void raaMatrix::rotate(raaVector &vRads)
{
	raaMatrix m, mMe;

	mMe.set(m_afMatrix);
	m=!mMe;
	m.rotate(raaVector(1.0f, 0.0f, 0.0f), vRads[0]);
	set(mMe*m*mMe);

	mMe.set(m_afMatrix);
	m=!mMe;
	m.rotate(raaVector(0.0f, 1.0f, 0.0f), vRads[1]);
	set(mMe*m*mMe);

	mMe.set(m_afMatrix);
	m=!mMe;
	m.rotate(raaVector(0.0f, 0.0f, 1.0f), vRads[2]);
	set(mMe*m*mMe);

}

void raaMatrix::revRotate(raaVector &vRads)
{
	raaMatrix m, mMe;

	mMe.set(m_afMatrix);
	m=!mMe;
	m.rotate(raaVector(0.0f, 0.0f, 1.0f), vRads[2]);
	set(mMe*m*mMe);

	mMe.set(m_afMatrix);
	m=!mMe;
	m.rotate(raaVector(0.0f, 1.0f, 0.0f), vRads[1]);
	set(mMe*m*mMe);

	mMe.set(m_afMatrix);
	m=!mMe;
	m.rotate(raaVector(1.0f, 0.0f, 0.0f), vRads[0]);
	set(mMe*m*mMe);
}
