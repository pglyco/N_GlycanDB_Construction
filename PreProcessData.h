#ifndef PREPROCESSDATA_H_
#define PREPROCESSDATA_H_
#include "DataStructure.h"
class CReduceMono{
public:
	vector<SInitalStructInfo> m_vInitalStruct;
	vector<SStructInfo> m_vStructInfo;
	vector<int>verIsNglycan;
	void Read(const char *fname);
	void ConvertAll();
	bool ToBaseMono(SStructInfo &nex);
	bool ConvertOne(SInitalStructInfo &pre,SStructInfo &nex);
	bool IsN_Glycan(SStructInfo & strInfo);
	void FindN_Glycan();
	void DeleteRestruct();
	void Initial();
	bool OutOneRecord(ofstream &out,SStructInfo &structInfo);//����ɱ�׼��ʽ;
	void OutAllNglycans(const char *fname);//������е�N�ǽṹ;
private:
	string MonoName[5];
	double MonoMass[5];
};

void CReduceMono::Read( const char *fname )
{//��ȡ����;
	ifstream mycin(fname);
	string line;
	istringstream strCin;
	int cnt =0;
	int sNode,eNode;
	getline(mycin,line);
	while(!mycin.eof())
	{
		if(line.find("RES")==line.npos)
		{
			getline(mycin,line);
			continue;
		}
		SInitalStructInfo tempInitNode;
		tempInitNode.m_strTitle = line;
		while(getline(mycin,line),line!="LIN")
		{//��ȡ�ڵ���Ϣ;
			tempInitNode.m_vMonoInitalInfo.push_back(line);
		}
		while(getline(mycin,line)&&line.find("RES")==line.npos)
		{//��ȡ�ڵ��������Ϣ;
			vector<int>vLink;
			strCin.clear();
			strCin.str(line);
			strCin>>sNode>>eNode;
			vLink.push_back(sNode-1);//��֤�±��0��ʼ��
			vLink.push_back(eNode-1);
			tempInitNode.m_vMonoLink.push_back(vLink);
		}
		m_vInitalStruct.push_back(tempInitNode);
		cnt++;
	}
	cout<<"GlycomeDB contains "<<cnt<<" structures "<<endl;
}

void CReduceMono::ConvertAll()
{//ת���ṹ;
	for(size_t preNode=0;preNode<m_vInitalStruct.size();preNode++)
	{
		SStructInfo tempNode;
		tempNode.m_strTitle = m_vInitalStruct[preNode].m_strTitle;
		ConvertOne(m_vInitalStruct[preNode],tempNode);
	}
}

bool CReduceMono::ConvertOne(SInitalStructInfo &pre,SStructInfo &nex)
{//convert pre into nex
	nex.m_strTitle = pre.m_strTitle;
	nex.m_vMonoLink.resize(pre.m_vMonoInitalInfo.size());
	for(size_t nLin =0;nLin<pre.m_vMonoLink.size();nLin++)
	{//�������ӹ�ϵ;
		nex.m_vMonoLink[pre.m_vMonoLink[nLin][0]].push_back(pre.m_vMonoLink[nLin][1]);
		nex.m_vMonoLink[pre.m_vMonoLink[nLin][1]].push_back(pre.m_vMonoLink[nLin][0]);
	}
	vector<EBaseMonoGly>temArr;
	bool yesNgly =true;
	ofstream mycout("notNglycan.txt",ios::app);
	for(size_t indMono=0;indMono<pre.m_vMonoInitalInfo.size();indMono++)
	{
		 if(pre.m_vMonoInitalInfo[indMono].find("gal-HEX-1:5|6:d")!=string::npos)
		{//�����ε�������;
			temArr.push_back(b_a_lgal_hex_1_5_OR_1_6);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:a-dglc-HEX")!=string::npos
			&&pre.m_vMonoInitalInfo[indMono].find("1:5|6:d")==string::npos)
		{//N-���������ǰ����ǻ�;
			temArr.push_back(b_a_dglc_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:b-dglc-HEX")!=string::npos
			&&pre.m_vMonoInitalInfo[indMono].find("1:5|6:d")==string::npos)
		{//N-���������ǰ����ǻ�;
			//if(pre.m_vMonoInitalInfo[indMono].find("1:5|6:d")==string::npos)
			temArr.push_back(b_b_dglc_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:x-dglc-HEX")!=string::npos
			&&pre.m_vMonoInitalInfo[indMono].find("1:5|6:d")==string::npos)
		{//N-���������ǰ����ǻ�;
			//if(pre.m_vMonoInitalInfo[indMono].find("1:5|6:d")==string::npos)
			temArr.push_back(b_x_dglc_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:o-dglc-HEX")!=string::npos
			&&pre.m_vMonoInitalInfo[indMono].find("1:5|6:d")==string::npos)
		{//N-���������ǰ����ǻ�;
			//if(pre.m_vMonoInitalInfo[indMono].find("1:5|6:d")==string::npos)
			temArr.push_back(b_o_dglc_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:a-dgal-HEX")!=string::npos)
		{//��ɫԲ��;
			temArr.push_back(b_a_dgal_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:b-dgal-HEX")!=string::npos)
		{//��ɫԲ��;
			temArr.push_back(b_b_dgal_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:x-dgal-HEX")!=string::npos)
		{//��ɫԲ��;
			temArr.push_back(b_x_dgal_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:a-dman-HEX")!=string::npos)
		{//�߸�¶��;
			temArr.push_back(b_a_dman_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:b-dman-HEX")!=string::npos)
		{//�߸�¶��;
			temArr.push_back(b_b_dman_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:x-dman-HEX")!=string::npos)
		{//�߸�¶��;
			temArr.push_back(b_x_dman_hex_1_5);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:a-lgal-HEX-")!=string::npos)
		{//�����ε�������;
			temArr.push_back(b_a_lgal_hex_1_5_OR_1_6);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:b-lgal-HEX")!=string::npos)
		{//�����ε�������;
			temArr.push_back(b_b_lgal_hex_1_5_OR_1_6);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:x-lgal-HEX")!=string::npos)
		{//�����ε�������;
			temArr.push_back(b_x_lgal_hex_1_5_OR_1_6);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:a-dgro-dgal-NON")!=string::npos)
		{//��Һ��;
			temArr.push_back(b_a_dgro_dgal_non_2_6_OR_1_a_OR_2_keto_OR_3_d);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:b-dgro-dgal-NON")!=string::npos)
		{//��Һ��;
			temArr.push_back(b_b_dgro_dgal_non_2_6_OR_1_a_OR_2_keto_OR_3_d);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("b:x-dgro-dgal-NON")!=string::npos)
		{//��Һ��;
			temArr.push_back(b_x_dgro_dgal_non_2_6_OR_1_a_OR_2_keto_OR_3_d);
		}
		//���ṹ;
		else if(pre.m_vMonoInitalInfo[indMono].find("s:n-acetyl")!=string::npos)
		{//�����ε�������;
			temArr.push_back(s_n_acetyl);
		}
		else if(pre.m_vMonoInitalInfo[indMono].find("s:")!=string::npos)
		{
			temArr.push_back(s_n_others);
		}
		else
		{
			mycout<<pre.m_strTitle<<"---"<<pre.m_vMonoInitalInfo[indMono]<<endl;
			yesNgly =false;
			break;
		}
	}
	nex.m_vInitalInfo = temArr;
	if(yesNgly)
	{//���û�б���������¼���;
		if(ToBaseMono(nex))
			m_vStructInfo.push_back(nex);
	}
	return yesNgly;
}

bool CReduceMono::ToBaseMono(SStructInfo &nex)
{//��Լ�����Ǻ���;
	int indx =0;
	bool find =false;
	for(size_t nMono=0;nMono<nex.m_vInitalInfo.size();nMono++)
	{//���ÿ�������Ƿ�����֮�����ĸ��ṹ���������Լ�������ṹ;
		find = false;
		if(nex.m_vInitalInfo[nMono]>=0&&nex.m_vInitalInfo[nMono]<=3)
		{//N���������ǰ�,������,���Ǻ���;
			for(size_t nLink =0;nLink<nex.m_vMonoLink[nMono].size();nLink++)
			{
				indx =nex.m_vMonoLink[nMono][nLink];
				if(nex.m_vInitalInfo[indx]==s_n_acetyl)
				{
					find =true;
					break;
				}
			}
			if(find)
			{//��¼��Ϣ;
				nex.m_vMonoInfo.push_back(NAcetylGlucosamine);
				nex.m_vBaseMono.push_back(nMono);
			}
			else 
				return false;
		}
		else if(nex.m_vInitalInfo[nMono]>=4&&nex.m_vInitalInfo[nMono]<=6)
		{//�����ǣ���ɫԲ��;
			for(size_t nLink =0;nLink<nex.m_vMonoLink[nMono].size();nLink++)
			{
				indx =nex.m_vMonoLink[nMono][nLink];
				if(nex.m_vInitalInfo[indx]>15)
				{
					find =true;
					break;
				}
			}
			if(find)
				return false;
			else
			{//��ɫԲ�ǲ��ܺ��и����ṹ;
				nex.m_vMonoInfo.push_back(Galactose);
				nex.m_vBaseMono.push_back(nMono);
			}
		}
		else if(nex.m_vInitalInfo[nMono]>=7&&nex.m_vInitalInfo[nMono]<=9)
		{//�߸�¶�ǣ���ɫԲ��,���Ǻ����е�Բ����;
			for(size_t nLink =0;nLink<nex.m_vMonoLink[nMono].size();nLink++)
			{
				indx =nex.m_vMonoLink[nMono][nLink];
				if(nex.m_vInitalInfo[indx]>15)
				{
					find =true;
					break;
				}
			}
			if(find)
				return false;
			else 
			{
				nex.m_vMonoInfo.push_back(Mannose);
				nex.m_vBaseMono.push_back(nMono);
			}
		}
		else if(nex.m_vInitalInfo[nMono]>=10&&nex.m_vInitalInfo[nMono]<=12)
		{//�����ǣ�������;
			for(size_t nLink =0;nLink<nex.m_vMonoLink[nMono].size();nLink++)
			{
				indx =nex.m_vMonoLink[nMono][nLink];
				if(nex.m_vInitalInfo[indx]>15)
				{
					find =true;
					break;
				}
			}
			if(find)
				return false;
			else
			{
				nex.m_vMonoInfo.push_back(Fucose);
				nex.m_vBaseMono.push_back(nMono);
			}
		}
		else if(nex.m_vInitalInfo[nMono]>=13&&nex.m_vInitalInfo[nMono]<=15)
		{//��Һ�ᣬ�����ǣ��и�����;
			for(size_t nLink =0;nLink<nex.m_vMonoLink[nMono].size();nLink++)
			{
				indx =nex.m_vMonoLink[nMono][nLink];
				if(nex.m_vInitalInfo[indx]==s_n_acetyl)
				{
					find =true;
					break;
				}
			}
			if(find)
			{
				nex.m_vMonoInfo.push_back(SalicAcid);
				nex.m_vBaseMono.push_back(nMono);	
			}
			else 
				return false;
		}
		else if(nex.m_vInitalInfo[nMono]>15)
		{
			nex.m_vMonoInfo.push_back(FalseBaseType);
			continue;
		}
		else
			return false;
	}
	return true;
}

bool CReduceMono::IsN_Glycan(SStructInfo & strInfo )
{//�жϽṹ�Ƿ����5�Ǻ���;
	//	cout<<strInfo.m_strTitle<<endl;
	if(strInfo.m_vMonoInfo[0]!=NAcetylGlucosamine)
		return false;
	vector<int>secondChild;
	int indChild;
	for(size_t indMono=0;indMono<strInfo.m_vMonoLink[0].size();indMono++)
	{//�����ڶ���ڵ�;
		indChild = strInfo.m_vMonoLink[0][indMono];
		if(strInfo.m_vInitalInfo[indChild]>15)//�����ṹ����;
			continue;
		if(strInfo.m_vMonoInfo[indChild]==NAcetylGlucosamine)
			secondChild.push_back(indChild);
	}
	if(secondChild.size()==0)
		return false;
	vector<int>thirdLevel;
	int nextChild;
	for(size_t indChild=0;indChild<secondChild.size();indChild++)
	{
		for(size_t indMono=0;indMono<strInfo.m_vMonoLink[secondChild[indChild]].size();indMono++)
		{//����������ڵ�;
			nextChild = strInfo.m_vMonoLink[secondChild[indChild]][indMono];
			if(strInfo.m_vInitalInfo[nextChild]>15)
				continue;
			if(strInfo.m_vMonoInfo[nextChild]==Mannose)
				thirdLevel.push_back(nextChild);
		}
	}
	if(thirdLevel.size()==0)
		return false;
	vector<int>fourthLevel;
	int cnt = 0;
	for(size_t indChild=0;indChild<thirdLevel.size();indChild++)
	{
		cnt =0;
		for(size_t indMono=0;indMono<strInfo.m_vMonoLink[thirdLevel[indChild]].size();indMono++)
		{//�������Ĳ�ڵ�;
			nextChild = strInfo.m_vMonoLink[thirdLevel[indChild]][indMono];
			if(strInfo.m_vInitalInfo[nextChild]>15)
				continue;
			if(strInfo.m_vMonoInfo[nextChild]==Mannose)
			{
				cnt++;
			}
		}
		if(cnt>=2)
			return true;
	}
	return false;
}

void CReduceMono::FindN_Glycan()
{//�ҵ����е�N�ǽṹ;
	ofstream mycout("Non-N-Glycan.txt");
	ofstream outN_gly("N-Glycan-all.txt");
	int cnt =0;
	verIsNglycan.resize(m_vStructInfo.size(),0);
	for(size_t i=0;i<m_vStructInfo.size();i++)
	{
		if(!IsN_Glycan(m_vStructInfo[i]))
		{
			mycout<<m_vStructInfo[i].m_strTitle<<endl;
			verIsNglycan[i] = 0;
		}
		else {
			cnt++;
			outN_gly<<m_vStructInfo[i].m_strTitle<<endl;
			verIsNglycan[i] =1;
		}

	}
	cout<<"N�ǽṹ��:"<<cnt<<endl;
}

void CReduceMono::DeleteRestruct()//Ϊʲôû�ж�����ɸѡ������N�Ǽ���ȥ���࣬���Ƕ���������ȥ�����أ� new revision
{//ɾ���ظ��Ľṹ,����ɸѡ;
	ofstream outSingle("Single.txt");
	ofstream outMult("Mult.txt");
	int nSizeOfStruct = m_vStructInfo.size();
	vector<int>vecIsDelete(nSizeOfStruct,0);
	bool isDeleted=false;
	for(size_t pre=0;pre<nSizeOfStruct;pre++)
	{
		if(vecIsDelete[pre])
			continue;
		if(!verIsNglycan[pre])//new addition
			continue;
		outSingle<<m_vStructInfo[pre].m_strTitle<<endl;
		outMult<<endl<<m_vStructInfo[pre].m_strTitle<<":\t";
		for(size_t nex= pre+1;nex<nSizeOfStruct;nex++)
		{
			isDeleted =false;
			if(vecIsDelete[nex])
				continue;
			if(!verIsNglycan[nex])//new addition
			    continue;
			else if(m_vStructInfo[pre].m_vMonoInfo.size()!=m_vStructInfo[nex].m_vMonoInfo.size()
				||m_vStructInfo[pre].m_vMonoLink.size()!=m_vStructInfo[nex].m_vMonoLink.size())
				continue;
			else
			{
				for(size_t cnt=0;cnt<m_vStructInfo[pre].m_vMonoInfo.size();cnt++)
				{
					if(m_vStructInfo[pre].m_vMonoInfo[cnt]
					!= m_vStructInfo[nex].m_vMonoInfo[cnt])
					{
						isDeleted = true;//���ǲ�ɾ������˼ѽ������
						break;
					}
				}
				if(isDeleted)//new addition
					continue;
				for(size_t cnt=0;cnt<m_vStructInfo[pre].m_vMonoLink.size();cnt++)
				{
					if(m_vStructInfo[pre].m_vMonoLink[cnt]
					!= m_vStructInfo[nex].m_vMonoLink[cnt])
					{
						isDeleted = true;
						break;
					}
				}
			}
			if(!isDeleted)//isDeletedΪ0����ɾ����
			{
				outMult<<m_vStructInfo[nex].m_strTitle<<"\t";
				vecIsDelete[nex] = 1;
				verIsNglycan[nex]=0;
			}
		}
	}
	int sum =0;
	for(size_t i=0;i<vecIsDelete.size();i++)
	{
		//if(!vecIsDelete[i])
		if(verIsNglycan[i])
		{
			sum++;
		}
	}
}

bool CReduceMono::OutOneRecord(ofstream &out,SStructInfo &structInfo)
{//convert to my stand format��
	//cout<<"��ʼ���"<<endl;
	out<<"[Begin]"<<endl;
	out<<structInfo.m_strTitle<<endl;
	out<<"rootAndnodes\t"<<structInfo.m_vBaseMono[0]+1<<"\t"<<structInfo.m_vBaseMono.size()<<endl;
	out<<"[Mono]"<<endl;
	vector<int>verMonoInfo[5];
	size_t idx=-1;
	for(size_t i=0;i<structInfo.m_vBaseMono.size();i++)
	{
		idx =structInfo.m_vBaseMono[i];
		if(structInfo.m_vMonoInfo[idx]==NAcetylGlucosamine)
		{
			verMonoInfo[0].push_back(idx);
		}
		else if(structInfo.m_vMonoInfo[idx]==Mannose)
		{
			verMonoInfo[1].push_back(idx);
		}
		else if(structInfo.m_vMonoInfo[idx]==Galactose)
		{
			verMonoInfo[2].push_back(idx);
		}
		else if(structInfo.m_vMonoInfo[idx]==Fucose)
		{
			verMonoInfo[3].push_back(idx);
		}
		else if(structInfo.m_vMonoInfo[idx]==SalicAcid)
		{
			verMonoInfo[4].push_back(idx);
		}
		else 
		{
			return false;
		}
	}
	map<int,int> toZeroBase;
	int cnt=1; 
	for(size_t i=0;i<structInfo.m_vBaseMono.size();i++)
	{
		toZeroBase[structInfo.m_vBaseMono[i]] =cnt++;
	}
	for(size_t i=0;i<5;i++)
	{
		if(verMonoInfo[i].size()>0)
		{
			out<<MonoName[i]<<"\t";
			for(size_t j=0;j<verMonoInfo[i].size();j++)
			{
				out<<toZeroBase[verMonoInfo[i][j]]<<"\t";
			}
			out<<endl;
		}
	}
	out<<"[Link]"<<endl;
	for(size_t i=0;i<structInfo.m_vBaseMono.size();i++)
	{
		idx =structInfo.m_vBaseMono[i];
		out<<toZeroBase[idx]<<"\t";
		for(size_t j=0;j<structInfo.m_vMonoLink[idx].size();j++)
		{
			if(toZeroBase[structInfo.m_vMonoLink[idx][j]]&&
				toZeroBase[idx]<toZeroBase[structInfo.m_vMonoLink[idx][j]])
				out<<toZeroBase[structInfo.m_vMonoLink[idx][j]]<<"\t";
		}
		out<<endl;
	}
	out<<"[End]"<<endl;
	return true;
}

void CReduceMono::Initial()
{
	MonoName[0]="N-acetylgalucosamine";
	MonoMass[0]=203.07937253300003;
	MonoName[1]="Mannose";
	MonoMass[1]=162.0528234315;
	MonoName[2]="Glucose"; 
	MonoMass[2]=162.0528234315;
	MonoName[3]="Fucose";
	MonoMass[3]=146.0579088094;
	MonoName[4]="Sialic";
	MonoMass[4]=291.09541652769997;
}
	


void CReduceMono::OutAllNglycans( const char *fname )
{
	ofstream outStream(fname);
	int cnt=0;
	for(size_t i=0;i<m_vStructInfo.size();i++)
	{
		if(verIsNglycan[i]==1)
		{
			cnt++;
			OutOneRecord(outStream,m_vStructInfo[i]);
		}
	}
}
#endif