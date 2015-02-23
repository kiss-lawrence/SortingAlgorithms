//
//  BubbleSorting.h
//  SortingAlgorithms
//
//  Created by 刘睿 on 23/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#ifndef __SortingAlgorithms__BubbleSorting__
#define __SortingAlgorithms__BubbleSorting__

#include "Algorithm.h"

class BubbleSorting : public Algorithm {
  public :
    BubbleSorting(int size);
    virtual const char* getName() const override;
    virtual void init(int size) override;
    virtual void nextStep(Data& data) override;
  
  private :
    static const char* name;
    bool swapped;
};

#endif /* defined(__SortingAlgorithms__BubbleSorting__) */
