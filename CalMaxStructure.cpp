#include "CalMaxStructure.h"
#include<time.h>
bool CCalMaxStructure::ComByMass( const CGlyTree &cTreeA,const CGlyTree &cTreeB )
{
	return cTreeA.m_dMass<cTreeB.m_dMass;
}
void CCalMaxStructure::GetMaxTrees(const char *strFile)
{//��ȡͨ�ýṹ;
	m_pCIO->Read(strFile,m_vcMaxTrees);
}
//��������Ac��������Ac����Gc
void CCalMaxStructure::CalGcSubTrees() {
	vector<int>IsSame(500,0);
	CGlyTree tempsame;
	vector<CGlyTree> vcRes;
	m_vvcResTees.clear();

	//////////////without Gc
	for(size_t i = 0; i < m_vcMaxTrees.size(); ++i) 
	{ 
		m_vvcResTees.push_back(m_vcMaxTrees[i]);
	} 

	////////////////with Gc
	//for(size_t i = 0; i < m_vcMaxTrees.size(); ++i) {
	//	vcRes.clear();
	//	m_vcMaxTrees[i].ExtendAc2Gc(vcRes, m_pMono, 0);
	//	for(int j=0;j<vcRes.size();j++)
	//	{
	//		if(IsSame[j])
	//			continue;
	//		m_vvcResTees.push_back(vcRes[j]);
	//		for(int k=j+1;k<vcRes.size();k++)
	//		{
	//			if(tempsame.IsSame(vcRes[j],vcRes[k],vcRes[j].mRoot,vcRes[k].mRoot))
	//			    IsSame[k]=1;
	//		}
	//	}
	//}
}

bool CCalMaxStructure::Is_Comb_N_Glycan(CGlyTree & tptTree, int & root)
{
	//�жϽṹ�Ƿ����5�Ǻ���;
	if (tptTree.m_vuNodeLabel[root] != 1)
		return false;
	vector<int>secondChild;
	int indChild;
	for (size_t indMono = 0; indMono<tptTree.m_vvuTopology[root].size(); indMono++)
	{//�����ڶ���ڵ�;
		indChild = tptTree.m_vvuTopology[root][indMono];
		//if (strInfo.m_vInitalInfo[indChild]>15)//�����ṹ����;
		//	continue;
		if (tptTree.m_vuNodeLabel[indChild] == 1)
			secondChild.push_back(indChild);
	}
	if (secondChild.size() == 0)
		return false;
	vector<int>thirdLevel;
	int nextChild;
	for (size_t indChild = 0; indChild<secondChild.size(); indChild++)
	{
		for (size_t indMono = 0; indMono<tptTree.m_vvuTopology[secondChild[indChild]].size(); indMono++)
		{//����������ڵ�;
			nextChild = tptTree.m_vvuTopology[secondChild[indChild]][indMono];
			if (tptTree.m_vuNodeLabel[nextChild] == 0)
				thirdLevel.push_back(nextChild);
		}
	}
	if (thirdLevel.size() == 0)
		return false;
	vector<int>fourthLevel;
	int cnt = 0;
	for (size_t indChild = 0; indChild<thirdLevel.size(); indChild++)
	{
		cnt = 0;
		for (size_t indMono = 0; indMono<tptTree.m_vvuTopology[thirdLevel[indChild]].size(); indMono++)
		{//�������Ĳ�ڵ�;
			nextChild = tptTree.m_vvuTopology[thirdLevel[indChild]][indMono];
			if (tptTree.m_vuNodeLabel[nextChild] == 0)
			{
				cnt++;
			}
		}
		if (cnt >= 2)
			return true;
	}
	return false;
}

void CCalMaxStructure::ThreeMaxTreeToSubTree()
{
	CEnumerate temppp(6,"maxstructure.ini");
	m_vvcResTees[0].initvcsub();
	int type=1;
	////////////////********************////////////////////���ڵ�������vcSubTrees������ȫ�ֵ�
	cout<<"m_vvcResTees.size() "<<m_vvcResTees.size()<<endl;
	for(int i=0;i<m_vvcResTees.size()-1;i++)
	{
		int tmp=type<<i;
		m_vvcResTees[i].MaxGetFragmentIons(tmp);
		m_vvcResTees[i+1].vcSubTrees=m_vvcResTees[i].vcSubTrees;
		int sum_tree_num=0;
	for(int g=0;g<m_vvcResTees[i].vcSubTrees.size();g++)
	{
		sum_tree_num+=m_vvcResTees[i].vcSubTrees[g].size();
	}
	cout<<" before delete redundancy, the num of subtrees of "<<i+1<<" maxtrees is "<<sum_tree_num<<endl;
	}
	int tempp=type<<(m_vvcResTees.size()-1);
	m_vvcResTees[m_vvcResTees.size()-1].MaxGetFragmentIons(tempp);
	

	////////////////////combine the subtrees of three maxtrees
	vector<CGlyTree> ComSubTrees;//ComSubTrees �洢�����������ͨ�ýṹ�����з�����������
	
	int ThirdTreeNodeNum=m_vvcResTees[m_vvcResTees.size()-1].GetSetSize();
	cout<<"MaxTreeSize"<<ThirdTreeNodeNum<<endl;
	for(size_t i=0;i<ThirdTreeNodeNum;i++)//m_vcMaxTrees[2].vcSubTrees  
	{
		vector<int> isDelete(5000,0);
		for(size_t j=0;j<m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i].size();j++)
		{
			if(isDelete[j])
				continue;
			
			for(size_t k=j+1;k<m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i].size();k++)
			{
				if(m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i][j]==m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i][k])
				{	
					m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i][j].GlyType=(m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i][j].GlyType|m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i][k].GlyType);
					isDelete[k]=1;
				}
			}
			ComSubTrees.push_back(m_vvcResTees[m_vvcResTees.size()-1].vcSubTrees[i][j]);
		}	
	}
	/////////����������������Ƭ������������������������Ƭ������ļ��С�
	ofstream myccout("AllStand_GlycanMAX_pGlyco.txt");
	ofstream structout("AllStand_GlycanMAX_pGlyco_Link.txt");
	unInt outnum=0;
	cout<<"begin to output AllStand"<<endl;
	for(size_t i=0;i<ComSubTrees.size();i++)
	{
		ComSubTrees[i].CalMass();
<<<<<<< HEAD
		if (1==1)
		//////////////////////if (Is_Comb_N_Glycan(ComSubTrees[i], ComSubTrees[i].mRoot))///////�����������ж��Ƿ�ΪN_�ǵģ��ǳ���Ҫ������
=======
		if (Is_Comb_N_Glycan(ComSubTrees[i], ComSubTrees[i].mRoot))
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
		{
			temppp.OutOneTrees(myccout,  ComSubTrees[i], outnum,temppp.vcRes);
			temppp.OutOneTreeLink(structout,ComSubTrees[i],outnum);//����������Link�ṹ
			outnum++;
		}
	}
	myccout.close();
	structout.close();
	cout<<"AllStand tree num is "<<outnum<<endl;
	cout<<"subtree fragment end "<<endl;

}