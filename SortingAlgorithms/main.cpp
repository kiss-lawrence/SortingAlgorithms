//
//  main.cpp
//  SortingAlgorithms
//
//  Created by 刘睿 on 22/02/2015.
//  Copyright (c) 2015 none. All rights reserved.
//

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Algorithm.h"
#include "SelectionSorting.h"
#include "BubbleSorting.h"
#include "InsertionSorting.h"
#include "ResourcePath.hpp"

const float DEFAULT_WINDOW_WIDTH = 800.0f;
const float DEFAULT_WINDOW_HEIGHT = 600.0f;

const sf::Time TIME_STEP[] = {sf::seconds(0.001f), sf::seconds(0.005f), sf::seconds(0.01f), sf::seconds(0.05f), sf::seconds(0.1f)};
const int TIME_STEP_NUM = 5;

const int MIN_DATA_NUM = 10;
const int MAX_DATA_NUM = 50;

const int ALGO_NUM = 3;

const sf::String getGuiString(Algorithm* algo, int dataNum, int speedLevel) {
  sf::String str;
  str += algo->getName();
  str += "\nData Number = " + std::to_string(dataNum);
  str += "\nSpeed Level = " + std::to_string(TIME_STEP_NUM - speedLevel);
  str += "\n\nUse Up and Down to control speed. Use Left and Right to control data number. Use Space to pause or replay. Use N to change algorithm.";
  return str;
}

int main(int argc, char** argv) {
  sf::RenderWindow window(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "Sorting Algorithms Visualizer");
  
  bool isStopping = false;
  bool isPlaying = true;
  int speedLevel = 0;
  int dataNum = 50;

  Algorithm* algo = new SelectionSorting(dataNum);
  int algoID = 0;
  Data data(dataNum, algo);
  
  sf::Font font;
  font.loadFromFile(resPath() + "Arial.ttf");
  sf::Text gui;
  gui.setFont(font);
  gui.setCharacterSize(12);
  gui.setColor(sf::Color::Black);
  gui.move(5.0f, 0.0f);
  sf::String guiText = getGuiString(algo, dataNum, speedLevel);
  gui.setString(guiText);
  
  sf::Clock clock;
  sf::Time acc = sf::Time::Zero;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      
      //handle input
      if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Up :
            if (speedLevel) {
              speedLevel--;
            }
            break;
          case sf::Keyboard::Down :
            if (speedLevel < TIME_STEP_NUM - 1) {
              speedLevel++;
            }
            break;
          case sf::Keyboard::Left :
            if (isStopping && dataNum > MIN_DATA_NUM) {
              dataNum -= 10;
              data.init(dataNum);
              algo->init(dataNum);
            }
            break;
          case sf::Keyboard::Right :
            if (isStopping && dataNum < MAX_DATA_NUM) {
              dataNum += 10;
              data.init(dataNum);
              algo->init(dataNum);
            }
            break;
          case sf::Keyboard::Space :
            if (isStopping && !isPlaying) {
              isStopping = false;
              isPlaying = true;
              if (algo->isTerminated()) {
                data.init(dataNum);
                algo->init(dataNum);
              }
            } else if (!isStopping && isPlaying) {
              isPlaying = false;
            } else if (!isStopping && !isPlaying) {
              isPlaying = true;
            }
            break;
          case sf::Keyboard::N :
            if (isStopping) {
              algoID = (algoID + 1) % ALGO_NUM;
              delete algo;
              switch (algoID) {
                case 0 :
                  algo = new SelectionSorting(dataNum);
                  break;
                case 1 :
                  algo = new BubbleSorting(dataNum);
                  break;
                case 2 :
                  algo = new InsertionSorting(dataNum);
                  break;
                default:
                  break;
              }
              data.setAlgorithm(algo);
              data.init(dataNum);
            }
            break;
          default :
            //do nothing
            break;
        }
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::N) {
          guiText = getGuiString(algo, dataNum, speedLevel);
          gui.setString(guiText);
        }
      }
    }
      
    //update
    if (!isStopping && isPlaying) {
      acc += clock.restart();
      if (acc > TIME_STEP[speedLevel]) {
        acc = sf::Time::Zero;
        if (!algo->isTerminated()) {
          data.update();
        } else {
          isStopping = true;
          isPlaying = false;
        }
      }
    }
    
    //render
    window.clear(sf::Color::White);
    data.display(window);
    window.draw(gui);
    window.display();
  }
  
  delete algo;
}













