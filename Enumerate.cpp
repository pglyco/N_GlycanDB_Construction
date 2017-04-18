#include "Enumerate.h"
<<<<<<< HEAD
time_t S1, E1, IO_time = 0;
=======
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
CEnumerate::CEnumerate( int size,const char *startTreeFile )
{
	if(size<0)
	{
		cout<<"the number of tree is error!"<<endl;
		return ;
	}
	pMono = CMonoInfo::GetMono("mono.ini");
	CRead * pRead = new CReadAllStruct(pMono);
	pRead->Read(startTreeFile,m_vSmallTrees);
	m_MaxSize = size;
	InitalizeIndex();
	delete pRead;
	pRead = NULL;
}
bool CEnumerate::ComByMass( const CGlyTree &cTreeA,const CGlyTree &cTreeB )
{
	return cTreeA.m_dMass<cTreeB.m_dMass;
}

//////////////new compare function
bool CEnumerate::ComByValue( const CGlyTree &cTreeA,const CGlyTree &cTreeB )
{
	return cTreeA.m_vuNodeValue[cTreeA.mRoot]<cTreeB.m_vuNodeValue[cTreeB.mRoot];
}
bool CEnumerate::OutOneTreeWithoutProduceFrag( ofstream &mycout, CGlyTree &cTree, unInt &size,vector<CGlyTree> &vcRes)
{
	const int GlyVecNum=5;
	//vcRes.clear();
	//求这个树的每个小结构;
	///////////without restriction
	//cTree.GetFragmentIons(vcRes);
	vector<CGlyTree>::iterator iter;
	for(iter=vcRes.begin();iter!=vcRes.end();iter++)
		(*iter).CalMass();

	/////////with restriction
	//if(cTree.GetFragmentIons(vcRes)==false)//如果这棵树不合理，则不输出。
	//{
	//	 return false;//cTree.GetFragmentIons(vcAllRes);//给定一棵树，生成这棵树的所有子树并去冗余（包括镜像）
	//}
	sort(vcRes.begin(),vcRes.end(),ComByMass);//生成碎片离子，并将碎片离子按质量排序
	mycout.setf(ios::fixed);
	mycout.precision(6);
	mycout<<"Begin"<<endl;
	mycout<<"DBID=\t0\tGLYID=\t"<<size<<endl;
	mycout<<"Struct=\t0"<<endl;
	mycout<<"Mass=\t"<<cTree.m_dMass<<endl;
	mycout<<"kind=\t";
	vector<unChar>::iterator itKind;
	for(itKind=cTree.m_vuNodeKind.begin();itKind!=cTree.m_vuNodeKind.end();itKind++)
	{
		mycout<<(int)(*itKind)<<"\t";//////////why need to change into int?
	}
		mycout<<endl;
	mycout<<"Ions:"<<endl;
	for(size_t i=0;i<vcRes.size()-1;i++)
	{
		if (i>0 && vcRes[i].m_vuNodeKind == vcRes[i - 1].m_vuNodeKind)
		{
			cout << " i " << i << endl;
			continue;
		}
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
	vcRes.clear();
	return true;
}

void CEnumerate::OutOneTreeLinkPlusValue(ofstream &structout, CGlyTree &arry, unInt &size)
{//输出成最大通用结构的形式;
<<<<<<< HEAD
	S1 = clock();
=======
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
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
<<<<<<< HEAD
	structout << "Value=\t" << arry.str_m_vuNodeValue[arry.mRoot] <<"\t";//输出糖结构的value值，以便归并的时候可以直接读取从而去冗余。
	
	structout << "kind=\t";
	vector<unChar>::iterator itKind;
	for (itKind = arry.m_vuNodeKind.begin(); itKind != arry.m_vuNodeKind.end(); itKind++)
	{
		structout << (int)(*itKind) << "\t";//////////why need to change into int?
	}
	structout << endl;

	/////structout << "Value=\t" << arry.str_m_vuNodeValue[arry.mRoot] << endl;
=======
	structout << "Value=\t" << arry.str_m_vuNodeValue[arry.mRoot] << endl;//输出糖结构的value值，以便归并的时候可以直接读取从而去冗余。
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
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
<<<<<<< HEAD
	E1 = clock();
	IO_time += E1 - S1;
=======
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
}

bool CEnumerate::OutOneTrees( ofstream &mycout,  CGlyTree &cTree, unInt &size,vector<CGlyTree> &vcRes)
{
	const int GlyVecNum=5;
	vcRes.clear();
	//求这个树的每个小结构;

	/////////////without restriction
	//cTree.GetFragmentIons(vcRes);

	/////with restriction
	if(!cTree.GetFragmentIons(vcRes))//如果这棵树不合理，则不输出。
	{
		 return false;//cTree.GetFragmentIons(vcAllRes);//给定一棵树，生成这棵树的所有子树并去冗余（包括镜像）
	}
	vector<CGlyTree>::iterator iter;
	for(iter=vcRes.begin();iter!=vcRes.end();iter++)
		(*iter).CalMass();
	
	sort(vcRes.begin(),vcRes.end(),ComByMass);//生成碎片离子，并将碎片离子按质量排序
	mycout.setf(ios::fixed);
	mycout.precision(6);
	mycout<<"Begin"<<endl;
	mycout<<"GLYID=\t"<<size<<" GLYTYPE=\t"<<cTree.GlyType<<endl;
	mycout<<"Struct=\t0"<<endl;
	mycout<<"Mass=\t"<<cTree.GetMass()<<endl;
<<<<<<< HEAD
	if (cTree.m_suNodeSet.size() != 0)
		mycout << "rootAndnodes\t" << (cTree.mRoot + 1) << "\t" << cTree.m_suNodeSet.size() << endl;
	else
		mycout << "rootAndnodes\t" << (cTree.mRoot + 1) << "\t" << cTree.m_vuNodeLabel.size() << endl;
	mycout << "GlyStr=\t" << cTree.str_m_vuNodeValue[cTree.mRoot]<<endl;

	mycout << "kind=\t";
=======
	mycout<<"kind=\t";
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
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
typedef int LoserTree[5000];
int k;
struct _LsNode
{
 double key;
};

CGlyTree b[5001];//[0……k-1]是败者树的叶子，[k]存储的是最小关键字
void CEnumerate::swap(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}
void CEnumerate::Adjust(LoserTree Ls,int s,int k)
{//沿从叶子结点全局变量b[s]到根结点全局变量ls[1]的路径调整败者树，胜者存ls[0]
 int i,t;
 t=(k+s)/2;//t是全局变量b[s]的双亲结点的序号
 for(t=(k+s)/2;t>0;t/=2)//t>0表示t还在败者树上，t/=2为b[s]的双亲结点的双亲结点序号
 {
	 if(b[s].m_vuNodeValue[b[s].mRoot]>b[Ls[t]].m_vuNodeValue[b[Ls[t]].mRoot])//当b[s]的关键字大于其双亲结点的关键字时，变换
        swap(s,Ls[t]);
 }
 Ls[0]=s;
}

void CEnumerate::CreateLoserTree(LoserTree Ls,unInt &k)
{
	
 int i;
 b[k].mRoot=0;
 b[k].m_vuNodeValue[b[k].mRoot]=0;
 for(i=0;i<k;i++)
  Ls[i]=k;
 for(i=k-1;i>=0;i--)
  Adjust(Ls,i,k);
 
}

<<<<<<< HEAD
////////// This output is aimed for glycan extension, VIP
//unInt & CEnumerate::OutOneTreeAndTreeLinkPlusValue(ofstream & FinalOut, ofstream & FinalOutLink, CGlyTree & newArry, vector<CGlyTree> & vcRes, unInt & GlyId)
//{
//	CGlyTree tempsame;
//	vector<CGlyTree> vcResTemp;
//	vector<CGlyTree> newArryWithGc;
//	newArryWithGc.clear();
//	vcResTemp.clear();
//	newArry.ExtendAc2Gc(vcResTemp, m_pMono, 0);///输出到临时文件的都是合理的糖结构
//	vector<int>IsSame(100000, 0);
//	for (int j = 0; j<vcResTemp.size(); j++)
//	{
//		vcResTemp[j].ValueTree();
//		if (IsSame[j])
//			continue;
//		vcResTemp[j].CalKind();
//		vcResTemp[j].CalMass();
//		OutOneTrees(FinalOut, vcResTemp[j], GlyId, vcRes);
//		OutOneTreeLinkPlusValue(FinalOutLink, vcResTemp[j], GlyId);
//		GlyId++;
//		for (int k = j + 1; k<vcResTemp.size(); k++)
//		{
//			if (tempsame.IsSame(vcResTemp[j], vcResTemp[k], vcResTemp[j].mRoot, vcResTemp[k].mRoot))
//				IsSame[k] = 1;
//		}
//	}
//	return GlyId;
//}
//////////This output is NOT aimed for glycan extension
unInt & CEnumerate::OutOneTreeAndTreeLinkPlusValue(ofstream & FinalOut, ofstream & FinalOutLink, CGlyTree & newArry, vector<CGlyTree> & vcRes, unInt & GlyId)
{
	OutOneTreeLinkPlusValue(FinalOutLink, newArry, GlyId);
	GlyId++;
	return GlyId;
}






//#define MAXN pow(2,63)+1
extern unsigned long long MAXN=pow(2,63)+1;
double epsilon=0.000000000006;
void CEnumerate::K_Merge(LoserTree Ls,unInt NodeNum,unInt &k)
=======

unInt & CEnumerate::OutOneTreeAndTreeLinkPlusValue(ofstream & FinalOut, ofstream & FinalOutLink, CGlyTree & newArry, vector<CGlyTree> & vcRes, unInt & GlyId)
{
	CGlyTree tempsame;
	vector<CGlyTree> vcResTemp;
	vector<CGlyTree> newArryWithGc;
	newArryWithGc.clear();
	vcResTemp.clear();
	newArry.ExtendAc2Gc(vcResTemp, m_pMono, 0);///输出到临时文件的都是合理的糖结构
	vector<int>IsSame(100000, 0);
	for (int j = 0; j<vcResTemp.size(); j++)
	{
		vcResTemp[j].ValueTree();
		if (IsSame[j])
			continue;
		vcResTemp[j].CalKind();
		vcResTemp[j].CalMass();
		OutOneTrees(FinalOut, vcResTemp[j], GlyId, vcRes);
		OutOneTreeLinkPlusValue(FinalOutLink, vcResTemp[j], GlyId);
		GlyId++;
		for (int k = j + 1; k<vcResTemp.size(); k++)
		{
			if (tempsame.IsSame(vcResTemp[j], vcResTemp[k], vcResTemp[j].mRoot, vcResTemp[k].mRoot))
				IsSame[k] = 1;
		}
	}
	return GlyId;
}
//#define MAXN pow(2,63)+1
extern unsigned long long MAXN=pow(2,63)+1;
double epsilon=0.000000000006;
void CEnumerate::K_Merge(LoserTree Ls,unInt NodeNum,unInt &k,ofstream& OutSameCodeRedunTreeFile,ofstream& OutDifCodeFile,ofstream& SameCodeIrredunFile)
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
{
	char outnamelink[200];
	char outname[200];
    sprintf( outnamelink,"GlycanDB_pGlyco_Link with %d nodes.txt",NodeNum);
	sprintf( outname,"GlycanDB_pGlyco with %d nodes.txt",NodeNum);
	ofstream FinalOutLink(outnamelink);
	ofstream FinalOut(outname);
	ifstream* mycin=new ifstream [5000];
	CGlyTree* A=new CGlyTree[40000];
	CGlyTree TempRead;
	for(int ii=0;ii<k;ii++)
	{//打开所有k路输出文件
		 char subfname[200];
		 sprintf( subfname,"GlycanDB_pGlyco_Link_Subfile%d",ii);
		 mycin[ii].open(subfname);
		 if (!mycin[ii])
		 {
			 cout<<"we have only "<<ii<<" subfiles."<<endl;
			 k=ii;
			 break;
		 }
		b[ii].m_vuNodeLabel.resize(NodeNum,-1);
		b[ii].m_vuNodeValue.resize(NodeNum,0);
		b[ii].str_m_vuNodeValue.resize(NodeNum, "0");
		b[ii].m_vvuTopology.resize(NodeNum);
		b[ii].m_dMass = 0.0;
		TempRead.ReadOneTreeInfo(mycin[ii],b[ii]);
	}
	b[k].m_vuNodeValue.resize(NodeNum,0);
	b[k].str_m_vuNodeValue.resize(NodeNum, "0");
    CreateLoserTree(Ls,k); 
	int q;
	int i=0;
	unInt GlyId=0;   
	while(b[Ls[0]].m_vuNodeValue[b[Ls[0]].mRoot] != MAXN)
	{
		//存储b中最小值的位置，对应一路文件
		q = Ls[0];//输出之前需要保证临时文件中的元素按质量非降序排列的。
		A[i]=b[q];
		if(i==0||A[i].m_vuNodeValue[A[i].mRoot]==A[i-1].m_vuNodeValue[A[i-1].mRoot])
		{
				i++;
				TempRead.ReadOneTreeInfo(mycin[q],b[q]);
			    Adjust(Ls,q,k);
				if(b[Ls[0]].m_vuNodeValue[b[Ls[0]].mRoot]== MAXN)
				{
				   A[i-1].CalKind();///输出到临时文件的都是合理的糖结构
				   A[i-1].CalMass();
				   GlyId = OutOneTreeAndTreeLinkPlusValue(FinalOut,FinalOutLink, A[i-1], vcRes, GlyId);
				}
				    continue;
		}
			if(i==1&&A[i].m_vuNodeValue[A[i].mRoot]!=A[i-1].m_vuNodeValue[A[i-1].mRoot])
			{
				A[i-1].CalKind();
				A[i-1].CalMass();
				GlyId = OutOneTreeAndTreeLinkPlusValue(FinalOut, FinalOutLink, A[i - 1], vcRes, GlyId);
				A[0]=A[1];
				TempRead.ReadOneTreeInfo(mycin[q],b[q]);
			    Adjust(Ls,q,k);
				if(b[Ls[0]].m_vuNodeValue[b[Ls[0]].mRoot]== MAXN)
				{
				   A[0].CalKind();
				   A[0].CalMass();
				   GlyId = OutOneTreeAndTreeLinkPlusValue(FinalOut, FinalOutLink, A[0], vcRes, GlyId);
				}
				continue;
			}
	    A[i-1].CalKind();
		A[i-1].CalMass();
		OutOneTrees(FinalOut, A[i-1], GlyId,vcRes);
		OutOneTreeLinkPlusValue(FinalOutLink,A[i-1],GlyId);
		A[0]=A[i];
		TempRead.ReadOneTreeInfo(mycin[q],b[q]);
		Adjust(Ls,q,k);
		if(b[Ls[0]].m_vuNodeValue[b[Ls[0]].mRoot]== MAXN)
		{
				   A[0].CalKind();
				   A[0].CalMass();
				   GlyId = OutOneTreeAndTreeLinkPlusValue(FinalOut, FinalOutLink, A[0], vcRes, GlyId);			   
		}
		i=1;
	}
	for(int i=0;i<k;i++)
		mycin[i].close();
	FinalOutLink.close();
	FinalOut.close();
	delete []A;
}
CEnumerate TempGlobal(6,"maxstructure.ini");
//time_t start1=clock();
//time_t start2=clock();
//double time_all;
/////以相等的编码值为集合去冗余
<<<<<<< HEAD
int CEnumerate::DeleteRedundancyAccordCode(vector<CGlyTree>& mTestTrees,unInt size)
=======
int CEnumerate::DeleteRedundancyAccordCode(ofstream& SameCodeRedunFile,ofstream& DifCodeFile,ofstream& SameCodeIrredunFile,vector<CGlyTree>& mTestTrees,unInt size)
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
{
	sort(mTestTrees.begin(),mTestTrees.end(),ComByValue);
	int start,end;
	bool *IsRedun=new bool[5000000];
	for(int i=0;i<5000000;i++)
		IsRedun[i]=0;
	//memset(IsRedun,0,sizeof(IsRedun));
	int UnRedunNum=0;
	unInt OutNum=0;
	unInt SameCodeRedunNum=0;
	unInt SameCodeIrredunNum=0;
	unInt DifCodeNum=0;
	for(int i=0;i<size-1;i++)
	{
	  if(mTestTrees[i].m_vuNodeValue[mTestTrees[i].mRoot]==mTestTrees[i+1].m_vuNodeValue[mTestTrees[i+1].mRoot])
	  {
		start=i;
		while(i<size-1&&mTestTrees[i].m_vuNodeValue[mTestTrees[i].mRoot]==mTestTrees[i+1].m_vuNodeValue[mTestTrees[i+1].mRoot])
		{
			i++;
		}
		 for(int j=start;j<=i;j++)
		 {
			 if(IsRedun[j])
				 continue;
			 mTestTrees[UnRedunNum++]=mTestTrees[j];
			 for(int k=j+1;k<=i;k++)
			 {
			   if(mTestTrees[j]==mTestTrees[k])
			   {
				   IsRedun[k]=1;
			   }
			 }
		 }

		 if (i == size - 2)
		 {
			 mTestTrees[UnRedunNum++] = mTestTrees[i + 1];
		 }
	  }
	  else
	  {
        mTestTrees[UnRedunNum++]=mTestTrees[i];
		if(i==size-2)
		{
			mTestTrees[UnRedunNum++]=mTestTrees[i+1];
		} 
	  }
	}
	delete []IsRedun;
	return UnRedunNum;
}

unInt CEnumerate::IrredundantGlycansExtensionAndOutput(ofstream& structout, ofstream & structoutLink, CGlyTree & newArry, unInt & RealSum)
{
	////////////////////Added again 2016/09/26
	////////////// Extend NewArry to those with Gc//// 如果糖结构本身不合理，则扩展后也同样不合理。因此，我们只对非冗余且合理的糖结构进行扩展。
	CGlyTree tempsame;
	vector<CGlyTree> vcResFrag;
	vector<CGlyTree> vcResExtend;
	vector<CGlyTree> newArryWithGc;
	newArryWithGc.clear();
	if (!newArry.GetFragmentIons(vcResFrag))
		return RealSum;
	vcResExtend.clear();
	newArry.ExtendAc2Gc(vcResExtend, m_pMono, 0);
	vector<int>IsSame(100000, 0);
	for (int j = 0; j<vcResExtend.size(); j++)
	{
		vcResExtend[j].ValueTree();
		if (IsSame[j])
			continue;
		vcResExtend[j].CalKind();
		vcResExtend[j].CalMass();
		vcResFrag.clear();
		vcResExtend[j].GetFragmentIons(vcResFrag);
		OutOneTreeWithoutProduceFrag(structout, vcResExtend[j], RealSum, vcResFrag);
		OutOneTreeLinkPlusValue(structoutLink, vcResExtend[j], RealSum);
		RealSum++;
		for (int k = j + 1; k<vcResExtend.size(); k++)
		{
			if (tempsame.IsSame(vcResExtend[j], vcResExtend[k], vcResExtend[j].mRoot, vcResExtend[k].mRoot))
				IsSame[k] = 1;
		}
	}
	return RealSum;
}

void CEnumerate::IrredundantGlycansExtension(vector<CGlyTree> & newArry, int & testnum)
{
	////////////// Extend NewArry to those with Gc//// 如果糖结构本身不合理，则扩展后也同样不合理。因此，我们只对非冗余且合理的糖结构进行扩展。
	CGlyTree tempsame;
	vector<CGlyTree> vcResFrag;
	vector<CGlyTree> vcResExtend;
	vector<CGlyTree> newArryWithGc;
	newArryWithGc.clear();
	for (size_t i = 0; i < testnum; ++i) //mFinalTrees.size();
	{
		if (!newArry[i].GetFragmentIons(vcResFrag))
			continue;
		vcResExtend.clear();
		newArry[i].ExtendAc2Gc(vcResExtend, m_pMono, 0);
		vector<int>IsSame(100000, 0);
		for (int j = 0; j<vcResExtend.size(); j++)
		{
			vcResExtend[j].ValueTree();
			if (IsSame[j])
				continue;
			newArryWithGc.push_back(vcResExtend[j]);
			for (int k = j + 1; k<vcResExtend.size(); k++)
			{
				if (tempsame.IsSame(vcResExtend[j], vcResExtend[k], vcResExtend[j].mRoot, vcResExtend[k].mRoot))
					IsSame[k] = 1;
			}
		}
	}
	newArry = newArryWithGc;
	cout << "extend Ac to Gc with regard to all trees, resulting in " << newArryWithGc.size() << " trees " << endl;
}


void CEnumerate::ProduceAllTrees()
{//Enumerate all structures;
	if(m_vSmallTrees.size()==0){
		cout<<"Initialize of mSmallTrees is error,please check"<<endl;
		return;
	}
	unsigned cntTotal=0;
	queue<CGlyTree> startArry;
	m_vSmallTrees[0].GenerateLogPrime();
	m_vSmallTrees[0].m_suNodeSet.clear();
	m_vSmallTrees[0].GetFragmentIons(vcRes);//生成五糖核心的碎片离子
	m_vSmallTrees[0].CalMass();
	startArry.push(m_vSmallTrees[0]);
	vector<CGlyTree> newArry;
	set<unChar>::iterator iter;
	vector<CGlyTree>::iterator iterGly;
	vector<CGlyTree> startArryVec;
	CGlyTree tempTree;
	startArryVec.clear();
<<<<<<< HEAD
	m_MaxSize=6;
	unInt sub_count;
	char* s="GlycanDB_pGlyco_Link_Subfile";
	char subreadname[200];
	int EachReadNum = 1000000;// 5000;// 80000;//000;
	m_pMono = CMonoInfo::GetMono("mono.ini");
	bool Flag_Rational;
	time_t start = clock();
=======
	m_MaxSize=3;
	unInt sub_count;
	char* s="GlycanDB_pGlyco_Link_Subfile";
	char subreadname[200];
	int EachReadNum = 1000;// 5000;// 80000;//000;
	m_pMono = CMonoInfo::GetMono("mono.ini");
	bool Flag_Rational;
	ofstream OutSameCodeRedunTreeFile("SameCodeRedun.txt");
	ofstream OutDifCodeFile("DifCode.txt");
	ofstream SameCodeIrredunFile("SameCodeIrredun.txt");
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
	for(unInt i=1;i<=m_MaxSize;i++)
	{
		//求每一个size对应的糖结构;
	    cout<<" node "<<i+5<<endl;
	    sub_count=0;
		int ReadNum;
		newArry.clear();
		//把11个节点的糖集合读到startArry中，注意这里startArry是queue。
		sprintf( subreadname,"GlycanDB_pGlyco_Link with %d nodes.txt",i+4);
		ifstream mycin(subreadname);
		if(true)
		{
		  if(i!=1)
		     ReadNum=tempTree.ReadAllTreesInfoAsQueue(mycin,startArry,EachReadNum);
		  else
			 ReadNum=1;
		  while(ReadNum)
		 {
			 unInt tempsize=startArry.size();
		     for(size_t j=0;j<tempsize;j++)
		    {
			//在size-1结构基础上生长出来;
			    for(int initer=0;initer<i+4;initer++)
			//for(iter=startArry.front().m_suNodeSet.begin();iter!=startArry.front().m_suNodeSet.end();iter++)
			  {
				//每个节点都添加一个单糖;
				 Flag_Rational=true;
				 unChar label = startArry.front().m_vuNodeLabel[initer];
				 if(startArry.front().m_vvuTopology[initer].size()>=BranchLimit[label])
					 continue;////去掉规则1 验证枚举库是否包含合并库
				 for(int l=0;l<MONOSIZE;l++)
				 {
					 if(!MonoExist[l])continue;
					 CGlyTree copy = startArry.front();
					 vector<unChar>newLeaf;
					 copy.m_vvuTopology.push_back(newLeaf);
					 copy.m_vvuTopology[initer].push_back(i+4);
					 copy.m_vuNodeLabel.push_back(l);
					 copy.m_vuNodeValue.push_back(0);
					 copy.str_m_vuNodeValue.push_back("0");
					 copy.ValueTree();
	                 copy.m_dMass += m_pMono->GetMass(l);
				     newArry.push_back(copy);
				}
			 }
			startArry.pop();
		    if(newArry.size()>=EachReadNum&&i!=1)//为了能按照subfile输出6个节点的糖集合，只好不能保证一棵树的扩展是否完成了。
			{
				char* subfname=new char[200];
				sprintf(subfname,"%s%d",s,sub_count);
				ofstream structoutsub(subfname);
				sort(newArry.begin(),newArry.end(),ComByValue);
				unInt sumtempp=0;
				unInt RealSum=0;
<<<<<<< HEAD
				int testnum=DeleteRedundancyAccordCode(newArry,newArry.size());
=======
				int testnum=DeleteRedundancyAccordCode(OutSameCodeRedunTreeFile,OutDifCodeFile,SameCodeIrredunFile,newArry,newArry.size());
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
				for (int r = 0; r<testnum; r++)
				{
					if(newArry[r].GetFragmentIons(vcRes))
					{
					   OutOneTreeLinkPlusValue(structoutsub, newArry[r], RealSum);
				       RealSum++;
					}
				}
				structoutsub<<"Begin"<<endl;
                structoutsub<<"Mass=\t"<<MAXN;
				structoutsub.close();
				newArry.clear();
				sub_count++;

			}
		}
		 if(i!=1) 
		     ReadNum=tempTree.ReadAllTreesInfoAsQueue(mycin,startArry,EachReadNum);
		 else
			 break;
		}
		}
	   if(newArry.size())
	  {
		  sort(newArry.begin(),newArry.end(),ComByValue);
		  char* subfnameLink=new char[200];
		  if(sub_count==0)
		  {
			  char* subfname=new char[200];
			  cout<<"i is "<<i<<endl;
			  sprintf(subfnameLink,"GlycanDB_pGlyco_Link with %d nodes.txt",i+5);
			  sprintf(subfname,"GlycanDB_pGlyco with %d nodes.txt",i+5);
			  ofstream structoutLink(subfnameLink);
			  ofstream structout(subfname);
			  unInt sumtempp=0;
				unInt RealSum=0;
<<<<<<< HEAD
			    int testnum=DeleteRedundancyAccordCode(newArry,newArry.size());
=======
			    int testnum=DeleteRedundancyAccordCode(OutSameCodeRedunTreeFile,OutDifCodeFile,SameCodeIrredunFile,newArry,newArry.size());
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
				for (int r = 0; r < testnum; r++)
				{
					if(newArry[r].GetFragmentIons(vcRes))
					{
					  newArry[r].CalKind();
				      newArry[r].CalMass();
				      OutOneTreeWithoutProduceFrag(structout,newArry[r],RealSum,vcRes);
				      OutOneTreeLinkPlusValue(structoutLink,newArry[r],RealSum);
					  RealSum++;
					}			   
				}
			  newArry.clear();
			  delete []subfname;
		  }
		  else
		  {
	            sprintf(subfnameLink,"%s%d",s,sub_count);
				ofstream structoutsubLink(subfnameLink);
				unInt sumtempp=0;
				unInt RealSum=0;
<<<<<<< HEAD
				int testnum=DeleteRedundancyAccordCode(newArry,newArry.size());
=======
				int testnum=DeleteRedundancyAccordCode(OutSameCodeRedunTreeFile,OutDifCodeFile,SameCodeIrredunFile,newArry,newArry.size());
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
				for (int r = 0; r<testnum; r++)
				{
					if(newArry[r].GetFragmentIons(vcRes))
					{
                       OutOneTreeLinkPlusValue(structoutsubLink,newArry[r],RealSum);
				       RealSum++;
					}
				}
				newArry.clear();
				if(RealSum)
				{
				sub_count++;
				structoutsubLink<<"[Begin]"<<endl;
                structoutsubLink<<"Mass=\t"<<MAXN;
				structoutsubLink.close();
				}
				cout<<" sub_count "<<sub_count<<endl;

		  }
		delete []subfnameLink;
	}
	if(sub_count> 1)
	{
	   LoserTree Ls;
	   cout<<"begin to merge"<<endl;
<<<<<<< HEAD
	   K_Merge(Ls,i+5,sub_count);//k路合并排序
=======
	   K_Merge(Ls,i+5,sub_count,OutSameCodeRedunTreeFile,OutDifCodeFile,SameCodeIrredunFile);//k路合并排序
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
	}
	if(sub_count==1)
		cout<<"you need to deal with this "<<endl;
	   mycin.close();
	}
<<<<<<< HEAD
	time_t end = clock();
	cout << (end - start - IO_time) / 1000.0 << endl;
	cout << " IO_time " << IO_time / 1000. << endl;
=======
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
	cout<<" fragment end "<<endl;
}

void CEnumerate::OutOneTreeLink(ofstream &structout,CGlyTree &arry,unInt &size)
{//输出成最大通用结构的形式;
	const int GlyKindNum=5;
	for(unInt j =0;j<GlyKindNum;j++)
		nodeID[j].clear();
	set<unChar>::iterator iterSet;
	if(arry.m_suNodeSet.size()!=0)
	{
	 for(iterSet=arry.m_suNodeSet.begin();iterSet!=arry.m_suNodeSet.end();iterSet++)
	 {
		nodeID[(int)arry.m_vuNodeLabel[*iterSet]].push_back(*iterSet+1);
	 }
	}
	else
	{
		for(int j=0;j<arry.m_vuNodeLabel.size();j++)
	  {
		nodeID[(int)arry.m_vuNodeLabel[j]].push_back(j+1);
	  }
	}
	const int Maxnum=5;
	structout<<"[Begin]"<<endl;
	structout<<"GLYID=\t"<<size<<" GLYTYPE=\t"<<arry.GlyType<<endl;//<<"TOTALNODES=\t"<<mFinalTrees[size].m_vuNodeLabel.size()<<endl;
	/*for(int s=3;s>=0;s--)
		structout<<(arry.GlyType>>s&1);
	structout<<endl;*/
	if(arry.m_suNodeSet.size()!=0)
	    structout<<"rootAndnodes\t"<<(arry.mRoot+1)<<"\t"<<arry.m_suNodeSet.size()<<endl;
	else
		structout<<"rootAndnodes\t"<<(arry.mRoot+1)<<"\t"<<arry.m_vuNodeLabel.size()<<endl;
	structout<<"[Mono]"<<endl;
	for(size_t j =0;j<Maxnum;j++)
	{
			if(nodeID[j].size()>0)
			{
				structout<<pMono->GetMonoName(j)<<"\t";
				for(size_t k=0;k<nodeID[j].size();k++)
				{
					structout<<nodeID[j][k]<<"\t";
				}
				structout<<endl;
			}
	}
		structout<<"[Link]"<<endl;
		for(size_t j=0;j<arry.m_vvuTopology.size();j++){
			if(arry.m_vvuTopology[j].size()>0){
				structout<<j+1<<"\t";
				for(size_t k=0;k<arry.m_vvuTopology[j].size();k++){
					structout<<arry.m_vvuTopology[j][k]+1<<"\t";
				}
				structout<<endl;
			}
		}
		structout<<"[End]"<<endl;	
}
void CEnumerate::OutTreeIonsLink(ofstream &mycout,vector<CGlyTree> &arry)
{//输出成最大通用结构的形式;
	CMonoInfo *pMono = CMonoInfo::GetMono("mono.ini");
	vector<CGlyTree> *pArry = NULL;
	for(size_t i=0;i<arry.size();i++){
		mycout<<"TOTALNODES=\t"<<arry[i].m_suNodeSet.size()<<endl;
		mycout<<"[MONO]"<<endl;
		for(size_t j=0;j<pMono->GetMonoSize();j++){
			if(arry[i].m_vuNodeKind[j]){
				mycout<<pMono->GetMonoName(j)<<"\t";
				set<unChar>::iterator iter;
				for(iter=arry[i].m_suNodeSet.begin();iter!=arry[i].m_suNodeSet.end();iter++){
					if(arry[i].m_vuNodeLabel[*iter] == j){
						mycout<<(*iter+1)<<" ";
					}
				}
				mycout<<endl;
			}
		}
		mycout<<"[Link]"<<endl;
		for(size_t j=0;j<arry[i].m_vvuTopology.size();j++){
			if(arry[i].m_vvuTopology[j].size()>0)
			{
				mycout<<j+1<<"\t";
				for(size_t k=0;k<arry[i].m_vvuTopology[j].size();k++)
					mycout<<(arry[i].m_vvuTopology[j][k]+1)<<" ";
				mycout<<endl;
			}
		}
		mycout<<"[End]"<<endl;
	}
	
}
void CEnumerate::InitalizeIndex()
{
	iHex = pMono->GetLabel(string("Hex"));
	iHexNAc = pMono->GetLabel("HexNAc");
	iNeuAc = pMono->GetLabel("NeuAc");
	idHex = pMono->GetLabel("dHex");
	iXyl = pMono->GetLabel("Xyl");
}
CEnumerate::~CEnumerate()
{
	pMono = NULL;
}
unInt CEnumerate::iXyl=0;

unInt CEnumerate::iNeuAc=0;

unInt CEnumerate::idHex=0;

unInt CEnumerate::iHexNAc=0;

unInt CEnumerate::iHex =0;


