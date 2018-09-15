# Neopixel-guitar-hero
Allows user to add notes at specific times so that lights will come down a Neopixel grid in "guitar-hero" style.

Use the matlab gui to communicate with the arduino via a serial connection.
It sends info to the arduino about which song to play and how fast to play it.

The arduino code consists mainly of arrays, functions to move the lights down the array, and a section where you can add your own songs.
Variable 'timer' keeps track of how far into the song you are (1 increment is one unit of time that can be whatever you want...allows for different time signatures and speeds)

When adding notes, consider the following - 

Each key has 8 LED, and I arranged the neopixel values to go in column-major order instead of row-major so 
for the first key the values would be 0-7. Each key starts at (previous key + 8), so the keys go on like 0,8,16,24, etc.
Knowing this, you can add a note at a given time by using
if(timer==*TIME*)
{
      Grid[0][*VALUE OF FIRST LED AT THE NOTE YOU WANT TO PLAY*] = 1;
}

then at the end of your song add 

showColor();
pushDown();
delay((speedfactor*150-150));
timer++;

This will do the rest for you and 'push' the colors down until it reaches the bottom.

The above code was FOR JUST PLAIN LIGHTS WITH NO FINGERING

FOR SHOWING DIFFERENT COLORS FOR LEFT AND RIGHT HANDS
you have to also add 1s to the 'Left' and 'Right' arrays like this
if(timer==*TIME*)
{
          Left[0][*VALUE OF FIRST LED AT THE NOTE YOU WANT TO PLAY*] = 1;
          Right[0][*VALUE OF FIRST LED AT THE NOTE YOU WANT TO PLAY*] = 1;
          Grid[0][*VALUE OF FIRST LED AT THE NOTE YOU WANT TO PLAY*] = 1;
          Grid[0][*VALUE OF FIRST LED AT THE NOTE YOU WANT TO PLAY*] = 1;
}

and then at the end 

showColorHands();
pushDown();
delay((speedfactor*150-150));
timer++;

FOR SHOWING DIFFERENT COLORS FOR EACH FINGER
you have to also add 1s to 'finone', 'fintwo', 'finthree', 'finfour', and 'finfive'
if(timer==*TIME*)
{
          finthree[0][*VALUE OF FIRST LED AT THE NOTE YOU WANT TO PLAY*] = 1;
          Grid[0][*VALUE OF FIRST LED AT THE NOTE YOU WANT TO PLAY*] = 1;
}

and then
showColorFingers();
pushDown();
delay((speedfactor*150-150));
timer++;
