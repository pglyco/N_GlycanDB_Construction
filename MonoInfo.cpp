#include "MonoInfo.h"
CMonoInfo * CMonoInfo::m_spMonoInfo = NULL;

CMonoInfo *CMonoInfo::GetMono(const char * pMonoini)
{
	if(m_spMonoInfo==NULL){
		m_spMonoInfo = new CMonoInfo();
		m_spMonoInfo->InitMonoMap(pMonoini);
	}
	return m_spMonoInfo;
}

void CMonoInfo::GetFree()
{
	if(m_spMonoInfo!=NULL){
		delete m_spMonoInfo;
		m_spMonoInfo = NULL;
	}
}

void CMonoInfo::InitMonoMap(const char *pMonoini)//这里把单糖的名字与其表示的Label对应起来了
{//读取mono.ini配置文件;
	ifstream myCin("mono.ini");
	if(!myCin){
		cout<<"Can not open mono.ini"<<endl;
		exit(0);
	}
	string strLine,strName;
	istringstream issCin;
	while(getline(myCin,strLine)){
		if(strLine.find("BEGIN")!= string::npos)
			break;
	}
	double dMass = 0;
	unInt iCnt = 0;
	getline(myCin,strLine);
	while(getline(myCin,strLine)){
		if(strLine.find("END")!=string::npos)
			break;
		issCin.clear();
		issCin.str(strLine);
		issCin>>dMass>>strName;
		m_mMono2Label[strName] = iCnt;//Hex:0, HexNAc:1, NeuAc:2, NeuGc:3, dHex:4
		m_mLabel2Mono[iCnt] = strName;
		m_mLabel2Mass.push_back(dMass);
		iCnt++;
	}
	cout<<"read mono.ini finished"<<endl;
}

unInt CMonoInfo::GetLabel(const string &strName)
{
	if(m_mMono2Label.count(strName)==0){
		cout<<strName<<endl;
		cout<<"单糖名称不存在"<<endl;
		return 0x7fffffff;
	}
	else	
		return m_mMono2Label[strName];
}

double CMonoInfo::GetMass( const unInt uLabel )
{
	if((int)uLabel<0||(int)uLabel>=m_mLabel2Mass.size()){
		cout<<" uLabel "<<uLabel<<"m_mLabel2Mass.size() "<<m_mLabel2Mass.size()<<endl;
		cout<<"exceed the bound of mass-arry"<<endl;
		exit(0);
	}
	return m_mLabel2Mass[uLabel];
}

int CMonoInfo::GetMonoSize()
{
	return m_mLabel2Mass.size();
}

std::string CMonoInfo::GetMonoName( const unInt &uiKind )
{
	return m_mLabel2Mono[uiKind];
}

