//
//  BubbleSorting.cpp
//  SortingAlgorithms
//
//  Created by 刘睿 on 23/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#include "BubbleSorting.h"
#include "Data.h"

const char* BubbleSorting::name = "Bubble Sorting";

BubbleSorting::BubbleSorting(int size) : Algorithm() {
  init(size);
}

const char* BubbleSorting::getName() const {
  return BubbleSorting::name;
}

void BubbleSorting::init(int size) {
  rmI = 0;
  rmJ = size - 1;
  swapped = false;
  terminated = false;
}

void BubbleSorting::nextStep(Data& data) {
  int n = data.getSize();
  if (rmJ <= rmI) {
    if (!swapped) {
      data.determineAll();
      terminated = true;
      rmJ = n - 1;
      return;
    }
    data.determine(rmI);
    rmI++;
    rmJ = n - 1;
    swapped = false;
    return;
  }
  if (data.getValue(rmJ) < data.getValue(rmJ - 1)) {
    data.swap(rmJ, rmJ - 1);
    swapped = true;
  }
  rmJ--;
}