#include "GlyTree.h"
#include "Enumerate.h"
CMonoInfo * CGlyTree::m_pMono = NULL;

<<<<<<< HEAD
time_t S2, E2;

=======
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
int Threshold=pow(2,20);//ÿ���ڵ����������֧

bool CGlyTree::ComByString(const string &StringA, const string &StringB)
{
	if (StringA.length()<StringB.length())
		return true;
	else if (StringA.length()>StringB.length())
		return false;
	else
	{
		for (int i = 0; i<StringA.length(); i++)
		{
			if (StringA[i]<StringB[i])
				return true;
			else if (StringA[i]>StringB[i])
				return false;
		}
		return false;
	}
}

<<<<<<< HEAD
////////////////////////// all the elements in this constructed str are digits
/////////////////////////Sort Accord Str
//string CGlyTree::RecurForValueTree(CGlyTree &cTree, unInt root, unInt level)
//{//�ݹ���һ�����ĸ��ڵ����ֵ;
//	unsigned long long tempvalue;
//	if (root<0 || root >= cTree.m_vvuTopology.size())
//	{
//		cout << "beyond the bound of array error" << endl;
//		return 0;
//	}
//	cTree.str_m_vuNodeValue[root] = "";
//	tempvalue = cTree.m_vuNodeLabel[root] + 3;
//	stringstream stream;
//	stream.str("");
//	stream << tempvalue;
//	cTree.str_m_vuNodeValue[root] += stream.str();
//	if (cTree.m_vvuTopology[root].size() == 0)
//	{
//		return cTree.str_m_vuNodeValue[root];
//	}
//	vector<string> ValueNextLevel;
//	vector<double> VecStrValue;
//	vector<StrAndValue> CodeOfNode;
//	StrAndValue TempSV;
//	ValueNextLevel.clear();
//	VecStrValue.clear();
//	for (size_t i = 0; i<cTree.m_vvuTopology[root].size(); i++)
//	{
//		ValueNextLevel.push_back(RecurForValueTree(cTree, cTree.m_vvuTopology[root][i], level + 1));
//	}
//	sort(ValueNextLevel.begin(), ValueNextLevel.end(), ComByString);
//	cTree.str_m_vuNodeValue[root] += "1";
//	vector<string>::iterator itString;
//	for (itString = ValueNextLevel.begin(); itString != ValueNextLevel.end(); itString++)
//	{
//		cTree.str_m_vuNodeValue[root] += (*itString);
//	}
//	cTree.str_m_vuNodeValue[root] += "2";
//	return cTree.str_m_vuNodeValue[root];
//}


///////////////////////Sort Accord Str
string &CGlyTree::RecurForValueTree(CGlyTree &cTree, unInt root, unInt level)
{//�ݹ���һ�����ĸ��ڵ����ֵ;
	if (root<0 || root >= cTree.m_vvuTopology.size())
	{
		cout << "beyond the bound of array error" << endl;
		return string("");
	}
	///int addc = level * 2;
	int addc = level ;///�����Ϊһ��
	//char tempil='A'+addc;//////�����Ϊ��A'
	char tempil = 'A' + addc;////����ַ�
	stringstream stream;
	stream.str("");
	stream << tempil;
	cTree.str_m_vuNodeValue[root] = stream.str();

	string ss;
	ss.resize(1);
	char* ress2 = &ss[0];
	*ress2-- = cTree.m_vuNodeLabel[root] + 1 + '0';

	cTree.str_m_vuNodeValue[root] += ss;
	////char tempir = 'B' + addc;////////�����Ϊ'B'///�Ҷ��ַ�
	char tempir = 'a' + addc;////////�����Ϊ'a'///�Ҷ��ַ�
	stream.str("");
	stream << tempir;

	if (cTree.m_vvuTopology[root].size() == 0)
	{
		cTree.str_m_vuNodeValue[root] += stream.str();
=======
///////////////////////Sort Accord Str
string CGlyTree::RecurForValueTree(CGlyTree &cTree, unInt root, unInt level)
{//�ݹ���һ�����ĸ��ڵ����ֵ;
	unsigned long long tempvalue;
	if (root<0 || root >= cTree.m_vvuTopology.size())
	{
		cout << "beyond the bound of array error" << endl;
		return 0;
	}
	cTree.str_m_vuNodeValue[root] = "";
	tempvalue = cTree.m_vuNodeLabel[root] + 3;
	stringstream stream;
	stream.str("");
	stream << tempvalue;
	cTree.str_m_vuNodeValue[root] += stream.str();
	if (cTree.m_vvuTopology[root].size() == 0)
	{
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
		return cTree.str_m_vuNodeValue[root];
	}
	vector<string> ValueNextLevel;
	vector<double> VecStrValue;
	vector<StrAndValue> CodeOfNode;
	StrAndValue TempSV;
	ValueNextLevel.clear();
	VecStrValue.clear();
	for (size_t i = 0; i<cTree.m_vvuTopology[root].size(); i++)
	{
		ValueNextLevel.push_back(RecurForValueTree(cTree, cTree.m_vvuTopology[root][i], level + 1));
	}
	sort(ValueNextLevel.begin(), ValueNextLevel.end(), ComByString);
<<<<<<< HEAD
=======
	cTree.str_m_vuNodeValue[root] += "1";
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
	vector<string>::iterator itString;
	for (itString = ValueNextLevel.begin(); itString != ValueNextLevel.end(); itString++)
	{
		cTree.str_m_vuNodeValue[root] += (*itString);
	}
<<<<<<< HEAD
	////char tempir1 = 'B' + addc;//////�Ҷ��ַ�
	char tempir1 = 'a' + addc;//////�Ҷ��ַ�
	stream.str("");
	stream << tempir1;
	cTree.str_m_vuNodeValue[root] += stream.str();
	return cTree.str_m_vuNodeValue[root];
}


=======
	cTree.str_m_vuNodeValue[root] += "2";
	return cTree.str_m_vuNodeValue[root];
}

>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
double logprime[4000];
void CGlyTree::GenerateLogPrime()
{
	bool flag;
	int countl = 0;
	for (int i = 2; i<5000; i++)
	{
		flag = true;
		for (int j = 2; j<(int)sqrt(i) + 1; j++)
		{
			if (i%j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			logprime[countl++] = log(i);

	}
	cout << " countl " << countl << endl;
}

double CGlyTree::ConvertStringWithGodel(string& StringRoot)
{
	double temp = 0;
	for (int i = 0; i<StringRoot.size(); i++)
	{
		temp += StringRoot[i] * logprime[i];
	}
	return temp;
}

void CGlyTree::ValueTree()
{
	CGlyTree & cTree = *this;
	RecurForValueTree(cTree,cTree.mRoot,0);
	cTree.m_vuNodeValue[cTree.mRoot] = ConvertStringWithGodel(cTree.str_m_vuNodeValue[cTree.mRoot]);
}
bool CGlyTree::OutOneTrees( ofstream &mycout,  CGlyTree &cTree, unInt &size,vector<CGlyTree> &vcRes)
{
	const int GlyVecNum=5;
	vcRes.clear();
	//���������ÿ��С�ṹ;
	///////////without restriction
	cTree.GetFragmentIons(vcRes);
	vector<CGlyTree>::iterator iter;
	for(iter=vcRes.begin();iter!=vcRes.end();iter++)
		(*iter).CalMass();
	/////////with restriction
	//if(cTree.GetFragmentIons(vcRes)==false)//���������������������
	//{
	//	 return false;//cTree.GetFragmentIons(vcAllRes);//����һ���������������������������ȥ���ࣨ��������
	//}
	sort(vcRes.begin(),vcRes.end(),ComByMass);//������Ƭ���ӣ�������Ƭ���Ӱ���������
	mycout.setf(ios::fixed);
	mycout.precision(6);
	mycout<<"Begin"<<endl;
	mycout<<"GLYID=\t"<<size<<" GLYTYPE=\t"<<cTree.GlyType<<endl;
	mycout<<"Struct=\t0"<<endl;
	mycout<<"Mass=\t"<<cTree.GetMass()<<endl;
	mycout<<"kind=\t";
	vector<unChar>::iterator itKind;
	for(itKind=cTree.m_vuNodeKind.begin();itKind!=cTree.m_vuNodeKind.end();itKind++)
	{
		mycout<<(int)(*itKind)<<"\t";
	}
		mycout<<endl;
	mycout<<"Ions:"<<endl;
	for(size_t i=0;i<vcRes.size()-1;i++)
	{
		/*if(i>0&&vcRes[i].m_vuNodeKind==vcRes[i-1].m_vuNodeKind)
			continue;*/
		mycout<<"IonStruct=\t0"<<endl;
		mycout<<"IonMass=\t"<<vcRes[i].m_dMass<<endl;
		mycout<<"IonKind=\t";
		for(itKind=vcRes[i].m_vuNodeKind.begin();itKind!=vcRes[i].m_vuNodeKind.end();itKind++)
		{
			mycout<<(int)(*itKind)<<"\t";
		}
		mycout<<endl;
	}
	mycout<<"End"<<endl;
	return true;
}

void CGlyTree::OutOneTreeLinkPlusValue(ofstream &structout, CGlyTree &arry, unInt &size)
{//��������ͨ�ýṹ����ʽ;
	//cout<<" m_mLabel2Mono[uiKind] "<<m_mLabel2Mono[0]<<endl;
	CMonoInfo *pMono = CMonoInfo::GetMono("mono.ini");
	const int GlyKindNum = 5;
	for (unInt j = 0; j<GlyKindNum; j++)
		nodeID[j].clear();
	set<unChar>::iterator iterSet;
	if (arry.m_suNodeSet.size() != 0)
	{
		for (iterSet = arry.m_suNodeSet.begin(); iterSet != arry.m_suNodeSet.end(); iterSet++)
		{
			nodeID[(int)arry.m_vuNodeLabel[*iterSet]].push_back(*iterSet + 1);
		}
	}
	else
	{
		for (int j = 0; j<arry.m_vuNodeLabel.size(); j++)
		{
			nodeID[(int)arry.m_vuNodeLabel[j]].push_back(j + 1);
		}
	}
	const int Maxnum = 5;
	structout << "Begin" << endl;
	structout << "Value=\t" << arry.m_vuNodeValue[arry.mRoot] << endl;//����ǽṹ��valueֵ���Ա�鲢��ʱ�����ֱ�Ӷ�ȡ�Ӷ�ȥ���ࡣ
	structout << "GLYID=\t" << size << endl;//<<"TOTALNODES=\t"<<mFinalTrees[size].m_vuNodeLabel.size()<<endl;
	if (arry.m_suNodeSet.size() != 0)
		structout << "rootAndnodes\t" << (arry.mRoot + 1) << "\t" << arry.m_suNodeSet.size() << endl;
	else
		structout << "rootAndnodes\t" << (arry.mRoot + 1) << "\t" << arry.m_vuNodeLabel.size() << endl;
	structout << "[Mono]" << endl;

	for (size_t j = 0; j<Maxnum; j++)
	{
		if (nodeID[j].size()>0)
		{
			structout << pMono->GetMonoName(j) << "\t";
			for (size_t k = 0; k<nodeID[j].size(); k++)
			{
				structout << nodeID[j][k] << "\t";
			}
			structout << endl;
		}
	}
	structout << "[Link]" << endl;
	for (size_t j = 0; j<arry.m_vvuTopology.size(); j++){
		if (arry.m_vvuTopology[j].size()>0){
			structout << j + 1 << "\t";
			for (size_t k = 0; k<arry.m_vvuTopology[j].size(); k++){
				structout << arry.m_vvuTopology[j][k] + 1 << "\t";
			}
			structout << endl;
		}
	}

	structout << "End" << endl;
}

unInt counter_example_num=0;

bool CGlyTree::IsSame(CGlyTree &cTreeA,CGlyTree &cTreeB,unInt uRa,unInt uRb)
{
	if(cTreeA.m_vuNodeValue[uRa]!=cTreeB.m_vuNodeValue[uRb])
	{
		return false;
	}
	return true;
}
bool CGlyTree::operator==( CGlyTree & cTreeB )
{
	 CGlyTree & cTreeA = *this;
	return IsSame(cTreeA,cTreeB,cTreeA.mRoot,cTreeB.mRoot);
}
bool CGlyTree::RestricRules( vector<unChar> &comb )//Hex:0, HexNAc:1, NeuAc:2, NeuGc:3, dHex:4
{// Rules in <<Automated assignments of N- and O-site Specific glycosylation...>>;
	if(comb[0]>0&&comb[1]<2)//rule 1
		return false;
	if(comb[1]>=4&&comb[0]<2)//rule 2
		return false;
	if(comb[1]<comb[4])//rule 3
		return false;
	if(comb[4]>=2&&(comb[0]<2||comb[1]<3))//rule 4
		return false;
	if(comb[2]==1&&(comb[0]<3||comb[1]<3))//rule 5
		return false;
	if(comb[3] == 1 && (comb[0]<3 || comb[1]<3))//rule 5
		return false;
	if(comb[2]>=2&&(comb[0]<4||comb[1]<4))//rule 6
		return false;
	if (comb[3] >= 2 && (comb[0]<4 || comb[1]<4))//rule 6
		return false;
	if(comb[0]<comb[2])//rule 7
		return false;
	if (comb[0]<comb[3])//rule 7
		return false;
	return true;
}
bool CGlyTree::MaxGetFragmentIons(int &type)//vcSubTrees[i]��ʾ��i+1���ڵ���������ϣ�������GetFragmentIons()�����Ĳ��֮�������������Ϊ��ʹ�����ͨ�ýṹ��ȥ���������Ч�ʡ�
{//�Ե�ǰ�ṹΪ���ͨ�ýṹ��ȡ���еķ������ӽṹ;
	CGlyTree & cMaxTree =* this;///enumerate�е�
	vector<CGlyTree> vcTrees;
	vector<CGlyTree> vcTemps;
	//��ʼ��һ����С�Ľڵ�,������ڵ�������չ���������ӽṹ;
	CGlyTree sStem;//
	sStem.m_vuNodeLabel.resize(cMaxTree.m_vvuTopology.size(),-1);
	sStem.m_vuNodeValue.resize(cMaxTree.m_vvuTopology.size(),0);
	sStem.str_m_vuNodeValue.resize(cMaxTree.m_vvuTopology.size());
	sStem.m_vvuTopology.resize(cMaxTree.m_vvuTopology.size());
	sStem.m_dMass = 0.0;
	sStem.mRoot=cMaxTree.mRoot;
	sStem.m_dMass = 0.0;
	sStem.InsertSet(cMaxTree.mRoot);
	sStem.SetLabel(cMaxTree.mRoot,cMaxTree.GetLabel(cMaxTree.mRoot));
	cout<<"cMaxTree.mRoot "<<cMaxTree.mRoot<<endl;
	sStem.CalKindMassValue();
	sStem.Ions.resize(cMaxTree.m_vvuTopology.size());
	sStem.Ions.push_back(sStem);//��Ƭ����
	sStem.GlyType=type;
	vcTrees.push_back(sStem);//A���ϳ�ʼ��Ϊ���ڵ㣬B����Ϊ������г�ȥA�����е����нڵ㼯�ϣ�����A�����е�ÿ���ڵ㣬��B�������ҵ��ýڵ������˹�ϵ�Ľڵ㣬�����ڵ�֮�����һ���ߣ�����B�е��Ǹ��ڵ����A�����С�
	vcSubTrees[0].push_back(sStem);//���迼��ȥ��������⣬ȥ������������ͬ�ڵ㼯�ϵ�����	
	unChar ucGlyTreesID = 0;
	for(size_t cTotal=1;cTotal<cMaxTree.GetSetSize();cTotal++){
		//ע�����cTotal = 1������Ƭ���Ӱ����������Ľṹ;
		for(size_t i=0;i<vcTrees.size();i++){
			//��vcTrees�е�ÿһ����Ϊ��׼������һ���µĽڵ���չ���µĽṹ;
			set<unChar>::iterator sInNode;
			for(sInNode=vcTrees[i].m_suNodeSet.begin();sInNode!=vcTrees[i].m_suNodeSet.end();
				sInNode++){
					//����ÿһ���ڵ�����ڽڵ��Ƿ��ڼ�����;
					for(size_t j=0;j<cMaxTree.m_vvuTopology[*sInNode].size();j++){
						unChar uLinker = cMaxTree.m_vvuTopology[*sInNode][j];
						if(vcTrees[i].m_suNodeSet.count(uLinker)==0){
							//���ڼ����б�ʾ������ӽ���;
							CGlyTree cTemp = vcTrees[i];
							cTemp.AddAnEdge(*sInNode,uLinker,cMaxTree.GetLabel(uLinker));//cTotal+1���ڵ������
							cTemp.CalKind();
							//���ҽڵ㼯���Ƿ��ظ�;ע�����ﲻ��ɾ������ṹ;
							//�ж�������Y���ӣ��Ƿ�����Լ����������������㣬�����������
							/*if(!RestricRules(cTemp.m_vuNodeKind))///�ϲ��ⲻ��Ҫ�������������
								return false;*/
							//ȥ���ڵ㼯����ͬ���������
							vector<CGlyTree>::iterator itGlyTree;
							for(itGlyTree=vcTemps.begin();itGlyTree!=vcTemps.end();itGlyTree++)//vcTemps:cTotal+1���ڵ����������
							{
								if(CompareSet(*itGlyTree,cTemp)){//������ͬ��㼯�ϵ�����ֻ����һ����//�Ƿ���Ի�һ�ַ�����
									break;
								}
							}
							if(itGlyTree==vcTemps.end())
							{	
								ucGlyTreesID++;
								cTemp.CalMass();
								cTemp.mRoot=cMaxTree.mRoot;//����˳����Ҫ�Ĺ���
								cTemp.ValueTree();
								for(itGlyTree=vcTemps.begin();itGlyTree!=vcTemps.end();itGlyTree++)
								{
									if(*itGlyTree==cTemp)//���cTemp��vcTemps�����е��������࣬��break������ͬ�ڵ������ȥ�������ࣩ.
										break;
								}
								if(itGlyTree==vcTemps.end())
								   vcSubTrees[cTotal].push_back(cTemp);
								vcTemps.push_back(cTemp);//����vcTemps����ȥ����������
							}
						}
					}
			}	
		}
		FreeVector(vcTrees);
		vcTrees = vcTemps;
		vcTemps.clear();
		FreeVector(vcTemps);
	}
	 return true;
	 
}
bool CGlyTree::GetFragmentIons(vector<CGlyTree> &vcSubTrees )//vcSubTrees[i]��ʾ��i+1���ڵ���������ϡ�
{//�Ե�ǰ�ṹΪ���ͨ�ýṹ��ȡ���еķ������ӽṹ;
	//InitalizeIndex();
	bool flag_ion=true;
	CGlyTree & cMaxTree =* this;///enumerate�е�
	vcSubTrees.clear();
	vector<CGlyTree> vcTrees;
	vector<CGlyTree> vcTemps;
	//��ʼ��һ����С�Ľڵ�,������ڵ�������չ���������ӽṹ;
	//CGlyTree sStem(cMaxTree.m_vvuTopology.size());//
	CGlyTree sStem;//
	sStem.m_vuNodeLabel.resize(cMaxTree.m_vvuTopology.size(),-1);
	sStem.m_vuNodeValue.resize(cMaxTree.m_vvuTopology.size(),0);
	sStem.str_m_vuNodeValue.resize(cMaxTree.m_vvuTopology.size(), "0");
	sStem.m_vvuTopology.resize(cMaxTree.m_vvuTopology.size());
	sStem.m_dMass = 0.0;
	sStem.InsertSet(cMaxTree.mRoot);
	sStem.SetLabel(cMaxTree.mRoot,cMaxTree.GetLabel(cMaxTree.mRoot));
	sStem.mRoot=cMaxTree.mRoot;
	sStem.CalKindMassValue();
	vcTrees.push_back(sStem);//A���ϳ�ʼ��Ϊ���ڵ㣬B����Ϊ������г�ȥA�����е����нڵ㼯�ϣ�����A�����е�ÿ���ڵ㣬��B�������ҵ��ýڵ������˹�ϵ�Ľڵ㣬�����ڵ�֮�����һ���ߣ�����B�е��Ǹ��ڵ����A�����С�
	vcSubTrees.push_back(sStem);//���迼��ȥ��������⣬ȥ������������ͬ�ڵ㼯�ϵ�����
	for(size_t cTotal=1;cTotal<cMaxTree.GetSetSize();cTotal++){
		//ע�����cTotal = 1������Ƭ���Ӱ����������Ľṹ;
		for(size_t i=0;i<vcTrees.size();i++){
			//��vcTrees�е�ÿһ����Ϊ��׼������һ���µĽڵ���չ���µĽṹ;
			set<unChar>::iterator sInNode;
			for(sInNode=vcTrees[i].m_suNodeSet.begin();sInNode!=vcTrees[i].m_suNodeSet.end();
				sInNode++){
					//����ÿһ���ڵ�����ڽڵ��Ƿ��ڼ�����;
					for(size_t j=0;j<cMaxTree.m_vvuTopology[*sInNode].size();j++){
						unChar uLinker = cMaxTree.m_vvuTopology[*sInNode][j];
						if(vcTrees[i].m_suNodeSet.count(uLinker)==0){
							//���ڼ����б�ʾ������ӽ���;
							CGlyTree cTemp = vcTrees[i];
							cTemp.AddAnEdge(*sInNode,uLinker,cMaxTree.GetLabel(uLinker));//cTotal+1���ڵ������
							cTemp.CalKind();//û��set����Ͳ��ܼ���kind,��ô��������Ҳ��û��������
							//���ҽڵ㼯���Ƿ��ظ�;ע�����ﲻ��ɾ������ṹ;

<<<<<<< HEAD
							////////�ж�������Y���ӣ��Ƿ�����Լ����������������㣬�����������
							//if(!RestricRules(cTemp.m_vuNodeKind))//ȥ������2����֤ö�ٿ��Ƿ�����ϲ���
							//	return false;//����ں���������ϲ���ʱ����Ҫע��

=======
							//�ж�������Y���ӣ��Ƿ�����Լ����������������㣬�����������
							if(!RestricRules(cTemp.m_vuNodeKind))//ȥ������2����֤ö�ٿ��Ƿ�����ϲ���
								return false;//����ں���������ϲ���ʱ����Ҫע��
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
							//ȥ���ڵ㼯����ͬ���������
							vector<CGlyTree>::iterator itGlyTree;
							for(itGlyTree=vcTemps.begin();itGlyTree!=vcTemps.end();itGlyTree++)//vcTemps:cTotal+1���ڵ����������
							{
								if(CompareSet(*itGlyTree,cTemp)){//������ͬ��㼯�ϵ�����ֻ����һ����//�Ƿ���Ի�һ�ַ�����
									break;
								}
							}
							if(itGlyTree==vcTemps.end())
							{	
								cTemp.CalMass();
								cTemp.ValueTree();
								for(itGlyTree=vcTemps.begin();itGlyTree!=vcTemps.end();itGlyTree++)
								{
								    if((*itGlyTree).m_vuNodeKind==cTemp.m_vuNodeKind)
									   break;
									if(*itGlyTree==cTemp)//���cTemp��vcTemps�����е��������࣬��break����ͬ�ڵ�����ȥ�������ࣩ.
										break;
								}
								if(itGlyTree==vcTemps.end())
								{
								   vcSubTrees.push_back(cTemp);
								}
								vcTemps.push_back(cTemp);//����vcTemps����ȥ����������
							}
						}
					}
			}	
		}
		FreeVector(vcTrees);
		vcTrees = vcTemps;
		vcTemps.clear();
		FreeVector(vcTemps);
	}
	 return true;
	 
}
void CGlyTree::InsertSet( unInt uiNodeID )
{
	m_suNodeSet.insert(uiNodeID);
}

void CGlyTree::SetTopo( unInt uPre,unInt uNext )
{
	m_vvuTopology[uPre].push_back(uNext);
}

void CGlyTree::SetLabel( unInt uNode,unInt uLabel )
{
	m_vuNodeLabel[uNode] = uLabel;
}
unInt CGlyTree::GetLabel( unInt uNodeID )
{
	return m_vuNodeLabel[uNodeID];
}

unInt CGlyTree::GetSetSize()
{
	if(m_suNodeSet.size()!=0)
	    return m_suNodeSet.size();
	else
		return m_vuNodeLabel.size();
}
void CGlyTree::AddAnEdge(unInt uStart,unInt uNewEnd,unInt uLabelEnd)
{//���һ���µı�;
	m_suNodeSet.insert(uNewEnd);
	m_vvuTopology[uStart].push_back(uNewEnd);
	m_vuNodeLabel[uNewEnd] = uLabelEnd;
}
bool CGlyTree::CompareSet( const CGlyTree &cTreeA,const CGlyTree &cTreeB )
{
	return cTreeA.m_suNodeSet == cTreeB.m_suNodeSet;
}

void CGlyTree::CalMass()
{
	m_dMass = 0.0;
	m_pMono = CMonoInfo::GetMono("mono.ini");
	if(!m_pMono){
		cout<<"CGlyTree �� m_pMono ��ʼ��ʧ��"<<endl;
	}
	if(m_suNodeSet.size()!=0)
	{
		set<unChar>::iterator itNode;
	    for(itNode = m_suNodeSet.begin();itNode!=m_suNodeSet.end();itNode++){
		   m_dMass += m_pMono->GetMass(m_vuNodeLabel[*itNode]);
	}
	}
	else
	{
		vector<unChar>::iterator itLabel;
		 //for(int j=0;j<cTree.m_vuNodeLabel.size();j++)
		for(itLabel = m_vuNodeLabel.begin();itLabel!= m_vuNodeLabel.end();itLabel++)
	  {
		  if(*itLabel==' ')
			  continue;
		  m_dMass += m_pMono->GetMass(*itLabel);
	  }
	}
}

void CGlyTree::CalKind()
{
	m_pMono = CMonoInfo::GetMono("mono.ini");
	if(!m_pMono){
		cout<<"CGlyTree �� m_pMono ��ʼ��ʧ��"<<endl;
	}
	if(m_vuNodeKind.size()>0){
		for(size_t i=0;i<m_vuNodeKind.size();i++){
			m_vuNodeKind[i] = 0;
		}
	}
	else{
		m_vuNodeKind.resize(m_pMono->GetMonoSize(),0);
	}
	if(m_suNodeSet.size()!=0)
	{
	   set<unChar>::iterator itNode;
	   for(itNode = m_suNodeSet.begin();itNode!=m_suNodeSet.end();itNode++)
	  {
		m_vuNodeKind[m_vuNodeLabel[(*itNode)]]++;
	  }
	}
	else
	{
		vector<unChar>::iterator itLabel;
		for(itLabel = m_vuNodeLabel.begin();itLabel!= m_vuNodeLabel.end();itLabel++)
	  {
		  if(*itLabel==' ')
			  continue;
		m_vuNodeKind[(*itLabel)]++;
	  }

	}

}
double CGlyTree::GetMass()
{
	return m_dMass;
}
void CGlyTree::CalKindMassValue()
{
	time_t start_cal=clock();
	ValueTree();
	time_t end_cal=clock();
	//sum_cal_val+=(end_cal-start_cal);
	CalKind();
	CalMass();
}

void CGlyTree::ComMaxAndGlycome()
{
	///////calculate value of each tree
	int type1=1;
	for(size_t i=0;i<mAllTrees.size();i++)
	{
		mAllTrees[i].ValueTree();
		mAllTrees[i].GlyType=type1<<3;
	}
	for(size_t i=0;i<mMaxTrees.size();i++)
	{
		mMaxTrees[i].ValueTree();
	}
	//////////delete the dedundancy of mAlltrees
	int cnt=0;
	cout<<"after first round elimination, there are "<<mAllTrees.size()<<" structures "<<endl;
	mIsDeleted.resize(mAllTrees.size(),0);
	ofstream mycout("..\\..\\FindN_Glycan\\FindN_Glycan\\same.txt");


///////////���԰��ձ���ֵȥ����
//
//	sort(mAllTrees.begin(),mAllTrees.end(),ComByMass);
//	int curr;
//	for(int i=0;i<mAllTrees.size()-1;i++)
//	{
//	    curr=i;
//		while(mAllTrees[i].m_vuNodeValue==mAllTrees[i+1].m_vuNodeValue)
//			i++;
//		for(int pre=curr;pre<=i-1;pre++)
//		{
//			if(mIsDeleted[pre])
//			    continue;
//		for(size_t next=pre+1;next<=i;next++)
//		{
//			if(mAllTrees[pre]==mAllTrees[next])
//			{
//				mIsDeleted[next]=1,cnt++;
//				mycout<<mAllTrees[pre].mStructName<<"=="<<mAllTrees[next].mStructName<<endl;
//			}
//		}
//		}
//	}
//	////////////////////// above need to be tested

	/////////////////////glycomedb second round elimination
	for(size_t pre=0;pre<mAllTrees.size();pre++)
	{
		if(mIsDeleted[pre])
			continue;
		for(size_t next=pre+1;next<mAllTrees.size();next++)
		{
			/*if(mAllTrees[pre].m_vuNodeKind[3]!=mAllTrees[next].m_vuNodeKind[3])
				continue;*//////has not been tested
			if(mAllTrees[pre]==mAllTrees[next])
			{
				mIsDeleted[next]=1,cnt++;
				mycout<<mAllTrees[pre].mStructName<<"=="<<mAllTrees[next].mStructName<<endl;
			}
		}
	}
	cout<<"Second round of elimination deletes "<<cnt<<" structures"<<endl;

	////////combine two databases
	vector<int>isSame(8000,0);
	int RedunNum=0;
	unInt outcount=0;
	ofstream OutputGlycomedb("N_glycan of GlycomeDB.txt");
	ofstream StructGlycomedb("N_glycan Link of GlycomeDB.txt");
	CEnumerate oEnumGlycans1(6,"srctree.ini");
	for(size_t i=0;i<mAllTrees.size();i++)
	{
		if(mIsDeleted[i])
			continue;
		////////////Output the irredundant glycomedb

		/////ע�⣬���ͨ�ýṹ��Ҳ����������������
		mAllTrees[i].CalKind();
	    mAllTrees[i].CalMass();
		oEnumGlycans1.OutOneTrees(OutputGlycomedb, mAllTrees[i],outcount,oEnumGlycans1.vcRes);
		oEnumGlycans1.OutOneTreeLink(StructGlycomedb,mAllTrees[i],outcount);
		outcount++;


		////////////////////////////////////
		for(size_t j=0;j<mMaxTrees.size();j++)
		{
			if(isSame[j])
			    continue;
			if(mAllTrees[i].mCntNodes==mMaxTrees[j].mCntNodes)
			{
				if(mAllTrees[i]==mMaxTrees[j])
				{
					mAllTrees[i].GlyType=mAllTrees[i].GlyType|mMaxTrees[j].GlyType;
					RedunNum++;
					isSame[j]=1;
				}
			}
		}
	}
	cout<<" outcount "<<outcount<<endl;
	OutputGlycomedb.close();
	StructGlycomedb.close();

///////////////////just try to output the stuctures that glycomedb has particularly
//	for(size_t i=0;i<mMaxTrees.size();i++)
//	{
//		
//		for(size_t j=0;j<mAllTrees.size();j++)
//		{
//			if(mIsDeleted[j])
//			   continue;
//			if(isSame[j])
//			    continue;
//			if(mAllTrees[j].mCntNodes==mMaxTrees[i].mCntNodes)
//			{
//				if(mAllTrees[j]==mMaxTrees[i])
//				{
//					mAllTrees[j].GlyType=mAllTrees[j].GlyType|mMaxTrees[i].GlyType;
//					//cout<<mAllTrees[i].GlyType<<":"<<mAllTrees[i].GlyType<<mMaxTrees[j].GlyType<<endl;
//					RedunNum++;
//					isSame[j]=1;
//				}
//			}
//		}
//	}
	//CEnumerate temppout(6,"maxstructure.ini");

	cout<<" maxdb and glycomedb have both "<<RedunNum<<" structures"<<endl;
	mFinalTrees.clear();
	int glycomenum=0;
	int maxnum=0;
	
	ofstream outglyy("glycomedb owns extrally.txt");
	for(size_t i=0;i<mAllTrees.size();i++)
	{
		//if(!mIsDeleted[i]&&(!isSame[i]))
		if(!mIsDeleted[i])
		{
			mFinalTrees.push_back(mAllTrees[i]);
		    glycomenum++;
			//temppout.OutOneTreeLink(outglyy,mAllTrees[i],glycomenum);
		}
	}
	cout<<" MergeDB contains "<<glycomenum<<" glycome structures "<<endl;
	for(size_t i=0;i<mMaxTrees.size();i++)
	{
		if(!isSame[i])
		{
			mFinalTrees.push_back(mMaxTrees[i]);
			maxnum++;
		}
		
	}
	cout<<" MergeDB contains "<<maxnum<<" max structures "<<endl;
	cout<<"MergeDB contains "<<mFinalTrees.size()<<" structures"<<endl;
	//////////////with Gc
	CGlyTree tempsame;
	vector<CGlyTree> vcRes;
	mFinalTreesWithGc.clear();
	for(size_t i = 0; i < mFinalTrees.size(); ++i) //mFinalTrees.size();
	{
		vcRes.clear();
		mFinalTrees[i].ExtendAc2Gc(vcRes, m_pMono, 0);
		vector<int>IsSame(100000,0);
		for(int j=0;j<vcRes.size();j++)
		{
			if(IsSame[j])
				continue;
<<<<<<< HEAD
			vcRes[j].GlyType = mFinalTrees[i].GlyType;
=======
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
			mFinalTreesWithGc.push_back(vcRes[j]);
			for(int k=j+1;k<vcRes.size();k++)
			{
				if(tempsame.IsSame(vcRes[j],vcRes[k],vcRes[j].mRoot,vcRes[k].mRoot))
				    IsSame[k]=1;
			}
		}
	}
	cout<<"extend Ac to Gc with regard to all trees, resulting in "<<mFinalTreesWithGc.size()<<" trees "<<endl;
}
<<<<<<< HEAD

//bool CGlyTree::ComByMass( const CGlyTree &cTreeA,const CGlyTree &cTreeB )
//{
//	return cTreeA.m_dMass<cTreeB.m_dMass;
//}

///////////////sort by mass and then by codestr
bool CGlyTree::ComByMass(const CGlyTree &cTreeA, const CGlyTree &cTreeB)
{
	return cTreeA.m_dMass<cTreeB.m_dMass;
}


=======
bool CGlyTree::ComByMass( const CGlyTree &cTreeA,const CGlyTree &cTreeB )
{
	return cTreeA.m_dMass<cTreeB.m_dMass;
}
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
void  CGlyTree::InitNameToLabelStand()
{
	mMapNameToLabel["N-acetylgalucosamine"]=1;
	mMapNameToLabel["Mannose"]=0;//Բ
	mMapNameToLabel["Glucose"] =0;
	mMapNameToLabel["Fucose"]=4;//������
	mMapNameToLabel["Sialic"]=2;
}
void  CGlyTree::InitNameToLabelAllStand()
{
	mMapNameToLabel["HexNAc"]=1;
	mMapNameToLabel["Hex"]=0;
	mMapNameToLabel["NeuAc"] =2;
	mMapNameToLabel["NeuGc"] =3;
	mMapNameToLabel["dHex"]=4;
}
//#define MAXN 1000000000000000000//�ڱ�  
#define MAXN pow(2,63)+1
void CGlyTree::ReadOneTreeInfo(ifstream &mycin, CGlyTree &tptTree)
{
	//�ǵ�Ҫ����InitNameToLabelAllStand()
	//Hex:0, HexNAc:1, NeuAc:2, NeuGc:3, dHex:4//����дһ��
	//string MAXN="100000000000000000000";
	tptTree.m_vuNodeLabel.clear();
	tptTree.m_vvuTopology.clear();
	InitNameToLabelAllStand();
	istringstream strcin;
	string line;
	while (getline(mycin, line))
	{//��ȡÿһ���ǽṹ��;
		if (line == "Begin")
			break;
	}
	//cout << " line begin---------- " << line << endl;
	getline(mycin, line);
	strcin.clear();
	strcin.str(line);
	string temptems;
	//string tempvalue;
	double tempvalue;
	strcin >> temptems >> tempvalue;
	if (tempvalue == MAXN)
	{
<<<<<<< HEAD
		//cout << " come here " << endl;
=======
		cout << " come here " << endl;
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
		tptTree.mRoot = 0;
		tptTree.m_vuNodeValue[tptTree.mRoot] = tempvalue;
		return;
	}
	//cout << " line 1 " << line << " temptems " << temptems << " tempvalue " << tempvalue << endl;
	getline(mycin, line);
	//cout << " line 2 " << line << endl;
	tptTree.mStructName = line;
	tptTree.mStructName = "none";
	getline(mycin, line);

	strcin.clear();
	strcin.str(line);
	string tems;
	strcin >> tems >> tptTree.mRoot >> tptTree.mCntNodes;
	tptTree.mRoot -= 1;
	if (tptTree.mRoot != 0)
		cout << "-----------wrong " << endl;
	tptTree.m_vuNodeLabel.resize(tptTree.mCntNodes);
	tptTree.m_vuNodeValue.resize(tptTree.mCntNodes);
	tptTree.str_m_vuNodeValue.resize(tptTree.mCntNodes);
	while (getline(mycin, line))
	{
		if (line == "[Mono]")break;
	}
	string glyname;
	double mass = 0;
	int inputid = 0;
	int id_num = 0;
	//int map_inputid_to_id[50];
	while (getline(mycin, line))
	{//��ȡ�ǵ���������������Ӧ�ı����������;
		if (line == "[Link]")break;
		strcin.clear();
		strcin.str(line);
		strcin >> glyname;
		while (strcin >> inputid)
		{
			//map_inputid_to_id[inputid]=id_num;
			//id_num++;
			tptTree.m_vuNodeLabel[inputid - 1] = mMapNameToLabel[glyname];
		}
	}
	//��ȡ���˹�ϵ;
	tptTree.m_vvuTopology.resize(tptTree.mCntNodes);
	int pre, next, temp_s = 0;
	while (getline(mycin, line))
	{//��ȡ���˹�ϵ;
		if (line.length() == 0)continue;
		if (line == "End")break;
		strcin.clear();
		strcin.str(line);
		strcin >> pre;
		while (strcin >> next)tptTree.m_vvuTopology[pre - 1].push_back(next - 1);
	}
	//tptTree.m_vuNodeValue[tptTree.mRoot]=tempvalue;//����value��double,�����Լ���ɣ�
	tptTree.ValueTree();
}
int CGlyTree::ReadAllTreesInfoAsQueue( ifstream &mycin,queue<CGlyTree>&mTrees,int& EachReadNum)
{
<<<<<<< HEAD
	S2 = clock();
=======
	
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
	istringstream strcin;
	string line;
	InitNameToLabelAllStand();
	while (getline(mycin,line))
	{//��ȡÿһ���ǽṹ��;
		if(line!="Begin")continue;//�˴���Ҫ��׳;
		CGlyTree tptTree;
		getline(mycin,line);
		strcin.clear();
		strcin.str(line);
		string temtems;
		double temvalue;
		strcin>>temtems>>temvalue;
		getline(mycin,line);
		tptTree.mStructName=line;
		tptTree.mStructName="none";
		getline(mycin,line);
		strcin.clear();
		strcin.str(line);
		string tems;
		strcin>>tems>>tptTree.mRoot>>tptTree.mCntNodes;
		tptTree.mRoot-=1;
		while(getline(mycin,line))
		{
			if(line=="[Mono]")break;
		}
		//tptTree.m_vuNodeLabel.resize(tptTree.mCntNodes);
		tptTree.m_vuNodeLabel.resize(tptTree.mCntNodes);//bad idea
		tptTree.m_vuNodeValue.resize(tptTree.mCntNodes);
		tptTree.str_m_vuNodeValue.resize(tptTree.mCntNodes);
		string glyname;
		double mass=0;
		int inputid=0;
		int id_num=0;
		//int map_inputid_to_id[50];
		while(getline(mycin,line))
		{//��ȡ�ǵ���������������Ӧ�ı����������;
			if(line=="[Link]")break;
			strcin.clear();
			strcin.str(line);
			strcin>>glyname;
			while (strcin>>inputid)
			{
				//map_inputid_to_id[inputid]=id_num;
				//id_num++;
				/*if(id<1||id>tptTree.mCntNodes)
				{
					cout<<"�Ǳ�Ŷ�ȡ�Ƿ�"<<endl;
					return;
				}*/
				tptTree.m_vuNodeLabel[inputid-1] = mMapNameToLabel[glyname];
			}
		}
		//��ȡ���˹�ϵ;
		
		tptTree.m_vvuTopology.resize(tptTree.mCntNodes);
		int pre,next,temp_s=0;
		while (getline(mycin,line))
		{//��ȡ���˹�ϵ;
			if(line.length()==0)continue;
			if(line=="End")break;
			strcin.clear();
			strcin.str(line);
			strcin>>pre;
			while(strcin>>next)tptTree.m_vvuTopology[pre-1].push_back(next-1);
		}
		//tptTree.m_vuNodeValue[tptTree.mRoot]=temvalue;//��ȡ�ǽṹ�ı���ֵ
		tptTree.ValueTree();
		mTrees.push(tptTree);
		if(mTrees.size()==EachReadNum)
		{
			cout<<"��ȡ����"<<mTrees.size()<<endl;
			return mTrees.size();
		}
	}
	return mTrees.size();
<<<<<<< HEAD
	E2 = clock();
	IO_time += (E2 - S2);
=======
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
}
void CGlyTree::ReadAllTreesInfo( const char *inFile,vector<CGlyTree>&mTrees)
{
	//mMapNameToLabel["N-acetylgalucosamine"]=1;
	//mMapNameToLabel["Mannose"]=0;//Բ
	//mMapNameToLabel["Glucose"] =0;
	//mMapNameToLabel["Fucose"]=4;//������
	//mMapNameToLabel["Sialic"]=2;= 
	mTrees.clear();
	//mMapNameToLabel["HexNAc"]=1;
	//mMapNameToLabel["Hex"]=0;
	//mMapNameToLabel["NeuAc"] =2;
	//mMapNameToLabel["dHex"]=4;
    //Hex:0, HexNAc:1, NeuAc:2, NeuGc:3, dHex:4//����дһ��
	ifstream mycin(inFile);
	istringstream strcin;
	string line;
	int temp;
	//int ReadNum=0;
	while (getline(mycin,line))
	{//��ȡÿһ���ǽṹ��;
		if(line!="[Begin]")continue;//�˴���Ҫ��׳;
		//ReadNum++;
		CGlyTree tptTree;
		getline(mycin,line);
		strcin.clear();
		strcin.str(line);
		string tems,tems1;
		strcin>>tems>>temp>>tems1>>tptTree.GlyType;
		getline(mycin,line);
		strcin.clear();
		strcin.str(line);
		strcin>>tems>>tptTree.mRoot>>tptTree.mCntNodes;
		tptTree.mRoot-=1;
		while(getline(mycin,line))
		{
			if(line=="[Mono]")break;
		}
		//tptTree.m_vuNodeLabel.resize(tptTree.mCntNodes);
		tptTree.m_vuNodeLabel.resize(tptTree.mCntNodes);//bad idea
		tptTree.m_vuNodeValue.resize(tptTree.mCntNodes);
		tptTree.str_m_vuNodeValue.resize(tptTree.mCntNodes);
		string glyname;
		double mass=0;
		int inputid=0;
		int id_num=0;
		int map_inputid_to_id[50];
		while(getline(mycin,line))
		{//��ȡ�ǵ���������������Ӧ�ı����������;
			if(line=="[Link]")break;
			strcin.clear();
			strcin.str(line);
			strcin>>glyname;
			while (strcin>>inputid)
			{
				map_inputid_to_id[inputid]=id_num;
				id_num++;
				tptTree.m_vuNodeLabel[id_num-1] = mMapNameToLabel[glyname];
			}
		}
		//��ȡ���˹�ϵ;
		
		tptTree.m_vvuTopology.resize(tptTree.mCntNodes);
		int pre,next,temp_s=0;
		while (getline(mycin,line))
		{//��ȡ���˹�ϵ;
			if(line.length()==0)continue;
			if(line=="[End]")break;
			strcin.clear();
			strcin.str(line);
			strcin>>pre;
			if(temp_s==0)
				tptTree.mRoot=map_inputid_to_id[pre];
			temp_s++;
			while(strcin>>next)tptTree.m_vvuTopology[map_inputid_to_id[pre]].push_back(map_inputid_to_id[next]);
		}
		mTrees.push_back(tptTree);
		if(mTrees.size()>=1000000)
			break;
	}
	cout<<"��ȡ����"<<mTrees.size()<<endl;
}
void CGlyTree::ExtendAc2Gc(vector<CGlyTree> &vcSubTrees, CMonoInfo * pMono, size_t tStart){
	if ( tStart == m_vuNodeLabel.size() ) 
	{
		vcSubTrees.push_back(*this);
		return;
	}
	ExtendAc2Gc(vcSubTrees, pMono, tStart + 1);
	if (m_vuNodeLabel[tStart] == pMono->GetLabel("NeuAc")) {
		CGlyTree tree = *this;
		tree.m_vuNodeLabel[tStart] = pMono->GetLabel("NeuGc");
		tree.CalKindMassValue();
		tree.ExtendAc2Gc(vcSubTrees, pMono, tStart + 1);
	}
	
}
void CGlyTree::initvcsub()
{
	vcSubTrees.resize(100);
}
