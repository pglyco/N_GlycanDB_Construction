#ifndef ENUMERATE_H_
#define ENUMERATE_H_
#define _CRT_SECURE_NO_WARNINGS
#include "AllHead.h"

extern time_t IO_time;
//////////////////////////////////////////////////////////////////////////
//生成树结构的参数，这里先用固定配置;
//////////////////////////////////////////////////////////////////////////
//const unsigned long long MAXN=
const unInt MONOSIZE = 5;//单糖种类的数量;
const unInt MAXBRANCH = 3;//最多三叉树;
const unInt BranchLimit[MONOSIZE]={3,3,1,0,1};//每种糖最多连接的分支;
//const unInt BranchLimit[MONOSIZE]={100,100,100,100,100};
//const unInt BranchLimit[MONOSIZE]={4,3,1,0,1};//每种糖最多连接的分支;
const unInt MonoExist[MONOSIZE]={1,1,1,0,1};//每种单糖是否参与枚举,1表示参与，0反之;
const double MonoMass[MONOSIZE]={162.0528234315,203.07937253300003,291.09541652769997,0,146.0579088094};
const unInt Link[MONOSIZE][MONOSIZE]={
	1,1,1,0,1,
	1,1,1,0,1,
	1,1,1,0,1,
	0,0,0,0,0,
	1,1,1,0,1
};
class CEnumerate{
	//枚举所有的糖结构;
public:
	CEnumerate(int size,const char *startTreeFile);
	~CEnumerate();
	typedef int LoserTree[5000];
	void Adjust(LoserTree Ls,int s,int k);
	void swap(int &a,int &b);
	void CreateLoserTree(LoserTree Ls,unInt &k);
	void K_Merge(LoserTree Ls,unInt NodeNum,unInt &k);
	void OutTreeIonsLink(ofstream &mycout,vector<CGlyTree> &arry);
	bool OutOneTreeWithoutProduceFrag( ofstream &mycout, CGlyTree &cTree, unInt &size,vector<CGlyTree> &vcRes);
	void ProduceAllTrees();
    bool RestricRules(vector<unInt> &comb);
	bool OutOneTrees( ofstream &mycout,  CGlyTree &cTree, unInt &size,vector<CGlyTree> &vcRes);
	static bool ComByMass(const CGlyTree &cTreeA,const CGlyTree &cTreeB);
	static bool ComByValue(const CGlyTree &cTreeA,const CGlyTree &cTreeB);
	void OutOneTreeLink(ofstream &mycout,CGlyTree &arry,unInt &size);
	void OutOneTreeLinkPlusValue(ofstream &structout,CGlyTree &arry,unInt &size);
	int DeleteRedundancyAccordCode(vector<CGlyTree>& mTestTrees,unInt size);
	unInt IrredundantGlycansExtensionAndOutput(ofstream& structout, ofstream & structoutLink, CGlyTree & newArry, unInt & RealSum);
	void IrredundantGlycansExtension(vector<CGlyTree> & newArry, int & testnum);
	CMonoInfo * pMono;
	//CCalMaxStructure * p;//不知道这个删除会不会有问题。
	//糖库生成规则使用;
	void InitalizeIndex();
	static unInt iHex;
	static unInt iHexNAc;
	static unInt idHex;
	static unInt iNeuAc;
	static unInt iXyl;
	vector<CGlyTree>m_vSmallTrees;
	vector<CGlyTree> vcRes;
	vector<unInt> nodeID[5];
	CMonoInfo * m_pMono;
	unInt & OutOneTreeAndTreeLinkPlusValue(ofstream & FinalOut, ofstream & FinalOutLink, CGlyTree & newArry, vector<CGlyTree> & vcRes, unInt &GlyId);
	//friend class CGlyTree;
private:
	unInt m_MaxSize;
	CEnumerate();
};
#endif