#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_
#include "common.h"
/************************************************************************/
/* 单糖的枚举变量;                                                        */
/************************************************************************/
enum EBaseMonoGly{
	//base type
	b_a_dglc_hex_1_5,//0
	b_b_dglc_hex_1_5,//1
	b_x_dglc_hex_1_5,//2
	b_o_dglc_hex_1_5,//3
	b_a_dgal_hex_1_5,//4
	b_b_dgal_hex_1_5,//5
	b_x_dgal_hex_1_5,//6
	b_a_dman_hex_1_5,//7
	b_b_dman_hex_1_5,//8
	b_x_dman_hex_1_5,//9
	b_a_lgal_hex_1_5_OR_1_6,//10
	b_b_lgal_hex_1_5_OR_1_6,//11
	b_x_lgal_hex_1_5_OR_1_6,//12
	b_a_dgro_dgal_non_2_6_OR_1_a_OR_2_keto_OR_3_d,//13
	b_b_dgro_dgal_non_2_6_OR_1_a_OR_2_keto_OR_3_d,//14
	b_x_dgro_dgal_non_2_6_OR_1_a_OR_2_keto_OR_3_d,//15
	//substitute
	s_n_acetyl,
	s_n_others,
	s_sulfare,
	s_amino,
	s_methyl,
	s_acetyl,
	s_n_sulfare,
	s_phosphate,
	s_anhydro,
	s_n_glycolyl,
	s_phospho_ethanolamine
};
//单糖信息;
//N糖几种糖核心;
enum EMidMonType{
	//中间的糖结构;
	b_dglc_hex_1_5,//0-3
	b_dgal_hex_1_5,//4-5
	b_dman_hex_1_5,//7-9
	b_lgal_hex_1_5_OR_1_6,//10-12
	b_dgro_dgal_non_2_6_OR_1_a_OR_2_keto_OR_3_d,//13-15
	s_others
};
enum EGlyMonoType{
	//转换后的糖结构;
	NAcetylGlucosamine,
	Mannose,
	Galactose,
	Fucose,
	SalicAcid,
	FalseBaseType
};
//原始结构;
struct SInitalStructInfo{
	string m_strTitle;
	vector<string> m_vMonoInitalInfo;
	vector<vector<int>>m_vMonoLink;
};
//中间结构;
struct SMidStructInfo{
	string m_strTitle;
	vector<EMidMonType> m_vMonoInfo;
	vector<vector<int>>m_vMonoLink;
};
//转换后的结构;
struct SStructInfo{
	string m_strTitle;
	vector<EBaseMonoGly>m_vInitalInfo;
	vector<EGlyMonoType> m_vMonoInfo;
	vector<vector<int>> m_vMonoLink;
	vector<int> m_vBaseMono;
};
#endif