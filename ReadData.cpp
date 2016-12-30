#include "ReadData.h"
#include "GlyTree.h"

void CReadAllStruct::Read(const char *strFile,vector<CGlyTree> &vsMaxStruct )
{

	cout << "In read" << endl;
	ifstream myCin(strFile);
	if(!myCin){
		cout<<"Can not open maxstructure.ini"<<endl;
		exit(0);
	}
	istringstream strCin;
	string strLine,strTemp;
	unInt uiSize =0,uiLabel=0,uiNode=0;
	CMonoInfo * pMono = CMonoInfo::GetMono("mono.ini");
	while (getline(myCin,strLine))
	{// read all the maxstructures;
		if(strLine.find("TOTALNODES")==string::npos)
			continue;
		strCin.clear();
		strCin.str(strLine);
		strCin>>strTemp>>uiSize;
		unChar tempchar=uiSize;
		//CGlyTree cMaxTree(tempchar);
		CGlyTree cMaxTree;//
	    cMaxTree.m_vuNodeLabel.resize(tempchar,-1);
	    cMaxTree.m_vuNodeValue.resize(tempchar,0);
		cMaxTree.str_m_vuNodeValue.resize(tempchar, "0");
	    cMaxTree.m_vvuTopology.resize(tempchar);
	    cMaxTree.m_dMass = 0.0;
		while(getline(myCin,strLine)){
			if(strLine.find("MONO")!=string::npos)
				break;
		}
		while(getline(myCin,strLine))
		{// read the label of each mono;
			if(strLine.find("LINK")!=string::npos)
				break;
			if(strLine.length()==0)
				continue;
			strCin.clear();
			strCin.str(strLine);
			strCin>>strTemp;
			uiLabel = pMono->GetLabel(strTemp);
			
			while(strCin>>uiNode)
		   {
				cMaxTree.SetLabel(uiNode-1,uiLabel);
				cMaxTree.InsertSet(uiNode-1);
			}
		}
		unInt uiPre = 0,uiNext =0;
		int temp_s=0;
		while (getline(myCin,strLine))
		{// read the topology of the structure;
			if(strLine.find("END")!=string::npos)
				break;
			if(strLine.length()==0)
				continue;
			strCin.clear();
			strCin.str(strLine);
			strCin>>uiPre;

			if(temp_s==0)
					cMaxTree.mRoot=uiPre-1;
			temp_s++;
			while(strCin>>uiNext){

				cMaxTree.SetTopo(uiPre-1,uiNext-1);
			}
		}
		vsMaxStruct.push_back(cMaxTree);
		cout<<vsMaxStruct.size()<<endl;
	}
	cout<<vsMaxStruct.size()<<endl;
}