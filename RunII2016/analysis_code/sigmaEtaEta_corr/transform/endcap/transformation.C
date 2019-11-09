void transformation(){

	TFile*fout=new TFile("transformation_endcap.root","RECREATE");

	TFile* fb=TFile::Open("../../histos/endcap/trans_endcap.root");
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

        TGraph*g1b=new TGraph(200, ymcb, ydab);
        g1b->SetNameTitle("endcap","endcap");

	fout->cd();
//	g1b->Draw("alp");
	g1b->Write();
	fout->Close();
}
