# Knight-Bus

###The Monster Book of Monsters



1.位图的四种写法

    // 原始方法（没有对齐）
    ofSetColor ( 255 , 255 , 255 ) ;
    
    string output = "Z :: Springs on/off : " + ofToString(springEnabled) +
    
    "\n J :: CursorMode repel/attract " + ofToString( cursorMode ) +
    
    "\n # of particles : " + ofToString( numParticles ) +
    
    " \n fps:" +ofToString( ofGetFrameRate() ) ;
    
    ofDrawBitmapString(output ,20,666);
 
    
    
    // 笨笨的方法（是对齐哒）
    ofDrawBitmapString("button Z :: Springs on/off__" +   ofToString(springEnabled),10,60);
    ofDrawBitmapString("button J :: CursorMode repel/attract__" + ofToString(cursorMode), 10, 80);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()),10,20);
    ofDrawBitmapString("Particles: " + ofToString(numParticles), 10, 40);
    
    
    // 整洁对齐的方法
    stringstream rules;
    rules << "Z :: Springs on/off :" << ofToString(springEnabled) <<endl
    << "J :: CursorMode repel/attract :" << ofToString(cursorMode) << endl
    << "particles :"<< ofToString(ofGetFrameRate())<<endl
    << "fps: "  << ofToString(ofGetFrameRate())<<endl;
    ofDrawBitmapString(rules.str(), 10, 30)
    
    
    // Debug后操作提示
    ofSetColor(255, 0, 0);
    string debug = "Drag your mouse around.";
    ofDrawBitmapString(debug, 20, 20);
    
    
_____

2.帧数的获取

	Regular:
	
	ofDrawBitmapString (ofToString(ofGetFrameRate()), ofPoint (20, 20));

	
	Cool:
	
	ofSetWindowTitle(ofToString( ofGetFrameRate()));或者可以加上你想要的信息
	
	ofSetWindowTitle("FPS:" + ofToString(ofGetFrameRate()));
	
	
____

	
3.插件“ofxControlPanel”和“ofxTrueTypeFontUC”
	
	大部分有“ofxControlPanel”的插件要把它整个包放到 src 文件夹里面，不要放入Addons.要注意不能同时有两个相同插件在一个项目里面，这样会造成重复编译；编译，这样会报“linker command failed with exit code 1 (use -vto see invocation)”这个错误。
	
	“ofxTrueTypeFontUC”这个插件到0.9.0的版本由于新版本Freetype的结构发生变化，所以include里面不要包含任何子位置
	
	＃include "freetype2/freetype/freetype.h"一律改成  #include "freetype.h"
	就可以暂时解决编译问题，其实在其他插件出问题时也可以用这个方法。
	
	
4.关于Gui的隐藏

	在Draw里面画
	if( bHide ){
	
			gui.draw();
		}
		
	然后在keyPressed里
	
	if( key == 'h' ){
	
			bHide = !bHide;
			
		}
			
			
____

5.全屏

	if( key == ' '){
	        ofToggleFullscreen();
	    }
	    
或者在setup里面

ofSetFullscreen();	    
____
	    
	    
6.在老版本（testApp）里面发现插件“ofxControlPanel”和“ofxBox2d”有时候都需要加到src文件夹里面后，项目才能被编译。

____

7.动画开关

	ofApp.h:     bool    bDraw2D;
	Setup:       bDraw2D = true;
	keyPressed:  bDraw2D = !bDraw2D;(任意键控制动画)
	
____

8.储存项目照片：

	if ( key == ' ' ) {		//Grab the screen image to file
		ofImage image;	
		image.grabScreen( 0, 0, ofGetWidth(), ofGetHeight() );	

		//Select random file name
		int n = ofRandom( 0, 1000 );
		string fileName = "screen" + ofToString( n ) + ".png";

		image.save( fileName );		
		
____	
	
9.关于“KeyPressed”下面的按键语法

    if( key == 'f') ofToggleFullscreen(); // 完全屏幕
    if( key == 'c') CGDisplayHideCursor(kCGDirectMainDisplay);  // 隐藏光标
    if( key == 'v')CGDisplayShowCursor(kCGDirectMainDisplay);  // 显示光标
    或者，也可以这样
    
        switch(key)
    {
        case OF_KEY_LEFT :
            ofSetFullscreen(true);
            break;
        case OF_KEY_RIGHT :
            ofSetFullscreen(false);
            break;
        case OF_KEY_DOWN :
            ofShowCursor();
            break;
        case OF_KEY_UP :
            ofHideCursor();
            break;
        default:
            break;
    }
    
    or........
    
        switch (key) {
        case 'b':
            ofShowCursor();
            break;
            
        default:'m';
            ofHideCursor();
            break;
    }
    ps:去掉'm';就是任意键控制（隐藏光标）

     
    
____
   
10.关于Bug：no member named 'idleMovie' in 'ofVideoplayer'的问题,[参考](http://stackoverflow.com/questions/26310285/no-member-named-idlemovie-in-ofvideoplayer)

	  格式问题：vidPlayer.idleMovie(); 用 vidPlayer.update();来代替
	  
	  
	  
____

11.解决Bug “use of undeclared identifier glutSolidSphere”（使用未声明的标识符）
	
	首先Google报错提示，第一个是官网论坛，看了下没帮助（不过还是有收获）
	第二个是Stack Overflow   叫我加上  #include <glut.h>  解决！
	链接：http://stackoverflow.com/questions/5365441/opengl-glut-compiling-issues
	而在文件包里搜素“glut.h”有提示（一个.h文件里有Readme的东西）
	
	
____
12.调取摄像头

	ofVideoGrabber cam;
	cam.initGrabber(1000,2000); // 像素取样
	cam.update();
	cam.draw(0, 0, 550, 550); 
	
	
	
13.声音取样

	(参考YINAN Project-Noise Basic)
	
	还有ofVideoGrabber cam 和 ofCamer cam 的区别
	

14.解决Bug “Thread 1: EXC_BAD_ACCESS(code=1,address= 0x 20)”

	把Push_back 从鼠标点击转移到鼠标移动（所以和触发事件相关？）这是第一次解决这类无解Bug（hmwk）
	

	
15.Project introduce

	Stickie is a mobile device centric collaborative system. The project utilizes physical space as a valuable medium for people to digitally annotate their environment. Stickie incorporates the smartphone as an extension of the human body to spatially interact with visual content.
	
	stickie是以移动设备为中心的协同系统。这个项目作为一个有价值的媒介；利用了数字化的方式标注了人们所处环境。Stickie结合智能手机;让人们的可视内容交互延伸到空间。
	
	
____

16.Shader的Uniform语法参照这里:

http://bgepython.tutorialsforblender3d.com/Shader

	
____

17.解决Bug: redefinition 'ofxCvHaarFinder'

	去掉src里面的ofxCvHaarFinder.h文件，只加‘ofxOpenCv’ 这个插件，然后重新生成项目
	
	
	
18.关于Bug：ofxAutoControlPanel.h 文件找不到

	暂时解决，首先把ofxAutoControlPanel.h这个文件从src里面删除，重新加
	
	载“ofxControlPanel”插件；相应的把.h里面的声明换成ofxControlPanel的声明；
	
	把Setup里面的Panel.setup();去掉。



19.关于0.9.0API变更

	accumulation.reloadTexture();替换成accumulation.update();
	
	不要跟随IDE的自动纠错改成unloadTexture();
	
	
	

 


____

#Quibbler
###1.关于运行窗口和语法
.h文件移除后，即使编译成功Debug窗口也跳不出来

get.pixel 变成 get.Data
使用中文字体插件后，载入语法依旧是Font.loadFont(),因为插件还在0.8.4

###2.关于歌曲断点播发

键盘事件：( if & else 语句在这里不适合)

    1.在setup里面
	 bgmusic.setPaused(true);
	 

    2.KeyPressed里面
    switch ( key ) {
        case 'p':
            bgmusic.setPaused(false);
            break;
            
        default:
            bgmusic.setPaused(true);
            break;
    }

鼠标事件：

	1.在.h里面声明
	ofPoint mousePos, pastMousePos;
	
	2.在setup里面
	bgmusic.setPaused(true);
	
	3.在update里面
	if(mousePos.distance(pastMousePos) > 0){
    
        bgmusic.setPaused(false);
    }
    else{
        bgmusic.setPaused(true);
    }

    pastMousePos.set(mouseX, mouseY);
    
    4.在mouseMove里面
    mousePos.set(x,y);
____
    
##Buckbeak    
    
 1.
setup

ofSetbackgroundAuto(false);

	int numCircles = 100;
	
	for(int i = 0; i < numCicles; i++){
	
	    xOffset.push_back(ofRandom(-500, 500));
	    yOffset.push_back(ofRandom(-300, 300));
	    
	    }
	    
	 int numCircle = 10
	 
	 for(int i = 0; i < numCircle; i++){
	 ofPoint p;
	 ofPOint v;
	 float r = ofRandom(10,25);
	 p.set(ofGetWidth()/2, ofGetHeight()/2);
	 v.set(ofRandomuf()*4, ofRandomuf()*4);
	 
	 
	 pos.push_back(p);
	 pos.push_back(v);
	 radius.push_back(r);
	 


____

2.
update

	circle.r = float(mouseX) / ofGetwidth() * 255;
	ciircleColor.r = ofMap(mouseX, 0, ofGetwidth(), 0, 255);
	
	circleColor.r = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
	
	pos = pos + vel;

____

3.
draw

	ofFill();
	
	ofsetColor(barColor);
	
	ofDrawrectangle(0, 374, ofGetWidth(), 20);

	float yPos = ofGetHeight()/5;
	
	for(int i = 0; i < circleResolutions.size(); i++){
	
	  ofSetCircleResolution(circleResolutions[i]);
	  float x = (i+1) * radius * 3.0;
	  float y = yPos;

____

4.
KeyPressed

	if(key == 'f'){
	  myVideo.setFrame()0;
	  }
	  
	  if(key == OF_KEY_LEFT){
	     int prevFrame = myVideo.getCurrentFrame() - 1;
	     myVideo.setFrame(prevFrame);
	  }
	  
	  
	  if(key == OF_KEY_RIGHT){
	  
	 int nextFrame = myVideo.getCurrentFrame() + 1;
	 myVideo.setFrame(prevFrame);
	  
	  
	  }   
  
  
  5.GUI
  
	  setup
	  radius.set("radius", 15.0, 10.0, 100.0);
	  circleColor.set("circleColor",
	                   ofColor(150, 23, 41),
	                   ofColor(0, 0, 0),
	                   ofColor(255, 255, 255, 255));
	                   
	   circleResolution = 8;
	   
	   myPanel.setup();
	   myPanel.add(radiius);
	   myPanel.add(circleColor);
	   
	   
	   update
	   circleResolution = ofMap(mouseX, 0, ofGetWidth(), 3, 8);
   
   
____  

6.Shadertoy语法

	ST：vec3 col = texture2D(iChannel0, vec2(uv.x, -uv.y * prop)).xyz;

	OF：vec3 col = texture2D(u_tex0, vec2(uv.x, uv.y * prop)).xyz;
	
	要预先声明：uniform sampler2D u_tex0;
		      uniform vec2 u_tex0Resolution;
		               
		               
		               
	m = center
	
	p = st
	
	fbm = random 
	
	float bind 直接不用	
	
	
____	


7.OSC不是为这种不间断、大量原始数据传输而设计的，不是慢的问题，而是丢数据。

8.UDP:User Datagram Protocol，缩写为UDP，又称使用者资料包协定，是一个简单的面向数据报的传输层协议(轻量级 TCP)

____
	
###Debug：称为 调试版本，它包含调试信息，且不做任何优化，便于程序员调试.

###Release：称为 发布版本，它往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户能很好地使用.

____
###crookshanks

	void ofBackground(int r, int g, int b, int a){
	
	ofGetCurrentRenderer()->background(r,g,b,a);
	}
这是ofBackGround的定义函数


->  的左边是指针，右边是普通变量。

"->"指针操作符


____

手绘的哲学：在人综合意志的统摄下，用非自动机械的方法去结构形象的意愿和能力。

____

ofVideoGrabber cam;中

cam.setDeviceID(1);是指外接摄像头

cam.initGrabber(640,480);自带摄像头  //等于cam.setup()  

ofVideoGrabber cam; 调用摄像头的都是：cam.setup()


____

Addon:

ofxTween弃用，官方的ofxEasing  addon替代

语法过时：

”interpolated“
”ofVec3f interp = thisPoint.interpolated(nextPoint, ofMap(j, 0, steps-1, 0.0, 1.0, true));“

Bug:

“linker command failed with exit code 1 (use -v to see invocation)“

解决：还是两个相同的项目一起编译引起的ofxFX里面有ofxFluid 一样的文件（src）

一般来讲ofxFX和ofxFliud两个插件不能同时使用，因为后者就是前者分离出来的一个例子，分出液态那一部分功能


____

    if(rect.y+rect.getHeight() >= ofGetHeight() && speed.y > 0) {
        speed.y *= -1;
        
       里面rect.getHeight()等价于rect.height
       
____


###workshop
Data story studio

###旋转
	model.setRotation(0, 0 + ofGetElapsedTimef() * 100, 0, 1, 0);
	
	//正面旋转--沿着Y轴旋转


###背景设置

	ofBackgroundGradient( ofColor( 255 ), ofColor( 0 ) );
	
	//背景渐变
	
	
____

####ofdrawBitmapstringHighlight("title", x, y);  里面的Highlight是黑底白字效果。
___

	ofSetVerticalSync( true );
	ofPushMatrix();
	ofTranslate(350, 125);
	ofPopMatrix();
	
	平移坐标时，相关的for loop 要放到他们中间


____

###OF语法
	
	
	int main( ){
	    ofGLWindowSettings settings;
	    settings.width = PROJECTOR_WIDTH;
	    settings.height = PROJECTOR_HEIGHT;
	    settings.setGLVersion(3, 2);
	    settings.windowMode = OF_FULLSCREEN;
	    ofCreateWindow(settings);
	
	    ofRunApp(new ofApp());
	}
in 0.9.1, just write " ofSetFullscreen( true ) "  in setup.
____
	
###在类里面重新定义数据

	#define UINT unsigned int
	
	#define UCHAR unsigned char
	
	
14个0是7个字节，一个零是半个字节。0x是十六进制的类型

	LPVIOD  void*
	
	UCHAR   unsigned char
	
	UINT    unsigned int
	
	BYTE    char
	
	USHORT  unsigned short
	
	BOOL    bool
	
	FALSE   false



👻👻
	
	





 



	  
	  
	