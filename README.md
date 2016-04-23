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
			
			
____

5.全屏

	if( key == ' '){
	        ofToggleFullscreen();
	    }
	    
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
	
	


16.Shader的Uniform语法:[参照这里](http://bgepython.tutorialsforblender3d.com/Shader)

	


17.解决Bug: redefinition 'ofxCvHaarFinder'

	去掉src里面的ofxCvHaarFinder.h文件，只加‘ofxOpenCv’ 这个插件，然后重新生成项目
	
	
	
18.关于Bug：ofxAutoControlPanel.h 文件找不到

	暂时解决，首先把ofxAutoControlPanel.h这个文件从src里面删除，重新加
	
	载“ofxControlPanel”插件；相应的把.h里面的声明换成ofxControlPanel的声明；
	
	把Setup里面的Panel.setup();去掉。



19.关于0.9.0API变更

	accumulation.reloadTexture();替换成accumulation.update();
	
	不要跟随IDE的自动纠错改成unloadTexture();
	
	
	
20.经济学人  三月 2015

#书的未来
##从草纸到像素
###书籍的撰写、出版和销售方式的数字化变革才刚刚开始
###死亡语言未成真
###新型作者遇到新型读者
###标准每况愈下，日子越来越好
###思想从过去流传至未来
#####书的进化将在线下和线上同时发生，而对书的界定也将拓展。人们还会继续认为书是文化得以从过去想未来流传的根本渠道。他们可能不会在像西塞罗写《义务论》那样，尝试用奴隶抄录的手卷向子女传递智慧，甚至也不用印刷物。甚至，可能伏尔泰说的没错，他们中再没有人能写出比两千年前的这本书更有智慧的东西。但那不会是因为不够努力或没有机会，也不会是因为缺少未来的读者要在他们留下的书籍中寻求智慧。


21.others

#强盗大亨和硅谷苏丹（美国白手起家的富人）
###今天的科技界亿万富翁和当年的一代资本巨头有诸多共性，可能多到对自身不利

#改写规则
###商业模式与法律相抵牾的创新公司多得惊人

#风险与回报
###数据和科技开始颠覆保险业

#超连接世界
###阿联酋航空、阿提哈德航空、卡塔尔航空--加上最近崛起的土耳其航空，它们的快速发展看来会持续

#乔布斯2.0
###一本新书试图重塑全球最著名发明家之一

#吞并或被吞并
###合并大潮在望，美国大型互联网企业看来将分为猎人和猎物

#玛格丽特与熊(俄罗斯天然气工业股份公司)
### 欧盟反垄断专员向俄罗斯天然气工业股份公司开刀，带来欧洲政策及燃气业大变革

#晨曦中的红色天空
###有关抢掠和纠正的励志传奇

#在商言商
###公司何所为，争论复争论

#快要撞车
###对汽车制造商而言，来自中国的滚滚利润不会持续

#王朝（家族势力）
###政商界的家族势力可能让精英制度的信徒感到担忧

#寄希望于去银行化学
###宣布关闭通用电气的金融部门，杰夫·伊梅尔特在拯救公司的战斗中只赢了一半

#高风险业务（商业与银行混业）
###给首席执行官的信息：不要试图把公司变成高盛

#撒哈拉以南争斗正酣（外资在非洲）
###私募股权掀非洲投资热，当地企业需啊各路资本，多多益善

#几内亚“喊犯规”（采矿与腐败）
###非洲最大的铁矿石开采项目受纷争困扰，工程一再延误

#颠覆者被颠覆
###一个专门发现潜在反叛者的行业自身也正面对着一些搅局者

#工资只降不升，怎么办？（低工资的经济学分析）
### 即便经济回暖，富裕国家劳工薪酬仍旧冰封。政客苦寻对策，却可能弄巧成拙

#厌倦了膨胀的美联储（美国的金融管制）
### 前央行行长把矛头对准了自己人

#休克疗法
###州政府金融监管官员惹争议

#下一件大事
### 或者不是？

#积少成多（支付）
###如果你有钱--甚至即使你没钱--你现在都可以用各种方式买单

#很酷（众筹）
###被银行拒绝的小企业可以从这里贷款

#古吉拉特邦模式（印度经济）
###莫迪经济学如何在印度宜商之邦锻造成型

#取之于民，用之于民（P2P借贷）
###但金融民主化能扛过经济衰退期吗？

#明抢暗剑（国际银行业）
###金融科技会让银行变得更弱势，盈利减少。但它不太可能让银行完全消失

#“欠条”诱惑
###希腊或许可以靠打欠条缓解现金短缺，但这只能解燃眉之急

#交易手段
###货币体系一直由国家推行

#危机之前，未雨绸缪
###监管希望让银行倒闭更容易，此举决定银行生存环境

#冻结（市场流动性）
###监管令银行更安全，但令市场风险更高？

#对手众多（中国在非洲）
###中国在非洲影响已很大，但现在遭遇抵触情绪

#农场门口的野蛮人（投资农业）
###吃苦耐劳的投资者正在寻求生财之道

#在市场上播种
###一家非营利性机构证明农村合作社能成为安全且盈利的借款人

#手机星球
###智能手机无处不在，叫人上瘾，变革世界

#人工智能的黎明
###强大的电脑将重塑人类未来。如何确保希望大于危险

#需要一场绿色革命
###企业如何能帮助解决亚洲的环境问题

#硅谷一尝食滋味
###科技创业公司进军食品行业，用植物可持续制造肉奶制品
 


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
  
  
  GUI:
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

5.Shadertoy语法

	ST：vec3 col = texture2D(iChannel0, vec2(uv.x, -uv.y * prop)).xyz;

	OF：vec3 col = texture2D(u_tex0, vec2(uv.x, uv.y * prop)).xyz;
	
	要预先声明：uniform sampler2D u_tex0;
		      uniform vec2 u_tex0Resolution;
		               
		               
		               
	m = center
	
	p = st
	
	fbm = random 
	
	float bind 直接不用	
	
	
____	


6.OSC不是为这种不间断、大量原始数据传输而设计的，不是慢的问题，而是丢数据。

7.UDP:User Datagram Protocol，缩写为UDP，又称使用者资料包协定，是一个简单的面向数据报的传输层协议(轻量级 TCP)

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
	
	


####ofSetVerticalSync( true );
____

####ofdrawBitmapstringHighlight("title", x, y);  里面的Highlight是黑底白字效果。
___

####ofPushMatrix();
####ofTranslate(350, 125);
####ofPopMatrix();

####平移坐标时，相关的for loop 要放到他们中间

####megenta洋红色

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
	
	





 



	  
	  
	