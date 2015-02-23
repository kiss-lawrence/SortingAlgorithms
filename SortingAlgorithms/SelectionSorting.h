//
//  SelectionSorting.h
//  SortingAlgorithms
//
//  Created by 刘睿 on 22/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#ifndef __SortingAlgorithms__SelectionSorting__
#define __SortingAlgorithms__SelectionSorting__

#include "Algorithm.h"

class SelectionSorting : public Algorithm {
  public :
    SelectionSorting(int size);
    virtual const char* getName() const override;
    virtual void init(int size) override;
    virtual void nextStep(Data& data) override;
  
  private :
    static const char* name;
    int minI;
};

#endif /* defined(__SortingAlgorithms__SelectionSorting__) */
