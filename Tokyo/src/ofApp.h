#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    
        static const int N = 256;
        static const int n = 300;
        float spectrum[ N ];
        float Rad = 500;
        float Vel = 0.1;
        float time0 = 0;
        float tx[n], ty[n];
    
    
        ofPoint p[n];
        ofSoundPlayer sound;
        ofImage tokyo;
    
        int bandRad = 2;
        int bandVel = 100;
    
};
