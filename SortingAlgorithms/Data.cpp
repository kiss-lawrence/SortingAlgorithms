//
//  Data.cpp
//  SortingAlgorithms
//
//  Created by 刘睿 on 22/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#include "Data.h"
#include "Algorithm.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

DataUnit::DataUnit(int num, int maxNum) : isDetermined(false), number(num), rect() {
  float w = COLUMN_WIDTH, h = (float)num / (float)maxNum * DIAGRAM_HEIGHT;
  rect.setSize(sf::Vector2f(w, h));
  updateColor();
}

void DataUnit::updateColor() {
  if (isDetermined) {
    rect.setFillColor(sf::Color::Black);
  } else {
    rect.setFillColor(sf::Color(211, 211, 211));
  }
}

void DataUnit::determine() {
  isDetermined = true;
  updateColor();
}

Data::Data(int num, Algorithm* algo) : indicator(sf::Vector2f(COLUMN_WIDTH, INDICATOR_HEIGHT)) {
  init(num);
  setAlgorithm(algo);
  indicator.setFillColor(sf::Color::Red);
  indicator.setPosition(getX(0), INDICATOR_POS);
  srand(time(nullptr));
}

void Data::setAlgorithm(Algorithm* algo) {
  this->algo = algo;
}

void Data::init(int num) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i]) {
      delete arr[i];
    }
  }
  arr.clear();
  for (int i = 1; i <= num; i++) {
    arr.push_back(new DataUnit(i, num));
  }
  randomize();
  indicator.setPosition(getX(0), INDICATOR_POS);
}

void Data::randomize() {
  for (int i = 0; i < 200; i++) {
    int a = rand() % arr.size();
    int b = rand() % arr.size();
    DataUnit* tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
  }
  for (int i = 0; i < arr.size(); i++) {
    updatePosition(i);
  }
}

void Data::swap(int i, int j) {
  DataUnit* tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
  updatePosition(i);
  updatePosition(j);
}

void Data::updatePosition(int i) {
  float w = arr[i]->rect.getSize().x, h = arr[i]->rect.getSize().y;
  float x = getX(i), y = BASE_POS - h;
  arr[i]->rect.setPosition(x, y);
}

float Data::getX(int i) {
  float startx = (DEFAULT_WINDOW_WIDTH - arr.size() * COLUMN_WIDTH - (arr.size() - 1) * GAP_WIDTH) / 2.0f;
  return startx + i * (COLUMN_WIDTH + GAP_WIDTH);
}

void Data::determine(int i) {
  arr[i]->determine();
}

void Data::determineAll() {
  for (int i = 0; i < arr.size(); i++) {
    arr[i]->determine();
  }
}

void Data::display(sf::RenderWindow& window) const {
  for (int i = 0; i < arr.size(); i++) {
    window.draw(arr[i]->rect);
  }
  window.draw(indicator);
}

int Data::getValue(int i) const {
  return arr[i]->number;
}

int Data::getSize() const {
  return arr.size();
}

void Data::update() {
  algo->nextStep(*this);
  indicator.setPosition(getX(algo->getIndicatorPos()), INDICATOR_POS);
}

Data::~Data() {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i]) {
      delete arr[i];
    }
  }
}


















