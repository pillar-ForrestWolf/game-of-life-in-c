#!/bin/sh
cd build;
make && test/game-of-life-test;
cd ..;