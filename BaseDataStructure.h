#ifndef BASEDATASTRUCTURE_H_
#define BASEDATASTRUCTURE_H_
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
template<class T>
void FreeVector(vector<T> & vec){
	vector<T> vtTemp;
	vtTemp.swap(vec);
}
typedef unsigned int unInt;
typedef unsigned char unChar;
typedef vector<vector<unChar>> vvuTree;
#endif