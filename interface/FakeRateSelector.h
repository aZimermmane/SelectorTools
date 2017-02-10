//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb  8 23:47:12 2017 by ROOT version 6.06/01
// from TTree ntuple/ntuple
// found on file: /data/kelong/DibosonAnalysisData/DYControlFakeRate/2017-02-05-data_MuonEG_Run2016B-23Sep2016-v3-WZxsec2016-DYControlFakeRate-v1/skim-ntuplize_1.root
//////////////////////////////////////////////////////////

#ifndef FakeRateSelector_h
#define FakeRateSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1.h>
#include <TH2.h>
#include <exception>

// Headers needed by this particular selector
#include <vector>



class FakeRateSelector : public TSelector {
public :
    TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain
    
    TList* histDir_;
    TH2D* passingTight2D_;
    TH1D* passingTight1DPt_;
    TH1D* passingTight1DEta_;
    TH2D* passingLoose2D_;
    TH1D* passingLoose1DPt_;
    TH1D* passingLoose1DEta_;
    TH2D* ratio2D_;
    TH1D* ratio1DPt_;
    TH1D* ratio1DEta_;

    Float_t type1_pfMETEt;
    UInt_t nWWLooseElec;
    UInt_t nWZLooseMuon;
    Bool_t l1IsTight;
    Bool_t l2IsTight;
    Bool_t l3IsTight;
    Bool_t e1IsEB;
    Bool_t e2IsEB;
    Bool_t e3IsEB;
    Float_t e1PVDXY;
    Float_t e2PVDXY;
    Float_t e3PVDXY;
    Float_t e1PVDZ;
    Float_t e2PVDZ;
    Float_t e3PVDZ;
    Float_t m1RelPFIsoDBR04;
    Float_t m2RelPFIsoDBR04;
    Float_t m3RelPFIsoDBR04;
    Float_t l3Eta;
    Float_t l3Pt;
    
    TBranch* b_type1_pfMETEt;
    TBranch* b_nWWLooseElec;
    TBranch* b_nWZLooseMuon;
    TBranch* b_l1IsTight;
    TBranch* b_l2IsTight;
    TBranch* b_l3IsTight;
    TBranch* b_e1IsEB;
    TBranch* b_e2IsEB;
    TBranch* b_e3IsEB;
    TBranch* b_e1PVDXY;
    TBranch* b_e2PVDXY;
    TBranch* b_e3PVDXY;
    TBranch* b_e1PVDZ;
    TBranch* b_e2PVDZ;
    TBranch* b_e3PVDZ;
    TBranch* b_m1RelPFIsoDBR04;
    TBranch* b_m2RelPFIsoDBR04;
    TBranch* b_m3RelPFIsoDBR04;
    TBranch* b_l3Eta;
    TBranch* b_l3Pt;

    // Readers to access the data (delete the ones you do not need).
    FakeRateSelector(TTree * /*tree*/ =0) { }
    virtual ~FakeRateSelector() { }
    virtual Int_t   Version() const { return 2; }
    virtual void    Begin(TTree *tree);
    virtual void    SlaveBegin(TTree *tree);
    virtual void    Init(TTree *tree);
    virtual Bool_t  Notify();
    virtual Bool_t  Process(Long64_t entry);
    virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
    virtual void    SetOption(const char *option) { fOption = option; }
    virtual void    SetObject(TObject *obj) { fObject = obj; }
    virtual void    SetInputList(TList *input) { fInput = input; }
    virtual TList  *GetOutputList() const { return fOutput; }
    virtual void    SlaveTerminate();
    virtual void    Terminate();

    ClassDef(FakeRateSelector,0);
private:
    const char* name_ = "Unnamed";
    std::string channel_ = "undefined";
    bool tightZLeptons();
    bool lepton3IsTight();
};

#endif

#ifdef FakeRateSelector_cxx
void FakeRateSelector::Init(TTree *tree)
{
    // The Init() function is called when the selector needs to initialize
    // a new tree or chain. Typically here the reader is initialized.
    // It is normally not necessary to make changes to the generated
    // code, but the routine can be extended by the user if needed.
    // Init() will be called many times when running on PROOF
    // (once per file to be processed).
    if (!tree) return;
    fChain = tree;
    fChain->SetBranchAddress("type1_pfMETEt", &type1_pfMETEt, &b_type1_pfMETEt);
    fChain->SetBranchAddress("nWWLooseElec", &nWWLooseElec, &b_nWWLooseElec);
    fChain->SetBranchAddress("nWZLooseMuon", &nWZLooseMuon, &b_nWZLooseMuon);

    if (channel_ == "eee") {
        fChain->SetBranchAddress("e1IsCBVIDTight", &l1IsTight, &b_l1IsTight);
        fChain->SetBranchAddress("e2IsCBVIDTight", &l2IsTight, &b_l2IsTight);
        fChain->SetBranchAddress("e3IsCBVIDTight", &l3IsTight, &b_l3IsTight);
        fChain->SetBranchAddress("e1IsEB", &e1IsEB, &b_e1IsEB);
        fChain->SetBranchAddress("e2IsEB", &e2IsEB, &b_e2IsEB);
        fChain->SetBranchAddress("e3IsEB", &e3IsEB, &b_e3IsEB);
        fChain->SetBranchAddress("e1PVDXY", &e1PVDXY, &b_e1PVDXY);
        fChain->SetBranchAddress("e2PVDXY", &e2PVDXY, &b_e2PVDXY);
        fChain->SetBranchAddress("e3PVDXY", &e3PVDXY, &b_e3PVDXY);
        fChain->SetBranchAddress("e1PVDZ", &e1PVDZ, &b_e1PVDZ);
        fChain->SetBranchAddress("e2PVDZ", &e2PVDZ, &b_e2PVDZ);
        fChain->SetBranchAddress("e3PVDZ", &e3PVDZ, &b_e3PVDZ);
        
        fChain->SetBranchAddress("e3Pt", &l3Pt, &b_l3Pt);
        fChain->SetBranchAddress("e3Eta", &l3Eta, &b_l3Eta);
    }
    else if (channel_ == "eem") { 
        fChain->SetBranchAddress("e1IsCBVIDTight", &l1IsTight, &b_l1IsTight);
        fChain->SetBranchAddress("e2IsCBVIDTight", &l2IsTight, &b_l2IsTight);
        fChain->SetBranchAddress("e1IsEB", &e1IsEB, &b_e1IsEB);
        fChain->SetBranchAddress("e2IsEB", &e2IsEB, &b_e2IsEB);
        fChain->SetBranchAddress("e1PVDXY", &e1PVDXY, &b_e1PVDXY);
        fChain->SetBranchAddress("e2PVDXY", &e2PVDXY, &b_e2PVDXY);
        fChain->SetBranchAddress("e1PVDZ", &e1PVDZ, &b_e1PVDZ);
        fChain->SetBranchAddress("e2PVDZ", &e2PVDZ, &b_e2PVDZ);
        
        fChain->SetBranchAddress("mIsWZMediumMuon", &l3IsTight, &b_l3IsTight);
        fChain->SetBranchAddress("mRelPFIsoDBR04", &m3RelPFIsoDBR04, &b_m3RelPFIsoDBR04);
        fChain->SetBranchAddress("mPt", &l3Pt, &b_l3Pt);
        fChain->SetBranchAddress("mEta", &l3Eta, &b_l3Eta);
    }
    else if (channel_ == "emm") { 
        fChain->SetBranchAddress("eIsCBVIDTight", &l3IsTight, &b_l3IsTight);
        fChain->SetBranchAddress("eIsEB", &e3IsEB, &b_e3IsEB);
        fChain->SetBranchAddress("ePVDXY", &e3PVDXY, &b_e3PVDXY);
        fChain->SetBranchAddress("ePVDZ", &e3PVDZ, &b_e3PVDZ);
        fChain->SetBranchAddress("m1IsWZMediumMuon", &l1IsTight, &b_l1IsTight);
        fChain->SetBranchAddress("m1RelPFIsoDBR04", &m1RelPFIsoDBR04, &b_m1RelPFIsoDBR04);
        fChain->SetBranchAddress("m2IsWZMediumMuon", &l2IsTight, &b_l2IsTight);
        fChain->SetBranchAddress("m2RelPFIsoDBR04", &m2RelPFIsoDBR04, &b_m2RelPFIsoDBR04);
        fChain->SetBranchAddress("ePt", &l3Pt, &b_l3Pt);
        fChain->SetBranchAddress("eEta", &l3Eta, &b_l3Eta);
    }
    else if (channel_ == "mmm") { 
        fChain->SetBranchAddress("m1IsWZMediumMuon", &l1IsTight, &b_l1IsTight);
        fChain->SetBranchAddress("m1RelPFIsoDBR04", &m1RelPFIsoDBR04, &b_m1RelPFIsoDBR04);
        fChain->SetBranchAddress("m2IsWZMediumMuon", &l2IsTight, &b_l2IsTight);
        fChain->SetBranchAddress("m2RelPFIsoDBR04", &m2RelPFIsoDBR04, &b_m2RelPFIsoDBR04);
        fChain->SetBranchAddress("m3IsWZMediumMuon", &l3IsTight, &b_l3IsTight);
        fChain->SetBranchAddress("m3RelPFIsoDBR04", &m3RelPFIsoDBR04, &b_m3RelPFIsoDBR04);
        fChain->SetBranchAddress("m3Pt", &l3Pt, &b_l3Pt);
        fChain->SetBranchAddress("m3Eta", &l3Eta, &b_l3Eta);
    }
    else
        throw std::invalid_argument("Invalid channel choice!");
}

Bool_t FakeRateSelector::Notify()
{
    // The Notify() function is called when a new file is opened. This
    // can be either for a new TTree in a TChain or when when a new TTree
    // is started when using PROOF. It is normally not necessary to make changes
    // to the generated code, but the routine can be extended by the
    // user if needed. The return value is currently not used.

    return kTRUE;
}


#endif // #ifdef FakeRateSelector_cxx