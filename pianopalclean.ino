// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            9

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      208


// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

int Notes[8][26];
int Grid[8][26];
int isCyan[8][26];
int isCyanLeft[8][26];
int Right[8][26];
int Left[8][26];
int finone[8][26];
int fintwo[8][26];
int finthree[8][26];
int finfour[8][26];
int finfive[8][26];
int loc;
int timer;
int mode;
volatile int waittime;




int doi;
int speedfactor;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket

Notes[8][26];
loc = 0;
timer = 1;
  for (int i =0; i < 26; i++) {
    for (int j =0; j < 8; j++) {
      Notes[j][i] = loc;
      Grid[j][i] = 0;
      isCyan[j][i] = 0;
      isCyanLeft[j][i] = 0;
      Right[j][i] = 0;
      Left[j][i] = 0;
      finone[j][i] = 0;
      fintwo[j][i] = 0;
      finthree[j][i] = 0;
      finfour[j][i] = 0;
      finfive[j][i] = 0;
      loc++;
      }
  }

  // End of trinket special code
  Serial.begin(9600);
  //waittime = 400;
  pixels.begin(); // This initializes the NeoPixel library.
  waittime = 200;
}


void pushDown()
{
  for(int i = 25; i>=0; i--)
  {
    for(int j =7; j>=0; j--)
    {
      if(Grid[j][i] ==1)
      {
        Grid[j][i] = 0;
        if(j!=7)
        {
          Grid[j+1][i] = 1;
        }
      }
      if(isCyan[j][i] ==1)
      {
        isCyan[j][i] = 0;
        if(j!=7)
        {
          isCyan[j+1][i] = 1;
        }
      }

      //////
      if(Left[j][i] ==1)
      {
        Left[j][i] = 0;
        if(j!=7)
        {
          Left[j+1][i] = 1;
        }
      }
      if(Right[j][i] ==1)
      {
        Right[j][i] = 0;
        if(j!=7)
        {
          Right[j+1][i] = 1;
        }
      }
      if(isCyanLeft[j][i] ==1)
      {
        isCyanLeft[j][i] = 0;
        if(j!=7)
        {
          isCyanLeft[j+1][i] = 1;
        }
      }
      ////////
      if(finone[j][i] ==1)
      {
        finone[j][i] = 0;
        if(j!=7)
        {
          finone[j+1][i] = 1;
        }
      }
      if(fintwo[j][i] ==1)
      {
        fintwo[j][i] = 0;
        if(j!=7)
        {
          fintwo[j+1][i] = 1;
        }
      }
      if(finthree[j][i] ==1)
      {
        finthree[j][i] = 0;
        if(j!=7)
        {
          finthree[j+1][i] = 1;
        }
      }
      if(finfour[j][i] ==1)
      {
        finfour[j][i] = 0;
        if(j!=7)
        {
          finfour[j+1][i] = 1;
        }
      }
      if(finfive[j][i] ==1)
      {
        finfive[j][i] = 0;
        if(j!=7)
        {
          finfive[j+1][i] = 1;
        }
      }
    }
  }
}

void showColor()
{
  uint32_t cyan = pixels.Color(0, 150, 150);
    uint32_t blue = pixels.Color(0, 0, 150);

  pixels.setBrightness(30);
  for(int i = 25; i>=0; i--)
  {
    for(int j =7; j>=0; j--)
    {
      if(Grid[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
          pixels.setPixelColor(Notes[j][i], cyan);
          int k = 7;
          
          while(Grid[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyan[k-1][i] = 1;
            k--;
          }
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          if (isCyan[j][i] == 1)
          {  
            //pixels.setPixelColor(Notes[3][19], cyan);   
             pixels.setPixelColor(Notes[j][i], cyan); 
          }
          else
          {
            pixels.setPixelColor(Notes[j][i], blue); 
          }
          
        }
        // Moderately bright green color.
      } 
      else
      {
        //pixels.setPixelColor(Notes[j][i], 50,0,0,5);
        pixels.setPixelColor(Notes[j][i], pixels.Color(0,0,0));
      }
    }
  }
  pixels.show();
}

void showColorHands()
{
  uint32_t green = pixels.Color(0, 150, 0);
    uint32_t red = pixels.Color(150, 0, 0);
    uint32_t yellow = pixels.Color(150, 150, 0);
    uint32_t orange = pixels.Color(150, 60, 0);

  pixels.setBrightness(30);
  for(int i = 25; i>=0; i--)
  {
    for(int j =7; j>=0; j--)
    {
      if(Right[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
             pixels.setPixelColor(Notes[j][i], yellow); 
          int k = 7;
          
          while(Right[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyan[k-1][i] = 1;
            k--;
          }
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          if (isCyan[j][i] == 1)
          {  
             pixels.setPixelColor(Notes[j][i], yellow); 
          }
          else
          {
            pixels.setPixelColor(Notes[j][i], green); 
          }
          
        }
        
      } 
      if(Left[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
             pixels.setPixelColor(Notes[j][i], orange); 
          int k = 7;
          
          while(Left[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyanLeft[k-1][i] = 1;
            k--;
          }
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          if (isCyanLeft[j][i] == 1)
          {  
             pixels.setPixelColor(Notes[j][i], orange); 
          }
          else
          {
            pixels.setPixelColor(Notes[j][i], red); 
          }
          
        }
        
      }
      else
      {
        //pixels.setPixelColor(Notes[j][i], 50,0,0,5);
        if(Grid[j][i] == 0)
        {
          pixels.setPixelColor(Notes[j][i], pixels.Color(0,0,0));
        }
        
      }
    }
  }
  pixels.show();
}

void showColorFingers()
{
  uint32_t pink = pixels.Color(150, 0, 150);
  uint32_t green = pixels.Color(0, 150, 0);
    uint32_t red = pixels.Color(150, 0, 0);
    uint32_t blue = pixels.Color(0, 0, 150);
        uint32_t yellow = pixels.Color(150, 150, 0);
                uint32_t white = pixels.Color(150, 150, 150);



  pixels.setBrightness(30);
  for(int i = 25; i>=0; i--)
  {
    for(int j =7; j>=0; j--)
    {
      if(finone[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
             pixels.setPixelColor(Notes[j][i], white); 
          int k = 7;
          /*
          while(Right[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyan[k-1][i] = 1;
            k--;
          }*/
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          
          
            pixels.setPixelColor(Notes[j][i], pink); 
          
          
        }
        
      } 
      if(fintwo[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
             pixels.setPixelColor(Notes[j][i], white); 
          int k = 7;
          /*
          while(Left[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyanLeft[k-1][i] = 1;
            k--;
          }*/
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          
          
            pixels.setPixelColor(Notes[j][i], green); 
          
          
        }
        
      }
      if(finthree[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
             pixels.setPixelColor(Notes[j][i], white); 
          int k = 7;
          /*
          while(Left[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyanLeft[k-1][i] = 1;
            k--;
          }*/
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          
          
            pixels.setPixelColor(Notes[j][i], red); 
          
          
        }
        
      }
      if(finfour[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
             pixels.setPixelColor(Notes[j][i], white); 
          int k = 7;
          /*
          while(Left[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyanLeft[k-1][i] = 1;
            k--;
          }*/
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          
          
            pixels.setPixelColor(Notes[j][i], blue); 
          
          
        }
        
      }
      if(finfive[j][i] ==1)
      {
        if(j == 7)
        { 
          //pixels.setBrightness(120);
             pixels.setPixelColor(Notes[j][i], white); 
          int k = 7;
          /*
          while(Left[k-1][i] == 1 && k>=0) //if out of bounds error it's here
          {
            //pixels.setPixelColor(Notes[7][14], cyan);
            //pixels.setPixelColor(Notes[k-1][i], cyan);
            isCyanLeft[k-1][i] = 1;
            k--;
          }*/
          
         //pixels.show();
          
        }
        else
        {
          //uint32_t cyan = pixels.Color(0, 150, 150);
          //pixels.setBrightness(80);
          
          
            pixels.setPixelColor(Notes[j][i], yellow); 
          
          
        }
        
      }
      else
      {
        //pixels.setPixelColor(Notes[j][i], 50,0,0,5);
        if(Grid[j][i] == 0)
        {
          pixels.setPixelColor(Notes[j][i], pixels.Color(0,0,0));
        }
        
      }
    }
  }
  pixels.show();
}

void increaseSpeed()
{
  waittime = waittime/2;
}

void decreaseSpeed()
{
  waittime = waittime*2;
}

void loop() {

if(Serial.available()>0)
{
  doi = Serial.parseInt();
  speedfactor = doi/10;
  doi = doi%10;

  if(doi == 1)
  {
    //cscalefingeringupdown();
  }
  else if(doi == 2)
  {
    //carpeggiofinger();
  }
  else if(doi == 3)
      {
      timer = 0;
      while(timer < 41)
      {
            if(timer==1)
        {
          Grid[0][0] = 1;
        }
        
        if(timer == 3)
        {
          Grid[0][0] = 1;
        }
        
        if(timer ==5)
        {
          Grid[0][7] = 1;
        }
        
        if(timer ==7)
        {
          Grid[0][7] = 1;
        }
        
        if(timer ==9)
        {
          Grid[0][9] = 1;
        }
        
        if(timer ==11)
        {
          Grid[0][9] = 1;
        }
        
        if(timer ==13 || timer == 14 || timer == 15 || timer == 16)
        {
          Grid[0][7] = 1;
        }
        
        if(timer ==17 || timer == 19 )
        {
          Grid[0][5] = 1;
        }
        
        if(timer ==21 || timer == 23 )
        {
          Grid[0][4] = 1;
        }
        
        if(timer ==25 || timer == 27 )
        {
          Grid[0][2] = 1;
        }
        
        if(timer ==29 || timer == 30 || timer == 31 || timer == 32 )
        {
          Grid[0][0] = 1;
        }
        
        showColor();
        pushDown();
        //delay(waittime);
                delay((speedfactor*150-150));

        timer++;
      }
    }

    else if(doi == 4)
    {
      timer = 0;
      while(timer < 40)
      {
            
        if(timer==1)
        {
          Grid[0][5] = 1;
        }

        if(timer==2)
        {
          Grid[0][9] = 1;
        }

        if(timer==3)
        {
          Grid[0][5] = 1;
        }

        if(timer==4||timer == 5 || timer==6||timer == 7 || timer == 8)
        {
          Grid[0][4] = 1;
        }


        if(timer==9)
        {
          Grid[0][5] = 1;
        }

        if(timer==10)
        {
          Grid[0][9] = 1;
        }

        if(timer==11)
        {
          Grid[0][4] = 1;
        }

        if(timer==12 || timer == 13 || timer == 14)
        {
          Grid[0][2] = 1;
        }

        if(timer==16)
        {
          Grid[0][2] = 1;
        }

        if(timer==17)
        {
          Grid[0][5] = 1;
        }

        if(timer==18)
        {
          Grid[0][2] = 1;
        }

        if(timer==19||timer == 20 || timer == 21 || timer == 22 || timer == 23)
        {
          Grid[0][0] = 1;
        }


        showColor();
        pushDown();
        //delay(waittime*1.5);
                delay((speedfactor*150-150));

        timer++;
      }
      
    }
  if(doi == 5)
  {
    timer = 0;
      while(timer < 55)
      {
        if(timer == 1 || timer == 3 || timer == 5 || timer == 7 || timer == 9||timer == 11)
        {
          Left[0][5] = 1;
          Right[0][7] = 1;
          Grid[0][5] = 1;
          Grid[0][7] = 1;
          
        }

        if(timer == 13 || timer == 15 || timer == 17 || timer == 19 || timer == 21||timer == 23)
        {
          Left[0][4] = 1;
          Right[0][7] = 1;
          Grid[0][4] = 1;
          Grid[0][7] = 1;
        }

        if(timer == 25 || timer == 27 || timer == 29 || timer == 31 || timer == 33||timer == 35)
        {
          Left[0][2] = 1;
          Right[0][11] = 1;
          Grid[0][2] = 1;
          Grid[0][11] = 1;
        }

        if(timer == 37 || timer == 38 || timer == 40 || timer == 42)
        {
          Left[0][0] = 1;
          Right[0][12] = 1;
          Grid[0][0] = 1;
          Grid[0][12] = 1;
        }
        
        
        showColorHands();
        pushDown();
        //delay(waittime*1.5);
        delay((speedfactor*150-150));

        timer++;
      }
      
  }
  else if(doi == 6)
  {
    timer = 0;
      while(timer < 75)
      {
        if(timer == 1 || timer == 3)
        {
          finthree[0][4] = 1;
          Grid[0][4] = 1;
          
        }

        if(timer == 5)
        {
          finfour[0][5] = 1;
          Grid[0][5] = 1;
          
        }

        if(timer == 7 || timer == 9)
        {
          finfive[0][7] = 1;
          Grid[0][7] = 1;
          
        }

        if(timer == 11)
        {
          finfour[0][5] = 1;
          Grid[0][5] = 1;
          
        }

        if(timer == 13)
        {
          finthree[0][4] = 1;
          Grid[0][4] = 1;
          
        }

        if(timer == 15)
        {
          fintwo[0][2] = 1;
          Grid[0][2] = 1;
          
        }


        if(timer == 17 || timer == 19)
        {
          finone[0][0] = 1;
          Grid[0][0] = 1;
          
        }

        if(timer == 21)
        {
          fintwo[0][2] = 1;
          Grid[0][2] = 1;
          
        }

        if(timer == 23 || timer == 25 || timer == 26)
        {
          finthree[0][4] = 1;
          Grid[0][4] = 1;
          
        }

        if(timer == 27 || timer == 28 || timer == 29)
        {
          fintwo[0][2] = 1;
          Grid[0][2] = 1;
          
        }

        if(timer == 31 || timer == 33)
        {
          finthree[0][4] = 1;
          Grid[0][4] = 1;
          
        }

        if(timer == 35)
        {
          finfour[0][5] = 1;
          Grid[0][5] = 1;
          
        }

        if(timer == 37 || timer == 39)
        {
          finfive[0][7] = 1;
          Grid[0][7] = 1;
          
        }

        if(timer == 41)
        {
          finfour[0][5] = 1;
          Grid[0][5] = 1;
          
        }

        if(timer == 43)
        {
          finthree[0][4] = 1;
          Grid[0][4] = 1;
          
        }

        if(timer == 45)
        {
          fintwo[0][2] = 1;
          Grid[0][2] = 1;
          
        }


        if(timer == 47 || timer == 49)
        {
          finone[0][0] = 1;
          Grid[0][0] = 1;
          
        }

        if(timer == 51)
        {
          fintwo[0][2] = 1;
          Grid[0][2] = 1;
          
        }

        if(timer == 53)
        {
          finthree[0][4] = 1;
          Grid[0][4] = 1;
          
        }

        if(timer == 55 || timer == 56)
        {
          fintwo[0][2] = 1;
          Grid[0][2] = 1;
          
        }

        if(timer == 57 || timer == 59|| timer == 60)
        {
          finone[0][0] = 1;
          Grid[0][0] = 1;
          
        }

        showColorFingers();
        pushDown();
        delay((speedfactor*150-150));
        timer++;
      }
  }
  else if(doi == 7)
    {
      
      increaseSpeed();
      //factor[0] = factor[0] - 1;
      //carpeggiofinger();
      
    }
    else if(doi == 8)
    {
      decreaseSpeed();
     // factor[0] = factor[0] + 1;
    }
  
      
    

  
}
    

  
}
