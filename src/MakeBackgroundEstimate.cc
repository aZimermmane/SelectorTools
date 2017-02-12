#define MakeBackgroundEstimate_cxx
// The class definition in MakeBackgroundEstimate.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following se                                              MakeBackgroundEstimate.C")
// root> T->Process("MakeBackgroundEstimate.C","some options")
// root> T->Process("MakeBackgroundEstimate.C+")
//


#include "Analysis/WZAnalysis/interface/MakeBackgroundEstimate.h"
#include <TStyle.h>

void MakeBackgroundEstimate::Begin(TTree * /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();
}

void MakeBackgroundEstimate::SlaveBegin(TTree * /*tree*/)
{
    // The SlaveBegin() function is called after the Begin() function.
    // When running with PROOF SlaveBegin() is called on each slave server.
    // The tree argument is deprecated (on PROOF 0 is passed).
    fakeRate_allE = (ScaleFactor *) GetInputList()->FindObject("fakeRate_allE");
    fakeRate_allMu = (ScaleFactor *) GetInputList()->FindObject("fakeRate_allMu");

    if (GetInputList() != nullptr) {
        TNamed* name = (TNamed *) GetInputList()->FindObject("name");
        TNamed* chan = (TNamed *) GetInputList()->FindObject("channel");
        if (name != nullptr) {
            name_ = name->GetTitle();
        }
        if (chan != nullptr) {
            channel_ = chan->GetTitle();
        }
    }
    histDir_ = new TList();
    histDir_->SetName(name_.c_str());
    fOutput->Add(histDir_);
    massHist_= new TH1D(("Mass_"+channel_).c_str(),
        "Mass; Events; M_{3l} [GeV];", 20, 0, 400);
    massHist_->SetDirectory(0);
    histDir_->Add(massHist_);
    TString option = GetOption();
}

Bool_t MakeBackgroundEstimate::Process(Long64_t entry)
{
    // The Process() function is called for each entry in the tree (or possibly
    // keyed object in the case of PROOF) to be processed. The entry argument
    // specifies which entry in the currently loaded tree is to be processed.
    // When processing keyed objects with PROOF, the object is already loaded
    // and is available via the fObject pointer.
    //
    // This function should contain the \"body\" of the analysis. It can contain
    // simple or elaborate selection criteria, run algorithms on the data
    // of the event and typically fill histograms.
    //
    // The processing can be stopped by calling Abort().
    //
    // Use fStatus to set the return value of TTree::Process().
    //
    // The return value is currently not used.

    if (name_.find("data") == std::string::npos)
        b_genWeight->GetEntry(entry);
    else 
        genWeight = 1;
    b_type1_pfMETEt->GetEntry(entry);
    b_nWWLooseElec->GetEntry(entry);
    b_nWZLooseMuon->GetEntry(entry);
    b_l1IsTight->GetEntry(entry);
    b_l2IsTight->GetEntry(entry);
    b_l3IsTight->GetEntry(entry);
    b_l1Eta->GetEntry(entry);
    b_l1Pt->GetEntry(entry);
    b_l2Eta->GetEntry(entry);
    b_l2Pt->GetEntry(entry);
    b_l3Eta->GetEntry(entry);
    b_l3Pt->GetEntry(entry);
    if (channel_ == "eee") {
        b_e1IsEB->GetEntry(entry);
        b_e2IsEB->GetEntry(entry);
        b_e3IsEB->GetEntry(entry);
        b_e1PVDXY->GetEntry(entry);
        b_e2PVDXY->GetEntry(entry);
        b_e3PVDXY->GetEntry(entry);
        b_e1PVDZ->GetEntry(entry);
        b_e2PVDZ->GetEntry(entry);
        b_e3PVDZ->GetEntry(entry);
    }
    else if (channel_ == "eem") {
        b_e1IsEB->GetEntry(entry);
        b_e2IsEB->GetEntry(entry);
        b_e1PVDXY->GetEntry(entry);
        b_e2PVDXY->GetEntry(entry);
        b_e1PVDZ->GetEntry(entry);
        b_e2PVDZ->GetEntry(entry);
        b_m3RelPFIsoDBR04->GetEntry(entry);
    }
    else if (channel_ == "emm") {
        b_e3IsEB->GetEntry(entry);
        b_e3PVDXY->GetEntry(entry);
        b_e3PVDZ->GetEntry(entry);
        b_m1RelPFIsoDBR04->GetEntry(entry);
        b_m2RelPFIsoDBR04->GetEntry(entry);
    }
    else if (channel_ == "mmm") {
        b_m1RelPFIsoDBR04->GetEntry(entry);
        b_m2RelPFIsoDBR04->GetEntry(entry);
        b_m3RelPFIsoDBR04->GetEntry(entry);
    }
    if (nWWLooseElec + nWZLooseMuon != 3)
        return true;
    if (type1_pfMETEt < 30)
        return true;
    //if (IsFPPRegion())
        massHist_->Fill(Mass, getl1FakeRate());
    //else if (IsPFPRegion())
    //    massHist_->Fill(Mass, getl2FakeRate());
    //else if (IsFPFRegion())
    //    massHist_->Fill(Mass, getl1FakeRate()*getl3FakeRate());
    //else if (IsFFPRegion())
    //    massHist_->Fill(Mass, getl1FakeRate()*getl2FakeRate());
    //else if (IsPFFRegion())
    //    massHist_->Fill(Mass, getl2FakeRate()*getl3FakeRate());
    //else
    //    massHist_->Fill(Mass, getl1FakeRate()*getl2FakeRate()*getl3FakeRate());
    return kTRUE;
}

float MakeBackgroundEstimate::getl1FakeRate() {
    if (channel_ == "eem" || channel_ == "eee")
        return fakeRate_allE->Evaluate2D(l1Pt, l1Eta);
    else
        return fakeRate_allMu->Evaluate2D(l1Pt, l1Eta);
}

float MakeBackgroundEstimate::getl2FakeRate() {
    if (channel_ == "eem" || channel_ == "eee")
        return fakeRate_allE->Evaluate2D(l2Pt, l2Eta);
    else
        return fakeRate_allMu->Evaluate2D(l2Pt, l2Eta);
}

float MakeBackgroundEstimate::getl3FakeRate() {
    if (channel_ == "emm" || channel_ == "eee")
        return fakeRate_allE->Evaluate2D(l3Pt, l3Eta);
    else
        return fakeRate_allMu->Evaluate2D(l3Pt, l3Eta);
}

bool MakeBackgroundEstimate::IsFPPRegion() {
    return zlep2IsTight() && wlepIsTight();
}
bool MakeBackgroundEstimate::IsPFPRegion() {
    return zlep1IsTight() && wlepIsTight();
}

bool MakeBackgroundEstimate::IsPPFRegion() {
    return zlep1IsTight() && zlep2IsTight();
}

bool MakeBackgroundEstimate::IsFPFRegion() {
    return zlep2IsTight();
}

bool MakeBackgroundEstimate::IsFFPRegion() {
    return wlepIsTight();
}

bool MakeBackgroundEstimate::IsPFFRegion() {
    return zlep1IsTight();
}

bool MakeBackgroundEstimate::zlep1IsTight() {
    if (channel_ == "eem" || channel_ == "eee") {
        return (l1IsTight &&
            (e1IsEB ? e1PVDXY < 0.05 : e1PVDXY < 0.1) &&
            (e1IsEB ? e1PVDZ < 0.1 : e1PVDZ < 0.2));
    }
    else 
        return l1IsTight && (m1RelPFIsoDBR04 < 0.15);
}

bool MakeBackgroundEstimate::zlep2IsTight() {
    if (channel_ == "eem" || channel_ == "eee") {
        return (l2IsTight &&
            (e2IsEB ? e2PVDXY < 0.05 : e2PVDXY < 0.1) &&
            (e2IsEB ? e2PVDZ < 0.1 : e2PVDZ < 0.2));
    }
    else 
        return l2IsTight && (m2RelPFIsoDBR04 < 0.15);
}

bool MakeBackgroundEstimate::wlepIsTight() {
    if (channel_ == "emm" || channel_ == "eee") {
        return (l2IsTight &&
            (e3IsEB ? e3PVDXY < 0.05 : e3PVDXY < 0.1) &&
            (e3IsEB ? e3PVDZ < 0.1 : e3PVDZ < 0.2));
    }
    else 
        return l3IsTight && (m3RelPFIsoDBR04 < 0.15);
}

void MakeBackgroundEstimate::SlaveTerminate()
{
    // The SlaveTerminate() function is called after all entries or objects
    // have been processed. When running with PROOF SlaveTerminate() is called
    // on each slave server.

}

void MakeBackgroundEstimate::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.
}
