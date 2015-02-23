//
//  InsertionSorting.cpp
//  SortingAlgorithms
//
//  Created by 刘睿 on 23/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#include "InsertionSorting.h"
#include "Data.h"

const char* InsertionSorting::name = "Insertion Sorting";

InsertionSorting::InsertionSorting(int size) : Algorithm() {
  init(size);
}

const char* InsertionSorting::getName() const {
  return InsertionSorting::name;
}

void InsertionSorting::init(int size) {
  rmI = 1;
  rmJ = rmI;
  terminated = false;
}

void InsertionSorting::nextStep(Data& data) {
  int n = data.getSize();
  if (rmI == 1) {
    data.determine(0);
  }
  if (rmJ <= 0 || data.getValue(rmJ - 1) < data.getValue(rmJ)) {
    if (rmI + 1 >= n) {
      data.determine(rmJ);
      terminated = true;
      rmJ = n - 1;
      return;
    }
    data.determine(rmJ);
    rmI++;
    rmJ = rmI;
    return;
  }
  data.swap(rmJ, rmJ - 1);
  rmJ--;
}