#include "Analysis/VVAnalysis/interface/FakeRateSelector.h"
#include "Analysis/VVAnalysis/interface/SelectorBase.h"
#include "Analysis/VVAnalysis/interface/ZSelector.h"
#include "Analysis/VVAnalysis/interface/ZZGenSelector.h"
#include "Analysis/VVAnalysis/interface/WGenSelector.h"
#include "Analysis/VVAnalysis/interface/ZGenSelector.h"
#include "Analysis/VVAnalysis/interface/NanoGenSelectorBase.h"
#include "Analysis/VVAnalysis/interface/WZSelector.h"
#include "Analysis/VVAnalysis/interface/TTTSelector.h"
#include "Analysis/VVAnalysis/interface/WZSelectorBase.h"
#include "Analysis/VVAnalysis/interface/WZBackgroundSelector.h"
#include "Analysis/VVAnalysis/interface/ScaleFactor.h"
#include "Analysis/VVAnalysis/interface/disambiguateFinalStates.h"
#include "Analysis/VVAnalysis/interface/disambiguateFinalStatesZZ.h"

namespace{
  namespace{
    FakeRateSelector pFakeRateSelector;
    WZSelectorBase pWZSelectorBase;
    SelectorBase pSelectorBase;
    ZSelector pZSelector;
    WZSelector pWZSelector;
    NanoGenSelectorBase pNanoGenSelectorBase;
    ZZGenSelector pZZGenSelector;
    TTTSelector pTTTSelector;
    WGenSelector pWGenSelector;
    ZGenSelector pZGenSelector;
    TTTSelector pTTTSelector;
    WZBackgroundSelector pWZBackgroundSelector;
    ScaleFactor pScaleFactor;
    disambiguateFinalStates pDisambiguator;
    disambiguateFinalStates pDisambiguatorZZ;
  }
}
