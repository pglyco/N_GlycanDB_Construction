#ifndef CALMAXSTRUCTURE_H_
#define CALMAXSTRUCTURE_H_
#include "ReadData.h"
#include"MonoInfo.h"
#include "GlyTree.h"
#include"BaseDataStructure.h"
#include "Enumerate.h"
//
class CCalMaxStructure{
public:
	//friend class CReduceMono;
	CCalMaxStructure(){};
	CCalMaxStructure(CReadAllStruct *pCReader,CMonoInfo *pMono):m_pCIO(pCReader),m_pMono(pMono){}
	static bool ComByMass(const CGlyTree &cTreeA,const CGlyTree &cTreeB);
	void GetMaxTrees(const char *strFile);
	void CalGcSubTrees();
	void ThreeMaxTreeToSubTree();
	CReadAllStruct * m_pCIO;
	CMonoInfo * m_pMono;
	vector<CGlyTree> m_vcMaxTrees;
	vector<CGlyTree> m_vvcResTees;
	bool Is_Comb_N_Glycan(CGlyTree & tptTree, int & root);
};
#endif