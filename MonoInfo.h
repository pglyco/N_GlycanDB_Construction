#ifndef MONOINFO_H_
#define MONOINFO_H_
#include "BaseDataStructure.h"
class CMonoInfo{
//单例模式只生成一个对象;
public:
	static CMonoInfo *GetMono(const char * pMonoini);
	static void GetFree();
	unInt GetLabel(const string &strName);
	string GetMonoName(const unInt &uiKind);
	double GetMass(const unInt uLabel);
	int GetMonoSize();
	map<string,unInt> m_mMono2Label;//名字和编号的映射;
	map<unInt,string> m_mLabel2Mono;//编号和名字的映射;
	vector<double>  m_mLabel2Mass;//糖的质量;
private:
	CMonoInfo(){};
	void InitMonoMap(const char * pMonoini);
	static CMonoInfo * m_spMonoInfo;
};
#endif