#ifdef __MAKECINT__
#pragma link C++ class s+;
#pragma link C++ class vector<s>+;
#endif



#include <iostream>
#include <vector>
#include "TFile.h"
#include "TTree.h"
using namespace std;
struct s
{
	double x;
	double y;
};

void sv()
{

	vector<s> v = {{1,2}};
	cout << v.at(0).x << endl;
	cout << v.at(0).y << endl;
	TFile tf("v.root","recreate");
	auto tree = new TTree("tree","tree");
	tree->Branch("v",&v);
	for(int i = 0; i < 10; i ++)
	{
		s vs = { (double) i, double(2*i)};
		v.push_back(vs);
	tree->Fill();
	}
	tree->Write();
	

}
