// raaVector.cpp: implementation of the raaVector class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <math.h>
#include "raaVector.h"

//////////////////////////////////////////////////////////////////////
// Construction/festruction
//////////////////////////////////////////////////////////////////////

raaVector::raaVector(unsigned int uiDim)
{
	m_afVector=new float[uiDim];
	m_bContainedVector=false;
	m_uiDim=uiDim;

	if(uiDim==4) m_afVector[3]=1.0f;

	m_f=0.0f;
	set(0.0f, 0.0f, 0.0f);
}
/*
raaVector::raaVector(raaVector &v)
{
m_afVector=new float[3];
m_bContainedVector=false;
m_uiDim=3;

set(v[0], v[1], v[2]);	
}
*/

raaVector::raaVector(float fX, float fY, float fZ)
{
	m_afVector=new float[3];
	m_bContainedVector=false;
	m_uiDim=3;	

	m_f=0.0f;
	set(fX, fY, fZ);
}

raaVector::raaVector(float fX, float fY, float fZ, float fA)
{
	m_afVector=new float[4];
	m_bContainedVector=false;
	m_uiDim=4;

	m_f=0.0f;
	set(fX, fY, fY, fA);
}

raaVector::raaVector(float* pVector, unsigned int uiContainedVector)
{
	if(uiContainedVector)
	{
		m_afVector=pVector;
		m_bContainedVector=true;
		m_uiDim=uiContainedVector;
	}
	else
	{
		m_afVector=new float[4];
		m_bContainedVector=false;
		m_uiDim=4;
		m_afVector[3]=1.0f;

		m_f=0.0f;
		set(pVector[0], pVector[1], pVector[2]);
	}
}

raaVector::raaVector(raaVector &v, unsigned int uiContainedVector)
{
	if(uiContainedVector)
	{
		if(uiContainedVector<=v.getDim())
		{
			m_uiDim=uiContainedVector;
			m_afVector=v.get();
			m_bContainedVector=true;
		}
		else
		{
			m_uiDim=v.getDim();
			m_afVector=v.get();
			m_bContainedVector=true;
		}
	}
	else
	{
		m_uiDim=v.getDim();
		m_afVector=new float[m_uiDim];
		m_bContainedVector=false;

		m_f=0.0f;

		if(m_uiDim==4)
			set(v[0], v[1], v[2], v[3]);
		else
			set(v[0], v[1], v[2]);
	}
}


raaVector::~raaVector(void)
{
	if(!m_bContainedVector) delete [] m_afVector;
}

void raaVector::set(float fX, float fY, float fZ, float fA)
{
	m_afVector[0]=fX;
	m_afVector[1]=fY;
	m_afVector[2]=fZ;

	if(m_uiDim==4)
		m_afVector[3]=fA;
}

void raaVector::set(float* pVector, unsigned int uiSize)
{
	if(pVector)
	{
		m_uiDim=uiSize;
		m_afVector[0]=pVector[0];
		m_afVector[1]=pVector[1];
		m_afVector[2]=pVector[2];

		if(m_uiDim==4) m_afVector[3]=pVector[3];
	}
}

void raaVector::set(const float* pVector, unsigned int uiSize)
{
	if(pVector)
	{
		m_uiDim=uiSize;
		m_afVector[0]=pVector[0];
		m_afVector[1]=pVector[1];
		m_afVector[2]=pVector[2];

		if(m_uiDim==4) m_afVector[3]=pVector[3];
	}
}

float* raaVector::get()
{
	return m_afVector;
}

float& raaVector::operator[](unsigned int uiIndex)
{
	if(uiIndex<m_uiDim)
		return m_afVector[uiIndex];

	return m_f;
}

raaVector& raaVector::operator=(raaVector &v)
{
	if(!isContained() && !v.isContained())
	{
		m_afVector[0]=v[0];
		m_afVector[1]=v[1];
		m_afVector[2]=v[2];

		if(m_uiDim==4 && v.getDim()==4) m_afVector[3]=v[3];
		else if(m_uiDim==4) m_afVector[3]=1.0f;

	}
	else if(isContained() && !v.isContained())
	{
		m_afVector[0]=v[0];
		m_afVector[1]=v[1];
		m_afVector[2]=v[2];

		if(m_uiDim==4 && v.getDim()==4)
			m_afVector[3]=v[3];
	}
	else if(!isContained() && v.isContained())
	{
		delete [] m_afVector;
		m_afVector=v.get();
		m_bContainedVector=true;
		m_uiDim=v.getDim();
	}
	else
	{
		m_afVector=v.get();
		m_uiDim=v.getDim();
	}			

	return v;
}

bool raaVector::isContained()
{
	return m_bContainedVector;
}

bool raaVector::operator==(raaVector &v)
{
	if(fabs(m_afVector[0]-v[0])<0.001f && fabs(m_afVector[1]-v[1])<0.001f && fabs(m_afVector[2]-v[2])<0.001f)
		return true;

	return false;
}

raaVector raaVector::operator+(raaVector &v)
{
	raaVector _v;
	_v[0]=m_afVector[0]+v[0];
	_v[1]=m_afVector[1]+v[1];
	_v[2]=m_afVector[2]+v[2];

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4)
		_v[3]=m_afVector[3]+v[3];

	return _v;
}

raaVector raaVector::operator-(raaVector &v)
{
	raaVector _v;
	_v[0]=m_afVector[0]-v[0];
	_v[1]=m_afVector[1]-v[1];
	_v[2]=m_afVector[2]-v[2];

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4)
		_v[3]=m_afVector[3]-v[3];

	return _v;
}

raaVector& raaVector::operator+=(raaVector &v)
{
	m_afVector[0]+=v[0];
	m_afVector[1]+=v[1];
	m_afVector[2]+=v[2];

	if(m_uiDim==4 && v.getDim()==4)
		m_afVector[3]+=v[3];

	return *this;
}

raaVector& raaVector::operator-=(raaVector &v)
{
	m_afVector[0]-=v[0];
	m_afVector[1]-=v[1];
	m_afVector[2]-=v[2];

	if(m_uiDim==4 && v.getDim()==4)
		m_afVector[3]-=v[3];

	return *this;
}

raaVector raaVector::operator+(float f)
{
	raaVector _v;
	_v[0]=m_afVector[0]+f;
	_v[1]=m_afVector[1]+f;
	_v[2]=m_afVector[2]+f;

	if(m_uiDim==4)
		_v[3]=m_afVector[3]+f;

	return _v;
}

raaVector raaVector::operator-(float f)
{
	raaVector _v;
	_v[0]=m_afVector[0]-f;
	_v[1]=m_afVector[1]-f;
	_v[2]=m_afVector[2]-f;

	if(m_uiDim==4)
		_v[3]=m_afVector[3]-f;

	return _v;
}

raaVector& raaVector::operator+=(float f)
{
	m_afVector[0]+=f;
	m_afVector[1]+=f;
	m_afVector[2]+=f;

	if(m_uiDim==4)
		m_afVector[3]+=f;

	return *this;
}

raaVector& raaVector::operator-=(float f)
{
	m_afVector[0]-=f;
	m_afVector[1]-=f;
	m_afVector[2]-=f;

	if(m_uiDim==4)
		m_afVector[3]-=f;

	return *this;
}

raaVector raaVector::operator*(raaVector &v)
{
	raaVector _v;
	_v[0]=m_afVector[0]*v[0];
	_v[1]=m_afVector[1]*v[1];
	_v[2]=m_afVector[2]*v[2];

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4)
		_v[3]=m_afVector[3]*v[3];

	return _v;
}

raaVector raaVector::operator*(float f)
{
	raaVector _v;
	_v[0]=m_afVector[0]*f;
	_v[1]=m_afVector[1]*f;
	_v[2]=m_afVector[2]*f;

	if(m_uiDim==4)
		_v[3]=m_afVector[3]*f;

	return _v;
}

raaVector& raaVector::operator*=(raaVector &v)
{
	m_afVector[0]*=v[0];
	m_afVector[1]*=v[1];
	m_afVector[2]*=v[2];

	if(m_uiDim==4 && v.getDim()==4)
		m_afVector[3]*=v[3];

	return *this;
}

raaVector& raaVector::operator*=(float f)
{
	m_afVector[0]*=f;
	m_afVector[1]*=f;
	m_afVector[2]*=f;

	if(m_uiDim==4)
		m_afVector[3]*=f;

	return *this;
}

raaVector raaVector::operator/(raaVector &v)
{
	raaVector _v;
	_v[0]=m_afVector[0]/v[0];
	_v[1]=m_afVector[1]/v[1];
	_v[2]=m_afVector[2]/v[2];

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4)
		_v[3]=m_afVector[3]/v[3];

	return _v;
}

raaVector raaVector::operator/(float f)
{
	raaVector _v;
	_v[0]=m_afVector[0]/f;
	_v[1]=m_afVector[1]/f;
	_v[2]=m_afVector[2]/f;

	if(m_uiDim==4 && _v.getDim()==4)
		_v[3]=m_afVector[3]/f;

	return _v;
}

raaVector& raaVector::operator/=(raaVector &v)
{
	m_afVector[0]/=v[0];
	m_afVector[1]/=v[1];
	m_afVector[2]/=v[2];

	if(m_uiDim==4 && v.getDim()==4 )
		m_afVector[3]/=v[3];

	return *this;
}

raaVector& raaVector::operator/=(float f)
{
	m_afVector[0]/=f;
	m_afVector[1]/=f;
	m_afVector[2]/=f;

	if(m_uiDim==4)
		m_afVector[3]/=f;

	return *this;
}

float raaVector::dot(raaVector &v)
{
	return m_afVector[0]+v[0]+m_afVector[1]*v[1]+m_afVector[2]*v[2];
}

float raaVector::operator|(raaVector &v)
{
	return m_afVector[0]*v[0]+m_afVector[1]*v[1]+m_afVector[2]*v[2];
}

raaVector raaVector::cross(raaVector &v)
{
	raaVector _v;

	_v[0]=m_afVector[1]*v[2]-m_afVector[2]*v[1];
	_v[0]=m_afVector[2]*v[0]-m_afVector[0]*v[2];
	_v[0]=m_afVector[0]*v[1]-m_afVector[1]*v[0];

	return _v;
}

raaVector raaVector::operator^(raaVector &v)
{
	raaVector _v;

	_v[0]=m_afVector[1]*v[2]-m_afVector[2]*v[1];
	_v[1]=m_afVector[2]*v[0]-m_afVector[0]*v[2];
	_v[2]=m_afVector[0]*v[1]-m_afVector[1]*v[0];

	return _v;
}

float raaVector::normalise()
{
	float fLen=length();

	m_afVector[0]/=fLen;
	m_afVector[1]/=fLen;
	m_afVector[2]/=fLen;

	return fLen;
}

float raaVector::operator!()
{
	float fLen=length();

	m_afVector[0]/=fLen;
	m_afVector[1]/=fLen;
	m_afVector[2]/=fLen;

	return fLen;
}

float raaVector::length()
{
	return sqrt(m_afVector[0]*m_afVector[0]+m_afVector[1]*m_afVector[1]+m_afVector[2]*m_afVector[2]);
}

float raaVector::operator~()
{
	return sqrt(m_afVector[0]*m_afVector[0]+m_afVector[1]*m_afVector[1]+m_afVector[2]*m_afVector[2]);
}

void raaVector::print()
{
	std::cout << "Vector -> " << m_afVector[0] << " : " << m_afVector[1] << " : " << m_afVector[2] << std::endl;
}

raaVector raaVector::normal(raaVector &v0, raaVector &v1, raaVector &v2)
{
	raaVector a, b, n;

	a=v0-v1;
	b=v2-v1;

	n=a^b;
	!n;

	return n;
}

unsigned int raaVector::getDim()
{
	return m_uiDim;
}

raaVector raaVector::project(raaVector vDir, float fLen)
{
	raaVector v=vDir;

	!v;
	v=v*fLen;

	v[0]=m_afVector[0]+v[0];
	v[1]=m_afVector[1]+v[1];
	v[2]=m_afVector[2]+v[2];

	return v;
}

float raaVector::planeRayIntersection(raaVector vRayStart, raaVector vRayEnd, raaVector vPlaneNormal, float fPlaneDist)
{
	float fLen=-1.0f;

	raaVector vDir=vRayEnd-vRayStart;

	float a, b;

	a=vPlaneNormal|vRayStart;
	b=vPlaneNormal|vDir;

	if(fabs(b)>0.00001f)
	{
		fLen=fPlaneDist-a/b;
	}

	return fLen;
}

int raaVector::planeBoxIntersection(raaVector *pvBoxArray, unsigned int *auiBoxIndexArray, raaVector vPlaneNormal, float fPlaneDist, float *adHits)
{
	int iCount=0;
	if(pvBoxArray && auiBoxIndexArray && adHits)
	{
		for(int i=0;i<12;i++)
		{
			float fHit=planeRayIntersection(pvBoxArray[auiBoxIndexArray[i*2]], pvBoxArray[auiBoxIndexArray[i*2+1]], vPlaneNormal, fPlaneDist);

			if(fHit>=0.0f && fHit <=1.0f)
			{
				adHits[i]=fHit;
				iCount++;
			}
		}
	}

	return iCount;
}

raaVector raaVector::slerp(raaVector v, float fStep)
{
	raaVector _v;

	_v[0]=m_afVector[0]+fStep*(v[0]-m_afVector[0]);
	_v[1]=m_afVector[1]+fStep*(v[1]-m_afVector[1]);
	_v[2]=m_afVector[2]+fStep*(v[2]-m_afVector[2]);

	return _v;
}

raaVector raaVector::mult(raaMatrix &r)
{
	raaVector _v;

	if(m_uiDim==4)
	{
		_v[0]=m_afVector[0]*r[0]+m_afVector[1]*r[4]+m_afVector[2]*r[8]+m_afVector[3]*r[12];
		_v[1]=m_afVector[0]*r[1]+m_afVector[1]*r[5]+m_afVector[2]*r[9]+m_afVector[3]*r[13];
		_v[2]=m_afVector[0]*r[2]+m_afVector[1]*r[6]+m_afVector[2]*r[10]+m_afVector[3]*r[14];
		_v[3]=m_afVector[0]*r[3]+m_afVector[1]*r[7]+m_afVector[2]*r[11]+m_afVector[3]*r[15];
	}
	else
	{
		_v[0]=m_afVector[0]*r[0]+m_afVector[1]*r[4]+m_afVector[2]*r[8];
		_v[1]=m_afVector[0]*r[1]+m_afVector[1]*r[5]+m_afVector[2]*r[9];
		_v[2]=m_afVector[0]*r[2]+m_afVector[1]*r[6]+m_afVector[2]*r[10];
	}

	return _v;
}

raaVector raaVector::operator*(raaMatrix &r)
{
	return mult(r);
}

/*
// raaVector.cpp: implementation of the raaVector class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <math.h>
#include "raaVector.h"

//////////////////////////////////////////////////////////////////////
// Construction/festruction
//////////////////////////////////////////////////////////////////////

raaVector::raaVector(unsigned int uiDim)
{
	m_afVector=new float[uiDim];
	m_bContainedVector=false;
	m_uiDim=uiDim;

	if(uiDim==4) m_afVector[3]=1.0f;

	m_f=0.0f;
	set(0.0f, 0.0f, 0.0f);
}

//raaVector::raaVector(raaVector &v)
//{
//	m_afVector=new float[3];
//	m_bContainedVector=false;
//	m_uiDim=3;
//
//	set(v[0], v[1], v[2]);	
//}


raaVector::raaVector(float fX, float fY, float fZ)
{
	m_afVector=new float[3];
	m_bContainedVector=false;
	m_uiDim=3;	

	m_f=0.0f;
	set(fX, fY, fZ);
}

raaVector::raaVector(float fX, float fY, float fZ, float fA)
{
	m_afVector=new float[4];
	m_bContainedVector=false;
	m_uiDim=4;

	m_f=0.0f;
	set(fX, fY, fY, fA);
}

raaVector::raaVector(float* pVector, unsigned int uiContainedVector)
{
	if(uiContainedVector)
	{
		m_afVector=pVector;
		m_bContainedVector=true;
		m_uiDim=uiContainedVector;
	}
	else
	{
		m_afVector=new float[4];
		m_bContainedVector=false;
		m_uiDim=4;
		m_afVector[3]=1.0f;

		m_f=0.0f;
		set(pVector[0], pVector[1], pVector[2]);
	}
}

raaVector::raaVector(raaVector &v, unsigned int uiContainedVector)
{
	if(uiContainedVector)
	{
		if(uiContainedVector<=v.getDim())
		{
			m_uiDim=uiContainedVector;
			m_afVector=v.get();
			m_bContainedVector=true;
		}
		else
		{
			m_uiDim=v.getDim();
			m_afVector=v.get();
			m_bContainedVector=true;
		}
	}
	else
	{
		m_uiDim=v.getDim();
		m_afVector=new float[m_uiDim];
		m_bContainedVector=false;

		m_f=0.0f;

		if(m_uiDim==4)
			set(v[0], v[1], v[2], v[3]);
		else
			set(v[0], v[1], v[2]);
	}
}


raaVector::~raaVector(void)
{
	if(!m_bContainedVector) delete [] m_afVector;
}

void raaVector::set(float fX, float fY, float fZ, float fA)
{
	m_afVector[0]=fX;
	m_afVector[1]=fY;
	m_afVector[2]=fZ;

	if(m_uiDim==4)
		m_afVector[3]=fA;
}

float* raaVector::get()
{
	return m_afVector;
}

float& raaVector::operator[](unsigned int uiIndex) 
{
	if(uiIndex<m_uiDim)
		return m_afVector[uiIndex];

	return m_f;
}

raaVector& raaVector::operator=(raaVector &v)
{
	if(!isContained() && !v.isContained())
	{
		m_afVector[0]=v[0];
		m_afVector[1]=v[1];
		m_afVector[2]=v[2];

		if(m_uiDim==4 && v.getDim()==4) m_afVector[3]=v[3];
		else if(m_uiDim==4) m_afVector[3]=1.0f;

	}
	else if(isContained() && !v.isContained())
	{
		m_afVector[0]=v[0];
		m_afVector[1]=v[1];
		m_afVector[2]=v[2];
	
		if(m_uiDim==4 && v.getDim()==4)
			m_afVector[3]=v[3];
	}
	else if(!isContained() && v.isContained())
	{
		delete [] m_afVector;
		m_afVector=v.get();
		m_bContainedVector=true;
		m_uiDim=v.getDim();
	}
	else
	{
		m_afVector=v.get();
		m_uiDim=v.getDim();
	}			

	return v;
}

bool raaVector::isContained()
{
	return m_bContainedVector;
}

bool raaVector::operator==(raaVector &v)
{
	if(fabs(m_afVector[0]-v[0])<0.001f && fabs(m_afVector[1]-v[1])<0.001f && fabs(m_afVector[2]-v[2])<0.001f)
		return true;

	return false;
}

void raaVector::set(unsigned int uiIndex, float f)
{
	m_afVector[uiIndex]=f;
}


raaVector raaVector::operator+( raaVector &v) 
{
	raaVector _v(m_afVector[0]+v[0], m_afVector[1]+v[1], m_afVector[2]+v[2]);

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4) _v.set(3,m_afVector[3]+v[3]);

	return _v;
}


raaVector raaVector::operator-(raaVector &v)
{
	raaVector _v(m_afVector[0]-v[0],m_afVector[1]-v[1],m_afVector[2]-v[2]);

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4) _v.set(3, m_afVector[3]-v[3]);

	return _v;
}

raaVector& raaVector::operator+=(raaVector &v)
{
	m_afVector[0]+=v[0];
	m_afVector[1]+=v[1];
	m_afVector[2]+=v[2];

	if(m_uiDim==4 && v.getDim()==4)
		m_afVector[3]+=v[3];

	return *this;
}

raaVector& raaVector::operator-=(raaVector &v)
{
	m_afVector[0]-=v[0];
	m_afVector[1]-=v[1];
	m_afVector[2]-=v[2];

	if(m_uiDim==4 && v.getDim()==4)
		m_afVector[3]-=v[3];

	return *this;
}

raaVector raaVector::operator+(float f)  
{
	raaVector _v(m_afVector[0]+f,m_afVector[1]+f,m_afVector[2]+f);

	if(m_uiDim==4) _v.set(3,m_afVector[3]+f);

	return _v;
}

raaVector raaVector::operator-(float f)
{
	raaVector _v(m_afVector[0]-f,m_afVector[1]-f,m_afVector[2]-f);

	if(m_uiDim==4) _v.set(3,m_afVector[3]-f);

	return _v;
}

raaVector& raaVector::operator+=(float f)
{
	m_afVector[0]+=f;
	m_afVector[1]+=f;
	m_afVector[2]+=f;

	if(m_uiDim==4)
		m_afVector[3]+=f;

	return *this;
}

raaVector& raaVector::operator-=(float f)
{
	m_afVector[0]-=f;
	m_afVector[1]-=f;
	m_afVector[2]-=f;

	if(m_uiDim==4)
		m_afVector[3]-=f;

	return *this;
}

raaVector raaVector::operator*(raaVector &v)
{
	raaVector _v(m_afVector[0]*v[0],m_afVector[1]*v[1], m_afVector[2]*v[2]);

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4) _v.set(3,m_afVector[3]*v[3]);

	return _v;
}

raaVector raaVector::operator*(float f)
{
	raaVector _v;
	
	_v.set(m_afVector[0]*f,m_afVector[1]*f,m_afVector[2]*f);

	if(m_uiDim==4) _v.set(3,m_afVector[3]*f);

	return _v;
}

raaVector& raaVector::operator*=(raaVector &v)
{
	m_afVector[0]*=v[0];
	m_afVector[1]*=v[1];
	m_afVector[2]*=v[2];

	if(m_uiDim==4 && v.getDim()==4)
		m_afVector[3]*=v[3];
 
	return *this;
}

raaVector& raaVector::operator*=(float f)
{
	m_afVector[0]*=f;
	m_afVector[1]*=f;
	m_afVector[2]*=f;

	if(m_uiDim==4)
		m_afVector[3]*=f;

	return *this;
}

raaVector raaVector::operator/( raaVector &v) 
{
	raaVector _v(m_afVector[0]/v[0],m_afVector[1]/v[1],m_afVector[2]/v[2]);

	if(m_uiDim==4 && v.getDim()==4 && _v.getDim()==4) _v.set(3,m_afVector[3]/v[3]);

	return _v;
}

raaVector raaVector::operator/(float f)
{
	raaVector _v(m_afVector[0]/f,m_afVector[1]/f,m_afVector[2]/f);

	if(m_uiDim==4 && _v.getDim()==4) _v.set(3, m_afVector[3]/f);
 
	return _v;
}

raaVector& raaVector::operator/=(raaVector &v)
{
	m_afVector[0]/=v[0];
	m_afVector[1]/=v[1];
	m_afVector[2]/=v[2];

	if(m_uiDim==4 && v.getDim()==4 )
		m_afVector[3]/=v[3];

	return *this;
}

raaVector& raaVector::operator/=(float f)
{
	m_afVector[0]/=f;
	m_afVector[1]/=f;
	m_afVector[2]/=f;

	if(m_uiDim==4)
		m_afVector[3]/=f;

	return *this;
}

float raaVector::dot(raaVector &v)
{
	return m_afVector[0]+v[0]+m_afVector[1]*v[1]+m_afVector[2]*v[2];
}

float raaVector::operator|( raaVector &v) 
{
	return m_afVector[0]*v[0]+m_afVector[1]*v[1]+m_afVector[2]*v[2];
}

raaVector raaVector::cross(raaVector &v)
{
	raaVector _v(m_afVector[1]*v[2]-m_afVector[2]*v[1],m_afVector[2]*v[0]-m_afVector[0]*v[2],m_afVector[0]*v[1]-m_afVector[1]*v[0]);

	return _v;
}

raaVector raaVector::operator^(raaVector &v)
{
	raaVector _v(m_afVector[1]*v[2]-m_afVector[2]*v[1],m_afVector[2]*v[0]-m_afVector[0]*v[2],m_afVector[0]*v[1]-m_afVector[1]*v[0]);

	return _v;
}

float raaVector::normalise()
{
	float fLen=length();

	m_afVector[0]/=fLen;
	m_afVector[1]/=fLen;
	m_afVector[2]/=fLen;

	return fLen;
}

float raaVector::operator!()
{
	float fLen=length();

	m_afVector[0]/=fLen;
	m_afVector[1]/=fLen;
	m_afVector[2]/=fLen;

	return fLen;
}

float raaVector::length()
{
	return sqrt(m_afVector[0]*m_afVector[0]+m_afVector[1]*m_afVector[1]+m_afVector[2]*m_afVector[2]);
}

float raaVector::operator~()
{
	return sqrt(m_afVector[0]*m_afVector[0]+m_afVector[1]*m_afVector[1]+m_afVector[2]*m_afVector[2]);
}

void raaVector::print()
{
	std::cout << "Vector -> " << m_afVector[0] << " : " << m_afVector[1] << " : " << m_afVector[2] << std::endl;
}

raaVector raaVector::normal(raaVector &v0, raaVector &v1, raaVector &v2)
{
	raaVector a, b, n;

	a=v0-v1;
	b=v2-v1;

	n=a^b;
	!n;

	return n;
}

unsigned int raaVector::getDim()  
{
	return m_uiDim;
}

raaVector raaVector::project(raaVector vDir, float fLen) 
{
	raaVector v=vDir;

	!v;
	v=v*fLen;
	
	v.set(0,m_afVector[0]+v[0]);
	v.set(1,m_afVector[1]+v[1]);
	v.set(2, m_afVector[2]+v[2]);

	return v;
}

void raaVector::proj( raaVector &vStart,  raaVector &vDir, float fLen) 
{
	m_afVector[0]=vStart[0]+vDir[0]*fLen;
	m_afVector[1]=vStart[1]+vDir[1]*fLen;
	m_afVector[2]=vStart[2]+vDir[2]*fLen;
}

float raaVector::planeRayIntersection(raaVector vRayStart, raaVector vRayEnd, raaVector vPlaneNormal, float fPlaneDist)
{
	float fLen=-1.0f;

	raaVector vDir=vRayEnd-vRayStart;

	float a, b;

	a=vPlaneNormal|vRayStart;
	b=vPlaneNormal|vDir;
	
	if(fabs(b)>0.00001f)
	{
		fLen=fPlaneDist-a/b;
	}

	return fLen;
}

int raaVector::planeBoxIntersection(raaVector *pvBoxArray, unsigned int *auiBoxIndexArray, raaVector vPlaneNormal, float fPlaneDist, float *adHits)
{
	int iCount=0;
	if(pvBoxArray && auiBoxIndexArray && adHits)
	{
		for(int i=0;i<12;i++)
		{
			float fHit=planeRayIntersection(pvBoxArray[auiBoxIndexArray[i*2]], pvBoxArray[auiBoxIndexArray[i*2+1]], vPlaneNormal, fPlaneDist);

			if(fHit>=0.0f && fHit <=1.0f)
			{
				adHits[i]=fHit;
				iCount++;
			}
		}
	}

	return iCount;
}

raaVector raaVector::slerp(raaVector v, float fStep)
{
	raaVector _v(m_afVector[0]+fStep*(v[0]-m_afVector[0]),m_afVector[1]+fStep*(v[1]-m_afVector[1]),m_afVector[2]+fStep*(v[2]-m_afVector[2]));

	return _v;
}

raaVector raaVector::slerpByDir(raaVector v, float fStep)
{
	raaVector _v(m_afVector[0]+fStep*(v[0]),m_afVector[1]+fStep*(v[1]),m_afVector[2]+fStep*(v[2]));

	return _v;
}

raaVector raaVector::mult(raaMatrix &r)
{
	raaVector _v;

	if(m_uiDim==4)
	{
		_v.set(0,m_afVector[0]*r[0]+m_afVector[1]*r[4]+m_afVector[2]*r[8]+m_afVector[3]*r[12]);
		_v.set(1,m_afVector[0]*r[1]+m_afVector[1]*r[5]+m_afVector[2]*r[9]+m_afVector[3]*r[13]);
		_v.set(2,m_afVector[0]*r[2]+m_afVector[1]*r[6]+m_afVector[2]*r[10]+m_afVector[3]*r[14]);
		_v.set(3,m_afVector[0]*r[3]+m_afVector[1]*r[7]+m_afVector[2]*r[11]+m_afVector[3]*r[15]);
	}
	else
	{
		_v.set(0,m_afVector[0]*r[0]+m_afVector[1]*r[4]+m_afVector[2]*r[8]);
		_v.set(1,m_afVector[0]*r[1]+m_afVector[1]*r[5]+m_afVector[2]*r[9]);
		_v.set(2,m_afVector[0]*r[2]+m_afVector[1]*r[6]+m_afVector[2]*r[10]);
	}

	return _v;
}

raaVector raaVector::operator*(raaMatrix &r)
{
	return mult(r);
}
*/