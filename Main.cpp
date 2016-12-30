////按照新的动态规划的方法，只能在生成所有结构的碎片离子之后，才能对碎片离子集合去镜像冗余。



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
	///五糖核心(m_smallTrees)和三个通用结构都是用 Read 函数读取的。
   ///注意都五糖核心及最大通用结构的Read函数与读N_gly_Structure.txt中的Read函数不一样。
	//time_t start1,end1,start0,end0;

	//////////////////////////////////////////
	//这里由于限制条件需要用到Kind信息，故计算了Kind。另外，这里碎片离子的标号不一定是连续的且标号可能超过节点数，故需要Set信息。
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
//	oPreProcess.ConvertAll();//结果存储在m_vStructInfo中
//	oPreProcess.FindN_Glycan();
//	oPreProcess.DeleteRestruct();//注意这个是否要注释掉
//	oPreProcess.Initial();
//	oPreProcess.OutAllNglycans("stand.txt");//CReduceMono::OutAllNglycans
//	cout<<"select nglystructure end "<<endl;
//
//	/////////////三个最大通用结构没有计算Kind，通用结构的子树及其碎片离子都计算了Kind。
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
//	////这里应该是没有计算Kind及Set,只保留了Label和拓扑，并根据这两个结构计算出了编码值Value用于去冗余
//
//	/////*****///////****combine two databases//合并库的时候需要注释掉GetFragmentIons函数中的RestricRules
//	cout<<"combine two databases begin "<<endl;
//	CGlyTree oMergeGlyDB;
//	oMergeGlyDB.InitNameToLabelStand();
//	oMergeGlyDB.ReadAllTreesInfo("stand.txt",oMergeGlyDB.mAllTrees); //2. GlycomeDB的N糖库/////////////////CGlyTree::ReadAllTreesInfo
//	oMergeGlyDB.InitNameToLabelAllStand();
//	oMergeGlyDB.ReadAllTreesInfo("AllStand_GlycanMAX_pGlyco_Link.txt",oMergeGlyDB.mMaxTrees);//AllStand.txt//1. 三个最大通用结果得到的N糖库////////////////////////CGlyTree::ReadAllTreesInfo
//	oMergeGlyDB.ComMaxAndGlycome();//1.计算mAllTrees和mMaxTrees的所有树结构编码值//2.先取出mAllTrees的冗余结构 //3.mAllTrees和mMaxTrees合并
//	CEnumerate temppout(6,"maxstructure.ini");//还可以有其它的调用方式么？
//	ofstream myccoutcom("Combination.txt");
//	ofstream structoutcom("CombinationLink.txt");
//	cout<<"begin to output combination "<<endl;////之前需要先计算mass,才能按mass排序！！！
//
//	//////////////////////不生成Gc,不生成Gc就把mFinalTreesWithGc改为mFinalTrees
//	//for(size_t i =0;i<oMergeGlyDB.mFinalTrees.size();i++)
//	//{
//	//  oMergeGlyDB.mFinalTrees[i].CalKind();
//	//  oMergeGlyDB.mFinalTrees[i].CalMass();
//	//}
//	//cout<<"begin to sort "<<endl;
//	//sort(oMergeGlyDB.mFinalTrees.begin(),oMergeGlyDB.mFinalTrees.end(),oMergeGlyDB.ComByMass);//加上排序
//	//cout<<" sort finished "<<endl;
//	//cout<<" output "<<oMergeGlyDB.mFinalTrees.size()<<" trees "<<endl;
//
//	/////getfragmentions函数中需要注释掉合理N糖的判定条件。因为OutOneTrees中用到这个函数了。
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
//		/////注意，最大通用结构库也是用这个函数输出的
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
//	//type编码：（从右至左）第i位为1表示该糖结构的来源为i，其中来源0表示通用结构1，来源1表示通用结构2，来源2表示通用结构3，来源3表示GlycomeDB。
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
//	////////////////////生成Gc  ComMaxAndGlycome()中的with Gc 也需要改。
//	for(size_t i =0;i<oMergeGlyDB.mFinalTreesWithGc.size();i++)
//	{
//	  oMergeGlyDB.mFinalTreesWithGc[i].CalKind();
//	  oMergeGlyDB.mFinalTreesWithGc[i].CalMass();
//	}
//	cout<<"begin to sort "<<endl;
//	sort(oMergeGlyDB.mFinalTreesWithGc.begin(),oMergeGlyDB.mFinalTreesWithGc.end(),oMergeGlyDB.ComByMass);//加上排序
//	cout<<" sort finished "<<endl;
//	cout<<" output "<<oMergeGlyDB.mFinalTreesWithGc.size()<<" trees "<<endl;
//	/////getfragmentions函数中需要注释掉合理N糖的判定条件。因为OutOneTrees中用到这个函数了。
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