//
//  SelectionSorting.cpp
//  SortingAlgorithms
//
//  Created by 刘睿 on 22/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#include "SelectionSorting.h"
#include "Data.h"

const char* SelectionSorting::name = "Selection Sorting";

SelectionSorting::SelectionSorting(int size) : Algorithm() {
  init(size);
}

const char* SelectionSorting::getName() const {
  return SelectionSorting::name;
}

void SelectionSorting::init(int size) {
  rmI = 0;
  rmJ = rmI;
  minI = rmI;
  terminated = false;
}

void SelectionSorting::nextStep(Data& data) {
  int n = data.getSize();
  rmJ++;
  if (rmJ >= n) {
    if (rmI + 1 >= n) {
      data.determine(rmI);
      terminated = true;
      rmJ = n - 1;
      return;
    }
    data.swap(rmI, minI);
    data.determine(rmI);
    rmI++;
    rmJ = rmI;
    minI = rmI;
    return;
  }
  if (data.getValue(rmJ) < data.getValue(minI)) {
    minI = rmJ;
  }
}