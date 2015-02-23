//
//  Algorithm.h
//  SortingAlgorithms
//
//  Created by 刘睿 on 22/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#ifndef __SortingAlgorithms__Algorithm__
#define __SortingAlgorithms__Algorithm__

#include <SFML/Graphics.hpp>
class Data;

class Algorithm {
  public :
    Algorithm();
    virtual ~Algorithm();
    virtual void init(int size) = 0;
    virtual void nextStep(Data& data) = 0;
    virtual const char* getName() const = 0;
    bool isTerminated() const;
    int getIndicatorPos() const;
  
  protected :
    int rmI, rmJ;
    bool terminated;
};

#endif /* defined(__SortingAlgorithms__Algorithm__) */
