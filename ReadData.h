#ifndef READDATA_H_
#define READDATA_H_
#include "MonoInfo.h"
#include"BaseDataStructure.h"
#include "GlyTree.h"
class CRead
{
public:
	virtual void Read(const char *strFile,vector<CGlyTree>& vcStructs)=0;
};
class CReadAllStruct:public CRead
{
//读取最大通用库的类;
public:
	CReadAllStruct (const CMonoInfo *oMono):m_pMono(oMono){};
	void Read(const char *strFile,vector<CGlyTree> &vcMaxStruct);
private:
	const CMonoInfo *m_pMono;
};
#endif