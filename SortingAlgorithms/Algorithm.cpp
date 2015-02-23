//
//  Algorithm.cpp
//  SortingAlgorithms
//
//  Created by 刘睿 on 22/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#include "Algorithm.h"

Algorithm::Algorithm() : terminated(false) {
  
}

Algorithm::~Algorithm() {
  
}

bool Algorithm::isTerminated() const {
  return terminated;
}

int Algorithm::getIndicatorPos() const {
  return rmJ;
}
