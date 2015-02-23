//
//  InsertionSorting.h
//  SortingAlgorithms
//
//  Created by 刘睿 on 23/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#ifndef __SortingAlgorithms__InsertionSorting__
#define __SortingAlgorithms__InsertionSorting__

#include "Algorithm.h"

class InsertionSorting : public Algorithm {
  public :
    InsertionSorting(int size);
    virtual const char* getName() const override;
    virtual void init(int size) override;
    virtual void nextStep(Data& data) override;
  
  private :
    static const char* name;
};

#endif /* defined(__SortingAlgorithms__InsertionSorting__) */
