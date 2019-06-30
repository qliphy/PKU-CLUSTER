#include "closure.C"
#include "sideband.C"
#include "truetemplateUncer.C"
void Uncer(){
ofstream f4("./summary.txt");
f4<<"pt"<<"\t"<<"closure"<<"\t\t"<<"sideband"<<"\t"<<"template"<<"\t"<<"total"<<endl;
cout<<"closure test uncertainty"<<endl;
int j=0;
for(Int_t i=0;i<num;i++){
          if(j>=ptnumber-1) j=ptnumber-1;
         run_calculate(j,i);
	 j++;
	 if(j>=ptnumber-1) j=ptnumber-1;
	 open(lpt[i],hpt[i],"ZA1","ZA2","ZA");
	 open(lpt[i],hpt[i],"EWK","ZA");
	 f4<<fixed<<setprecision(0)<<lpt[i]<<"~"<<hpt[i]<<"\t"<<fixed<<setprecision(2)<<closure_uncer<<"\t\t"<<sideband_uncer<<"\t\t"<<truetemplate_uncer<<"\t\t"<<sqrt(closure_uncer*closure_uncer+sideband_uncer*sideband_uncer+truetemplate_uncer*truetemplate_uncer)<<endl;
   }

/*cout<<endl;
cout<<"chiso sideband uncertainty"<<endl;
  for(int i = 0;i<num;i++){
	  open(lpt[i],hpt[i],"ZA1","ZA2","ZA");
	  open(lpt[i],hpt[i],"EWK","ZA");
  }*/

/*cout<<endl;
cout<<"true template uncertainty"<<endl;
   for(int i = 0;i<num;i++){
	   Double_t lowpt[num]= {20,25,30,40,50,70,100,120};
	   Double_t highpt[num]={25,30,40,50,70,100,120,400};
	   open(lowpt[i],highpt[i],"EWK","ZA");
   }*/

}
