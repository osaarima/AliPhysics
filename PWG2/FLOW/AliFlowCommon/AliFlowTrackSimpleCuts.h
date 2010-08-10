/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. */
/* See cxx source for full Copyright notice */
/* $Id$ */

// AliFlowTrackSimpleCuts:
// A simple track cut class to the the AliFlowTrackSimple for basic
// kinematic cuts
// author: N. van der Kolk (kolk@nikhef.nl)
// mods: Mikolaj Krzewicki (mikolaj.krzewicki@cern.ch)

#ifndef ALIFLOWTRACKSIMPLECUTS_H
#define ALIFLOWTRACKSIMPLECUTS_H

#include "TNamed.h"
#include "AliFlowTrackSimple.h"  //needed as include

class TParticle;

class AliFlowTrackSimpleCuts : public TNamed {

 public:
  AliFlowTrackSimpleCuts();
  AliFlowTrackSimpleCuts(const AliFlowTrackSimpleCuts& someCuts);
  AliFlowTrackSimpleCuts& operator=(const AliFlowTrackSimpleCuts& someCuts);
  virtual  ~AliFlowTrackSimpleCuts();
  
  //setters
  void SetPtMax(Double_t max)   {this->fPtMax = max; }
  void SetPtMin(Double_t min)   {this->fPtMin = min; }
  void SetEtaMax(Double_t max)  {this->fEtaMax = max; }
  void SetEtaMin(Double_t min)  {this->fEtaMin = min; }
  void SetPhiMax(Double_t max)  {this->fPhiMax = max; }
  void SetPhiMin(Double_t min)  {this->fPhiMin = min; }
  void SetPID(Int_t pid)        {this->fPID = pid; }
  void SetCharge(Int_t c)       {this->fCharge = c; }
  
  //getters
  Double_t GetPtMax() const     {return this->fPtMax; }
  Double_t GetPtMin() const     {return this->fPtMin; }
  Double_t GetEtaMax() const    {return this->fEtaMax; }
  Double_t GetEtaMin() const    {return this->fEtaMin; }
  Double_t GetPhiMax() const    {return this->fPhiMax; }
  Double_t GetPhiMin() const    {return this->fPhiMin; }
  Int_t    GetPID() const       {return this->fPID; }
  Int_t    GetCharge() const    {return this->fCharge; }
  
  //simple method to check if the simple track passes the simple cuts:
  Bool_t PassesCuts(const AliFlowTrackSimple *track) const;
  Bool_t PassesCuts(TParticle* p) const;

 private:
  Double_t fPtMax;
  Double_t fPtMin;
  Double_t fEtaMax;
  Double_t fEtaMin;
  Double_t fPhiMax;
  Double_t fPhiMin;
  Int_t    fPID;
  Int_t    fCharge;

  static const Int_t fgkIgnoreCharge=999;

  ClassDef(AliFlowTrackSimpleCuts,1)
};

#endif


