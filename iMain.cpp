/*************************************************
*Author >>> Mostafa Khalid Raihan                *
*Dept >>> CSE                                    *
*Section >>> A-1                                 *
*ID >>> 1105009                                  *
*Project Name >>> BOW & ARROW (GAME)             *
*                                                *
*                                                *
*Address of success >>> try,try,try@try.com      *
*************************************************/

/*************************************************
           ~~~~~INCLUDED HEADER FILES ~~~~~
*************************************************/
# include <vector>
# include <iostream>
# include <algorithm>
# include "iGraphics.h"
# include <math.h>
# include <stdlib.h>
# include <string>
# include <time.h>
using namespace std;


/*************************************************
           ~~~~~~FUNCTION PROTOTYPES~~~~~~
**************************************************/
void file(void );
void reset();
void balloon_lace(int , int );
void i_draw_arrow();
void arrow_move();
void i_draw_bow();
int check_screen();
void i_draw_arrow_2();
void sDelay(int );
void i_draw_balloons();
void create_balloon(int ,int ,int ,int ,int );
void i_draw_balloons();
void balloon_move1();
void balloon_move2();
void balloon_move3();
void balloon_move4();
void balloon_move5();
bool check(int , int );
void _hscore();


/***************************************************
                   ~~~~VARIABLES~~~~
****************************************************/

int mode ;
int Score;
int fake_target_e=0;
int fake_target_m=0;
int fake_target_h=0;
int target = 0;
int balloon_y[5];
int balloon_x[5];
int balloon = 0;
int arrow = 0;
int major = 25,minor = 40,seg = 100;
int background = 1;//background removing variable
int flag=1; //flag to determine wheather arrow is in toch with the boundary or not
int bound=1; // another flag to check wheather or not the arrow is bound with the bow
int bow_ml_up_x=70,bow_ml_up_y=500,bow_ml_down_x=70,bow_ml_down_y=480;//bow middle straight line parameter
int tilt_x_down=5,tilt_y_down=25;//tilting parameter
int rect_low_x=bow_ml_up_x-40,rect_low_y=bow_ml_up_y-10,width=70,height=2; //rectangle needed for arrow parameter
int p=30,q=490;
char ara[20],ara1[20],ara2[20],ara3[20],ara4[20];
int start = 0, end = 0;
int pp, qq;
double ma = major / 2.0, mi = minor / 2.0;
int score[7] = {0};
int alias_target = target;
bool result;
bool _hs = true;
vector <int> v;

/**********************************************************
                    ~~~~~~CODE~~~~~~
***********************************************************/

void iDraw()
{
  iClear();
	if(background==1)iShowBMP(0,0,"images/black.bmp");             //Main menu
	else if(background==2){//Main Game

		if(balloon == target){
			background = 6; // Score time
			result = true;
		}
		iShowBMP(0,0,"images/green.bmp");
		iSetcolor(.9,.7,.4);
		iText(850,680,"TIME : ",GLUT_BITMAP_TIMES_ROMAN_24);
		end ++;

		sprintf(ara,"%d",end-start);
		iText(930,680,ara,GLUT_BITMAP_TIMES_ROMAN_24);

		iText(850,650,"Arrow : ",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(ara1,"%d",arrow);
		iText(930,650,ara1,GLUT_BITMAP_TIMES_ROMAN_24);


		iSetcolor(.9,.7,.4);
		iText(350,680,"You need to shoot",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(ara3,"%d",target);
		iText(550,680,ara3,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(580,680,"balloons.... GO!!!!",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(780,620,"Remaining balloons : ",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(ara4,"%d",alias_target);
		iText(990,620,ara4,GLUT_BITMAP_TIMES_ROMAN_24);

		i_draw_arrow();//standstill
		i_draw_arrow_2();//movable
		i_draw_bow();
		i_draw_balloons();
	}
	else if(background == 3){                                      //instructions
		iClear();
		iShowBMP(0,0,"images/instructions2.bmp");
	}
	else if(background == 4){                                      //high scores
		iClear();
		
		if(_hs){
			_hscore();
		}
		_hs = false;
		iShowBMP(0,0,"images/high score.bmp");

        sprintf(ara2,"%d",score[4]);
		iText(370,300,"5.",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,300,ara2,GLUT_BITMAP_TIMES_ROMAN_24);

	    sprintf(ara2,"%d",score[3]);
		iText(370,350,"4.",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,350,ara2,GLUT_BITMAP_TIMES_ROMAN_24);


        sprintf(ara2,"%d",score[2]);
        iText(370,400,"3.",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,400,ara2,GLUT_BITMAP_TIMES_ROMAN_24);


        sprintf(ara2,"%d",score[1]);
       	iText(370,450,"2.",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,450,ara2,GLUT_BITMAP_TIMES_ROMAN_24);


        sprintf(ara2,"%d",score[0]);
		iText(370,500,"1.",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,500,ara2,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(background == 5){                                  // quit
		exit(0);
	}

	else if(background == 6){                                  // score showing


		iClear();


		int END = end;
		iSetcolor(.4,.4,.4);
		iText(380,500,"CONGRATZZZZZZZZZ!!!",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetcolor(.9,.14,.17);
		iText(430,350,"YOUR SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

		char ara5[20];
		if(target == fake_target_e)Score = ((1000/END)+(100/arrow));
		else if(target == fake_target_m)Score = ((10000/END)+(1000/arrow));
		else if(target == fake_target_h)Score = ((100000/END)+(1000/arrow));
		sprintf(ara5,"%d",Score);

		//score[5] = Score;

		if(result){
			file();
			result  =false;
		}


		iText(490,320,ara5,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetcolor(.8,.5,.7);
		iText(50,100,"Try Again?",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900,100,"Quit!!",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(background == 7){                                     // game mode
		iShowBMP(0,0,"images/game mode.bmp");
	}
}


void file(){
	FILE *fp;
	int ass=34;
	long tot;
	//long byte;
	if((fp=fopen("H.txt","ab+"))!=NULL){
		putw(Score,fp);
		tot = ftell(fp);
	}
	
	//printf("%ld\n",tot);
	fclose(fp);
//FILE *f;
	/*if((fp=fopen("H.txt","rb"))!=NULL){
		fseek(fp,(tot+1)*sizeof(int),SEEK_SET);
		//printf("%ld\n",ftell(fp));
		//fscanf(fp,"%d",&ass);
		
		//printf("This is ass %d\n",ass);
		//cout << "size\n" << v.size() << endl;
		fclose(fp);
	}
	/*for(int k=0;k<v.size();k++){
		printf("\n%d\n",v[k]);
	}*/	
}


void _hscore(){
	FILE *fp;
	int i;
	v.clear();
	if((fp=fopen("H.txt","a+"))!=NULL){
		while((i=getw(fp))!=EOF){
			v.push_back(i);
		}
	}
	//sort(v.begin(),v.end());
	fclose(fp);

	sort(v.begin(),v.end());
	int kk = 0;
	int kkk = v.size();
	kkk--;
	
	while(kk < 5){
		
		score[kk++] = v[kkk--];
	}
}
void balloon_lace(int x,int y){
	iLine (x,y-minor/2,x,y-2*minor);
}
bool check(int x,int y){
	double khalid1,khalid2;
	double pp = p+(70*1.0);
	double qq = q*1.0;
	khalid1 = ((pp-(x*1.0))/(ma*1.0));
	khalid2 = ((qq-(y*1.0))/(mi*1.0));

	if((khalid1*khalid1) + (khalid2*khalid2) - 1 <= 2)return false;

	else return true ;
}

void init(){
	int raihan;
	for(int i=0;i<5;i++){
		balloon_y[i] = 0;
	}
	raihan = rand()%(rand()%100);
	balloon_x[0] = raihan + 800;
	raihan = rand()%50;
	balloon_x[1] = raihan + 700;
	raihan = rand()%50;
	balloon_x[2] = raihan + 600;
	raihan = rand()%50;
	balloon_x[3] = raihan + 900;
	raihan = rand()%50;
	balloon_x[4] = raihan + 500;
}
void i_draw_balloons(){
	if(check(balloon_x[0],balloon_y[0])){
		iSetcolor(.5,.9,.6);
		iFilledEllipse(balloon_x[0],balloon_y[0],major,minor,seg);
		balloon_lace(balloon_x[0],balloon_y[0]);
	}
	else {
		balloon++;
		alias_target--;
		balloon_x[0] = rand()%(rand()%100);
		balloon_y[0] = 0;
		balloon_x[0] += 800;
		balloon_lace(balloon_x[0],balloon_y[0]);
	}
	if(check(balloon_x[1],balloon_y[1])){
		iSetcolor(.1,.9,.1);
		iFilledEllipse(balloon_x[1],balloon_y[1],major,minor,seg);
		balloon_lace(balloon_x[1],balloon_y[1]);
	}
	else {
		balloon++;
		alias_target--;
		balloon_x[1] = rand()%(rand()%100);
		balloon_y[1] = 0;
		balloon_x[1] += 700;
		balloon_lace(balloon_x[1],balloon_y[1]);
	}
	if(check(balloon_x[2],balloon_y[2])){
		iSetcolor((rand()%100)/255,(rand()%100)/255,(rand()%100)/255);
		
		//iSetcolor(.2,.5,.8);
		iFilledEllipse(balloon_x[2],balloon_y[2],major,minor,seg);
		balloon_lace(balloon_x[2],balloon_y[2]);
	}
	else {
		balloon++;
		alias_target--;
		balloon_x[2] = rand()%(rand()%100);
		balloon_y[2] = 0;
		balloon_x[2] += 600;
		iSetcolor((rand()%100)/255,(rand()%100)/255,(rand()%100)/255);
		balloon_lace(balloon_x[2],balloon_y[2]);
	}
	if(check(balloon_x[3],balloon_y[3])){
		iSetcolor(.7,.2,.6);
		iFilledEllipse(balloon_x[3],balloon_y[3],major,minor,seg);
		balloon_lace(balloon_x[3],balloon_y[3]);
	}
	else {
		balloon++;
		alias_target--;
		balloon_x[3] = rand()%(rand()%100);
		balloon_y[3] = 0;
		balloon_x[3] += 500;
		balloon_lace(balloon_x[3],balloon_y[3]);
	}
	if(check(balloon_x[4],balloon_y[4])){
		iSetcolor(.9,.1,.1);
		iFilledEllipse(balloon_x[4],balloon_y[4],major,minor,seg);
		balloon_lace(balloon_x[4],balloon_y[4]);
	}
	else {
		balloon++;
		alias_target--;
		balloon_x[4] = rand()%(rand()%100);
		balloon_y[4] = 0;
		balloon_x[4] += 900;
		balloon_lace(balloon_x[4],balloon_y[4]);
	}
}

void balloon_move1(){
	balloon_y[0]+=2;
	if(balloon_y[0]>700){
		balloon_y[0]=0;
	}
}

void balloon_move2(){
	balloon_y[1]+=3;
	if(balloon_y[1]>700){
		balloon_y[1]=0;
	}
}


void balloon_move3(){
	balloon_y[2]+=4;
	if(balloon_y[2]>700){
		balloon_y[2]=0;
	}
}


void balloon_move4(){
	balloon_y[3]+=5;
	if(balloon_y[3]>700){
		balloon_y[3]=0;
    }
}

void balloon_move5(){
	balloon_y[4]+=6;
	if(balloon_y[4]>700){
		balloon_y[4]=0;
	}
}

void arrow_move(){
	p+=10;
	if(p>1024){
		;
	}
}

int check_screen(){
	if(p<=30)return 1;
	else if(p>1024){
		return 2;
	}
	else return 3;
}




void iKeyboard(unsigned char key)
{
	if(key == 'w'){
		bow_ml_up_y+=7;
		bow_ml_down_y+=7;
		rect_low_y+=7;
		if(p<=30){
			q+=7;
		}
	}
	else if(key == 's'){
		bow_ml_up_y-=7;
		bow_ml_down_y-=7;
		rect_low_y-=7;
		if(p<=30){
			q-=7;
		}
	}
	else if(key == ' '){
		int x = check_screen();
		if(x == 1 ){
			iSettimer(20,arrow_move);
			arrow++;
		}else if(x == 2){
			p=bow_ml_up_x-40,q=bow_ml_up_y-10;
			arrow++;
		}
		else if (x == 3){

		}
	}
	//place your codes for other keys here
}
void i_draw_bow(){
	int i,j,k,m;
	iSetcolor(.8,.8,.8);
	iLine(bow_ml_up_x,bow_ml_up_y,bow_ml_down_x,bow_ml_down_y);//bow middle line
	iLine(bow_ml_up_x+tilt_x_down,bow_ml_up_y+tilt_y_down,bow_ml_up_x-(tilt_x_down+15),bow_ml_up_y+(tilt_y_down+30));//bow middle line associated tilt line up
	iLine(bow_ml_down_x+tilt_x_down,bow_ml_down_y-tilt_y_down,bow_ml_down_x-(tilt_x_down+15),bow_ml_down_y-(tilt_y_down+30));//bow middle line associated tilt line down

	//mid curve_down_horizontal
	for(i=0;i<=5;i++){
		iPoint(bow_ml_down_x+i,bow_ml_down_y,0);
	}

	//mid curve_down_curve1
	for(j=0;j<=4;j++){
		iPoint(bow_ml_down_x+i+j,bow_ml_down_y-j,0);
	}

	//mid curve_down_vertical
	for(k=0;k<=12;k++){
		iPoint(bow_ml_down_x+i+j,bow_ml_down_y-j-k,0);
	}

	//mid curve_down_curve2
	for(m=0;m<=7;m++){
		iPoint(bow_ml_down_x+i+j-m,bow_ml_down_y-j-k-m,0);
	}

	//mid curve_up_horizontal
	for(i=0;i<=5;i++){
		iPoint(bow_ml_up_x+i,bow_ml_up_y,0);
	}

	//mid curve_up_curve1
	for(j=0;j<=4;j++){
		iPoint(bow_ml_up_x+i+j,bow_ml_up_y+j,0);
	}

	//mid curvve_up_vertical
	for(k=0;k<=12;k++){
		iPoint(bow_ml_up_x+i+j,bow_ml_up_y+j+k,0);
	}

	//mid curve_up_curve2
	for(m=0;m<=7;m++){
		iPoint(bow_ml_up_x+i+j-m,bow_ml_up_y+j+k+m,0);
	}


	iLine(bow_ml_up_x-(tilt_x_down+15),bow_ml_up_y+(tilt_y_down+30),bow_ml_up_x-(tilt_x_down+15),bow_ml_up_y+(tilt_y_down+30)+10);//upcurve vertical
	iLine(bow_ml_down_x-(tilt_x_down+15),bow_ml_down_y-(tilt_y_down+30),bow_ml_down_x-(tilt_x_down+15),bow_ml_down_y-(tilt_y_down+30)-10);//downcurve vertical
	iLine(bow_ml_up_x-(tilt_x_down+15),bow_ml_up_y+(tilt_y_down+30)+10,bow_ml_up_x+(tilt_x_down-60),bow_ml_up_y+tilt_y_down-35);//upper portion tilt bow
	iLine(bow_ml_up_x+(tilt_x_down-60),bow_ml_up_y+tilt_y_down-35,bow_ml_down_x-(tilt_x_down+15),bow_ml_down_y-(tilt_y_down+30)-10);//lower portion tilt bow
}


void i_draw_arrow(){
	iSetcolor(.9,.6,.2);
	iFilledRectangle(rect_low_x,rect_low_y,width,height);
	iSetcolor(.7,.6,.9);
	iLine(rect_low_x+width,rect_low_y+1,rect_low_x+width-15,rect_low_y+8);//arrow head upper portion
	iLine(rect_low_x+width,rect_low_y+1,rect_low_x+width-15,rect_low_y-8);//arrow head lower portion
	iLine(rect_low_x,rect_low_y+1,rect_low_x-10,rect_low_y+10);//arrow back upper portion
    iLine(rect_low_x,rect_low_y+1,rect_low_x-10,rect_low_y-10);//arrow back lower portion
	iLine(rect_low_x-10,rect_low_y+10,rect_low_x-20,rect_low_y+10);//arrow back upper straight portion
	iLine(rect_low_x-10,rect_low_y-10,rect_low_x-20,rect_low_y-10);//arrow back lower straight portion
	iLine(rect_low_x-10,rect_low_y+height-1,rect_low_x-20,rect_low_y+10);//arrow back upper portion parallel
	iLine(rect_low_x-10,rect_low_y+1,rect_low_x-20,rect_low_y-10);//arrow back lower portion parallel
	iLine(rect_low_x,rect_low_y+1,rect_low_x-10,rect_low_y+1);
}
void i_draw_arrow_2(){
	iSetcolor(.9,.6,.2);
	iFilledRectangle(p,q,width,height);
	iSetcolor(.7,.6,.9);
	iLine(p+width,q+1,p+width-15,q+8);//arrow head upper portion
	iLine(p+width,q+1,p+width-15,q-8);//arrow head lower portion
	iLine(p,q+1,p-10,q+10);//arrow back upper portion
    iLine(p,q+1,p-10,q-10);//arrow back lower portion
	iLine(p-10,q+10,p-20,q+10);//arrow back upper straight portion
	iLine(p-10,q-10,p-20,q-10);//arrow back lower straight portion
	iLine(p-10,q+height-1,p-20,q+10);//arrow back upper portion parallel
	iLine(p-10,q+1,p-20,q-10);//arrow back lower portion parallel
	iLine(p,q+1,p-10,q+1);
}
void reset(){
	target = 0;
	balloon = 0;
	arrow = 0;
	major = 25,minor = 40,seg = 100;
	background = 1;
	flag=1;
	bound=1;
	bow_ml_up_x=70,bow_ml_up_y=500,bow_ml_down_x=70,bow_ml_down_y=480;
	tilt_x_down=5,tilt_y_down=25;
	rect_low_x=bow_ml_up_x-40,rect_low_y=bow_ml_up_y-10,width=70,height=2;
	start = 0, end = 0;
	ma = major / 2.0;
	mi = minor / 2.0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(score[i]>score[j]){
				double t = score[i];
				score[i] = score[j];
				score[j] = t;
			}
		}
	}
}
void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        //printf ("%d %d\n",mx,my);
		if(mx<644 && mx>372 && my<578 && my>534 && background==1){
            background = 7; // game mode
        }
        else if(mx<644 && mx>372 && my<448 && my>405 && background==1){
            background = 3; // instructions
        }
        else if(mx<644 && mx>372 && my<318 && my>274 && background==1){
            background = 4; // high score
			_hs = true;
        }
        else if(mx<644 && mx>372 && my<188 && my>147 && background==1){
            background = 5; // quit
        }
        else if(mx<103 && mx>7 && my<123 && my>108 && background ==3){
            background = 1; // instruction >> main menu
        }
        else if(mx<160 && mx>50 && my<118 && my>102 && background == 6){
             // game over >> try again
            reset();
            background = 1;
        }
        else if(mx<957 && mx>900 && my<117 && my>94 && background == 6){
            // game over >> quit
            exit(0);
        }
        else if(mx<445 && mx>53 && my<655 && my>604 && background == 7){
            background = 2; //game mode >> easy
            srand(time(NULL));
            target = alias_target = rand()%5+1;
            fake_target_e = target;
        }
        else if(mx<445 && mx>53 && my<572 && my>520 && background == 7){
            background = 2; // game mode >> medium
            srand(time(NULL));
            target = rand()%10+1;
            while(target<=5){
                target = rand()%10+1;
            }
            fake_target_m = target;
            alias_target = target;
        }
        else if(mx<445 && mx>53 && my<488 && my>437 && background == 7){
            background = 2; // game mode >> hard
            srand(time(NULL));
            target = rand()%15+1;
            while(target<=10){
                target = rand()%15+1;
            }
            fake_target_h = target;
            alias_target = target;
        }
        else if(mx<332 && mx>188 && my<185 && my>150 && background == 4){
            background = 1; // main menu >> highscore >> back
        }
		
		else if(mx<98 && mx>12 && my<48 && my>30 && background == 7){
			background = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

int main()
{
	init();
	iSettimer(50,balloon_move1);
	iSettimer(20,balloon_move2);
	iSettimer(20,balloon_move3);
	iSettimer(20,balloon_move4);
	iSettimer(20,balloon_move5);
	iInitialize(1024, 700, "BOW && ARROW !!!");
	return 0;
}

