RGB_MATRIX_EFFECT(mine)
RGB_MATRIX_EFFECT(mine_dim)
RGB_MATRIX_EFFECT(off)

//Standard colors
#define BLUE		0, 82, 204		// #0052cc
#define VIOLET		140, 0, 255		// #8c00ff
#define PINK		230, 0, 180		// #e600b4
#define RED			255, 0, 0		// #ff0000
#define ESC			150, 0, 0		// #8c0000
#define ORANGE		255, 40, 0		// #ff2600
#define YELLOW		200, 150, 0		// #c89600
#define GREEN		0, 190, 20		// #00be14
#define GREY		100, 100, 100	// #646464
#define WHITE		220, 220, 220	// #dcdcdc
#define TEAL		0, 179, 170		// #00ccc5
#define OFF			0, 0, 0			// #00b3aa

// Dim colors 50ish%
#define BLUE2		0, 35, 87
#define VIOLET2		98, 0, 178
#define PINK2		115, 0, 90
#define RED2		170, 0, 0
#define ESC2		110, 0, 0
#define ORANGE2		166, 25, 0
#define YELLOW2		112, 84, 0
#define GREEN2		0, 97, 10
#define GREY2		60, 60, 60
#define WHITE2		110, 110, 100
#define TEAL2		0, 87, 82	


// On
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool mine(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  
  rgb_matrix_set_color(0, ESC);				//ESC
  for (uint8_t i = 1; i < 13; i++) {
    rgb_matrix_set_color(i, ORANGE);		//Function #'s
  }
  rgb_matrix_set_color(13, TEAL);			//Prtsc
  rgb_matrix_set_color(14, ORANGE);			//Home
  rgb_matrix_set_color(15, VIOLET);			//Function
  rgb_matrix_set_color(16, YELLOW);			//Vol +
  rgb_matrix_set_color(17, YELLOW);			//Vol -
  
  
  for (uint8_t i = 18; i < 32; i++) {		//`-Bckspc
    rgb_matrix_set_color(i, GREEN);
  }
  rgb_matrix_set_color(32, RED);			//Del
  rgb_matrix_set_color(33, GREEN);			// /
  rgb_matrix_set_color(34, GREEN);			//*
  rgb_matrix_set_color(35, GREEN);			//-
  
  
  rgb_matrix_set_color(36, GREEN);			//Tab
  for (uint8_t i = 37; i < 49; i++) {
  rgb_matrix_set_color(i, BLUE);			//Q-]
  }
  rgb_matrix_set_color(49, GREEN);			//"\"
  rgb_matrix_set_color(50, BLUE);			//7
  rgb_matrix_set_color(51, BLUE);			//8
  rgb_matrix_set_color(52, BLUE);			//9
  rgb_matrix_set_color(53, GREEN);			//+
  
  
  rgb_matrix_set_color(54, GREEN);			//Caps
  for (uint8_t i = 55; i < 66; i++) {
    rgb_matrix_set_color(i, BLUE);			//A-"
  }
  rgb_matrix_set_color(66, GREEN);			//Enter
  rgb_matrix_set_color(67, BLUE);			//4
  rgb_matrix_set_color(68, BLUE);			//5
  rgb_matrix_set_color(69, BLUE);			//6
  
  
  rgb_matrix_set_color(70, GREEN);			//Shift
  for (uint8_t i = 71; i < 81; i++) {
    rgb_matrix_set_color(i, BLUE);			//Z-/
  } 
  rgb_matrix_set_color(81, GREEN);			//Shift
  rgb_matrix_set_color(82, PINK);			//Up
  rgb_matrix_set_color(83, BLUE);			//1
  rgb_matrix_set_color(84, BLUE);			//2
  rgb_matrix_set_color(85, BLUE);			//3
  rgb_matrix_set_color(86, GREEN);			//NumEnter
  
  
  rgb_matrix_set_color(87, GREEN);			//Ctrl
  rgb_matrix_set_color(88, GREY);			//Win
  rgb_matrix_set_color(89, GREEN);			//Alt
  rgb_matrix_set_color(90, GREEN);			//Space
  rgb_matrix_set_color(91, GREEN);			//Alt
  rgb_matrix_set_color(92, GREY);			//Win
  rgb_matrix_set_color(93, GREEN);			//Ctrl
  rgb_matrix_set_color(94, PINK);			//Left
  rgb_matrix_set_color(95, PINK);			//Down
  rgb_matrix_set_color(96, PINK);			//Right
  rgb_matrix_set_color(97, BLUE);			//0
  rgb_matrix_set_color(98, BLUE);			//.
  

  for (uint8_t i = 99; i < 119; i++) {
    rgb_matrix_set_color(i, OFF);			//Sides
  } 

  return rgb_matrix_check_finished_leds(led_max);
}


// Dim colors
static bool mine_dim(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  
  rgb_matrix_set_color(0, ESC2);			//ESC
  for (uint8_t i = 1; i < 13; i++) {
    rgb_matrix_set_color(i, ORANGE2);		//Function #'s
  }
  rgb_matrix_set_color(13, TEAL2);			//Prtsc
  rgb_matrix_set_color(14, ORANGE2);		//Home
  rgb_matrix_set_color(15, VIOLET2);		//Function
  rgb_matrix_set_color(16, YELLOW2);		//Vol +
  rgb_matrix_set_color(17, YELLOW2);		//Vol -
  
  
  for (uint8_t i = 18; i < 32; i++) {		//`-Bckspc
    rgb_matrix_set_color(i, GREEN2);
  }
  rgb_matrix_set_color(32, RED2);			//Del
  rgb_matrix_set_color(33, GREEN2);			// /
  rgb_matrix_set_color(34, GREEN2);			//*
  rgb_matrix_set_color(35, GREEN2);			//-
  
  
  rgb_matrix_set_color(36, GREEN2);			//Tab
  for (uint8_t i = 37; i < 49; i++) {
  rgb_matrix_set_color(i, BLUE2);			//Q-]
  }
  rgb_matrix_set_color(49, GREEN2);			//"\"
  rgb_matrix_set_color(50, BLUE2);			//7
  rgb_matrix_set_color(51, BLUE2);			//8
  rgb_matrix_set_color(52, BLUE2);			//9
  rgb_matrix_set_color(53, GREEN2);			//+
  
  
  rgb_matrix_set_color(54, GREEN2);			//Caps
  for (uint8_t i = 55; i < 66; i++) {
    rgb_matrix_set_color(i, BLUE2);			//A-"
  }
  rgb_matrix_set_color(66, GREEN2);			//Enter
  rgb_matrix_set_color(67, BLUE2);			//4
  rgb_matrix_set_color(68, BLUE2);			//5
  rgb_matrix_set_color(69, BLUE2);			//6
  
  
  rgb_matrix_set_color(70, GREEN2);			//Shift
  for (uint8_t i = 71; i < 81; i++) {
    rgb_matrix_set_color(i, BLUE2);			//Z-/
  } 
  rgb_matrix_set_color(81, GREEN2);			//Shift
  rgb_matrix_set_color(82, PINK2);			//Up
  rgb_matrix_set_color(83, BLUE2);			//1
  rgb_matrix_set_color(84, BLUE2);			//2
  rgb_matrix_set_color(85, BLUE2);			//3
  rgb_matrix_set_color(86, GREEN2);			//NumEnter
  
  
  rgb_matrix_set_color(87, GREEN2);			//Ctrl
  rgb_matrix_set_color(88, GREY2);			//Win
  rgb_matrix_set_color(89, GREEN2);			//Alt
  rgb_matrix_set_color(90, GREEN2);			//Space
  rgb_matrix_set_color(91, GREEN2);			//Alt
  rgb_matrix_set_color(92, GREY2);			//Win
  rgb_matrix_set_color(93, GREEN2);			//Ctrl
  rgb_matrix_set_color(94, PINK2);			//Left
  rgb_matrix_set_color(95, PINK2);			//Down
  rgb_matrix_set_color(96, PINK2);			//Right
  rgb_matrix_set_color(97, BLUE2);			//0
  rgb_matrix_set_color(98, BLUE2);			//.
  
  
  for (uint8_t i = 99; i < 119; i++) {
    rgb_matrix_set_color(i, OFF);			//Sides
  } 
  
  return rgb_matrix_check_finished_leds(led_max);
}


// Off
static bool off(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, OFF);
  } 
  
  return rgb_matrix_check_finished_leds(led_max);
}

#endif