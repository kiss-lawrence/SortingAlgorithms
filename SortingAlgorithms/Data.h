//
//  Data.h
//  SortingAlgorithms
//
//  Created by 刘睿 on 22/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#ifndef __SortingAlgorithms__Data__
#define __SortingAlgorithms__Data__

#include <SFML/Graphics.hpp>
#include <vector>
class Algorithm;

const float COLUMN_WIDTH = 10.0f;
const float GAP_WIDTH = 5.0f;

const float BASE_POS = 550.0f;
const float DIAGRAM_HEIGHT = 400.0f;

const float INDICATOR_POS = 553.0f;
const float INDICATOR_HEIGHT = 3.0f;


extern const float DEFAULT_WINDOW_WIDTH;
extern const float DEFAULT_WINDOW_HEIGHT;

class DataUnit {
  public :
    DataUnit(int num, int maxNum);
  
  private :
    sf::RectangleShape rect;
    bool isDetermined;
    int number;

    void updateColor();
    void determine();
  
  friend class Data;
};

class Data {
  public :
    Data(int num, Algorithm* algo);
    ~Data();
    void init(int num);
    void setAlgorithm(Algorithm* algo);
    void randomize();
    void swap(int i, int j);
    void display(sf::RenderWindow& window) const;
    int getValue(int i) const;
    int getSize() const;
    void determine(int i);
    void determineAll();
    void update();
  
  private :
    Algorithm* algo;
    std::vector<DataUnit*> arr;
    sf::RectangleShape indicator;
    void updatePosition(int i);
    float getX(int i);
};

#endif /* defined(__SortingAlgorithms__Data__) */
