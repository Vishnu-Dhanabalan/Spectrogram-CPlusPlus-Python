////////////////////////////////////////////////////
//  Project: Spectrogram in C++ and Python.
//  File: main.cpp
//  Version: 1.0
//
//  Author: Vishnu Dhanabalan.
//  Contact: vishnudhanabalan@outlook.com
////////////////////////////////////////////////////

/*
 main.cpp -- main file for spectrogram project.
 
 Info:
 Uses spectrogram class for creating spectrogram for audio files.
 
 Version history:
 v1.0  -- Created main.cpp with comments.
 */

#include <iostream>

#include "Spectrogram.h"

using namespace std;

int main(){
    // Curr path should end with '/'
    string currPath = "/Users/Vishnu/Google Drive/programming tutorials/c++ practice/XCode projects/Spec_CPP_Python_Hybrid/Spec_CPP_Python_Hybrid/";
    
    // audio file name must contain file extension.
    string audioFilename = "dtmf.wav";
    
    // window parameters
    unsigned int windowSize = 1024;
    unsigned int hopSize = windowSize/4;
    string windowType = "hann";
    unsigned int fftSize = windowSize * 2;
    
    // Create spectrogram.
    spectrogram mySpec;
    mySpec.setupSource(currPath, audioFilename);
    mySpec.setupSpectrogram(windowSize, hopSize, windowType, fftSize);
    mySpec.prepareFrames();
    mySpec.windowFrames();
    mySpec.doSTFT();
    mySpec.print();
    mySpec.plot();
    
    return 0;
}