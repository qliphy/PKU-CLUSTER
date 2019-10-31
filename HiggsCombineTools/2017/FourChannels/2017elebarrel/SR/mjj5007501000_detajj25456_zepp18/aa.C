void aa()
{
//=========Macro generated from canvas: /
//=========  (Mon Aug  5 17:38:13 2019) by ROOT version6.06/09
   TCanvas * = new TCanvas("", "",0,0,800,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.15);
   c1->SetRightMargin(0.05);
   c1->SetBottomMargin(0.13);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "",0,0,0.99,0.99);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-1.5,-8.480607,8.5,56.75483);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTickx(1);
   pad1->SetTicky(1);
   pad1->SetLeftMargin(0.15);
   pad1->SetRightMargin(0.05);
   pad1->SetBottomMargin(0.13);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",8,0,8);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(50.88364);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);
   hs_stack_1->SetLineStyle(0);
   hs_stack_1->SetLineWidth(2);
   hs_stack_1->SetMarkerStyle(20);
   hs_stack_1->GetXaxis()->SetBinLabel(1,"Mjj 500~800");
   hs_stack_1->GetXaxis()->SetBinLabel(2,"Mjj 800~1200");
   hs_stack_1->GetXaxis()->SetBinLabel(3,"Mjj 1200~2000");
   hs_stack_1->GetXaxis()->SetBinLabel(4,"Mjj 500~800");
   hs_stack_1->GetXaxis()->SetBinLabel(5,"Mjj 800~1200");
   hs_stack_1->GetXaxis()->SetBinLabel(6,"Mjj 1200~2000");
   hs_stack_1->GetXaxis()->SetBinLabel(7,"Mjj 500~1200");
   hs_stack_1->GetXaxis()->SetBinLabel(8,"Mjj 1200~2000");
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetXaxis()->SetTitleSize(0.06);
   hs_stack_1->GetXaxis()->SetTitleOffset(0.9);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetTitle("Events /bin");
   hs_stack_1->GetYaxis()->SetLabelFont(42);
   hs_stack_1->GetYaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetYaxis()->SetTitleSize(0.06);
   hs_stack_1->GetYaxis()->SetTitleOffset(0.8);
   hs_stack_1->GetYaxis()->SetTitleFont(42);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetZaxis()->SetTitleSize(0.06);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   
   TH1D *ST__1 = new TH1D("ST__1","",8,0,8);
   ST__1->SetEntries(8);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#00ff00");
   ST__1->SetFillColor(ci);

   ci = TColor::GetColor("#00ff00");
   ST__1->SetLineColor(ci);
   ST__1->SetLineStyle(0);
   ST__1->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   ST__1->SetMarkerColor(ci);
   ST__1->SetMarkerStyle(20);
   ST__1->GetXaxis()->SetBinLabel(1,"Mjj 500~800");
   ST__1->GetXaxis()->SetBinLabel(2,"Mjj 800~1200");
   ST__1->GetXaxis()->SetBinLabel(3,"Mjj 1200~2000");
   ST__1->GetXaxis()->SetBinLabel(4,"Mjj 500~800");
   ST__1->GetXaxis()->SetBinLabel(5,"Mjj 800~1200");
   ST__1->GetXaxis()->SetBinLabel(6,"Mjj 1200~2000");
   ST__1->GetXaxis()->SetBinLabel(7,"Mjj 500~1200");
   ST__1->GetXaxis()->SetBinLabel(8,"Mjj 1200~2000");
   ST__1->GetXaxis()->SetLabelFont(42);
   ST__1->GetXaxis()->SetLabelOffset(0.007);
   ST__1->GetXaxis()->SetTitleSize(0.06);
   ST__1->GetXaxis()->SetTitleOffset(0.9);
   ST__1->GetXaxis()->SetTitleFont(42);
   ST__1->GetYaxis()->SetLabelFont(42);
   ST__1->GetYaxis()->SetLabelOffset(0.007);
   ST__1->GetYaxis()->SetTitleSize(0.06);
   ST__1->GetYaxis()->SetTitleOffset(1.1);
   ST__1->GetYaxis()->SetTitleFont(42);
   ST__1->GetZaxis()->SetLabelFont(42);
   ST__1->GetZaxis()->SetLabelOffset(0.007);
   ST__1->GetZaxis()->SetTitleSize(0.06);
   ST__1->GetZaxis()->SetTitleFont(42);
   hs->Add(ST,"");
   
   TH1D *TTA__2 = new TH1D("TTA__2","",8,0,8);
   TTA__2->SetBinContent(1,0.09563855);
   TTA__2->SetBinContent(2,-0.03508053);
   TTA__2->SetBinContent(3,-0.01175434);
   TTA__2->SetBinContent(4,0.4208975);
   TTA__2->SetBinContent(5,0.03267143);
   TTA__2->SetBinContent(6,0.1014419);
   TTA__2->SetBinContent(8,0.05519073);
   TTA__2->SetBinError(1,0.2631501);
   TTA__2->SetBinError(2,0.1634272);
   TTA__2->SetBinError(3,0.06955252);
   TTA__2->SetBinError(4,0.1483573);
   TTA__2->SetBinError(5,0.132365);
   TTA__2->SetBinError(6,0.1057303);
   TTA__2->SetEntries(8);

   ci = TColor::GetColor("#00ffff");
   TTA__2->SetFillColor(ci);

   ci = TColor::GetColor("#00ffff");
   TTA__2->SetLineColor(ci);
   TTA__2->SetLineStyle(0);
   TTA__2->SetLineWidth(2);

   ci = TColor::GetColor("#00ffff");
   TTA__2->SetMarkerColor(ci);
   TTA__2->SetMarkerStyle(20);
   TTA__2->GetXaxis()->SetLabelFont(42);
   TTA__2->GetXaxis()->SetLabelOffset(0.007);
   TTA__2->GetXaxis()->SetTitleSize(0.06);
   TTA__2->GetXaxis()->SetTitleOffset(0.9);
   TTA__2->GetXaxis()->SetTitleFont(42);
   TTA__2->GetYaxis()->SetLabelFont(42);
   TTA__2->GetYaxis()->SetLabelOffset(0.007);
   TTA__2->GetYaxis()->SetTitleSize(0.06);
   TTA__2->GetYaxis()->SetTitleOffset(1.1);
   TTA__2->GetYaxis()->SetTitleFont(42);
   TTA__2->GetZaxis()->SetLabelFont(42);
   TTA__2->GetZaxis()->SetLabelOffset(0.007);
   TTA__2->GetZaxis()->SetTitleSize(0.06);
   TTA__2->GetZaxis()->SetTitleFont(42);
   hs->Add(TTA,"");
   
   TH1D *VV__3 = new TH1D("VV__3","",8,0,8);
   VV__3->SetBinContent(1,0.297494);
   VV__3->SetBinContent(3,0.2978801);
   VV__3->SetBinContent(4,0.8611259);
   VV__3->SetBinError(1,0.2949983);
   VV__3->SetBinError(3,0.2978801);
   VV__3->SetBinError(4,0.5013314);
   VV__3->SetEntries(8);

   ci = TColor::GetColor("#6666cc");
   VV__3->SetFillColor(ci);

   ci = TColor::GetColor("#6666cc");
   VV__3->SetLineColor(ci);
   VV__3->SetLineStyle(0);
   VV__3->SetLineWidth(2);

   ci = TColor::GetColor("#6666cc");
   VV__3->SetMarkerColor(ci);
   VV__3->SetMarkerStyle(20);
   VV__3->GetXaxis()->SetLabelFont(42);
   VV__3->GetXaxis()->SetLabelOffset(0.007);
   VV__3->GetXaxis()->SetTitleSize(0.06);
   VV__3->GetXaxis()->SetTitleOffset(0.9);
   VV__3->GetXaxis()->SetTitleFont(42);
   VV__3->GetYaxis()->SetLabelFont(42);
   VV__3->GetYaxis()->SetLabelOffset(0.007);
   VV__3->GetYaxis()->SetTitleSize(0.06);
   VV__3->GetYaxis()->SetTitleOffset(1.1);
   VV__3->GetYaxis()->SetTitleFont(42);
   VV__3->GetZaxis()->SetLabelFont(42);
   VV__3->GetZaxis()->SetLabelOffset(0.007);
   VV__3->GetZaxis()->SetTitleSize(0.06);
   VV__3->GetZaxis()->SetTitleFont(42);
   hs->Add(VV,"");
   
   TH1D *WA__4 = new TH1D("WA__4","",8,0,8);
   WA__4->SetEntries(8);

   ci = TColor::GetColor("#000099");
   WA__4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   WA__4->SetLineColor(ci);
   WA__4->SetLineStyle(0);
   WA__4->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   WA__4->SetMarkerColor(ci);
   WA__4->SetMarkerStyle(20);
   WA__4->GetXaxis()->SetLabelFont(42);
   WA__4->GetXaxis()->SetLabelOffset(0.007);
   WA__4->GetXaxis()->SetTitleSize(0.06);
   WA__4->GetXaxis()->SetTitleOffset(0.9);
   WA__4->GetXaxis()->SetTitleFont(42);
   WA__4->GetYaxis()->SetLabelFont(42);
   WA__4->GetYaxis()->SetLabelOffset(0.007);
   WA__4->GetYaxis()->SetTitleSize(0.06);
   WA__4->GetYaxis()->SetTitleOffset(1.1);
   WA__4->GetYaxis()->SetTitleFont(42);
   WA__4->GetZaxis()->SetLabelFont(42);
   WA__4->GetZaxis()->SetLabelOffset(0.007);
   WA__4->GetZaxis()->SetTitleSize(0.06);
   WA__4->GetZaxis()->SetTitleFont(42);
   hs->Add(WA,"");
   
   TH1D *plj__5 = new TH1D("plj__5","",8,0,8);
   plj__5->SetBinContent(1,10.68935);
   plj__5->SetBinContent(2,1.937119);
   plj__5->SetBinContent(4,27.24032);
   plj__5->SetBinContent(5,7.647566);
   plj__5->SetBinContent(6,0.575367);
   plj__5->SetBinContent(7,10.30808);
   plj__5->SetBinContent(8,5.615832);
   plj__5->SetBinError(1,2.021215);
   plj__5->SetBinError(2,0.8276931);
   plj__5->SetBinError(4,3.328047);
   plj__5->SetBinError(5,1.753009);
   plj__5->SetBinError(6,0.4080195);
   plj__5->SetBinError(7,2.026995);
   plj__5->SetEntries(8);

   ci = TColor::GetColor("#ffff00");
   plj__5->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   plj__5->SetLineColor(ci);
   plj__5->SetLineStyle(0);
   plj__5->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   plj__5->SetMarkerColor(ci);
   plj__5->SetMarkerStyle(20);
   plj__5->GetXaxis()->SetLabelFont(42);
   plj__5->GetXaxis()->SetLabelOffset(0.007);
   plj__5->GetXaxis()->SetTitleSize(0.06);
   plj__5->GetXaxis()->SetTitleOffset(0.9);
   plj__5->GetXaxis()->SetTitleFont(42);
   plj__5->GetYaxis()->SetLabelFont(42);
   plj__5->GetYaxis()->SetLabelOffset(0.007);
   plj__5->GetYaxis()->SetTitleSize(0.06);
   plj__5->GetYaxis()->SetTitleOffset(1.1);
   plj__5->GetYaxis()->SetTitleFont(42);
   plj__5->GetZaxis()->SetLabelFont(42);
   plj__5->GetZaxis()->SetLabelOffset(0.007);
   plj__5->GetZaxis()->SetTitleSize(0.06);
   plj__5->GetZaxis()->SetTitleFont(42);
   hs->Add(plj,"");
   
   TH1D *t_ZA__6 = new TH1D("t_ZA__6","",8,0,8);
   t_ZA__6->SetBinContent(1,15.29415);
   t_ZA__6->SetBinContent(2,4.173631);
   t_ZA__6->SetBinContent(3,0.3146356);
   t_ZA__6->SetBinContent(4,18.75586);
   t_ZA__6->SetBinContent(5,6.015142);
   t_ZA__6->SetBinContent(6,1.150829);
   t_ZA__6->SetBinContent(7,4.112772);
   t_ZA__6->SetBinContent(8,3.024686);
   t_ZA__6->SetBinError(1,1.819808);
   t_ZA__6->SetBinError(2,0.8019036);
   t_ZA__6->SetBinError(3,0.4217826);
   t_ZA__6->SetBinError(4,2.001125);
   t_ZA__6->SetBinError(5,1.06911);
   t_ZA__6->SetBinError(6,0.4151293);
   t_ZA__6->SetBinError(7,0.8964932);
   t_ZA__6->SetEntries(8);

   ci = TColor::GetColor("#ff00ff");
   t_ZA__6->SetFillColor(ci);

   ci = TColor::GetColor("#ff00ff");
   t_ZA__6->SetLineColor(ci);
   t_ZA__6->SetLineStyle(0);
   t_ZA__6->SetLineWidth(2);

   ci = TColor::GetColor("#ff00ff");
   t_ZA__6->SetMarkerColor(ci);
   t_ZA__6->SetMarkerStyle(20);
   t_ZA__6->GetXaxis()->SetLabelFont(42);
   t_ZA__6->GetXaxis()->SetLabelOffset(0.007);
   t_ZA__6->GetXaxis()->SetTitleSize(0.06);
   t_ZA__6->GetXaxis()->SetTitleOffset(0.9);
   t_ZA__6->GetXaxis()->SetTitleFont(42);
   t_ZA__6->GetYaxis()->SetLabelFont(42);
   t_ZA__6->GetYaxis()->SetLabelOffset(0.007);
   t_ZA__6->GetYaxis()->SetTitleSize(0.06);
   t_ZA__6->GetYaxis()->SetTitleOffset(1.1);
   t_ZA__6->GetYaxis()->SetTitleFont(42);
   t_ZA__6->GetZaxis()->SetLabelFont(42);
   t_ZA__6->GetZaxis()->SetLabelOffset(0.007);
   t_ZA__6->GetZaxis()->SetTitleSize(0.06);
   t_ZA__6->GetZaxis()->SetTitleFont(42);
   hs->Add(t_ZA,"");
   
   TH1D *ZA_sig__7 = new TH1D("ZA_sig__7","",8,0,8);
   ZA_sig__7->SetBinContent(1,6.087866);
   ZA_sig__7->SetBinContent(2,4.642518);
   ZA_sig__7->SetBinContent(3,2.804385);
   ZA_sig__7->SetBinContent(4,1.182416);
   ZA_sig__7->SetBinContent(5,2.625392);
   ZA_sig__7->SetBinContent(6,4.231791);
   ZA_sig__7->SetBinContent(7,0.2130374);
   ZA_sig__7->SetBinContent(8,2.06609);
   ZA_sig__7->SetBinError(1,0.3149597);
   ZA_sig__7->SetBinError(2,0.2738098);
   ZA_sig__7->SetBinError(3,0.214005);
   ZA_sig__7->SetBinError(4,0.1380921);
   ZA_sig__7->SetBinError(5,0.2054025);
   ZA_sig__7->SetBinError(6,0.2581857);
   ZA_sig__7->SetBinError(7,0.06000711);
   ZA_sig__7->SetEntries(8);

   ci = TColor::GetColor("#ff3333");
   ZA_sig__7->SetFillColor(ci);

   ci = TColor::GetColor("#ff3333");
   ZA_sig__7->SetLineColor(ci);
   ZA_sig__7->SetLineStyle(0);
   ZA_sig__7->SetLineWidth(2);

   ci = TColor::GetColor("#ff3333");
   ZA_sig__7->SetMarkerColor(ci);
   ZA_sig__7->SetMarkerStyle(21);
   ZA_sig__7->GetXaxis()->SetLabelFont(42);
   ZA_sig__7->GetXaxis()->SetLabelOffset(0.007);
   ZA_sig__7->GetXaxis()->SetTitleSize(0.06);
   ZA_sig__7->GetXaxis()->SetTitleOffset(0.9);
   ZA_sig__7->GetXaxis()->SetTitleFont(42);
   ZA_sig__7->GetYaxis()->SetLabelFont(42);
   ZA_sig__7->GetYaxis()->SetLabelOffset(0.007);
   ZA_sig__7->GetYaxis()->SetTitleSize(0.06);
   ZA_sig__7->GetYaxis()->SetTitleOffset(1.1);
   ZA_sig__7->GetYaxis()->SetTitleFont(42);
   ZA_sig__7->GetZaxis()->SetLabelFont(42);
   ZA_sig__7->GetZaxis()->SetLabelOffset(0.007);
   ZA_sig__7->GetZaxis()->SetTitleSize(0.06);
   ZA_sig__7->GetZaxis()->SetTitleFont(42);
   hs->Add(ZA_sig,"");
   hs->Draw("hist");
   
   TLegend *leg = new TLegend(0.82,0.7,0.95,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("ZA_sig","ZA_sig","lpf");

   ci = TColor::GetColor("#ff3333");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff3333");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff3333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("t_ZA","ZA","lpf");

   ci = TColor::GetColor("#ff00ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff00ff");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff00ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("plj","non-prompt","lpf");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ffff00");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("WA","WA","lpf");

   ci = TColor::GetColor("#000099");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("VV","VV","lpf");

   ci = TColor::GetColor("#6666cc");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#6666cc");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#6666cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("TTA","TTA","lpf");

   ci = TColor::GetColor("#00ffff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ffff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("ST","ST","lpf");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.18,0.82,"Preliminary");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.18,0.86,"CMS");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.76,0.92,"41.52 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
   pad1->Modified();
   ->cd();
   c1->Modified();
   ->cd();
   ->SetSelected();
}
