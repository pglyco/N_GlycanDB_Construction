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
	bool OutOneTrees( ofstream &mycout,  CGlyTree &cTree, unInt &size,vector<CGlyTree> &vcRes);//��ɾ
	void OutOneTreeLinkPlusValue(ofstream &structout,CGlyTree &arry,unInt &size);//��ɾ
	vector<unInt> nodeID[5];//��ɾ
	vector<CGlyTree> vcRes;//��ɾ
	CMonoInfo * pMono;//��ɾ
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
	//��Ա����;
	vector<vector<CGlyTree> > vcSubTrees;
	int GlyType;
	void initvcsub();
	void InitNameToLabelStand();
	void InitNameToLabelAllStand();
	int mRoot;
	int mCntNodes;
	string mStructName;
	vvuTree m_vvuTopology;
	vector<unChar> m_vuNodeLabel;//ÿ���ڵ��label;
	vector<unChar> m_vuNodeKind;//���ǽڵ�����;
	vector<double> m_vuNodeValue;//ÿ���ڵ��value;
	//vector<string> m_vuNodeValue;//ÿ���ڵ��value;
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
	void ReadAllTreesInfo(const char *inFile,vector<CGlyTree>&mTrees); // ���ǿ��ļ���vector��
	int ReadAllTreesInfoAsQueue( ifstream& mycin,queue<CGlyTree>&mTrees,int& EachReadNum);// ���ǿ��ļ���queue��
	void ComMaxAndGlycome();
	void ExtendAc2Gc(vector<CGlyTree> &vcSubTrees, CMonoInfo * pMono, size_t tStart);
//private:
//	CGlyTree();//��ֹĬ�Ϲ��캯����������;
};
#endif