#include "TString.h"
#include "TH1F.h"
#include "TStyle.h"
#include "TFile.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "THStack.h"
#include <iostream>

void ProduceCutBasedTemplates(){
 
 
 TFile *outputfile  = new TFile("ThetaFile_cutbased.root", "recreate");
 outputfile->cd();
 
 
 TH1F *yield_DY        = new TH1F("yield__dy",       "yield__dy",       1, 0.5, 1.5);
 TH1F *yield_fake      = new TH1F("yield__fake",     "yield__fake",     1, 0.5, 1.5);
 TH1F *yield_singletop = new TH1F("yield__singletop", "yield__singletop", 1, 0.5, 1.5);
 TH1F *yield_vv        = new TH1F("yield__vv",       "yield__vv",       1, 0.5, 1.5);
 TH1F *yield_rare      = new TH1F("yield__rare",     "yield__rare",     1, 0.5, 1.5);
 TH1F *yield_ttbar     = new TH1F("yield__ttbar",    "yield__ttbar",    1, 0.5, 1.5);
 TH1F *yield_susy175   = new TH1F("yield__susy175",    "yield__susy175",    1, 0.5, 1.5);
 
 yield_DY       ->SetBinContent(1,  178.6);      
 yield_fake     ->SetBinContent(1,  265.5);  
 yield_singletop->SetBinContent(1,  1010.5);  
 yield_vv       ->SetBinContent(1,  32.2);  
 yield_rare     ->SetBinContent(1,  239.6);  
 yield_ttbar    ->SetBinContent(1,  24050);  
 yield_susy175  ->SetBinContent(1,  3672.3);  
 
 yield_DY       ->SetBinError(1,  23.5);      
 yield_fake     ->SetBinError(1,  21.2);  
 yield_singletop->SetBinError(1,  2.7);  
 yield_vv       ->SetBinError(1,  1.7);  
 yield_rare     ->SetBinError(1,  7.7);  
 yield_ttbar    ->SetBinError(1,  40.0);  
 yield_susy175  ->SetBinError(1,  71.5);  
 
 
 
 //-------------------------------------
 //For isolation uncertainties
 //-------------------------------------
 
 
 TH1F *yield_singletop__iso__plus = new TH1F("yield__singletop__iso__plus", "yield__singletop__iso__plus", 1, 0.5, 1.5);
 TH1F *yield_vv__iso__plus        = new TH1F("yield__vv__iso__plus",       "yield__vv__iso__plus",       1, 0.5, 1.5);
 TH1F *yield_rare__iso__plus      = new TH1F("yield__rare__iso__plus",     "yield__rare__iso__plus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__iso__plus     = new TH1F("yield__ttbar__iso__plus",    "yield__ttbar__iso__plus",    1, 0.5, 1.5);
 TH1F *yield_susy175__iso__plus   = new TH1F("yield__susy175__iso__plus",    "yield__susy175__iso__plus",    1, 0.5, 1.5);
 
 
 TH1F *yield_singletop__iso__minus = new TH1F("yield__singletop__iso__minus", "yield__singletop__iso__minus", 1, 0.5, 1.5);
 TH1F *yield_vv__iso__minus        = new TH1F("yield__vv__iso__minus",       "yield__vv__iso__minus",       1, 0.5, 1.5);
 TH1F *yield_rare__iso__minus      = new TH1F("yield__rare__iso__minus",     "yield__rare__iso__minus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__iso__minus     = new TH1F("yield__ttbar__iso__minus",    "yield__ttbar__iso__minus",    1, 0.5, 1.5);
 TH1F *yield_susy175__iso__minus   = new TH1F("yield__susy175__iso__minus",    "yield__susy175__iso__minus",    1, 0.5, 1.5);
 
 
 yield_singletop__iso__plus->SetBinContent(1,  1010.5+0.015*1010.5);  
 yield_vv__iso__plus       ->SetBinContent(1,  32.2+0.019*32.2);  
 yield_rare__iso__plus     ->SetBinContent(1,  239.6+0.030*239.6);  
 yield_ttbar__iso__plus    ->SetBinContent(1,  24050+0.011*24050); 
 yield_susy175__iso__plus  ->SetBinContent(1,  3672.3+0.011*3672.3);  
 
 yield_singletop__iso__minus->SetBinContent(1,  1010.5-0.015*1010.5);  
 yield_vv__iso__minus       ->SetBinContent(1,  32.2-0.019*32.2);  
 yield_rare__iso__minus     ->SetBinContent(1,  239.6-0.030*239.6);  
 yield_ttbar__iso__minus    ->SetBinContent(1,  24050-0.011*24050);  
 yield_susy175__iso__minus  ->SetBinContent(1,  3672.3-0.011*3672.3); 

 
 //-------------------------------------
 //For les uncertainties
 //-------------------------------------
 
 
 TH1F *yield_singletop__les__plus = new TH1F("yield__singletop__les__plus", "yield__singletop__les__plus", 1, 0.5, 1.5);
 TH1F *yield_vv__les__plus        = new TH1F("yield__vv__les__plus",       "yield__vv__les__plus",       1, 0.5, 1.5);
 TH1F *yield_rare__les__plus      = new TH1F("yield__rare__les__plus",     "yield__rare__les__plus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__les__plus     = new TH1F("yield__ttbar__les__plus",    "yield__ttbar__les__plus",    1, 0.5, 1.5);
 TH1F *yield_susy175__les__plus   = new TH1F("yield__susy175__les__plus",    "yield__susy175__les__plus",    1, 0.5, 1.5);
 
 
 TH1F *yield_singletop__les__minus = new TH1F("yield__singletop__les__minus", "yield__singletop__les__minus", 1, 0.5, 1.5);
 TH1F *yield_vv__les__minus        = new TH1F("yield__vv__les__minus",       "yield__vv__les__minus",       1, 0.5, 1.5);
 TH1F *yield_rare__les__minus      = new TH1F("yield__rare__les__minus",     "yield__rare__les__minus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__les__minus     = new TH1F("yield__ttbar__les__minus",    "yield__ttbar__les__minus",    1, 0.5, 1.5);
 TH1F *yield_susy175__les__minus   = new TH1F("yield__susy175__les__minus",    "yield__susy175__les__minus",    1, 0.5, 1.5);
 
 
 yield_singletop__les__plus->SetBinContent(1,  1010.5 + 0.001*1010.5);  
 yield_vv__les__plus       ->SetBinContent(1,  32.2   + 0.042 *32.2);  
 yield_rare__les__plus     ->SetBinContent(1,  239.6  + 0.008*239.6);  
 yield_ttbar__les__plus    ->SetBinContent(1,  24050  + 0.002*24050);
 yield_susy175__les__plus  ->SetBinContent(1,  3672.3 + 0.008*3672.3);   
 
 yield_singletop__les__minus->SetBinContent(1,  1010.5-0.001*1010.5);  
 yield_vv__les__minus       ->SetBinContent(1,  32.2  -0.042 *32.2);  
 yield_rare__les__minus     ->SetBinContent(1,  239.6 -0.008*239.6);  
 yield_ttbar__les__minus    ->SetBinContent(1,  24050 -0.002*24050); 
 yield_susy175__les__minus  ->SetBinContent(1,  3672.3-0.008*3672.3);  
  
  
 
 //-------------------------------------
 //For jes uncertainties
 //-------------------------------------
 
 
 TH1F *yield_singletop__jes__plus = new TH1F("yield__singletop__jes__plus", "yield__singletop__jes__plus", 1, 0.5, 1.5);
 TH1F *yield_vv__jes__plus        = new TH1F("yield__vv__jes__plus",       "yield__vv__jes__plus",       1, 0.5, 1.5);
 TH1F *yield_rare__jes__plus      = new TH1F("yield__rare__jes__plus",     "yield__rare__jes__plus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__jes__plus     = new TH1F("yield__ttbar__jes__plus",    "yield__ttbar__jes__plus",    1, 0.5, 1.5);
 TH1F *yield_susy175__jes__plus   = new TH1F("yield__susy175__jes__plus",    "yield__susy175__jes__plus",    1, 0.5, 1.5);
 
 
 TH1F *yield_singletop__jes__minus = new TH1F("yield__singletop__jes__minus", "yield__singletop__jes__minus", 1, 0.5, 1.5);
 TH1F *yield_vv__jes__minus        = new TH1F("yield__vv__jes__minus",       "yield__vv__jes__minus",       1, 0.5, 1.5);
 TH1F *yield_rare__jes__minus      = new TH1F("yield__rare__jes__minus",     "yield__rare__jes__minus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__jes__minus     = new TH1F("yield__ttbar__jes__minus",    "yield__ttbar__jes__minus",    1, 0.5, 1.5);
 TH1F *yield_susy175__jes__minus   = new TH1F("yield__susy175__jes__minus",    "yield__susy175__jes__minus",    1, 0.5, 1.5);
 
 
 yield_singletop__jes__plus->SetBinContent(1,  1010.5  +0.034*1010.5);  
 yield_vv__jes__plus       ->SetBinContent(1,  32.2    +0.085*32.2);  
 yield_rare__jes__plus     ->SetBinContent(1,  239.6   +0.016*239.6);  
 yield_ttbar__jes__plus    ->SetBinContent(1,  24050   +0.020*24050); 
 yield_susy175__jes__plus  ->SetBinContent(1,  3672.3  +0.023*3672.3);  
 
 yield_singletop__jes__minus->SetBinContent(1,  1010.5 -0.034*1010.5);  
 yield_vv__jes__minus       ->SetBinContent(1,  32.2   -0.085*32.2);  
 yield_rare__jes__minus     ->SetBinContent(1,  239.6  -0.016*239.6);  
 yield_ttbar__jes__minus    ->SetBinContent(1,  24050  -0.020*24050); 
 yield_susy175__jes__minus  ->SetBinContent(1,  3672.3 -0.023*3672.3);  

  
 
 //-------------------------------------
 //For btag uncertainties
 //-------------------------------------
 
 
 TH1F *yield_singletop__btag__plus = new TH1F("yield__singletop__btag__plus", "yield__singletop__btag__plus", 1, 0.5, 1.5);
 TH1F *yield_vv__btag__plus        = new TH1F("yield__vv__btag__plus",       "yield__vv__btag__plus",       1, 0.5, 1.5);
 TH1F *yield_rare__btag__plus      = new TH1F("yield__rare__btag__plus",     "yield__rare__btag__plus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__btag__plus     = new TH1F("yield__ttbar__btag__plus",    "yield__ttbar__btag__plus",    1, 0.5, 1.5);
 TH1F *yield_susy175__btag__plus   = new TH1F("yield__susy175__btag__plus",    "yield__susy175__btag__plus",    1, 0.5, 1.5);
 
 
 TH1F *yield_singletop__btag__minus = new TH1F("yield__singletop__btag__minus", "yield__singletop__btag__minus", 1, 0.5, 1.5);
 TH1F *yield_vv__btag__minus        = new TH1F("yield__vv__btag__minus",       "yield__vv__btag__minus",       1, 0.5, 1.5);
 TH1F *yield_rare__btag__minus      = new TH1F("yield__rare__btag__minus",     "yield__rare__btag__minus",     1, 0.5, 1.5);
 TH1F *yield_ttbar__btag__minus     = new TH1F("yield__ttbar__btag__minus",    "yield__ttbar__btag__minus",    1, 0.5, 1.5);
 TH1F *yield_susy175__btag__minus   = new TH1F("yield__susy175__btag__minus",    "yield__susy175__btag__minus",    1, 0.5, 1.5);
 
 
 yield_singletop__btag__plus->SetBinContent(1,  1010.5 +0.017*1010.5);  
 yield_vv__btag__plus       ->SetBinContent(1,  32.2   +0.058*32.2);  
 yield_rare__btag__plus     ->SetBinContent(1,  239.6  +0.012*239.6);  
 yield_ttbar__btag__plus    ->SetBinContent(1,  24050  +0.014*24050); 
 yield_susy175__btag__plus  ->SetBinContent(1,  3672.3+0.027*3672.3);  
 
 yield_singletop__btag__minus->SetBinContent(1,  1010.5-0.017*1010.5);  
 yield_vv__btag__minus       ->SetBinContent(1,  32.2  -0.058*32.2);  
 yield_rare__btag__minus     ->SetBinContent(1,  239.6 -0.012*239.6);  
 yield_ttbar__btag__minus    ->SetBinContent(1,  24050 -0.014*24050); 
 yield_susy175__btag__minus  ->SetBinContent(1,  3672.3-0.027*3672.3);  

 
 //-------------------------------------
 //For mistag uncertainties
 //-------------------------------------
 
 
 //TH1F *yield_singletop__mistag__plus = new TH1F("yield_singletop__mistag__plus", "yield_singletop__mistag__plus", 1, 0.5, 1.5);
 TH1F *yield_vv__mistag__plus        = new TH1F("yield__vv__mistag__plus",       "yield__vv__mistag__plus",       1, 0.5, 1.5);
 TH1F *yield_rare__mistag__plus      = new TH1F("yield__rare__mistag__plus",     "yield__rare__mistag__plus",     1, 0.5, 1.5);
 //TH1F *yield_ttbar__mistag__plus     = new TH1F("yield__ttbar__mistag__plus",    "yield__ttbar__mistag__plus",    1, 0.5, 1.5);
 TH1F *yield_susy175__mistag__plus   = new TH1F("yield__susy175__mistag__plus",    "yield__susy175__mistag__plus",    1, 0.5, 1.5);
 
 
 //TH1F *yield_singletop__mistag__minus = new TH1F("yield_singletop__mistag__minus", "yield_singletop__mistag__minus", 1, 0.5, 1.5);
 TH1F *yield_vv__mistag__minus        = new TH1F("yield__vv__mistag__minus",       "yield__vv__mistag__minus",       1, 0.5, 1.5);
 TH1F *yield_rare__mistag__minus      = new TH1F("yield__rare__mistag__minus",     "yield__rare__mistag__minus",     1, 0.5, 1.5);
 //TH1F *yield_ttbar__mistag__minus     = new TH1F("yield__ttbar__mistag__minus",    "yield__ttbar__mistag__minus",    1, 0.5, 1.5);
 TH1F *yield_susy175__mistag__minus   = new TH1F("yield__susy175__mistag__minus",    "yield__susy175__mistag__minus",    1, 0.5, 1.5);
 
 
 //yield_singletop__mistag__plus->SetBinContent(1,  1010.5 +*1010.5);  
 yield_vv__mistag__plus       ->SetBinContent(1,  32.2   +0.025*32.2);  
 yield_rare__mistag__plus     ->SetBinContent(1,  239.6  +0.004*239.6);  
 //yield_ttbar__mistag__plus    ->SetBinContent(1,  24050  +*);  
 yield_susy175__mistag__plus  ->SetBinContent(1,  3672.3+0.003*3672.3); 
 
 //yield_singletop__mistag__minus->SetBinContent(1,  1010.5-*1010.5);  
 yield_vv__mistag__minus       ->SetBinContent(1,  32.2  -0.025*32.2);  
 yield_rare__mistag__minus     ->SetBinContent(1,  239.6 -0.004*239.6);  
 //yield_ttbar__mistag__minus    ->SetBinContent(1,  24050 -*);  
 yield_susy175__mistag__minus  ->SetBinContent(1,  3672.3-0.003*3672.3); 

 
 
 //-------------------------------------
 //For scale uncertainties
 //-------------------------------------
 
 
 
 TH1F *yield_ttbar__scale__plus     = new TH1F("yield__ttbar__scale__plus",    "yield__ttbar__scale__plus",    1, 0.5, 1.5);
 TH1F *yield_ttbar__scale__minus     = new TH1F("yield__ttbar__scale__minus",    "yield__ttbar__scale__minus",    1, 0.5, 1.5);
   
 yield_ttbar__scale__plus    ->SetBinContent(1,  24050+0.012*24050);   
 yield_ttbar__scale__minus   ->SetBinContent(1,  24050-0.012*24050);  

 
 
 
 //-------------------------------------
 //For scale uncertainties
 //-------------------------------------
 
 
 TH1F *yield_ttbar__match__plus     = new TH1F("yield__ttbar__match__plus",    "yield__ttbar__match__plus",      1, 0.5, 1.5);
 TH1F *yield_ttbar__match__minus    = new TH1F("yield__ttbar__match__minus",    "yield__ttbar__match__minus",    1, 0.5, 1.5);
 
 
 yield_ttbar__match__plus    ->SetBinContent(1,  24050+0.007*24050);  
 yield_ttbar__match__minus   ->SetBinContent(1,  24050-0.007*24050);  
 
 
 TH1F *yield_DATA   = new TH1F("yield__DATA",    "yield__DATA",	 1, 0.5, 1.5);
  
 yield_DATA       ->SetBinContent(1, 26401 );      
 yield_DATA       ->SetBinError(1,  162.484  );   
 
 
 outputfile->Write();
 
 
}
