RGB_MATRIX_EFFECT(mine)

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

// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
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

#endif