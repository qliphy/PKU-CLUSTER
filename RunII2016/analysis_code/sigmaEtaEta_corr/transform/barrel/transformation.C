void transformation(){

	TFile*fout=new TFile("transformation_barrel.root","RECREATE");

	TFile* fb=TFile::Open("../../histos/barrel/trans_barrel.root");
        TH1D* hdatab;
        TH1D* hmcb;
        fb->GetObject("DEle16",hdatab);
        fb->GetObject("ZJets",hmcb);

        double xmcb[200], ymcb[200];
        double xdab[200], ydab[200];

        for(int i=0;i<200;i++){
                xmcb[i]=(i+1)*1.0/200;
                xdab[i]=(i+1)*1.0/200;
        }

        hdatab->Scale(1./hdatab->Integral());
        hmcb->Scale(hdatab->Integral()/hmcb->Integral());
        hmcb->Scale(1./hmcb->Integral());

        hdatab->GetQuantiles(200, ydab, xdab);//divide the data to 200 parts, yda[i] presents the value of sieie that hdatab->Integral(0,hdatab>FindFixBin(yda[i])) >= i/200, which means that between two yda[i], the number of the events is same.
        hmcb->GetQuantiles(200, ymcb, xmcb);
        cout<<ydab[0]<<endl; 


        TH1D*hb = new TH1D("hbarrel","barrel mapping",199,ymcb);
        for(int i=1;i<=199;i++){
            hb->SetBinContent(i,ydab[i-1]);
        }
//        TGraph*g1b=new TGraph(200, xdab, ydab);
        TGraph*g1b=new TGraph(200, ymcb, ydab);
        g1b->SetNameTitle("barrel","barrel");

	TFile* f=TFile::Open("../../histos/endcap/trans_endcap.root");
	TH1D* hdata;
	TH1D* hmc;
	f->GetObject("DEle16",hdata);
	f->GetObject("ZJets",hmc);

	double xmc[200], ymc[200];
	double xda[200], yda[200];

	for(int i=0;i<200;i++){
		xmc[i]=(i+1)*1.0/200;
		xda[i]=(i+1)*1.0/200;
	}

	hdata->Scale(1./hdata->Integral());
	hmc->Scale(hdata->Integral()/hmc->Integral());
	hmc->Scale(1./hmc->Integral());

	hdata->GetQuantiles(200, yda, xda);
	hmc->GetQuantiles(200, ymc, xmc);

	TGraph*g1=new TGraph(200, ymc, yda);
	g1->SetNameTitle("endcap","endcap");

	fout->cd();
    g1b->Draw("alp");
//    hb->Draw();
//    hb->Write();
	g1b->Write();
	g1->Write();
	fout->Close();
}
