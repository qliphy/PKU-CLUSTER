#define plj_cxx
#include "plj.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <TCanvas.h>
#include "L1_weight.C"
#include <fstream>
using namespace std;
void plj::Loop()
{
//   In a ROOT session, you can do:
//      root> .L plj.C
//      root> plj t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   double lep1_phi_station2_tmp = 0;
   double lep2_phi_station2_tmp = 0;

   ifstream f1;
   //f1.open("../../plj-plot/Ele/ele-endcap-pljweight/pljweight.txt");
   f1.open("../../plj-plot/EleBarrel/ele-barrel-pljweight/pljweight.txt");
   Double_t scalef_f[10];
   for(Int_t i=0;i<10;i++){
      f1>>scalef_f[i];
      cout<<"scalef_f["<<"i"<<"] = "<<scalef_f[i]<<endl;
   }
  
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if(jentry%1000000==0) cout<<jentry<<", "<<nentries<<endl;
    
     if(photonet<20)                      {scalef_tmp=0;}
     if(photonet>20 &&  photonet<25)      {int i=0;scalef_tmp = scalef_f[i];}   
     if(photonet>25 &&  photonet<30)      {int i=0+1;scalef_tmp = scalef_f[i];}
     if(photonet>30 &&  photonet<35)      {int i=1+1;scalef_tmp = scalef_f[i];}
     if(photonet>35 &&  photonet<40)      {int i=2+1;scalef_tmp = scalef_f[i];}
     if(photonet>40 &&  photonet<45)      {int i=3+1;scalef_tmp = scalef_f[i];}
     if(photonet>45 &&  photonet<50)      {int i=4+1;scalef_tmp = scalef_f[i];}
     if(photonet>50 &&  photonet<60)      {int i=5+1;scalef_tmp = scalef_f[i];}
     if(photonet>60 &&  photonet<80)      {int i=6+1;scalef_tmp = scalef_f[i];}
     if(photonet>80 &&  photonet<120)     {int i=7+1;scalef_tmp = scalef_f[i];}
     if(photonet>120/*&&  photonet<400*/) {int i=8+1;scalef_tmp = scalef_f[i];} 
      
      pileupWeight_tmp=1;

      lep1_phi_station2_tmp = lep1_phi_station2;
      lep2_phi_station2_tmp = lep2_phi_station2;      
      
      if(lep1_phi_station2<0) lep1_phi_station2_tmp = lep1_phi_station2+6.28319;
      if(lep2_phi_station2<0) lep2_phi_station2_tmp = lep2_phi_station2+6.28319;
      
      l1_weight = L1_weight(lep1_phi_station2_tmp, lep2_phi_station2_tmp, lep1_eta_station2, lep2_eta_station2);      
      

      ExTree->Fill();
   }
}
