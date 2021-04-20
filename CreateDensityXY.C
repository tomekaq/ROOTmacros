#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h> 
#include <TTree.h> 
#include <TBranch.h> 
#include <TClass.h> 


{

gROOT->Reset(); 
gStyle->SetPalette(1);
gROOT->ForceStyle();
gStyle->SetOptStat(0);
gStyle->SetPalette(kBird);

auto c1  = new TCanvas("XY","XY",1200,800);

TFile *_file0 = TFile::Open( "DAT-10-6GeV_1.root");

TTree *tree;
_file0->GetObject("data_1",tree);

TBranch *xBranch;
Double_t xData; 
tree->SetBranchAddress("x",&xData,&xBranch);

TBranch *yBranch;
Double_t yData;
tree->SetBranchAddress("y",&yData,&yBranch);

int nentries = tree -> GetEntries();



auto *histogramCOLz = new TH2D("Statistics"	, "" ,30, -5000,5000,30,-5000,5000);

for(int i=1; i<=nentries; i=i+1)     
{
 	tree->GetEntry(i);
	histogramCOLz-> SetFillColor( kBlue-2);
	histogramCOLz->Fill(xData,yData);
}



histogramCOLz->Draw("colz");


return 0;                                             
}
