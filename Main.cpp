////�����µĶ�̬�滮�ķ�����ֻ�����������нṹ����Ƭ����֮�󣬲��ܶ���Ƭ���Ӽ���ȥ�������ࡣ



#include "AllHead.h"
#include "PreProcessData.h"
#include "DataStructure.h"
void EnumerateGlycans()
{
	CEnumerate oEnumGlycans(6,"srctree.ini");
	oEnumGlycans.ProduceAllTrees();
}
int main()
{
	///���Ǻ���(m_smallTrees)������ͨ�ýṹ������ Read ������ȡ�ġ�
   ///ע�ⶼ���Ǻ��ļ����ͨ�ýṹ��Read�������N_gly_Structure.txt�е�Read������һ����
	//time_t start1,end1,start0,end0;

	//////////////////////////////////////////
	//������������������Ҫ�õ�Kind��Ϣ���ʼ�����Kind�����⣬������Ƭ���ӵı�Ų�һ�����������ұ�ſ��ܳ����ڵ���������ҪSet��Ϣ��
	//*****///////*****enumerate all glycan structures
	time_t start=clock();
	EnumerateGlycans();///////CReadAllStruct::Read  //CEnumerate::OutOneTrees
	time_t end=clock();
	cout<<(end-start)/1000.0<<endl;


	////////////////////// Classify the glycan structures according to the Equivalence Class
	//const char * OrigFile = "GlycanDB_pGlyco_Enum_six_to_eleven_withGc.txt";
	//const char * OutFile = "Equivalence_Class_Merged_Enum_With_Gc_six_to_eleven_Dictionary_Examine.txt";
	//OutputData OutData;
	//OutData.OutputAccordEquivalenceClass(OrigFile, OutFile);

//	///////////////////////////select N_Gly_Structure and output as "stand.txt"
//	cout<<"select nglystructure begin "<<endl;
//	CReduceMono oPreProcess;
//	oPreProcess.Read("N_Gly_Structure.txt");////////CReduceMono::Read  PreProcessData.h
//	//ofstream mycout("notNglycan.txt");
//	oPreProcess.ConvertAll();//����洢��m_vStructInfo��
//	oPreProcess.FindN_Glycan();
//	oPreProcess.DeleteRestruct();//ע������Ƿ�Ҫע�͵�
//	oPreProcess.Initial();
//	oPreProcess.OutAllNglycans("stand.txt");//CReduceMono::OutAllNglycans
//	cout<<"select nglystructure end "<<endl;
//
//	/////////////�������ͨ�ýṹû�м���Kind��ͨ�ýṹ������������Ƭ���Ӷ�������Kind��
//	///////////*****///////****get subtrees of three max trees and output as "AllStand.txt"////////////change as AllStand_Glycan_pGlyco_Link.txt
//	vector< vector<CGlyTree> > m_vvcResTees;
//	CMonoInfo * pMono = CMonoInfo::GetMono("mono.ini");
//	CReadAllStruct * pCReader = new CReadAllStruct(pMono);
//	CCalMaxStructure * maxstru=new CCalMaxStructure(pCReader, pMono);
//	maxstru->GetMaxTrees("maxstructure.ini");/////////CReadAllStruct::Read
//	maxstru->CalGcSubTrees();
//	maxstru->ThreeMaxTreeToSubTree();//CEnumerate::OutOneTrees
//	delete pCReader;
//	pCReader = NULL;
//	delete maxstru;
//	maxstru=NULL;
//
//
//
//	////����Ӧ����û�м���Kind��Set,ֻ������Label�����ˣ��������������ṹ������˱���ֵValue����ȥ����
//
//	/////*****///////****combine two databases//�ϲ����ʱ����Ҫע�͵�GetFragmentIons�����е�RestricRules
//	cout<<"combine two databases begin "<<endl;
//	CGlyTree oMergeGlyDB;
//	oMergeGlyDB.InitNameToLabelStand();
//	oMergeGlyDB.ReadAllTreesInfo("stand.txt",oMergeGlyDB.mAllTrees); //2. GlycomeDB��N�ǿ�/////////////////CGlyTree::ReadAllTreesInfo
//	oMergeGlyDB.InitNameToLabelAllStand();
//	oMergeGlyDB.ReadAllTreesInfo("AllStand_GlycanMAX_pGlyco_Link.txt",oMergeGlyDB.mMaxTrees);//AllStand.txt//1. �������ͨ�ý���õ���N�ǿ�////////////////////////CGlyTree::ReadAllTreesInfo
//	oMergeGlyDB.ComMaxAndGlycome();//1.����mAllTrees��mMaxTrees���������ṹ����ֵ//2.��ȡ��mAllTrees������ṹ //3.mAllTrees��mMaxTrees�ϲ�
//	CEnumerate temppout(6,"maxstructure.ini");//�������������ĵ��÷�ʽô��
//	ofstream myccoutcom("Combination.txt");
//	ofstream structoutcom("CombinationLink.txt");
//	cout<<"begin to output combination "<<endl;////֮ǰ��Ҫ�ȼ���mass,���ܰ�mass���򣡣���
//
//	//////////////////////������Gc,������Gc�Ͱ�mFinalTreesWithGc��ΪmFinalTrees
//	//for(size_t i =0;i<oMergeGlyDB.mFinalTrees.size();i++)
//	//{
//	//  oMergeGlyDB.mFinalTrees[i].CalKind();
//	//  oMergeGlyDB.mFinalTrees[i].CalMass();
//	//}
//	//cout<<"begin to sort "<<endl;
//	//sort(oMergeGlyDB.mFinalTrees.begin(),oMergeGlyDB.mFinalTrees.end(),oMergeGlyDB.ComByMass);//��������
//	//cout<<" sort finished "<<endl;
//	//cout<<" output "<<oMergeGlyDB.mFinalTrees.size()<<" trees "<<endl;
//
//	/////getfragmentions��������Ҫע�͵�����N�ǵ��ж���������ΪOutOneTrees���õ���������ˡ�
//	
//	int RecTypeNum[20];
//	for(int w=0;w<20;w++)
//		RecTypeNum[w]=0;
//	////// without restriction
//	//for(size_t i =0;i<oMergeGlyDB.mFinalTrees.size();i++)
//	//{
//	//	RecTypeNum[oMergeGlyDB.mFinalTrees[i].GlyType]++;
//	//	temppout.OutOneTrees(myccoutcom, oMergeGlyDB.mFinalTrees[i],i,temppout.vcRes);//CEnumerate::OutOneTrees
//	//    temppout.OutOneTreeLink(structoutcom,oMergeGlyDB.mFinalTrees[i],i);
//	//	//cout<<" i is "<<i<<endl;
//	//}
//
//	///// with restriction
//	unInt num_count=0;
//	for(size_t i =0;i<oMergeGlyDB.mFinalTrees.size();i++)
//	{
//		/////ע�⣬���ͨ�ýṹ��Ҳ����������������
//		if(!temppout.OutOneTrees(myccoutcom, oMergeGlyDB.mFinalTrees[i],num_count,temppout.vcRes))//CEnumerate::OutOneTrees
//	       continue;
//		RecTypeNum[oMergeGlyDB.mFinalTrees[i].GlyType]++;
//		temppout.OutOneTreeLink(structoutcom,oMergeGlyDB.mFinalTrees[i],num_count);
//		num_count++;
//		//cout<<" i is "<<i<<endl;
//	}
//	cout<<" reasonable tree num is "<<num_count<<endl;
//
////// calculate the number of each type
//	//type���룺���������󣩵�iλΪ1��ʾ���ǽṹ����ԴΪi��������Դ0��ʾͨ�ýṹ1����Դ1��ʾͨ�ýṹ2����Դ2��ʾͨ�ýṹ3����Դ3��ʾGlycomeDB��
//	int sum=0;
//	int max[4];
//	for(int i=0;i<4;i++)
//		max[i]=0;
//	for(int i=0;i<20;i++)
//	{
//		if(RecTypeNum[i]!=0)
//		{
//			sum+=RecTypeNum[i];
//			cout<<"Type ";
//		for(int f=3;f>=0;f--)
//		{
//			cout<<(i>>f&1);
//			if(i>>f&1)
//			{
//				max[f]+=RecTypeNum[i];
//			}
//			
//		}
//
//		cout<<"includes "<<RecTypeNum[i]<<" structures "<<endl;
//		}
//	}
//	cout<<"sum is "<<sum<<endl;
//	for(int i=0;i<4;i++)
//		cout<<"source "<<i<<" contains "<<max[i]<<" structures "<<endl;
/////////////////////////////////////////////
//	myccoutcom.close();
//	structoutcom.close();
//	cout<<" combine two databases end "<<endl;
//
//	////////////////////����Gc  ComMaxAndGlycome()�е�with Gc Ҳ��Ҫ�ġ�
//	for(size_t i =0;i<oMergeGlyDB.mFinalTreesWithGc.size();i++)
//	{
//	  oMergeGlyDB.mFinalTreesWithGc[i].CalKind();
//	  oMergeGlyDB.mFinalTreesWithGc[i].CalMass();
//	}
//	cout<<"begin to sort "<<endl;
//	sort(oMergeGlyDB.mFinalTreesWithGc.begin(),oMergeGlyDB.mFinalTreesWithGc.end(),oMergeGlyDB.ComByMass);//��������
//	cout<<" sort finished "<<endl;
//	cout<<" output "<<oMergeGlyDB.mFinalTreesWithGc.size()<<" trees "<<endl;
//	/////getfragmentions��������Ҫע�͵�����N�ǵ��ж���������ΪOutOneTrees���õ���������ˡ�
//	for(size_t i =0;i<oMergeGlyDB.mFinalTreesWithGc.size();i++)
//	{
//		temppout.OutOneTrees(myccoutcom, oMergeGlyDB.mFinalTreesWithGc[i],i,temppout.vcRes);//CEnumerate::OutOneTrees
//	    temppout.OutOneTreeLink(structoutcom,oMergeGlyDB.mFinalTreesWithGc[i],i);
//		//cout<<" i is "<<i<<endl;
//	}
//	myccoutcom.close();
//	structoutcom.close();
//	cout<<" combine two databases end "<<endl;
}