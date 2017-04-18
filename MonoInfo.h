#ifndef MONOINFO_H_
#define MONOINFO_H_
#include "BaseDataStructure.h"
class CMonoInfo{
//����ģʽֻ����һ������;
public:
	static CMonoInfo *GetMono(const char * pMonoini);
	static void GetFree();
	unInt GetLabel(const string &strName);
	string GetMonoName(const unInt &uiKind);
	double GetMass(const unInt uLabel);
	int GetMonoSize();
	map<string,unInt> m_mMono2Label;//���ֺͱ�ŵ�ӳ��;
	map<unInt,string> m_mLabel2Mono;//��ź����ֵ�ӳ��;
	vector<double>  m_mLabel2Mass;//�ǵ�����;
private:
	CMonoInfo(){};
	void InitMonoMap(const char * pMonoini);
	static CMonoInfo * m_spMonoInfo;
};
#endif