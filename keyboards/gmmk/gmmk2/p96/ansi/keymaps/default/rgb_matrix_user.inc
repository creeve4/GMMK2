RGB_MATRIX_EFFECT(mine)
RGB_MATRIX_EFFECT(mine_dim)

//Standard colors
#define BLUE		0, 100, 255
#define VIOLET		140, 0, 255
#define PINK		255, 0, 200
#define RED			255, 0, 0
#define ESC			140, 0, 0
#define ORANGE		255, 40, 0
#define YELLOW		200, 150, 0
#define GREEN		0, 190, 20
#define GREY		100, 100, 100
#define WHITE		220, 220, 220
#define OFF			0, 0, 0

// Dim colors to 25%
#define BLUE2		0, 22, 56
#define VIOLET2		35, 0, 64
#define PINK2		64, 0, 50
#define RED2		100, 0, 0
#define ESC2		40, 0, 0
#define ORANGE2		64, 10, 0
#define YELLOW2		48, 36, 0
#define GREEN2		0, 48, 5
#define GREY2		30, 30, 30
#define WHITE2		51, 51, 51


// Standard colors
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool mine(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  
  rgb_matrix_set_color(0, ESC);				//ESC
  for (uint8_t i = 1; i < 13; i++) {
    rgb_matrix_set_color(i, ORANGE);		//Function #'s
  }
  rgb_matrix_set_color(13, ORANGE);			//Prtsc
  rgb_matrix_set_color(14, WHITE);			//Lights
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
  rgb_matrix_set_color(13, ORANGE2);		//Prtsc
  rgb_matrix_set_color(14, WHITE2);			//Lights
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

#endif