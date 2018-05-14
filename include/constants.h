#ifndef CONSTANTS_H
#define CONSTANTS_H

#if (__APPLE__ && __MACH__)
static const bool USE_DARK_STYLE = true;
#else
static const bool USE_DARK_STYLE = false; // dark style does not display some widgets properly on Linux
#endif
static const unsigned int CPU_FRAME_BUFFER_SIZE = 50;
static const unsigned int MAX_SIZE = 2560*2560;
static const unsigned int MAX_N = 50;
static const unsigned int GPU_FRAME_BUFFER_SIZE = 150;
static const unsigned int BLOCK_SIZE = 20;
static const unsigned int NUMBER_OF_BINS = 1024;

static const unsigned int FRAME_SKIP_FACTOR = 10; //This means only every frame modulo 10 will be redrawn, this has to do with the slowness of qcustomplot, a lower value will increase the frame rate. A value of 0 will make it attempt to draw every single frame
static const unsigned int TARGET_FRAMERATE = 60;
static const unsigned int FRAME_DISPLAY_PERIOD_MSECS = 1000 / TARGET_FRAMERATE;


#endif // CONSTANTS_H