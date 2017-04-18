#ifndef GLYCANTREE_H_
#define GLYCANTREE_H_
#include"BaseDataStructure.h"
#include "MonoInfo.h"
#include "common.h"
//#include "Enumerate.h"
class CGlyTree
{
public:
	/*CGlyTree(unInt uiSize)
	{
		m_vuNodeLabel.resize(uiSize,-1);
		m_vuNodeValue.resize(uiSize,0);
		m_vvuTopology.resize(uiSize);
		m_dMass = 0.0;
	}*/
	struct StrAndValue
	{
		string CodeStr;
		double CodeValue;
	};
	static bool ComByCodeValue(const StrAndValue & A, const StrAndValue & B);
	bool OutOneTrees( ofstream &mycout,  CGlyTree &cTree, unInt &size,vector<CGlyTree> &vcRes);//可删
	void OutOneTreeLinkPlusValue(ofstream &structout,CGlyTree &arry,unInt &size);//可删
	vector<unInt> nodeID[5];//可删
	vector<CGlyTree> vcRes;//可删
	CMonoInfo * pMono;//可删
	bool RestricRules(vector<unChar> &comb);
	bool MaxGetFragmentIons(int& type);
	bool GetFragmentIons(vector<CGlyTree> &vcSubTrees);
	void InsertSet(unInt uiNodeID);
	void SetTopo(unInt uPre,unInt uNext);
	void SetLabel(unInt uNodeID,unInt uLabel);
	unInt GetLabel(unInt uNodeID);
	unInt GetSetSize();
	void CalMass();
	void CalKind();
	void ValueTree();
	void GenerateLogPrime();
	double ConvertStringWithGodel(string& StringRoot);
<<<<<<< HEAD
	//string RecurForValueTree(CGlyTree &cTree, unInt root, unInt level);
	string &RecurForValueTree(CGlyTree &cTree, unInt root, unInt level);
=======
	string RecurForValueTree(CGlyTree &cTree, unInt root, unInt level);
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
	bool IsSame(CGlyTree &cTreeA,CGlyTree &cTreeB, unInt uRa,unInt uRb);
    bool operator==(CGlyTree &cTreeB);
	bool operator>(const CGlyTree &cTreeB);
	void AddAnEdge(unInt uStart,unInt uNewEnd,unInt uLabelEnd);
	void ReadOneTreeInfo( ifstream &mycin,CGlyTree &tptTree);
	bool CompareSet(const CGlyTree &cTreeA,const CGlyTree &cTreeB);
	double GetMass();
	friend class CCalMaxStructure;
	friend class CEnumerate;
	void CalKindMassValue();
	static bool ComByMass(const CGlyTree &cTreeA,const CGlyTree &cTreeB);
	static bool ComByString(const string &StringA, const string &StringB);
	//成员变量;
	vector<vector<CGlyTree> > vcSubTrees;
	int GlyType;
	void initvcsub();
	void InitNameToLabelStand();
	void InitNameToLabelAllStand();
	int mRoot;
	int mCntNodes;
	string mStructName;
	vvuTree m_vvuTopology;
	vector<unChar> m_vuNodeLabel;//每个节点的label;
	vector<unChar> m_vuNodeKind;//该糖节点的组成;
	vector<double> m_vuNodeValue;//每个节点的value;
	//vector<string> m_vuNodeValue;//每个节点的value;
	set<unChar> m_suNodeSet;
	vector<CGlyTree>Ions;
	vector<CGlyTree>mAllTrees;
	vector<CGlyTree>mMaxTrees;
	vector<CGlyTree>mTestTrees;
	vector<int>mIsDeleted;
	vector<CGlyTree>mFinalTrees;
	vector<CGlyTree>mFinalTreesWithGc;
	map<string,int> mMapNameToLabel;
	double m_dMass;
	static CMonoInfo *m_pMono;
	vector<string> str_m_vuNodeValue;
	void ReadAllTreesInfo(const char *inFile,vector<CGlyTree>&mTrees); // 读糖库文件到vector中
	int ReadAllTreesInfoAsQueue( ifstream& mycin,queue<CGlyTree>&mTrees,int& EachReadNum);// 读糖库文件到queue中
	void ComMaxAndGlycome();
	void ExtendAc2Gc(vector<CGlyTree> &vcSubTrees, CMonoInfo * pMono, size_t tStart);
//private:
//	CGlyTree();//禁止默认构造函数产生对象;
};
#endif