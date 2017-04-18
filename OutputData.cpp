
#include "OutputData.h"

void OutputData::OutputAccordEquivalenceClass(const char *OrigFile, const char *OutFile)
{///////////一定要保证输入文件中糖结构中的Y离子是按照质量排序的。
	ifstream mycin(OrigFile);
	ofstream mycout(OutFile);
	istringstream strcin;
	string line, name;
	double value;
	string StrValue;
	int GlycanID = -1;
	map<string, int> Dic_GlyStr_GlycanID;
	map<int, vector<int> > Dic_GlycanID_EquivalenceClassID;
	map<int, int> IrredundantGlycanID;
	vector<string> StrMassSet;
	while (getline(mycin, line))
	{
		//getline(mycin, line);
		strcin.clear();
		strcin.str(line);
		strcin >> name >> StrValue;
		if (name == "Mass=")
		{
			GlycanID += 1;
			vector<string> GlyandSubGlyMass;
			GlyandSubGlyMass.push_back(StrValue);
			while (name != "End")
			{
				getline(mycin, line);
				strcin.clear();
				strcin.str(line);
				strcin >> name >> StrValue;
<<<<<<< HEAD
				if (name == "IonMass=")/////////////确定这里质量已经按序排列了么？
=======
				if (name == "IonMass=")
>>>>>>> 305e4cbcbc52032e29a6bceef17153f461bfb193
				{
					GlyandSubGlyMass.push_back(StrValue);
				}
			}
			//sort(GlyandSubGlyMass.begin(), GlyandSubGlyMass.end());
			string str1 = "";
			for (int i = 0; i<GlyandSubGlyMass.size(); i++)
				str1 += GlyandSubGlyMass[i] + '+';
			vector<string>::iterator res = find(StrMassSet.begin(), StrMassSet.end(), str1);
			if (res == StrMassSet.end())
			{
				IrredundantGlycanID.insert(pair<int,int> (GlycanID,100));////map值为100表示非冗余
				StrMassSet.push_back(str1);
				//Dic_GlycanID_EquivalenceClassID.insert(pair<int, vector<int> >(GlycanID, {GlycanID}));//// 这里记得取消注释，VS 2010好像编译不通
				Dic_GlyStr_GlycanID.insert(pair<string, int>(str1, GlycanID));
			}
			else
			  Dic_GlycanID_EquivalenceClassID[Dic_GlyStr_GlycanID[str1]].push_back(GlycanID);

		}
	}
	mycin.close();
	GlycanID = -1;
	int MergedGlyID = -1;
	mycin.open(OrigFile);
	while (getline(mycin, line))
	{
		strcin.clear();
		strcin.str(line);
		strcin >> name >> StrValue;
		if (name == "Begin")
		{
			GlycanID += 1;
			if (IrredundantGlycanID[GlycanID] == 100)
			{
				MergedGlyID += 1;
				while (line != "End")
				{
					strcin.clear();
					strcin.str(line);
					strcin >> name >> StrValue;
					if (name == "DBID=")
					{
						mycout << "GLYID=\t" <<MergedGlyID<< "\tGLYTYPE=\t0\tOriginalGlyID=\t" <<GlycanID<<"\n";
						mycout << "ID of Equivalent Glycans\t";
						for (int m = 0; m < Dic_GlycanID_EquivalenceClassID[GlycanID].size();m++)
							mycout << Dic_GlycanID_EquivalenceClassID[GlycanID][m]<<"\t";
						mycout << "\n";
					}
					else
						mycout << line<<"\n";
					getline(mycin, line);
				}
				mycout<< line<<"\n";
			}
			else
			{
				while (line != "End")
					getline(mycin, line);
			}
		}
	}
	mycin.close();
	mycout.close();
}